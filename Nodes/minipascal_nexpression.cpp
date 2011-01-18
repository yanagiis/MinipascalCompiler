#include <stdio.h>
#include "minipascal_nexpression.h"

int minipascal::NExpression::index = 0;

minipascal::NExpression::NExpression()
{
        opposite = true;
        setFail(false);
        hs = RHS;
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

std::string minipascal::NExpression::getStoreReg()
{
        char buf[32];
        int count = sprintf(buf, "exp_%d", index);
        ++index;
        return std::string(buf, count);
}
