#include "minipascal_nvariabledeclaration.h"

minipascal::NVariableDeclaration::NVariableDeclaration(const std::string* name, const minipascal::Type* type): NDeclaration(name, type)
{

}

minipascal::NVariableDeclaration::~NVariableDeclaration()
{
        
}

std::string minipascal::NVariableDeclaration::getOutput()
{
        std::string output = "new variable : " + getName();
}