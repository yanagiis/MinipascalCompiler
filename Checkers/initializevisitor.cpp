#include "initializevisitor.h"

#include <stdio.h>
#include <iostream>
#include <llvm/Module.h>
#include <llvm/LLVMContext.h>
#include <llvm/Instructions.h>
#include <boost/cast.hpp>

#include "symbol.h"

minipascal::InitializeVisitor::InitializeVisitor(CodeGenContext* context)
{
        this->context = context;
}

minipascal::InitializeVisitor::~InitializeVisitor()
{

}

void minipascal::InitializeVisitor::visit(minipascal::Node* node)
{
        std::cout << "Should not call this method" << std::endl;
}

void minipascal::InitializeVisitor::visit(minipascal::NAssignment* node)
{
        showMessage("NAssignment -- " + node->getOutput());
        context->setNodeBlockMap(node);
        node->getVar()->accept(this);
        node->getExp()->accept(this);
}

void minipascal::InitializeVisitor::visit(minipascal::NBinaryOperator* node)
{
        showMessage("NBinaryOperator -- " + node->getOutput());
        context->setNodeBlockMap(node);
        node->getLeft()->accept(this);
        node->getRight()->accept(this);
        switch(node->getOP()) {
                case minipascal::NBinaryOperator::ADD:
                case minipascal::NBinaryOperator::SUB:
                case minipascal::NBinaryOperator::MUL:
                case minipascal::NBinaryOperator::DIV:
                        node->setType(node->getLeft()->getType());
                        break;
                case minipascal::NBinaryOperator::GT:
                case minipascal::NBinaryOperator::GE:
                case minipascal::NBinaryOperator::LT:
                case minipascal::NBinaryOperator::LE:
                case minipascal::NBinaryOperator::EQ:
                case minipascal::NBinaryOperator::NE:
                        node->setType(new minipascal::BooleanType());
                        break;
        }
}

void minipascal::InitializeVisitor::visit(minipascal::NBlock* node)
{
        showMessage("NBlock -- " + node->getOutput());
        context->setNodeBlockMap(node);
        minipascal::Stmt_list* stmts = node->getStmts();
        for(minipascal::Stmt_list::const_iterator it = stmts->begin(); it != stmts->end(); ++it)
        {
                (*it)->accept(this);
        }
}

void minipascal::InitializeVisitor::visit(minipascal::NBoolean* node)
{
        showMessage("NBoolean -- " + node->getOutput());
        context->setNodeBlockMap(node);
}

void minipascal::InitializeVisitor::visit(minipascal::NControl* node)
{
        showMessage("NControl -- " + node->getOutput());
        context->setNodeBlockMap(node);
        node->getCond()->accept(this);
        node->getTrue()->accept(this);
        node->getFalse()->accept(this);
}

void minipascal::InitializeVisitor::visit(minipascal::NDouble* node)
{
        showMessage("NDouble -- " + node->getOutput());
        context->setNodeBlockMap(node);
}

void minipascal::InitializeVisitor::visit(minipascal::NInt* node)
{
        showMessage("NInt -- " + node->getOutput());
        context->setNodeBlockMap(node);
}

void minipascal::InitializeVisitor::visit(minipascal::NLoop* node)
{
        showMessage("NLoop -- " + node->getOutput());
        context->setNodeBlockMap(node);
        node->getCond()->accept(this);
        node->getStmt()->accept(this);
}

void minipascal::InitializeVisitor::visit(minipascal::NMethodCall* node)
{
        showMessage("NMethodCall -- " + node->getOutput());
        context->setNodeBlockMap(node);
        SymbolTable::iterator it = context->getCurBlock()->getLocals()->find(node->getName());
        if(it == context->getCurBlock()->getLocals()->end())
        {
                showError("No such function : " + node->getName(), node);
                node->setFail(true);
                return;
        }
        
        node->setType(it->second->declaration->getType());
        
        const minipascal::Exps_list* exps = node->getExps();
        minipascal::Exps_list::const_iterator eit;
        for(eit = exps->begin(); eit != exps->end(); ++eit)
        {
                (*eit)->accept(this);
        }
        
        // args check
        try{
                NMethodDeclaration* method = boost::polymorphic_cast<NMethodDeclaration*>(it->second->declaration);
                Decls_list* decls = method->getArgs();
                Decls_list::iterator dit;
                for(dit = decls->begin(), eit = exps->begin(); dit != decls->end() && eit != exps->end(); ++eit, ++dit)
                {
                        if(!((*dit)->getType()->compare((*eit)->getType())))
                        {
                                showError("Function " + node->getName() + " args doesn't match" , node);
                                node->setFail(true);
                                return;
                        }
                }
        }catch(std::bad_cast& e){
                showError("No such function : " + node->getName(), node);
                node->setFail(true);
                return;
        }
}

