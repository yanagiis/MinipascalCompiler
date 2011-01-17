#ifndef TYPEVISITOR_H
#define TYPEVISITOR_H

#include "minipascal_visitor.h"

namespace minipascal {
        class TypeVisitor : public Visitor{
        public:
                TypeVisitor();
                virtual ~TypeVisitor();
                virtual void visit(minipascal::NAssignment* node);
                virtual void visit(minipascal::NBinaryOperator* node);
                virtual void visit(minipascal::NBlock* node);
                virtual void visit(minipascal::NBoolean* node);
                virtual void visit(minipascal::NControl* node);
                virtual void visit(minipascal::NDouble* node);
                virtual void visit(minipascal::NInt* node);
                virtual void visit(minipascal::NLoop* node);
                virtual void visit(minipascal::NMethodCall* node);
                virtual void visit(minipascal::NMethodDeclaration* node);
                virtual void visit(minipascal::NProgram* node);
                virtual void visit(minipascal::NStatementExpression* node);
                virtual void visit(minipascal::NString* node);
                virtual void visit(minipascal::NVariable* node);
                virtual void visit(minipascal::NVariableDeclaration* node);
                virtual void visit(minipascal::ArrayType* node);
                virtual void visit(minipascal::IntType* node);
                virtual void visit(minipascal::RealType* node);
                virtual void visit(minipascal::BooleanType* node);
                virtual void visit(minipascal::StringType* node);
                virtual void visit(minipascal::VoidType* node);
                virtual void visit(minipascal::Node* node);
        private:
                virtual void showMessage(std::string message);
                virtual void showError(std::string message, minipascal::Node* node);
        };
}

#endif // TYPEVISITOR_H
