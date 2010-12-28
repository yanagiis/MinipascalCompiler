#include "minipascal_nexpression.h"

minipascal::NExpression::NExpression()
{
        opposite = true;
}

minipascal::NExpression::~NExpression()
{

}

const minipascal::Type minipascal::NExpression::getType()
{
        return type;
}

void minipascal::NExpression::setType(const Type* type)
{
        this->type = type;
}

void minipascal::NExpression::setOpposite()
{
        opposite = !opposite;
}