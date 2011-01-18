#ifndef MINIPASCAL_NEXPRESSION_H
#define MINIPASCAL_NEXPRESSION_H

#include <string>
#include <list>
#include <boost/shared_ptr.hpp>

#include "minipascal_node.h"
#include "minipascal_type.h"

namespace minipascal {
        class NExpression : public Node {
        public:
                enum HS {
                        LHS, RHS
                };
        public:
                NExpression();
                virtual ~NExpression();
                NType* getType();
                void setType(minipascal::NType* type);
                void setOpposite();
                std::string getStoreReg();
        public:
                HS hs;
        protected:
                static int index;
        private:
                NType* type;
                bool opposite;
        };
        typedef boost::shared_ptr< NExpression > ShareNExpression;
        typedef std::list<ShareNExpression> Exps_list;
}

#endif // MINIPASCAL_NEXPRESSION_H
