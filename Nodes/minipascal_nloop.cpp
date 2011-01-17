#include "minipascal_nloop.h"

#include "minipascal_visitor.h"

minipascal::NLoop::NLoop(minipascal::NExpression* cond, minipascal::NStatement* stmt)
{ 
        setCond(cond);
        setStmt(stmt);
        setFail(false);
}

minipascal::NLoop::~NLoop()
{

}

void minipascal::NLoop::accept(minipascal::Visitor* visitor)
{
        return visitor->visit(this);
}

const minipascal::ShareNExpression minipascal::NLoop::getCond()
{
        return cond;
}

const minipascal::ShareNStatement minipascal::NLoop::getStmt()
{
        return stmt;
}

void minipascal::NLoop::setCond(minipascal::NExpression* cond)
{
        this->cond.reset(cond);
}

void minipascal::NLoop::setStmt(minipascal::NStatement* stmt)
{
        this->stmt.reset(stmt);
}

std::string minipascal::NLoop::getOutput()
{
        std::string output = "loop ( ... ) { ... }";
        return output;
}