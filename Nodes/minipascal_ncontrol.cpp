#include "minipascal_ncontrol.h"

#include "minipascal_visitor.h"

minipascal::NControl::NControl(NExpression* cond, NStatement* iftrue, NStatement* iffalse)
{
        setCond(cond);
        setTrue(iftrue);
        setFalse(iffalse);
        setFail(false);
}

minipascal::NControl::~NControl()
{
        
}

void minipascal::NControl::accept(minipascal::Visitor* visitor)
{
        return visitor->visit(this);
}

const minipascal::ShareNExpression minipascal::NControl::getCond()
{
        return cond;
}

const minipascal::ShareNStatement minipascal::NControl::getFalse()
{
        return iffalse;
}

const minipascal::ShareNStatement minipascal::NControl::getTrue()
{
        return iftrue;
}

void minipascal::NControl::setCond(minipascal::NExpression* cond)
{
        this->cond.reset(cond);
}

void minipascal::NControl::setFalse(minipascal::NStatement* iffalse)
{
        this->iffalse.reset(iffalse);
}

void minipascal::NControl::setTrue(minipascal::NStatement* iftrue)
{
        this->iftrue.reset(iftrue);
}

std::string minipascal::NControl::getOutput()
{
        std::string output = "if { ... } else { ... }";
        return output;
}