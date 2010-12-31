#include "minipascal_ndouble.h"

#include <stdio.h>

minipascal::NDouble::NDouble(double value)
{

}

minipascal::NDouble::~NDouble()
{

}

std::string minipascal::NDouble::getOutput()
{
        char* intstring = new char[16];
        int count = sprintf(intstring, "%f", getValue());
        std::string output(intstring, count);
        return output;
}

double minipascal::NDouble::getValue()
{
        return value;
}

void minipascal::NDouble::setValue(double value)
{
        this->value = value;
}