void minipascal::InitializeVisitor::visit(minipascal::NMethodDeclaration* node)
{
        showMessage("NMethodDeclaration -- " + node->getOutput());
        
        std::vector<const llvm::Type*> argTypes;
        minipascal::Decls_list* args = node->getArgs();
        for(Decls_list::iterator it = args->begin(); it != args->end(); ++it)
        {
                argTypes.push_back((*it)->getType()->getLLVMType());
        }
        llvm::FunctionType* ftype = llvm::FunctionType::get(node->getType()->getLLVMType(), argTypes, false);
        llvm::Function* function = llvm::Function::Create(ftype, llvm::GlobalValue::InternalLinkage, node->getName().c_str(), context->getModule());
        llvm::BasicBlock* bblock = llvm::BasicBlock::Create(llvm::getGlobalContext(), "entry", function, 0);
        
        Symbol* symbol = new Symbol();
        symbol->declaration = node;
        symbol->value = function;
        
        context->getCurBlock()->getLocals()->insert(SymbolTableItem(node->getName(), symbol));
        context->pushBlock();
        context->getCurBlock()->setBlock(bblock);
        context->setNodeBlockMap(node);
        
        minipascal::Decls_list* decls = node->getDecl();
        minipascal::Decls_list::iterator it;
        for(it = args->begin(); it != args->end(); ++it)
        {
                (*it)->accept(this);
        }
        for(it = decls->begin(); it != decls->end(); ++it)
        {
                (*it)->accept(this);
        }
        node->getBlock()->accept(this);
        context->popBlock();
}

void minipascal::InitializeVisitor::visit(minipascal::NProgram* node)
{
        showMessage("NProgram -- " + node->getOutput());
        
        llvm::FunctionType* ftype = llvm::FunctionType::get(llvm::Type::getVoidTy(llvm::getGlobalContext()), std::vector<const llvm::Type*>(), false);
        llvm::Function* mainFunction = llvm::Function::Create(ftype, llvm::GlobalValue::InternalLinkage, "main", context->getModule());
        llvm::BasicBlock* bblock = llvm::BasicBlock::Create(llvm::getGlobalContext(), "entry", mainFunction, 0);
        
        context->pushBlock();
        context->getCurBlock()->setBlock(bblock);
        context->setNodeBlockMap(node);
        
        minipascal::Decls_list* decls = node->getDecls();
        for(minipascal::Decls_list::iterator it = decls->begin(); it != decls->end(); ++it)
        {
                (*it)->accept(this);
        }
        minipascal::Mhd_list* mhds = node->getMhds();
        for(minipascal::Mhd_list::iterator it = mhds->begin(); it != mhds->end(); ++it)
        {
                (*it)->accept(this);
        }
        node->getBlock()->accept(this);
        context->popBlock();
}

void minipascal::InitializeVisitor::visit(minipascal::NStatementExpression* node)
{
        showMessage("NStatementExpression -- " + node->getOutput());
        context->setNodeBlockMap(node);
        node->getExps()->accept(this);
}

void minipascal::InitializeVisitor::visit(minipascal::NString* node)
{
        showMessage("NString -- " + node->getOutput());
        context->setNodeBlockMap(node);
}

