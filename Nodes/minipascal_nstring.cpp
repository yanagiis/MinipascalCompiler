#include "minipascal_nstring.h"

#include "minipascal_visitor.h"

minipascal::NString::NString(std::string* value)
{
        setValue(value);
        setType(new StringType());
        setFail(false);
}

minipascal::NString::~NString()
{

}

void minipascal::NString::accept(minipascal::Visitor* visitor)
{
        return visitor->visit(this);
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
