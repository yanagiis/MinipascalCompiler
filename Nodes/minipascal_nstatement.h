#ifndef MINIPASCAL_NSTATEMENT_H
#define MINIPASCAL_NSTATEMENT_H

#include <vector>
#include <boost/shared_ptr.hpp>

#include "minipascal_node.h"

namespace minipascal {
        class NStatement : public Node {
        public:
                NStatement();
                virtual ~NStatement();
        };
        typedef boost::shared_ptr<NStatement> ShareNStatement;
        typedef std::vector<ShareNStatement> Stmt_list;
}

#endif // MINIPASCAL_NSTATEMENT_H
