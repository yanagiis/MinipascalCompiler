#include "minipascal_nblock.h"

minipascal::NBlock::NBlock(minipascal::Stmt_list* stmts)
{
        setStmts(stmts);
}

minipascal::NBlock::~NBlock()
{
        stmts->clear();
}

void minipascal::NBlock::setStmts(minipascal::Stmt_list* stmts)
{
        this->stmts = stmts;
}

std::string minipascal::NBlock::getOutput()
{
        return std::string("{ ... }");
}

const minipascal::Stmt_list* minipascal::NBlock::getStmts()
{
        return stmts;
}
