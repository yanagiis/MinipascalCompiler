#include "minipascal_nassignment.h"

#include "minipascal_visitor.h"

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
