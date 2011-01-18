#include "minipascal_nmethodcall.h"

#include <boost/cast.hpp>
#include <llvm/Function.h>
#include <llvm/LLVMContext.h>
#include <llvm/Module.h>

#include "minipascal_visitor.h"
#include "../Checkers/symbol.h"
#include "../Checkers/codegencontext.h"

minipascal::NMethodCall::NMethodCall(std::string* name, minipascal::Exps_list* exps)
{
        setName(name);
        setExps(exps);
        setFail(false);
}

minipascal::NMethodCall::~NMethodCall()
{
        
}

void minipascal::NMethodCall::accept(minipascal::Visitor* visitor)
{
        return visitor->visit(this);
}

minipascal::Exps_list* minipascal::NMethodCall::getExps()
{
        return exps;
}

std::string minipascal::NMethodCall::getName()
{
        return name;
}

void minipascal::NMethodCall::setExps(minipascal::Exps_list* exps)
{
        this->exps = exps;
}

void minipascal::NMethodCall::setName(std::string* name)
{
        this->name = *name;
}

std::string minipascal::NMethodCall::getOutput()
{
        std::string output = getName() + "( ... )";
        return output;
}

llvm::Value* minipascal::NMethodCall::codeGen(CodeGenContext* context)
{
        CodeGenContext::BlockStack* stack = &(context->blockstack);
        CodeGenContext::BlockStack::reverse_iterator rit;
        SymbolTable::iterator it;
        for(rit = stack->rbegin(); rit != stack->rend(); ++rit)
        {
                it = (*rit)->getLocals()->find(getName());
                if(it != context->getCurBlock()->getLocals()->end())
                {
                        setType(it->second->declaration->getType());
                        
                        llvm::Function* function = context->getModule()->getFunction(getName().c_str());
                        std::vector<llvm::Value*> args;
                        const minipascal::Exps_list* exps = getExps();
                        minipascal::Exps_list::const_iterator eit;
                        for(eit = exps->begin(); eit != exps->end(); ++eit)
                        {
                                llvm::Value* arg = (*eit)->codeGen(context);
                                if(arg == NULL) return NULL;
                                args.push_back(arg);
                        }
                        
                        // args check
                        try{
                                NMethodDeclaration* method = boost::polymorphic_cast<NMethodDeclaration*>(it->second->declaration);
                                Decls_list* decls = method->getArgs();
                                Decls_list::iterator dit;
                                for(dit = decls->begin(), eit = exps->begin(); dit != decls->end() && eit != exps->end(); ++eit, ++dit)
                                {
                                        if(!((*dit)->getType()->compare((*eit)->getType())))
                                        {
                                                showError("Function " + getName() + " args doesn't match");
                                                setFail(true);
                                                context->fail = true;
                                                return NULL;
                                        }
                                }
                        }catch(std::bad_cast& e){
                                showError("No such function : " + getName());
                                setFail(true);
                                context->fail = true;
                                return NULL;
                        }
                        
//                         return llvm::CallInst::Create(function, args.begin(), args.end(), "", context->getCurBlock()->getBlock());
                        return context->builder->CreateCall<>(function, args.begin(), args.end(), "");
                }
        }
        
        showError("No such function : " + getName());
        setFail(true);
        context->fail = true;
        return NULL;
}
