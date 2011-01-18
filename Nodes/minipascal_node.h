#ifndef MINIPASCAL_NODE_H
#define MINIPASCAL_NODE_H

#include <string>
#include <llvm/Value.h>

class CodeGenContext;

namespace minipascal {
        class Visitor;
        class Node {
        public:
                // visitor use
                virtual void accept(minipascal::Visitor* visitor);
                virtual void showError(std::string message);
                // get methods
                int getLineNo() const;
                bool getFail() const;
                // set methods
                void setFail(bool fail);
                void setLineNo(int lineno);
                
                // pure virtual methods
                virtual std::string getOutput() = 0;
                virtual llvm::Value* codeGen(CodeGenContext* context) = 0;
        private:
                int lineno;
                bool fail;
        };
}

#endif // MINIPASCAL_NODE_H
