#ifndef MINIPASCAL_VISITOR_H
#define MINIPASCAL_VISITOR_H

#include "minipascal_node.h"

namespace minipascal {
        class Visitor {
        public:
                Visitor();
                virtual ~Visitor();
                virtual void visit(Node* node) = 0;
        };
}

#endif // MINIPASCAL_VISITOR_H
