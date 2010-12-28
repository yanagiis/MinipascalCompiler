#include "minipascal_nloop.h"

minipascal::NLoop::NLoop(const minipascal::NExpression* cond, const minipascal::NStatement* stmt)
{
        setCond(cond);
        setStmt(stmt);
}

minipascal::NLoop::~NLoop()
{

}

const minipascal::ShareNExpression minipascal::NLoop::getCond()
{
        return cond;
}

const minipascal::ShareNStatement minipascal::NLoop::getStmt()
{
        return stmt;
}

void minipascal::NLoop::setCond(const minipascal::NExpression* cond)
{
        this->cond.reset(cond);
}

void minipascal::NLoop::setStmt(const minipascal::NStatement* stmt)
{
        this->stmt.reset(stmt);
}

std::string minipascal::NLoop::getOutput()
{
        std::string output = "loop ( ... ) { ... }";
        return output;
}