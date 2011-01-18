#include "minipascal_nblock.h"

#include <iostream>
#include "minipascal_visitor.h"
#include "../Checkers/codegencontext.h"

minipascal::NBlock::NBlock(minipascal::Stmt_list* stmts)
{
        setStmts(stmts);
        setFail(false);
}

minipascal::NBlock::~NBlock()
{
        stmts->clear();
}

void minipascal::NBlock::accept(minipascal::Visitor* visitor)
{
        return visitor->visit(this);
}

void minipascal::NBlock::setStmts(minipascal::Stmt_list* stmts)
{
        this->stmts = stmts;
}

std::string minipascal::NBlock::getOutput()
{
        return std::string("{ ... }");
}

minipascal::Stmt_list* minipascal::NBlock::getStmts()
{
        return stmts;
}

llvm::Value* minipascal::NBlock::codeGen(CodeGenContext* context)
{
        std::cout << "Generating Block ... " << std::endl;
        llvm::Value* last = NULL;
        for(Stmt_list::iterator it = stmts->begin(); it != stmts->end(); ++it)
        {
                last = (*it)->codeGen(context);
        }
        return last;
}
