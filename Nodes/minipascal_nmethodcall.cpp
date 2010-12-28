#include "minipascal_nmethodcall.h"

minipascal::NMethodCall::NMethodCall(std::string* name, minipascal::Exps_list* exps)
{
        setName(name);
        setExps(exps);
}

minipascal::NMethodCall::~NMethodCall()
{
        
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
        std::string output = name + "( ... )";
        return output;
}
