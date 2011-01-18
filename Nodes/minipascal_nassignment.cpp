#include "minipascal_nassignment.h"

#include <iostream>
#include "minipascal_visitor.h"
#include "../Checkers/codegencontext.h"

minipascal::NAssignment::NAssignment(minipascal::NVariable* var, minipascal::NExpression* exp)
{
        setVar(var);
        setExp(exp);
        setFail(false);
}

minipascal::NAssignment::~NAssignment()
{
        
}

void minipascal::NAssignment::accept(minipascal::Visitor* visitor)
{
        return visitor->visit(this);
}

minipascal::ShareNExpression minipascal::NAssignment::getExp()
{
        return exp;
}

minipascal::ShareNVariable minipascal::NAssignment::getVar()
{
        return var;
}

void minipascal::NAssignment::setExp(minipascal::NExpression* exp)
{
        this->exp.reset(exp);
}

void minipascal::NAssignment::setVar(minipascal::NVariable* var)
{
        this->var.reset(var);
}

std::string minipascal::NAssignment::getOutput()
{
        std::string output = var->getOutput() + " = " + exp->getOutput();
        return output;
}

llvm::Value* minipascal::NAssignment::codeGen(CodeGenContext* context)
{
        std::cout << "Generating NAssignment node " << getOutput() << std::endl;
        
        getVar()->hs = NExpression::LHS;
        llvm::Value* lvalue = getVar()->codeGen(context);
        llvm::Value* rvalue = getExp()->codeGen(context);
        
        if(lvalue == NULL || rvalue == NULL) return NULL;
        
        // type check
        if(!(getVar()->getFail()))
        {
                if(!(getVar()->getType()->compare(getExp()->getType())))
                {
                        showError("Cannot assign type : " + getVar()->getType()->getName()  + " to type : " + getExp()->getType()->getName());
                        context->fail = true;
                        setFail(true);
                        return NULL;
                }
        }
        
        return context->builder->CreateStore(rvalue, lvalue);
}
