#ifndef MINIPASCAL_NBINARYOPERATOR_H
#define MINIPASCAL_NBINARYOPERATOR_H

#include "minipascal_nexpression.h"

namespace minipascal{
        class NBinaryOperator : public NExpression{
        public:
                enum BOP {
                        ADD, SUB, MUL, DIV, GT, GE, EQ, NE, LT, LE
                };
        public:
                NBinaryOperator(NExpression* left = NULL, NExpression* right = NULL);
                NBinaryOperator(BOP op, NExpression* left = NULL, NExpression* right = NULL);
                virtual ~NBinaryOperator();
                // set methods
                void setOP(BOP op);
                void setLeft(NExpression* left);
                void setRight(NExpression* right);
                // get methods
                BOP getOP();
                ShareNExpression getLeft();
                ShareNExpression getRight();
                // Implement Node pure virtual method
                std::string getOutput();
        private:
                ShareNExpression left;
                ShareNExpression right;
                BOP op;
        };
        typedef boost::shared_ptr<NBinaryOperator> ShareNBinaryOperator;
}

#endif // MINIPASCAL_NBINARYOPERATOR_H
