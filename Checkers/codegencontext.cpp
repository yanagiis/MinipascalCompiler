#include "codegencontext.h"

#include <llvm/Function.h>
#include <llvm/Module.h>
#include <llvm/LLVMContext.h>

#include "minipascal_nprogram.h"

CodeGenContext::CodeGenContext()
{
        blockmap = BlockMap();
        blockstack = BlockStack();
        module = new llvm::Module("main", llvm::getGlobalContext());
        setMainFunction(NULL);
        builder = new llvm::IRBuilder<>(llvm::getGlobalContext());
        fail = false;
}

CodeGenContext::~CodeGenContext()
{
        delete module;
}

ShareCodeGenBlock CodeGenContext::createCodeGenBlock()
{
        ShareCodeGenBlock shareblock;
        shareblock.reset(new CodeGenBlock());
        return shareblock;
}

void CodeGenContext::pushBlock()
{
        ShareCodeGenBlock shareblock = createCodeGenBlock();
        pushBlock(shareblock);
}

void CodeGenContext::pushBlock(ShareCodeGenBlock block)
{
        if(!blockstack.empty())
                block->setParent(blockstack.back());
        blockstack.push_back(block);
}

void CodeGenContext::popBlock()
{
        blockstack.pop_back();
}

ShareCodeGenBlock CodeGenContext::getNodeBlockMap(minipascal::Node* node)
{
        return blockmap.find(node)->second;
}

ShareCodeGenBlock CodeGenContext::getCurBlock()
{
        return blockstack.back();
}

llvm::Function* CodeGenContext::getMainFunction()
{
        return mainfunction;
}

llvm::Module* CodeGenContext::getModule()
{
        return module;
}

void CodeGenContext::setMainFunction(llvm::Function* mainfunction)
{
        this->mainfunction = mainfunction;
}

void CodeGenContext::setNodeBlockMap(minipascal::Node* node)
{
        blockmap.insert(BlockMapItem(node, getCurBlock()));
}
