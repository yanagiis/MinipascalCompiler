#include "minipascal_nstring.h"

minipascal::NString::NString(std::string* value)
{

}

minipascal::NString::~NString()
{

}

std::string minipascal::NString::getOutput()
{
        return getValue();
}

std::string minipascal::NString::getValue()
{
        return value;
}

void minipascal::NString::setValue(std::string* value)
{
        this->value = *value;
}
