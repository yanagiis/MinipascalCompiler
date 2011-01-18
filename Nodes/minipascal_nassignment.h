#ifndef MINIPASCAL_NASSIGNMENT_H
#define MINIPASCAL_NASSIGNMENT_H

#include "minipascal_nstatement.h"
#include "minipascal_nvariable.h"
#include "minipascal_nexpression.h"

namespace minipascal {
        class NAssignment : public NStatement{
        public:
                NAssignment(NVariable* var = NULL, NExpression* exp = NULL);
                virtual ~NAssignment();
                // set methods
                void setExp(NExpression* exp);
                void setVar(NVariable* var);
                // get methods
                ShareNExpression getExp();
                ShareNVariable getVar();
                // Implement Node pure virtual method
                std::string getOutput();
                virtual void accept(minipascal::Visitor* visitor);
                virtual llvm::Value* codeGen(CodeGenContext* context);
        private:
                ShareNExpression exp;
                ShareNVariable var;
        };
        typedef boost::shared_ptr<NAssignment> ShareNAssignment;
}

#endif // MINIPASCAL_NASSIGNMENT_H
