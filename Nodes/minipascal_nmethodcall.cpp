#include "minipascal_nmethodcall.h"

#include "minipascal_visitor.h"

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

const minipascal::Exps_list* minipascal::NMethodCall::getExps()
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
