#include "minipascal_nassignment.h"

minipascal::NAssignment::NAssignment(minipascal::NVariable* var, minipascal::NExpression* exp)
{
        setVar(var);
        setExp(exp);
}

minipascal::NAssignment::~NAssignment()
{
        
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
        this->exp.reset(var);
}

std::string minipascal::NAssignment::getOutput()
{
        std::string output = var->getOutput() + " = " + exp->getOutput();
        return output;
}
