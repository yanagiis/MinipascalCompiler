#include "minipascal_ndouble.h"

#include <string.h>

minipacsal::NDouble::NDouble(double value)
{

}

minipacsal::NDouble::~NDouble()
{

}

std::string minipacsal::NDouble::getOutput()
{
        char* intstring = new char[16];
        int count = sprintf(intstring, "%f", getValue());
        std::string output(intstring, count);
        return output;
}

double minipacsal::NDouble::getValue()
{
        return value;
}

void minipacsal::NDouble::setValue(double value)
{
        this->value = value;
}
