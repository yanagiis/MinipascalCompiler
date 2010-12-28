#include "minipascal_nstatementexpression.h"

minipascal::NStatementExpression::NStatementExpression(NExpression* exp)
{
        this->exp.reset(exp);
}

minipascal::NStatementExpression::~NStatementExpression()
{
        
}

minipascal::ShareNExpression minipascal::NStatementExpression::getExps()
{
        return exp;
}

void minipascal::NStatementExpression::setExps(minipascal::NExpression* exp)
{
        this->exp.reset(exp);
}

std::string minipascal::NStatementExpression::getOutput()
{
        return exp->getOutput();
}
