#include "minipascal_nint.h"

#include <stdio.h>

minipascal::NInt::NInt(int value)
{
        setValue(value);
}

minipascal::NInt::~NInt()
{

}

std::string minipascal::NInt::getOutput()
{
        char* intstring = new char[16];
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
