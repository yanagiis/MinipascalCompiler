#include "minipascal_nprogram.h"

#include <llvm/LLVMContext.h>
#include <llvm/Function.h>
#include <llvm/GlobalValue.h>

#include "minipascal_visitor.h"
#include "../Checkers/codegencontext.h"

minipascal::NProgram::NProgram()
{
        setFail(false);
}

minipascal::NProgram::~NProgram()
{
        decl_list->clear();
        ids->clear();
        mhd_list->clear();
        delete decl_list;
        delete ids;
        delete mhd_list;
}

void minipascal::NProgram::accept(minipascal::Visitor* visitor)
{
        return visitor->visit(this);
}

minipascal::ShareNBlock minipascal::NProgram::getBlock()
{
        return block;
}

minipascal::Decls_list* minipascal::NProgram::getDecls()
{
        return decl_list;
}

minipascal::Id_list* minipascal::NProgram::getIds()
{
        return ids;
}

minipascal::Mhd_list* minipascal::NProgram::getMhds()
{
        return mhd_list;
}

void minipascal::NProgram::setBlock(minipascal::NBlock* block)
{
        this->block.reset(block);
}

void minipascal::NProgram::setDecls(Decls_list* decl_list)
{
        this->decl_list = decl_list;
}

void minipascal::NProgram::setIds(Id_list* ids)
{
        this->ids = ids;
}

void minipascal::NProgram::setMhds(Mhd_list* mhd_list)
{
        this->mhd_list = mhd_list;
}

std::string minipascal::NProgram::getOutput()
{
        std::string output = "new program " + getName();
        return output;
}

llvm::Value* minipascal::NProgram::codeGen(CodeGenContext* context)
{
        llvm::FunctionType* ftype = llvm::FunctionType::get(llvm::Type::getVoidTy(llvm::getGlobalContext()), std::vector<const llvm::Type*>(), false);
        llvm::Function* mainFunction = llvm::Function::Create(ftype, llvm::GlobalValue::InternalLinkage, "main", context->getModule());
        llvm::BasicBlock* bblock = llvm::BasicBlock::Create(llvm::getGlobalContext(), "entry", mainFunction, 0);
        
        context->pushBlock();
        context->getCurBlock()->setBlock(bblock);
        context->builder->SetInsertPoint(bblock);
        
        for(minipascal::Decls_list::iterator it = decl_list->begin(); it != decl_list->end(); ++it)
        {
                NVariableDeclaration* decl = (NVariableDeclaration*)it->get();
                decl->global = true;
                decl->codeGen(context);
        }
        for(minipascal::Mhd_list::iterator it = mhd_list->begin(); it != mhd_list->end(); ++it)
        {
                (*it)->codeGen(context);
        }
        getBlock()->codeGen(context);
        context->builder->CreateRetVoid();
        context->popBlock();
}
