#ifndef MINIPASCAL_NSTATEMENT_H
#define MINIPASCAL_NSTATEMENT_H

#include <boost/shared_ptr.hpp>

#include "minipascal_node.h"

namespace minipascal {
        class NStatement : public Node {
        public:
                NStatement();
                virtual ~NStatement();
        };
        typedef boost::shared_ptr<NStatement> ShareNStatement;
}

#endif // MINIPASCAL_NSTATEMENT_H
