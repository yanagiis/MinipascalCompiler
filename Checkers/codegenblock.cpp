#include "codegenblock.h"

#include <llvm/Value.h>
#include <llvm/BasicBlock.h>

CodeGenBlock::CodeGenBlock()
{
        block = NULL;
        locals = new minipascal::SymbolTable();
        name = "";
}

CodeGenBlock::~CodeGenBlock()
{
        delete locals;
}

llvm::BasicBlock* CodeGenBlock::getBlock()
{
        return block;
}

minipascal::SymbolTable* CodeGenBlock::getLocals()
{
        return locals;
}

std::string CodeGenBlock::getName()
{
        return name;
}

ShareCodeGenBlock CodeGenBlock::getParent()
{
        return parent;
}

void CodeGenBlock::setBlock(llvm::BasicBlock* block)
{
        this->block = block;
}

void CodeGenBlock::setName(std::string name)
{
        this->name = name;
}

void CodeGenBlock::setParent(ShareCodeGenBlock parent)
{
        this->parent = parent;
}
