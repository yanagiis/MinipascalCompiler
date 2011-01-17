#include "typevisitor.h"

#include <iostream>

minipascal::TypeVisitor::TypeVisitor()
{

}

minipascal::TypeVisitor::~TypeVisitor()
{

}

void minipascal::TypeVisitor::visit(minipascal::NAssignment* node)
{
        showMessage("NAssignment -- " + node->getOutput());
        //if(node->getFail()) return;
        node->getExp()->accept(this);
        node->getVar()->accept(this);
        if(!(node->getVar()->getFail()))
        {
                if(!(node->getVar()->getType()->compare(node->getExp()->getType())))
                {
                        showError("Cannot assign type : " + node->getVar()->getType()->getName()  + " to type : " + node->getExp()->getType()->getName(), node);
                        node->setFail(true);
                        return;
                }
        }
}

void minipascal::TypeVisitor::visit(minipascal::NBinaryOperator* node)
{
        showMessage("NBinaryOperator -- " + node->getOutput());
        //if(node->getFail()) return;
        node->getLeft()->accept(this);
        node->getRight()->accept(this);
        if(!(node->getLeft()->getFail()))
        {
                if(!(node->getLeft()->getType()->compare(node->getRight()->getType())))
                {
                        showError("Cannot do binary operation", node);
                        node->setFail(true);
                        return;
                }
        }
}

void minipascal::TypeVisitor::visit(minipascal::NBlock* node)
{
        showMessage("NBlock -- " + node->getOutput());
        //if(node->getFail()) return;
        Stmt_list* stmts = node->getStmts();
        for(Stmt_list::iterator it = stmts->begin(); it != stmts->end(); ++it)
        {
                (*it)->accept(this);
        }
}

void minipascal::TypeVisitor::visit(minipascal::NBoolean* node)
{
        showMessage("NBoolean -- " + node->getOutput());
        //if(node->getFail()) return;
}

void minipascal::TypeVisitor::visit(minipascal::NControl* node)
{
        showMessage("NControl -- " + node->getOutput());
        //if(node->getFail()) return;
        BooleanType* type = new BooleanType();
        if(!(node->getCond()->getFail()))
        {
                if(!(node->getCond()->getType()->compare(type)))
                {
                        showError("condition expression in if statement isn't boolean type", node);
                        node->setFail(true);
                        return;
                }
        }
        delete type;
        node->getCond()->accept(this);
        node->getTrue()->accept(this);
        node->getFalse()->accept(this);
}

void minipascal::TypeVisitor::visit(minipascal::NDouble* node)
{
        showMessage("NDouble -- " + node->getOutput());
}

void minipascal::TypeVisitor::visit(minipascal::NInt* node)
{
        showMessage("NInt -- " + node->getOutput());
}

void minipascal::TypeVisitor::visit(minipascal::NLoop* node)
{
        showMessage("NLoop -- " + node->getOutput());
        //if(node->getFail()) return;
        BooleanType* type = new BooleanType();
        if(!(node->getCond()->getFail()))
        {
                if(!(node->getCond()->getType()->compare(type)))
                {
                        showError("condition expression in if statement isn't boolean type", node);
                        node->setFail(true);
                        return;
                }
        }
        node->getCond()->accept(this);
        node->getStmt()->accept(this);
}

void minipascal::TypeVisitor::visit(minipascal::NMethodCall* node)
{
        showMessage("NMethodCall -- " + node->getOutput());
        //if(node->getFail()) return;
}

void minipascal::TypeVisitor::visit(minipascal::NMethodDeclaration* node)
{
        showMessage("NMethodDeclaration -- " + node->getOutput());
        //if(node->getFail()) return;
        node->getBlock()->accept(this);
}

void minipascal::TypeVisitor::visit(minipascal::NProgram* node)
{
        showMessage("NProgram -- " + node->getOutput());
        //if(node->getFail()) return;
        Mhd_list* mhds = node->getMhds();
        for(Mhd_list::iterator it = mhds->begin(); it != mhds->end(); ++it)
        {
                (*it)->accept(this);
        }
        node->getBlock()->accept(this);
}

void minipascal::TypeVisitor::visit(minipascal::NStatementExpression* node)
{
        showMessage("NStatementExpression -- " + node->getOutput());
        //if(node->getFail()) return;
        node->getExps()->accept(this);
}

void minipascal::TypeVisitor::visit(minipascal::NString* node)
{
        showMessage("NString -- " + node->getOutput());
        //if(node->getFail()) return;
}

void minipascal::TypeVisitor::visit(minipascal::NVariable* node)
{
        showMessage("NVariable -- " + node->getOutput());
        //if(node->getFail()) return;
        Exps_list* exps = node->getExps();
        Exps_list::iterator it;
        for(it = exps->begin(); it != exps->end(); ++it)
        {
                (*it)->accept(this);
        }
        for(it = exps->begin(); it != exps->end(); ++it)
        {
                (*it)->getType();
        }
}

void minipascal::TypeVisitor::visit(minipascal::NVariableDeclaration* node)
{
        showMessage("NVariableDeclaration -- " + node->getOutput());
}

void minipascal::TypeVisitor::visit(minipascal::ArrayType* node)
{
        std::cout << "Should not call this in TypeVisitor" << std::endl;
}

void minipascal::TypeVisitor::visit(minipascal::IntType* node)
{
        std::cout << "Should not call this in TypeVisitor" << std::endl;
}

void minipascal::TypeVisitor::visit(minipascal::RealType* node)
{
        std::cout << "Should not call this in TypeVisitor" << std::endl;
}

void minipascal::TypeVisitor::visit(minipascal::BooleanType* node)
{
        std::cout << "Should not call this in TypeVisitor" << std::endl;
}

void minipascal::TypeVisitor::visit(minipascal::StringType* node)
{
        std::cout << "Should not call this in TypeVisitor" << std::endl;
}

void minipascal::TypeVisitor::visit(minipascal::VoidType* node)
{
        std::cout << "Should not call this in TypeVisitor" << std::endl;
}

void minipascal::TypeVisitor::visit(minipascal::Node* node)
{
        std::cout << "Should not call this in TypeVisitor" << std::endl;
}

void minipascal::TypeVisitor::showError(std::string message, minipascal::Node* node)
{
        std::cout << "Error : " << message << " at LINE:" << node->getLineNo() << std::endl;
}

void minipascal::TypeVisitor::showMessage(std::string name)
{
        std::cout << "TypeCheck " << name << std::endl;
}
