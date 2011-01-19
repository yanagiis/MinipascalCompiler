#include "minipascal_nstring.h"

#include <iostream>
#include <llvm/Constants.h>
#include <llvm/LLVMContext.h>
#include <llvm/GlobalVariable.h>
#include "minipascal_visitor.h"
#include "../Checkers/codegencontext.h"

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
        this->value.erase(0, 1);
        this->value.erase(this->value.size()-1, this->value.size());
}

llvm::Value* minipascal::NString::codeGen(CodeGenContext* context)
{
        std::cout << "Generating code for " << getOutput() << std::endl;
        llvm::Value* gvar_array_str = context->builder->CreateGlobalStringPtr(getValue().c_str());
        return gvar_array_str;
}
