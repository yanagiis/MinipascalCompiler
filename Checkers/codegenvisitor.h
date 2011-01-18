#ifndef CODEGENVISITOR_H
#define CODEGENVISITOR_H

#include <llvm/Support/IRBuilder.h>
#include <llvm/Value.h>
#include "minipascal_visitor.h"

class CodeGenContext;
class CodeGenVisitor : public minipascal::Visitor{
public:
        CodeGenVisitor();
        virtual ~CodeGenVisitor();
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
        virtual llvm::Value* codeGen(minipascal::NAssignment* node);
        virtual llvm::Value* codeGen(minipascal::NBinaryOperator* node);
        virtual llvm::Value* codeGen(minipascal::NBlock* node);
        virtual llvm::Value* codeGen(minipascal::NBoolean* node);
        virtual llvm::Value* codeGen(minipascal::NControl* node);
        virtual llvm::Value* codeGen(minipascal::NDouble* node);
        virtual llvm::Value* codeGen(minipascal::NInt* node);
        virtual llvm::Value* codeGen(minipascal::NLoop* node);
        virtual llvm::Value* codeGen(minipascal::NMethodCall* node);
        virtual llvm::Value* codeGen(minipascal::NMethodDeclaration* node);
        virtual llvm::Value* codeGen(minipascal::NProgram* node);
        virtual llvm::Value* codeGen(minipascal::NStatementExpression* node);
        virtual llvm::Value* codeGen(minipascal::NString* node);
        virtual llvm::Value* codeGen(minipascal::NVariable* node);
        virtual llvm::Value* codeGen(minipascal::NVariableDeclaration* node);
        virtual llvm::Value* codeGen(minipascal::ArrayType* node);
        virtual llvm::Value* codeGen(minipascal::IntType* node);
        virtual llvm::Value* codeGen(minipascal::RealType* node);
        virtual llvm::Value* codeGen(minipascal::BooleanType* node);
        virtual llvm::Value* codeGen(minipascal::StringType* node);
        virtual llvm::Value* codeGen(minipascal::VoidType* node);
public:
        CodeGenContext* context;
private:
        llvm::IRBuilder<>* builder;
        llvm::Value* value;
};

#endif // CODEGENVISITOR_H
