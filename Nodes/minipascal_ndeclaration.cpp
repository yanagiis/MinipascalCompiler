#include "minipascal_ndeclaration.h"

#include "minipascal_visitor.h"

minipascal::NDeclaration::NDeclaration()
{
        setFail(false);
}

minipascal::NDeclaration::NDeclaration(const std::string* name, minipascal::NType* type)
{
        setName(name);
        setType(type);
        setFail(false);
}

minipascal::NDeclaration::~NDeclaration()
{

}

std::string minipascal::NDeclaration::getName()
{
        return name;
}

minipascal::NType* minipascal::NDeclaration::getType()
{
        return type;
}

void minipascal::NDeclaration::setName(const char* name)
{
        if(name != NULL)
                this->name = std::string(name);
}

void minipascal::NDeclaration::setName(const std::string* name)
{
        if(name != NULL)
                this->name = std::string(*name);
}

void minipascal::NDeclaration::setType(minipascal::NType* type)
{
        if(type != NULL)
                this->type = type;
}
