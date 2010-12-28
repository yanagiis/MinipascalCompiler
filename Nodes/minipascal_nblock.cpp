#include "minipascal_nblock.h"
#include <../MiniPascal_Compiler/minipascal_node.h>

minipascal::NBlock::NBlock(Stmt_list* stmts)
{
        setStmts(stmts);
}

minipascal::NBlock::~NBlock()
{
        for(Stmt_list::iterator it = stmts->begin(); it != stmts->end(); ++it)
                delete *it;
        stmts->clear();
}

void minipascal::NBlock::setStmts(Stmt_list* stmts)
{
        this->stmts = stmts;
}

std::string minipascal::NBlock::getOutput()
{
        return std::string("{ ... }");
}

const Stmt_list* minipascal::NBlock::getStmts()
{
        return stmts;
}
