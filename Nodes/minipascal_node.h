#ifndef MINIPASCAL_NODE_H
#define MINIPASCAL_NODE_H

#include <string>

namespace minipascal {
        class Visitor;
        class Node {
        public:
                // vistor use
                virtual void accept(Visitor* visitor);
                // get methods
                int getLineNo() const;
                bool getFail() const;
                // set methods
                void setFail(bool fail);
                void setLineNo(int lineno);
                
                // pure virtual methods
                virtual std::string getOutput() = 0;
        private:
                int lineno;
                bool fail;
        };
}

#include "minipascal_visitor.h"

#endif // MINIPASCAL_NODE_H
