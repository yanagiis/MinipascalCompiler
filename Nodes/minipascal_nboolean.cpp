#include "minipascal_nboolean.h"

#include <iostream>
#include <llvm/Type.h>
#include <llvm/LLVMContext.h>
#include <llvm/Constants.h>
#include "minipascal_visitor.h"

minipascal::NBoolean::NBoolean(bool value)
{
        setValue(value);
        setType(new BooleanType());
        setFail(false);
}

minipascal::NBoolean::~NBoolean()
{
        
}

void minipascal::NBoolean::accept(minipascal::Visitor* visitor)
{
        return visitor->visit(this);
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

llvm::Value* minipascal::NBoolean::codeGen(CodeGenContext* context)
{
        std::cout << "Generating boolean ... " << std::endl;
        if(value)
                return llvm::ConstantInt::get(llvm::Type::getInt1Ty(llvm::getGlobalContext()), 1, true);
        else
                return llvm::ConstantInt::get(llvm::Type::getInt1Ty(llvm::getGlobalContext()), 0, true);
}
