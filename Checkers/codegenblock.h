#ifndef CODEGENBLOCK_H
#define CODEGENBLOCK_H

#include <string>
#include <boost/shared_ptr.hpp>

#include "symbol.h"

class CodeGenBlock;
namespace llvm {
        class Value;
        class BasicBlock;
}

typedef boost::shared_ptr<CodeGenBlock> ShareCodeGenBlock;
class CodeGenBlock {
public:
        CodeGenBlock();
        virtual ~CodeGenBlock();
        // get methods
        llvm::BasicBlock* getBlock();
        minipascal::SymbolTable* getLocals();
        ShareCodeGenBlock getParent();
        std::string getName();
        // set methods
        void setBlock(llvm::BasicBlock* block);
        void setParent(ShareCodeGenBlock parent);
        void setName(std::string name);
private:
        std::string name;
        llvm::BasicBlock* block;
        minipascal::SymbolTable* locals;
        ShareCodeGenBlock parent;
};

#endif // CODEGENBLOCK_H
