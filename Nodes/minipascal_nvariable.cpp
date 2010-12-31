#include "minipascal_nvariable.h"

minipascal::NVariable::NVariable(std::string name)
{
        setName(&name);
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
        return name;
}