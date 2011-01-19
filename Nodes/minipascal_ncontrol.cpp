#include "minipascal_ncontrol.h"

#include <stdio.h>
#include <llvm/LLVMContext.h>
#include <llvm/BasicBlock.h>
#include <llvm/Support/IRBuilder.h>

#include <iostream>

#include "minipascal_visitor.h"
#include "../Checkers/codegencontext.h"

int minipascal::NControl::index = 0;
minipascal::NControl::NControl(NExpression* cond, NStatement* iftrue, NStatement* iffalse)
{
        setCond(cond);
        setTrue(iftrue);
        setFalse(iffalse);
        setFail(false);
}

minipascal::NControl::~NControl()
{
        
}

void minipascal::NControl::accept(minipascal::Visitor* visitor)
{
        return visitor->visit(this);
}

const minipascal::ShareNExpression minipascal::NControl::getCond()
{
        return cond;
}

const minipascal::ShareNStatement minipascal::NControl::getFalse()
{
        return iffalse;
}

const minipascal::ShareNStatement minipascal::NControl::getTrue()
{
        return iftrue;
}

void minipascal::NControl::setCond(minipascal::NExpression* cond)
{
        this->cond.reset(cond);
}

void minipascal::NControl::setFalse(minipascal::NStatement* iffalse)
{
        this->iffalse.reset(iffalse);
}

void minipascal::NControl::setTrue(minipascal::NStatement* iftrue)
{
        this->iftrue.reset(iftrue);
}

std::string minipascal::NControl::getOutput()
{
        std::string output = "if { ... } else { ... }";
        return output;
}

llvm::Value* minipascal::NControl::codeGen(CodeGenContext* context)
{
        std::cout << "Generating code for if else statement" << std::endl;
        llvm::Value* condvalue = getCond()->codeGen(context);
        
        // condition type check
        BooleanType temp;
        if(!(getCond()->getType()->compare(&temp)))
        {
                showError("Condition are not boolean type");
                setFail(true);
                context->fail = true;
                return NULL;
        }
        
        char buf[32];
        int count;
        count = sprintf(buf, "THEN_%d", index);
        llvm::BasicBlock* then_bb = llvm::BasicBlock::Create(llvm::getGlobalContext(), buf, context->getCurBlock()->getBlock()->getParent(), 0);
        count = sprintf(buf, "ELSE_%d", index);
        llvm::BasicBlock* else_bb = llvm::BasicBlock::Create(llvm::getGlobalContext(), buf, context->getCurBlock()->getBlock()->getParent(), 0);
        count = sprintf(buf, "IFCONT_%d", index);
        llvm::BasicBlock* ifcont_bb = llvm::BasicBlock::Create(llvm::getGlobalContext(), buf, context->getCurBlock()->getBlock()->getParent(), 0);
        
        context->builder->CreateCondBr(condvalue, then_bb, else_bb);
        
        context->builder->SetInsertPoint(then_bb);
        llvm::Value* thenvalue = getTrue()->codeGen(context);
        context->builder->CreateBr(ifcont_bb);
        then_bb = context->builder->GetInsertBlock();
        
        context->builder->SetInsertPoint(else_bb);
        llvm::Value* elsevalue = getFalse()->codeGen(context);
        context->builder->CreateBr(ifcont_bb);
        
        if(condvalue == NULL || thenvalue == NULL || elsevalue == NULL) return NULL;
        
        context->builder->SetInsertPoint(ifcont_bb);
        
//         count = sprintf(buf, "IFTMP_%d", index);
//         llvm::PHINode* phi = context->builder->CreatePHI(llvm::Type::getDoubleTy(llvm::getGlobalContext()), buf);
//         phi->addIncoming(thenvalue, then_bb);
//         phi->addIncoming(elsevalue, else_bb);
        
        ++index;
        return ifcont_bb;
}
