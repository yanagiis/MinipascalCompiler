#include "minipascal_nexpression.h"

minipascal::NExpression::NExpression()
{
        opposite = true;
        setFail(false);
}

minipascal::NExpression::~NExpression()
{

}

minipascal::NType* minipascal::NExpression::getType()
{
        return type;
}

void minipascal::NExpression::setType(NType* type)
{
        this->type = type;
}

void minipascal::NExpression::setOpposite()
{
        opposite = !opposite;
}