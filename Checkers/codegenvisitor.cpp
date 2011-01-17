#include "codegenvisitor.h"

#include <iostream>

CodeGenVisitor::CodeGenVisitor()
{

}

CodeGenVisitor::~CodeGenVisitor()
{

}

void CodeGenVisitor::visit(minipascal::NAssignment* node)
{

}

void CodeGenVisitor::visit(minipascal::NBinaryOperator* node)
{

}

void CodeGenVisitor::visit(minipascal::NBlock* node)
{

}

void CodeGenVisitor::visit(minipascal::NBoolean* node)
{

}

void CodeGenVisitor::visit(minipascal::NControl* node)
{

}

void CodeGenVisitor::visit(minipascal::NDouble* node)
{

}

void CodeGenVisitor::visit(minipascal::NInt* node)
{

}

void CodeGenVisitor::visit(minipascal::NLoop* node)
{

}

void CodeGenVisitor::visit(minipascal::NMethodCall* node)
{

}

void CodeGenVisitor::visit(minipascal::NMethodDeclaration* node)
{

}

void CodeGenVisitor::visit(minipascal::NProgram* node)
{

}

void CodeGenVisitor::visit(minipascal::NStatementExpression* node)
{

}

void CodeGenVisitor::visit(minipascal::NString* node)
{

}

void CodeGenVisitor::visit(minipascal::NVariable* node)
{

}

void CodeGenVisitor::visit(minipascal::NVariableDeclaration* node)
{

}

void CodeGenVisitor::visit(minipascal::ArrayType* node)
{

}

void CodeGenVisitor::visit(minipascal::IntType* node)
{

}

void CodeGenVisitor::visit(minipascal::RealType* node)
{

}

void CodeGenVisitor::visit(minipascal::BooleanType* node)
{

}

void CodeGenVisitor::visit(minipascal::StringType* node)
{

}

void CodeGenVisitor::visit(minipascal::VoidType* node)
{

}

void CodeGenVisitor::visit(minipascal::Node* node)
{
        std::cout << "Shoud not call this method" << std::endl;
}
