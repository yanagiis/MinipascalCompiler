#include "minipascal_nvariabledeclaration.h"

#include "minipascal_visitor.h"

minipascal::NVariableDeclaration::NVariableDeclaration(const std::string* name, minipascal::NType* type): NDeclaration(name, type)
{
        setFail(false);
}

minipascal::NVariableDeclaration::~NVariableDeclaration()
{
        
}

void minipascal::NVariableDeclaration::accept(minipascal::Visitor* visitor)
{
        return visitor->visit(this);
}

std::string minipascal::NVariableDeclaration::getOutput()
{
        std::string output = "new variable : '" + getName() + "' ,type : " + getType()->getName();
        return output;
}