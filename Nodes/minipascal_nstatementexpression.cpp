#include "minipascal_nstatementexpression.h"

#include "minipascal_visitor.h"

minipascal::NStatementExpression::NStatementExpression(NExpression* exp)
{
        this->exp.reset(exp);
        setFail(false);
}

minipascal::NStatementExpression::~NStatementExpression()
{
        
}

void minipascal::NStatementExpression::accept(minipascal::Visitor* visitor)
{
        return visitor->visit(this);
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
