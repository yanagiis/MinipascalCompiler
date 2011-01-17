#ifndef CODEGENCONTEXT_H
#define CODEGENCONTEXT_H

#include <map>
#include <vector>
#include "codegenblock.h"

namespace minipascal {
        class Node;
        class NProgram;
}
namespace llvm {
        class Function;
        class Module;
}

class CodeGenContext {
public:
        typedef std::map<minipascal::Node*, ShareCodeGenBlock> BlockMap;
        typedef std::pair<minipascal::Node*, ShareCodeGenBlock> BlockMapItem;
        typedef std::vector<ShareCodeGenBlock> BlockStack;
public:
        CodeGenContext();
        virtual ~CodeGenContext();
        ShareCodeGenBlock createCodeGenBlock();
        void setNodeBlockMap(minipascal::Node* node);
        void pushBlock();
        void pushBlock(ShareCodeGenBlock block);
        void popBlock();
        // set methods
        void setMainFunction(llvm::Function* mainfunction);
        // get methods
        llvm::Module* getModule();
        llvm::Function* getMainFunction();
        ShareCodeGenBlock getCurBlock();
public:
        BlockStack blockstack;
private:
        BlockMap blockmap;
        llvm::Module* module;
        llvm::Function* mainfunction;
};

#endif // CODEGENCONTEXT_H
