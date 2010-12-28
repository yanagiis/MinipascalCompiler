#include "minipascal_nbinaryoperator.h"

minipascal::NBinaryOperator::NBinaryOperator(minipascal::NExpression* left, minipascal::NExpression* right): NExpression(left, right)
{
        setLeft(left);
        setRight(right);
}

minipascal::NBinaryOperator::NBinaryOperator(minipascal::NBinaryOperator::BOP op, minipascal::NExpression* left, minipascal::NExpression* right): NExpression(op, left, right)
{
        setOP(op);
        setLeft(left);
        setRight(right);
}

minipascal::NBinaryOperator::~NBinaryOperator()
{
}

minipascal::ShareNExpression minipascal::NBinaryOperator::getLeft()
{
        return left;
}

minipascal::NBinaryOperator::BOP minipascal::NBinaryOperator::getOP()
{
        return op;
}

minipascal::ShareNExpression minipascal::NBinaryOperator::getRight()
{
        return right;
}

void minipascal::NBinaryOperator::setLeft(minipascal::NExpression* left)
{
        this->left.reset(left);
}

void minipascal::NBinaryOperator::setOP(minipascal::NBinaryOperator::BOP op)
{
        this->op = op;
}

void minipascal::NBinaryOperator::setRight(minipascal::NExpression* right)
{
        this->right.reset(right);
}
 
std::string minipascal::NBinaryOperator::getOutput()
{
        std::string stringOP;
        switch(op){
                case ADD:
                        stringOP = "+";
                        break;
                case SUB:
                        stringOP = "-";
                        break;
                case MUL:
                        stringOP = "*";
                        break;
                case DIV:
                        stringOP = "/";
                        break;
                case GE:
                        stringOP = ">=";
                        break;
                case GT:
                        stringOP = ">";
                        break;
                case LE:
                        stringOP = "<=";
                        break;
                case LT:
                        stringOP = "<";
                        break;
                case EQ:
                        stringOP = "==";
                        break;
                case NE:
                        stringOP = "!=";
                        break;
        }
        std::string output = left->getOutput() + stringOP + right->getOutput();
        return output;
}