#ifndef MINIPASCAL_NEXPRESSION_H
#define MINIPASCAL_NEXPRESSION_H

#include <list>
#include <boost/shared_ptr.hpp>

#include "minipascal_node.h"
#include "minipascal_type.h"

namespace minipascal {
        class NExpression : public Node {
        public:
                NExpression();
                virtual ~NExpression();
                const Type* getType();
                void setType(minipascal::Type* type);
                void setOpposite();
        private:
                Type* type;
                bool opposite;
        };
        typedef boost::shared_ptr< NExpression > ShareNExpression;
        typedef std::list<ShareNExpression> Exps_list;
}

#endif // MINIPASCAL_NEXPRESSION_H
