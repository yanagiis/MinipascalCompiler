#include "minipascal_nmethoddeclaration.h"

#include <iostream>
#include <llvm/Function.h>
#include <llvm/LLVMContext.h>

#include "minipascal_visitor.h"
#include "../Checkers/codegencontext.h"

minipascal::NMethodDeclaration::NMethodDeclaration()
{
        setFail(false);
}

minipascal::NMethodDeclaration::~NMethodDeclaration()
{

}

void minipascal::NMethodDeclaration::accept(minipascal::Visitor* visitor)
{
        return visitor->visit(this);
}

minipascal::Decls_list* minipascal::NMethodDeclaration::getArgs()
{
        return args;
}

minipascal::ShareNBlock minipascal::NMethodDeclaration::getBlock()
{
        return block;
}

minipascal::Decls_list* minipascal::NMethodDeclaration::getDecl()
{
        return decl;
}

void minipascal::NMethodDeclaration::setArgs(minipascal::Decls_list* args)
{
        this->args = args;
}

void minipascal::NMethodDeclaration::setDecl(minipascal::Decls_list* decl)
{
        this->decl = decl;
}

void minipascal::NMethodDeclaration::setBlock(NBlock* block)
{
        this->block.reset(block);
}

std::string minipascal::NMethodDeclaration::getOutput()
{
        std::string output = "method declaration : '" + getName() + "', type : " + getType()->getName();
        return output;
}

llvm::Value* minipascal::NMethodDeclaration::codeGen(CodeGenContext* context)
{
        std::cout << "Generating code for " << getOutput() << std::endl;
        
        // collect args type
        std::vector<const llvm::Type*> argTypes;
        minipascal::Decls_list* args = getArgs();
        for(Decls_list::iterator it = args->begin(); it != args->end(); ++it)
        {
                argTypes.push_back((*it)->getType()->getLLVMType());
        }
        // create llvm function pointer
        llvm::FunctionType* ftype = llvm::FunctionType::get(getType()->getLLVMType(), argTypes, false);
        llvm::Function* function = llvm::Function::Create(ftype, llvm::GlobalValue::InternalLinkage, getName().c_str(), context->getModule());
        // create a basic block for this function
        llvm::BasicBlock* bblock = llvm::BasicBlock::Create(llvm::getGlobalContext(), "entry", function, 0);
        
        // add function to symboltable
        Symbol* symbol = new Symbol();
        symbol->declaration = this;
        symbol->value = function;       // IMPORTANT!! this is llvm function ptr
        context->getCurBlock()->getLocals()->insert(SymbolTableItem(getName(), symbol));
        
        // push symbol table
        context->pushBlock();
        context->getCurBlock()->setBlock(bblock);
        context->builder->SetInsertPoint(bblock);
        
        // set args name
        Symbol* argsymbol;
        Decls_list::iterator dit = getArgs()->begin();
        for(llvm::Function::arg_iterator arg_it = function->arg_begin(); arg_it != function->arg_end(); ++arg_it, ++dit)
        {
                // create ptr_arg for each argument
                std::string regname = "ptr_" + (*dit)->getName();
                llvm::Value* tempvalue = context->builder->CreateAlloca(arg_it->getType(), 0, regname.c_str());
                arg_it->setName((*dit)->getName().c_str());
                context->builder->CreateStore(arg_it, tempvalue);
                // add ptr_arg to symboltable
                argsymbol = new Symbol();
                argsymbol->declaration = (*dit).get();
                argsymbol->value = tempvalue;   // IMPORTANT!! this is llvm value ptr
                context->getCurBlock()->getLocals()->insert(SymbolTableItem((*dit)->getName(), argsymbol));
        }
        
        // add return value to symboltable
        VoidType temp;
        Symbol* retsymbol = new Symbol();
        if(!(getType()->compare(&temp)))
        {
                retsymbol->declaration = this;
                retsymbol->value = context->builder->CreateAlloca(this->getType()->getLLVMType(), 0, this->getName().c_str());
                context->getCurBlock()->getLocals()->insert(SymbolTableItem(this->getName(), retsymbol));
        }
        
        minipascal::Decls_list* decls = getDecl();
        minipascal::Decls_list::iterator it;
        for(it = decls->begin(); it != decls->end(); ++it)
        {
                (*it)->codeGen(context);
        }
        getBlock()->codeGen(context);
        
        if(!(getType()->compare(&temp)))
        {
                llvm::Value* retval = context->builder->CreateLoad(retsymbol->value, "retval");
                context->builder->CreateRet(retval);
        }
        else
        {
                context->builder->CreateRetVoid();
        }
        
        context->popBlock();
        context->builder->SetInsertPoint(context->getCurBlock()->getBlock());
}
