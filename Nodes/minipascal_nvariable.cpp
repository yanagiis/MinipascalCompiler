#include "minipascal_nvariable.h"

#include <stdio.h>
#include <boost/cast.hpp>
#include <llvm/LLVMContext.h>
#include "minipascal_visitor.h"
#include "../Checkers/codegencontext.h"

minipascal::NVariable::NVariable(std::string name)
{
        setName(&name);
        setFail(false);
}

minipascal::NVariable::~NVariable()
{
        
}

void minipascal::NVariable::accept(minipascal::Visitor* visitor)
{
        return visitor->visit(this);
}

minipascal::Exps_list* minipascal::NVariable::getExps()
{
        return exps_list;
}

void minipascal::NVariable::setExps(minipascal::Exps_list* exps_list)
{
        this->exps_list = exps_list;
}

std::string minipascal::NVariable::getName()
{
        return name;
}

void minipascal::NVariable::setName(std::string* name)
{
        this->name = *name;
}

std::string minipascal::NVariable::getOutput()
{
        std::string output = getName();
        if(exps_list->size() > 0)
        {
                for(Exps_list::iterator it = exps_list->begin(); it != exps_list->end(); ++it)
                {
                        output += ("[" + (*it)->getOutput() + "]");
                }
        }
        return output;
                
}

llvm::Value* minipascal::NVariable::codeGen(CodeGenContext* context)
{
        CodeGenContext::BlockStack* stack = &(context->blockstack);
        CodeGenContext::BlockStack::reverse_iterator rit;
        SymbolTable::iterator sit;
        for(rit = stack->rbegin(); rit != stack->rend(); ++rit)
        {
                if((sit = (*rit)->getLocals()->find(getName())) != (*rit)->getLocals()->end())
                {
                        std::vector<llvm::Value*> indics;
                        Exps_list* exps = getExps();
                        for(Exps_list::iterator it = exps->begin(); it != exps->end(); ++it)
                        {
                                llvm::Value* index = (*it)->codeGen(context);
                                if(index == NULL) return NULL;
                                indics.push_back(index);
                        }
                        
                        // set type
                        NType* type = (*sit).second->declaration->getType();
                        for(int i = 0; i < exps->size(); ++i)
                        {
                                try{
                                        ArrayType* temp = boost::polymorphic_cast<ArrayType*>(type);
                                        type = temp->getType();
                                } catch(std::bad_cast& e){
                                        showError("Variable " + getName() + " wrong dimention");
                                        context->fail = true;
                                        setFail(true);
                                        return NULL;
                                }
                        }
                        setType(type);
                        
                        {
                                int i = 0;
                                NType* temptype = sit->second->declaration->getType();
                                for(Exps_list::iterator it = exps->begin(); it != exps->end(); ++i, ++it)
                                {
                                        // if index is a constant
                                        try{
                                                ArrayType* arraytype = boost::polymorphic_cast<ArrayType*>(temptype);
                                                ArrayType::Range range = arraytype->getRange();
                                                // Is index out of range?
                                                NInt* constant = boost::polymorphic_cast<NInt*>(it->get());
                                                int index = constant->getValue();
                                                if(index < range.first || index > range.second)
                                                {
                                                        char num[3];
                                                        int count = sprintf(num, "%d", i);
                                                        std::string numstr = std::string(num, count);
                                                        showError("Variable " + getName() + "'s index["+ numstr +"] out of range");
                                                        context->fail = true;
                                                        setFail(true);
                                                        return NULL;
                                                }
                                                temptype = arraytype->getType();
                                        }catch(std::bad_cast& e){
                                                // do nothing 
                                        }
                                }
                        }
                        
                        // index type check
                        for(Exps_list::iterator it = exps->begin(); it != exps->end(); ++it)
                        {
                                IntType temp;
                                if(!((*it)->getType()->compare(&temp)))
                                {
                                        showError("Array index not int type");
                                        context->fail = true;
                                        setFail(true);
                                        return NULL;
                                }
                        }
                        
                        if(hs == NExpression::RHS)
                        {
                                // code generation
                                if(indics.size() > 0) // array
                                {
                                        try{
                                                ArrayType* temptype = boost::polymorphic_cast<ArrayType*>(sit->second->declaration->getType());
                                                llvm::Value* value = sit->second->value;
                                                for(std::vector<llvm::Value*>::iterator vit = indics.begin(); vit != indics.end(); ++vit)
                                                {
                                                        int lower = temptype->getRange().first;
                                                        llvm::Value* lowerbound = llvm::ConstantInt::get(llvm::Type::getInt64Ty(llvm::getGlobalContext()), lower, true);
                                                        std::vector<llvm::Value*> ptr_indices;
                                                        ptr_indices.push_back(lowerbound);
                                                        ptr_indices.push_back(*vit);
                                                        value = context->builder->CreateGEP(value, ptr_indices.begin(), ptr_indices.end(), "");
                                                }
                                                return context->builder->CreateLoad(value, getStoreReg().c_str());
                                        }catch(std::bad_cast& e) {
                                                return NULL;
                                        }
                                }
                                else // variable
                                {
                                        return context->builder->CreateLoad(sit->second->value, getStoreReg().c_str());
                                }
                        }
                        else // LHS
                        {
                                // code generation
                                if(indics.size() > 0) // array
                                {
                                        try{
                                                ArrayType* temptype = boost::polymorphic_cast<ArrayType*>(sit->second->declaration->getType());
                                                llvm::Value* value = sit->second->value;
                                                for(std::vector<llvm::Value*>::iterator vit = indics.begin(); vit != indics.end(); ++vit)
                                                {
                                                        int lower = temptype->getRange().first;
                                                        llvm::Value* lowerbound = llvm::ConstantInt::get(llvm::Type::getInt64Ty(llvm::getGlobalContext()), lower, true);
                                                        std::vector<llvm::Value*> ptr_indices;
                                                        ptr_indices.push_back(lowerbound);
                                                        ptr_indices.push_back(*vit);
                                                        value = context->builder->CreateGEP(value, ptr_indices.begin(), ptr_indices.end(), "");
                                                }
                                                return value;
                                        }catch(std::bad_cast& e) {
                                                return NULL;
                                        }
                                }
                                else // variable
                                {
                                        return sit->second->value;
                                }
                        }
                }
        }
        if(rit == stack->rend())
        {
                showError("Undeclared variable : " + getName());
                setFail(true);
                context->fail = true;
                return NULL;
        }
}
