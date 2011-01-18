#include "minipascal_nvariabledeclaration.h"

#include <iostream>
#include <llvm/GlobalVariable.h>

#include "minipascal_visitor.h"
#include "../Checkers/codegencontext.h"

minipascal::NVariableDeclaration::NVariableDeclaration(const std::string* name, minipascal::NType* type): NDeclaration(name, type)
{
        setFail(false);
        global = false;
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

llvm::Value* minipascal::NVariableDeclaration::codeGen(CodeGenContext* context)
{
        std::cout << "Generating code for " << getOutput() << std::endl;
        Symbol* symbol = new Symbol();
        std::pair<minipascal::SymbolTable::iterator,bool> result = context->getCurBlock()->getLocals()->insert(minipascal::SymbolTableItem(getName(), symbol));
        if(!result.second)
        {
                showError("Duplicate declaration " + getName());
                context->fail = true;
                setFail(true);
                return NULL;
        }
        llvm::Value* alloc;
        if(global)
        {
                alloc = new llvm::GlobalVariable(*(context->getModule()),
                        getType()->getLLVMType(),
                        false,
                        llvm::GlobalValue::CommonLinkage,
                        getType()->initializer(),
                        getName().c_str());
                
        }
        else
        {
                alloc = context->builder->CreateAlloca(getType()->getLLVMType(), 0, getName().c_str());
        }
        symbol->declaration = this;
        symbol->value = alloc;
        return alloc;
}
