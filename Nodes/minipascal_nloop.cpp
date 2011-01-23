#include "minipascal_nloop.h"

#include <stdio.h>
#include <llvm/BasicBlock.h>
#include <llvm/LLVMContext.h>

#include "minipascal_visitor.h"
#include "../Checkers/codegencontext.h"

int minipascal::NLoop::index = 0;

minipascal::NLoop::NLoop(minipascal::NExpression* cond, minipascal::NStatement* stmt)
{ 
        setCond(cond);
        setStmt(stmt);
        setFail(false);
}

minipascal::NLoop::~NLoop()
{

}

void minipascal::NLoop::accept(minipascal::Visitor* visitor)
{
        return visitor->visit(this);
}

const minipascal::ShareNExpression minipascal::NLoop::getCond()
{
        return cond;
}

const minipascal::ShareNStatement minipascal::NLoop::getStmt()
{
        return stmt;
}

void minipascal::NLoop::setCond(minipascal::NExpression* cond)
{
        this->cond.reset(cond);
}

void minipascal::NLoop::setStmt(minipascal::NStatement* stmt)
{
        this->stmt.reset(stmt);
}

std::string minipascal::NLoop::getOutput()
{
        std::string output = "loop ( ... ) { ... }";
        return output;
}

llvm::Value* minipascal::NLoop::codeGen(CodeGenContext* context)
{
        char buf[32];
        int count = sprintf(buf, "LOOP_CHECK_%d", index);
        llvm::BasicBlock* check_bb = llvm::BasicBlock::Create(llvm::getGlobalContext(), buf, context->getCurBlock()->getBlock()->getParent(), 0);
        count = sprintf(buf, "LOOP_%d", index);
        llvm::BasicBlock* body_bb = llvm::BasicBlock::Create(llvm::getGlobalContext(), buf, context->getCurBlock()->getBlock()->getParent(), 0);
        count = sprintf(buf, "LOOP_CONT_%d", index);
        llvm::BasicBlock* loop_cont = llvm::BasicBlock::Create(llvm::getGlobalContext(), buf, context->getCurBlock()->getBlock()->getParent(), 0);
        
        // create jump instruction which is used to jump to loop check
        context->builder->CreateBr(check_bb);
        context->builder->SetInsertPoint(check_bb);
        
        llvm::Value* condvalue = getCond()->codeGen(context);
        if(condvalue == NULL) return NULL;
        
        // condition type check
        BooleanType temp;
        if(!(getCond()->getType()->compare(&temp)))
        {
                IntType inttest;
                if(!(getCond()->getType()->compare(&inttest)))
                {
                        showError("Condition are not boolean or integer type");
                        setFail(true);
                        context->fail = true;
                        return NULL;
                }
                condvalue = context->builder->CreateICmpNE(condvalue, llvm::ConstantInt::get(inttest.getLLVMType(), 0, true), "");
        }
        
        context->builder->CreateCondBr(condvalue, body_bb, loop_cont);
        
        context->builder->SetInsertPoint(body_bb);
        llvm::Value* bodyvalue = getStmt()->codeGen(context);
        context->builder->CreateBr(check_bb);
        
        context->builder->SetInsertPoint(loop_cont);
        
        ++index;
        return condvalue;
}
