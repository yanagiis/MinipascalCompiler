#ifndef MINIPASCAL_NSTATEMENTEXPRESSION_H
#define MINIPASCAL_NSTATEMENTEXPRESSION_H

#include <boost/shared_ptr.hpp>

#include "minipascal_nexpression.h"
#include "minipascal_nstatement.h"

namespace minipascal {
        class NStatementExpression : public NStatement{
        public:
                NStatementExpression(NExpression* exp = NULL);
                virtual ~NStatementExpression();
                // set methods
                void setExps(NExpression* exp);
                // get methods
                ShareNExpression getExps();
                // Implement Node pure virtual method
                std::string getOutput();
                virtual void accept(minipascal::Visitor* visitor);
                virtual llvm::Value* codeGen(CodeGenContext* context);
        private:
                ShareNExpression exp;
        };
        typedef boost::shared_ptr<NStatementExpression> ShareNStatementExpression;
}

#endif // MINIPASCAL_NSTATEMENTEXPRESSION_H