void minipascal::InitializeVisitor::visit(minipascal::NVariable* node)
{
        showMessage("NVariable -- " + node->getOutput());
        context->setNodeBlockMap(node);
        // is this variable declaration?
        CodeGenContext::BlockStack* stack = &(context->blockstack);
        CodeGenContext::BlockStack::reverse_iterator rit;
        SymbolTable::iterator sit;
        for(rit = stack->rbegin(); rit != stack->rend(); ++rit)
        {
                if((sit = (*rit)->getLocals()->find(node->getName())) != (*rit)->getLocals()->end())
                {
                        Exps_list* exps = node->getExps();
                        for(Exps_list::iterator it = exps->begin(); it != exps->end(); ++it)
                        {
                                (*it)->accept(this);
                        }
                        
                        // set type
                        NType* type = (*sit).second->declaration->getType();
                        for(int i = 0; i < exps->size(); ++i)
                        {
                                try{
                                        ArrayType* temp = boost::polymorphic_cast<ArrayType*>(type);
                                        type = temp->getType();
                                } catch(std::bad_cast& e){
                                        showError("Variable " + node->getName() + " wrong dimention", node);
                                        node->setFail(true);
                                        return;
                                }
                        }
                        
                        int i= 0;
                        for(Exps_list::iterator it = exps->begin(); it != exps->end(); ++i, ++it)
                        {
                                // if index is a constant
                                try{
                                        NType* type = sit->second->declaration->getType();
                                        ArrayType* arraytype = boost::polymorphic_cast<ArrayType*>(type);
                                        ArrayType::Range range = arraytype->getRange();
                                        // Is index out of range?
                                        NInt* constant = boost::polymorphic_cast<NInt*>(it->get());
                                        int index = constant->getValue();
                                        if(index < range.first || index > range.second)
                                        {
                                                char num[3];
                                                int count = sprintf(num, "%d", i);
                                                std::string numstr = std::string(num, count);
                                                showError("Variable " + node->getName() + "'s index["+ numstr +"] out of range", node);
                                                node->setFail(true);
                                        }
                                }catch(std::bad_cast& e){
                                        // do nothing 
                                }
                        }
                        node->setType(type);
                        break;
                }
        }
        if(rit == stack->rend())
        {
                showError("Undeclared variable : " + node->getName(), node);
                node->setFail(true);
                return;
        }
}

void minipascal::InitializeVisitor::visit(minipascal::NVariableDeclaration* node)
{
        showMessage("NVariableDeclaration -- " + node->getOutput());
        context->setNodeBlockMap(node);
        
        llvm::AllocaInst* alloc = new llvm::AllocaInst(node->getType()->getLLVMType());
        Symbol* symbol = new Symbol();
        symbol->declaration = node;
        symbol->value = alloc;
        std::pair<minipascal::SymbolTable::iterator,bool> result = context->getCurBlock()->getLocals()->insert(minipascal::SymbolTableItem(node->getName(), symbol));
        if(!result.second)
        {
                showError("Duplicate declaration " + node->getName(), node);
        }
}

void minipascal::InitializeVisitor::visit(minipascal::ArrayType* node)
{
        showMessage("ArrayType -- " + node->getOutput());
        context->setNodeBlockMap(node);
        node->getType()->accept(this);
}

void minipascal::InitializeVisitor::visit(minipascal::IntType* node)
{
        showMessage("IntType -- " + node->getOutput());
        context->setNodeBlockMap(node);
}

void minipascal::InitializeVisitor::visit(minipascal::RealType* node)
{
        showMessage("RealType -- " + node->getOutput());
        context->setNodeBlockMap(node);
}

void minipascal::InitializeVisitor::visit(minipascal::BooleanType* node)
{
        showMessage("BooleanType -- " + node->getOutput());
        context->setNodeBlockMap(node);
}

void minipascal::InitializeVisitor::visit(minipascal::StringType* node)
{
        showMessage("StringType -- " + node->getOutput());
        context->setNodeBlockMap(node);
}

void minipascal::InitializeVisitor::visit(minipascal::VoidType* node)
{
        showMessage("VoidType -- " + node->getOutput());
        context->setNodeBlockMap(node);
}

void minipascal::InitializeVisitor::showMessage(std::string name)
{
        std::cout << "Initialize " << name <<  std::endl;
}

void minipascal::InitializeVisitor::showError(std::string message, minipascal::Node* node)
{
        char buf[8];
        sprintf(buf, "%d", node->getLineNo());
        std::cout << "Error : " << message << " at LINE:" << buf << std::endl;
}
