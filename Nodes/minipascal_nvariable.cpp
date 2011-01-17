#include "minipascal_nvariable.h"

#include "minipascal_visitor.h"

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