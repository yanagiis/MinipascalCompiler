#include "minipascal_nint.h"

#include <stdio.h>

#include "minipascal_visitor.h"

minipascal::NInt::NInt(int value)
{
        setValue(value);
        setType(new IntType());
        setFail(false);
}

minipascal::NInt::~NInt()
{

}

void minipascal::NInt::accept(minipascal::Visitor* visitor)
{
        return visitor->visit(this);
}

std::string minipascal::NInt::getOutput()
{
        char intstring[16];
        int count = sprintf(intstring, "%d", getValue());
        std::string output(intstring, count);
        return output;
}

int minipascal::NInt::getValue()
{
        return value;
}

void minipascal::NInt::setValue(int value)
{
        this->value = value;
}
