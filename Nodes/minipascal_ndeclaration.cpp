#include "minipascal_ndeclaration.h"

minipascal::NDeclaration::NDeclaration()
{

}

minipascal::NDeclaration::NDeclaration(const std::string* name, const minipascal::Type* type)
{
        setName(name);
        setType(type);
}

minipascal::NDeclaration::~NDeclaration()
{

}

std::string minipascal::NDeclaration::getName() const
{
        return name;
}

const minipascal::Type* minipascal::NDeclaration::getType() const
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

void minipascal::NDeclaration::setType(const minipascal::Type* type)
{
        if(type != NULL)
                this->type = type;
}
