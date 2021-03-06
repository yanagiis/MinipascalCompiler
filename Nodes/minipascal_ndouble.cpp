#include "minipascal_ndouble.h"

#include <stdio.h>
#include <llvm/Constants.h>
#include <llvm/LLVMContext.h>

#include <iostream>

#include "minipascal_visitor.h"
#include "../Checkers/codegencontext.h"

minipascal::NDouble::NDouble(double value)
{
        setValue(value);
        setType(new RealType());
        setFail(false);
}

minipascal::NDouble::~NDouble()
{

}

void minipascal::NDouble::accept(minipascal::Visitor* visitor)
{
        return visitor->visit(this);
}

std::string minipascal::NDouble::getOutput()
{
        char intstring[16];
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

llvm::Value* minipascal::NDouble::codeGen(CodeGenContext* context)
{
        std::cout << "Generating code for double " << getValue() << std::endl;
        return llvm::ConstantFP::get(llvm::Type::getDoubleTy(llvm::getGlobalContext()), value);
}
