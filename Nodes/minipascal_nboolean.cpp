#include "minipascal_nboolean.h"

minipascal::NBoolean::NBoolean(bool value)
{
        
}

minipascal::NBoolean::~NBoolean()
{
        
}

void minipascal::NBoolean::setOpposite()
{
        setValue(!getValue());
}

std::string minipascal::NBoolean::getOutput()
{
        std::string output;
        if(getValue())
                output = "True";
        else
                output = "False";
        return output;
}

bool minipascal::NBoolean::getValue()
{
        return value;
}

void minipascal::NBoolean::setValue(bool value)
{
        this->value = value;
}
