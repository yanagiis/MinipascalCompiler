#ifndef MINIPASCAL_NSTATEMENTEXPRESSION_H
#define MINIPASCAL_NSTATEMENTEXPRESSION_H

#include <boost/shared_ptr.hpp>

#include "minipascal_nexpression.h"

namespace minipascal {
        class NStatementExpression {
        public:
                NStatementExpression(NExpression* exp = NULL);
                virtual ~NStatementExpression();
                // set methods
                void setExps(NExpression* exp);
                // get methods
                ShareNExpression getExps();
                // Implement Node pure virtual method
                std::string getOutput();
        private:
                ShareNExpression exp;
        };
}

#endif // MINIPASCAL_NSTATEMENTEXPRESSION_H
