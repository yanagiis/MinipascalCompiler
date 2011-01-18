#include "minipascal_nbinaryoperator.h"

#include <stdio.h>
#include <iostream>
#include "minipascal_visitor.h"
#include "../Checkers/codegencontext.h"

minipascal::NBinaryOperator::NBinaryOperator(minipascal::NExpression* left, minipascal::NExpression* right)
{
        setLeft(left);
        setRight(right);
        setFail(false);
}

minipascal::NBinaryOperator::NBinaryOperator(minipascal::NBinaryOperator::BOP op, minipascal::NExpression* left, minipascal::NExpression* right)
{
        setOP(op);
        setLeft(left);
        setRight(right);
}

minipascal::NBinaryOperator::~NBinaryOperator()
{
}

void minipascal::NBinaryOperator::accept(minipascal::Visitor* visitor)
{
        return visitor->visit(this);
}

minipascal::ShareNExpression minipascal::NBinaryOperator::getLeft()
{
        return left;
}

minipascal::NBinaryOperator::BOP minipascal::NBinaryOperator::getOP()
{
        return op;
}

minipascal::ShareNExpression minipascal::NBinaryOperator::getRight()
{
        return right;
}

void minipascal::NBinaryOperator::setLeft(minipascal::NExpression* left)
{
        this->left.reset(left);
}

void minipascal::NBinaryOperator::setOP(minipascal::NBinaryOperator::BOP op)
{
        this->op = op;
}

void minipascal::NBinaryOperator::setRight(minipascal::NExpression* right)
{
        this->right.reset(right);
}
 
std::string minipascal::NBinaryOperator::getOutput()
{
        std::string stringOP;
        switch(op){
                case ADD:
                        stringOP = "+";
                        break;
                case SUB:
                        stringOP = "-";
                        break;
                case MUL:
                        stringOP = "*";
                        break;
                case DIV:
                        stringOP = "/";
                        break;
                case GE:
                        stringOP = ">=";
                        break;
                case GT:
                        stringOP = ">";
                        break;
                case LE:
                        stringOP = "<=";
                        break;
                case LT:
                        stringOP = "<";
                        break;
                case EQ:
                        stringOP = "==";
                        break;
                case NE:
                        stringOP = "!=";
                        break;
        }
        std::string output = left->getOutput() + stringOP + right->getOutput();
        return output;
}

llvm::Value* minipascal::NBinaryOperator::codeGen(CodeGenContext* context)
{
        std::cout << "Generating code for " << getOutput() << std::endl;
        llvm::Value* L = getLeft()->codeGen(context);
        llvm::Value* R = getRight()->codeGen(context);
        
        if(L == NULL || R == NULL) return NULL;
        
        switch(getOP()) {
                case minipascal::NBinaryOperator::ADD:
                case minipascal::NBinaryOperator::SUB:
                case minipascal::NBinaryOperator::MUL:
                case minipascal::NBinaryOperator::DIV:
                        setType(getLeft()->getType());
                        break;
                case minipascal::NBinaryOperator::GT:
                case minipascal::NBinaryOperator::GE:
                case minipascal::NBinaryOperator::LT:
                case minipascal::NBinaryOperator::LE:
                case minipascal::NBinaryOperator::EQ:
                case minipascal::NBinaryOperator::NE:
                        setType(new minipascal::BooleanType());
                        break;
        }
        
        // type check
        if(!(getLeft()->getFail()))
        {
                if(!(getLeft()->getType()->compare(getRight()->getType())))
                {
                        showError("Cannot do binary operation");
                        setFail(true);
                        context->fail = true;
                        return NULL;
                }
        }
        
        std::string name = getStoreReg();
        minipascal::IntType temp;
        // for integer binary operation
        if(getLeft()->getType()->compare(&temp))
        {
                switch(getOP()){
                case minipascal::NBinaryOperator::ADD:
                        return context->builder->CreateAdd(L, R, name.c_str());
                case minipascal::NBinaryOperator::SUB:
                        return context->builder->CreateSub(L, R, name.c_str());
                case minipascal::NBinaryOperator::MUL:
                        return context->builder->CreateMul(L, R, name.c_str());
                case minipascal::NBinaryOperator::DIV:
                        return context->builder->CreateSDiv(L, R, name.c_str());
                case minipascal::NBinaryOperator::LE:
                        return context->builder->CreateICmpSLE(L, R, name.c_str());
                case minipascal::NBinaryOperator::LT:
                        return context->builder->CreateICmpSLT(L, R, name.c_str());
                case minipascal::NBinaryOperator::EQ:
                        return context->builder->CreateICmpEQ(L, R, name.c_str());
                case minipascal::NBinaryOperator::NE:
                        return context->builder->CreateICmpNE(L, R, name.c_str());
                case minipascal::NBinaryOperator::GE:
                        return context->builder->CreateICmpSGE(L, R, name.c_str());
                case minipascal::NBinaryOperator::GT:
                        return context->builder->CreateICmpSGT(L, R, name.c_str());
                }
        }
        else // for real binary operation
        {
                switch(getOP()){
                case minipascal::NBinaryOperator::ADD:
                        return context->builder->CreateFAdd(L, R, name.c_str());
                case minipascal::NBinaryOperator::SUB:
                        return context->builder->CreateFSub(L, R, name.c_str());
                case minipascal::NBinaryOperator::MUL:
                        return context->builder->CreateFMul(L, R, name.c_str());
                case minipascal::NBinaryOperator::DIV:
                        return context->builder->CreateFDiv(L, R, name.c_str());
                case minipascal::NBinaryOperator::LE:
                        return context->builder->CreateFCmpOLE(L, R, name.c_str());
                case minipascal::NBinaryOperator::LT:
                        return context->builder->CreateFCmpOLT(L, R, name.c_str());
                case minipascal::NBinaryOperator::EQ:
                        return context->builder->CreateFCmpOEQ(L, R, name.c_str());
                case minipascal::NBinaryOperator::NE:
                        return context->builder->CreateFCmpONE(L, R, name.c_str());
                case minipascal::NBinaryOperator::GE:
                        return context->builder->CreateFCmpOGE(L, R, name.c_str());
                case minipascal::NBinaryOperator::GT:
                        return context->builder->CreateFCmpOGT(L, R, name.c_str());
                }
        }
}
