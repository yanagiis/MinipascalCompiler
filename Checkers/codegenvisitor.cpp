#include "codegenvisitor.h"

#include <iostream>
#include <llvm/Instructions.h>
#include <llvm/LLVMContext.h>
#include <llvm/Constants.h>
#include <llvm/Type.h>
#include <llvm/Module.h>
#include "codegencontext.h"

CodeGenVisitor::CodeGenVisitor()
{
        builder = new llvm::IRBuilder<>(llvm::getGlobalContext());
}

CodeGenVisitor::~CodeGenVisitor()
{
        delete builder;
}

void CodeGenVisitor::visit(minipascal::NAssignment* node)
{
        this->value = codeGen(node);
}

void CodeGenVisitor::visit(minipascal::NBinaryOperator* node)
{
        this->value = codeGen(node);
}

void CodeGenVisitor::visit(minipascal::NBlock* node)
{
        this->value = codeGen(node);
}

void CodeGenVisitor::visit(minipascal::NBoolean* node)
{
        this->value = codeGen(node);
}

void CodeGenVisitor::visit(minipascal::NControl* node)
{
        this->value = codeGen(node);
}

void CodeGenVisitor::visit(minipascal::NDouble* node)
{
        this->value = codeGen(node);
}

void CodeGenVisitor::visit(minipascal::NInt* node)
{
        this->value = codeGen(node);
}

void CodeGenVisitor::visit(minipascal::NLoop* node)
{
        this->value = codeGen(node);
}

void CodeGenVisitor::visit(minipascal::NMethodCall* node)
{
        this->value = codeGen(node);
}

void CodeGenVisitor::visit(minipascal::NMethodDeclaration* node)
{
        this->value = codeGen(node);
}

void CodeGenVisitor::visit(minipascal::NProgram* node)
{
        this->value = codeGen(node);
}

void CodeGenVisitor::visit(minipascal::NStatementExpression* node)
{
        this->value = codeGen(node);
}

void CodeGenVisitor::visit(minipascal::NString* node)
{
        this->value = codeGen(node);
}

void CodeGenVisitor::visit(minipascal::NVariable* node)
{
        this->value = codeGen(node);
}

void CodeGenVisitor::visit(minipascal::NVariableDeclaration* node)
{
        this->value = codeGen(node);
}

void CodeGenVisitor::visit(minipascal::ArrayType* node)
{
        this->value = codeGen(node);
}

void CodeGenVisitor::visit(minipascal::IntType* node)
{
        this->value = codeGen(node);
}

void CodeGenVisitor::visit(minipascal::RealType* node)
{
        this->value = codeGen(node);
}

void CodeGenVisitor::visit(minipascal::BooleanType* node)
{
        this->value = codeGen(node);
}

void CodeGenVisitor::visit(minipascal::StringType* node)
{
        this->value = codeGen(node);
}

void CodeGenVisitor::visit(minipascal::VoidType* node)
{
        this->value = codeGen(node);
}

void CodeGenVisitor::visit(minipascal::Node* node)
{
        std::cout << "Shoud not call this method" << std::endl;
}

llvm::Value* CodeGenVisitor::codeGen(minipascal::NAssignment* node)
{
        std::cout << "Creating code for " << node->getOutput() << std::endl;;
        node->getExp()->accept(this);
        llvm::Value* rightvalue = this->value;
        node->getVar()->accept(this);
        llvm::Value* declvalue = this->value;
        return builder->CreateStore(rightvalue, declvalue, false);
}

llvm::Value* CodeGenVisitor::codeGen(minipascal::NBinaryOperator* node)
{
        std::cout << "Creating code for " << node->getOutput() << std::endl;;
        
        node->getLeft()->accept(this);
        llvm::Value* L = this->value;
        node->getRight()->accept(this);
        llvm::Value* R = this->value;
        
        if(L == 0 || R == 0) return 0;
        
        minipascal::NType* temp = new minipascal::IntType();
        // for integer binary operation
        if(node->getLeft()->getType()->compare(temp))
        {
                switch(node->getOP()){
                case minipascal::NBinaryOperator::ADD:
                        return builder->CreateAdd(L, R, node->getOutput());
                case minipascal::NBinaryOperator::SUB:
                        return builder->CreateSub(L, R, node->getOutput());
                case minipascal::NBinaryOperator::MUL:
                        return builder->CreateMul(L, R, node->getOutput());
                case minipascal::NBinaryOperator::DIV:
                        return builder->CreateSDiv(L, R, node->getOutput());
                case minipascal::NBinaryOperator::LE:
                        return builder->CreateICmpSLE(L, R, node->getOutput());
                case minipascal::NBinaryOperator::LT:
                        return builder->CreateICmpSLT(L, R, node->getOutput());
                case minipascal::NBinaryOperator::EQ:
                        return builder->CreateICmpEQ(L, R, node->getOutput());
                case minipascal::NBinaryOperator::NE:
                        return builder->CreateICmpNE(L, R, node->getOutput());
                case minipascal::NBinaryOperator::GE:
                        return builder->CreateICmpSGE(L, R, node->getOutput());
                case minipascal::NBinaryOperator::GT:
                        return builder->CreateICmpSGT(L, R, node->getOutput());
                }
        }
        else // for real binary operation
        {
                switch(node->getOP()){
                case minipascal::NBinaryOperator::ADD:
                        return builder->CreateFAdd(L, R, node->getOutput());
                case minipascal::NBinaryOperator::SUB:
                        return builder->CreateFSub(L, R, node->getOutput());
                case minipascal::NBinaryOperator::MUL:
                        return builder->CreateFMul(L, R, node->getOutput());
                case minipascal::NBinaryOperator::DIV:
                        return builder->CreateFDiv(L, R, node->getOutput());
                case minipascal::NBinaryOperator::LE:
                        return builder->CreateFCmpOLE(L, R, node->getOutput());
                case minipascal::NBinaryOperator::LT:
                        return builder->CreateFCmpOLT(L, R, node->getOutput());
                case minipascal::NBinaryOperator::EQ:
                        return builder->CreateFCmpOEQ(L, R, node->getOutput());
                case minipascal::NBinaryOperator::NE:
                        return builder->CreateFCmpONE(L, R, node->getOutput());
                case minipascal::NBinaryOperator::GE:
                        return builder->CreateFCmpOGE(L, R, node->getOutput());
                case minipascal::NBinaryOperator::GT:
                        return builder->CreateFCmpOGT(L, R, node->getOutput());
                }
        }
}

llvm::Value* CodeGenVisitor::codeGen(minipascal::NBlock* node)
{
        std::cout << "Creating block ... " << std::endl;
        
        llvm::Value* last = NULL;
        minipascal::Stmt_list* stmts = node->getStmts();
        for(minipascal::Stmt_list::iterator it = stmts->begin(); it != stmts->end(); ++it)
        {
                (*it)->accept(this);
                last = this->value;
        }
        return last;
}

llvm::Value* CodeGenVisitor::codeGen(minipascal::NBoolean* node)
{
        std::cout << "Creating code for " << node->getOutput() << std::endl;;
}

llvm::Value* CodeGenVisitor::codeGen(minipascal::NControl* node)
{
        std::cout << "Creating code for " << node->getOutput() << std::endl;;
        
        node->getCond()->accept(this);
        llvm::Value* condvalue = this->value;
        if(!condvalue) return 0;
        
        llvm::BasicBlock* then_bb = llvm::BasicBlock::Create(llvm::getGlobalContext(), "then");
        llvm::BasicBlock* else_bb = llvm::BasicBlock::Create(llvm::getGlobalContext(), "else");
        llvm::BasicBlock* ifcont_bb = llvm::BasicBlock::Create(llvm::getGlobalContext(), "if");
        
        llvm::Value* thenv;
        llvm::Value* elsev;
        builder->CreateCondBr(condvalue, then_bb, else_bb);
        
        builder->SetInsertPoint(then_bb);
        node->getTrue()->accept(this);
        thenv = this->value;
        builder->CreateBr(ifcont_bb);
        then_bb = builder->GetInsertBlock();
        
        builder->SetInsertPoint(else_bb);
        node->getFalse()->accept(this);
        elsev = this->value;
        builder->CreateBr(ifcont_bb);
        
        builder->SetInsertPoint(ifcont_bb);
        llvm::PHINode* phi = builder->CreatePHI(llvm::Type::getDoubleTy(llvm::getGlobalContext()), "iftmp");
        
        phi->addIncoming(thenv, then_bb);
        phi->addIncoming(elsev, else_bb);
        
        return phi;
}

llvm::Value* CodeGenVisitor::codeGen(minipascal::NDouble* node)
{
        std::cout << "Creating code for " << node->getOutput() << std::endl;;
        return llvm::ConstantFP::get(llvm::Type::getFloatTy(llvm::getGlobalContext()), node->getValue());
}

llvm::Value* CodeGenVisitor::codeGen(minipascal::NInt* node)
{
        std::cout << "Creating code for " << node->getOutput() << std::endl;;
        return llvm::ConstantInt::get(llvm::Type::getInt32Ty(llvm::getGlobalContext()), node->getValue(), true);
}

llvm::Value* CodeGenVisitor::codeGen(minipascal::NLoop* node)
{
        std::cout << "Creating code for " << node->getOutput() << std::endl;;

}

llvm::Value* CodeGenVisitor::codeGen(minipascal::NMethodCall* node)
{
        std::cout << "Creating code for " << node->getOutput() << std::endl;;
        llvm::Function* function = context->getModule()->getFunction(node->getName().c_str());
        std::vector<llvm::Value*> args;
        minipascal::Exps_list* exps = node->getExps();
        for(minipascal::Exps_list::iterator it = exps->begin(); it != exps->end(); ++it)
        {
                (*it)->accept(this);
                llvm::Value* tempvalue = this->value;
                args.push_back(tempvalue);
        }
        llvm::CallInst* call = llvm::CallInst::Create(function, args.begin(), args.end(), "", context->getNodeBlockMap(node)->getBlock());
        std::cout << "Creating method call: " << node->getName() << std::endl;
        return call;
}

llvm::Value* CodeGenVisitor::codeGen(minipascal::NMethodDeclaration* node)
{
        std::cout << "Creating code for " << node->getOutput() << std::endl;;
        builder->SetInsertPoint(context->getNodeBlockMap(node)->getBlock());
        node->getBlock()->accept(this);
        llvm::ReturnInst::Create(llvm::getGlobalContext(), context->getNodeBlockMap(node)->getBlock());
        return context->getNodeBlockMap(node)->getLocals()->find(node->getName())->second->value;
}

llvm::Value* CodeGenVisitor::codeGen(minipascal::NProgram* node)
{
        std::cout << "Creating code for " << node->getOutput() << std::endl;;
        minipascal::Mhd_list* mhds = node->getMhds();
        for(minipascal::Mhd_list::iterator it = mhds->begin(); it != mhds->end(); ++it)
        {
                (*it)->accept(this);
        }
        builder->SetInsertPoint(context->getNodeBlockMap(node)->getBlock());
        node->getBlock()->accept(this);
        llvm::ReturnInst::Create(llvm::getGlobalContext(), context->getNodeBlockMap(node)->getBlock());
        return context->getMainFunction();
}

llvm::Value* CodeGenVisitor::codeGen(minipascal::NStatementExpression* node)
{
        std::cout << "Creating code for " << node->getOutput() << std::endl;;
        node->getExps()->accept(this);
        return this->value;
}

llvm::Value* CodeGenVisitor::codeGen(minipascal::NString* node)
{
        std::cout << "Creating code for " << node->getOutput() << std::endl;;
        // TODO wait
}

llvm::Value* CodeGenVisitor::codeGen(minipascal::NVariable* node)
{
        std::cout << "Creating code for " << node->getOutput() << std::endl;;
//         minipascal::Exps_list* exps = node->getExps();
//         for(minipascal::Exps_list::iterator it = exps->begin(); it != exps->end(); ++it)
//         {
//                 
//         }
        minipascal::SymbolTable* table = context->getNodeBlockMap(node)->getLocals();
        minipascal::SymbolTable::iterator it = table->find(node->getName());
        while(it == table->end())
        {
                
        }
        llvm::Value* value = it->second->value;
        return builder->CreateLoad(value);
}

llvm::Value* CodeGenVisitor::codeGen(minipascal::NVariableDeclaration* node)
{
        std::cout << "Creating code for " << node->getOutput() << std::endl;;
}

llvm::Value* CodeGenVisitor::codeGen(minipascal::ArrayType* node)
{
        std::cout << "Creating code for " << node->getOutput() << std::endl;;
}

llvm::Value* CodeGenVisitor::codeGen(minipascal::IntType* node)
{
        std::cout << "Creating code for " << node->getOutput() << std::endl;;
}

llvm::Value* CodeGenVisitor::codeGen(minipascal::RealType* node)
{
        std::cout << "Creating code for " << node->getOutput() << std::endl;;
}

llvm::Value* CodeGenVisitor::codeGen(minipascal::BooleanType* node)
{
        std::cout << "Creating code for " << node->getOutput() << std::endl;;
}

llvm::Value* CodeGenVisitor::codeGen(minipascal::StringType* node)
{
        std::cout << "Creating code for " << node->getOutput() << std::endl;;
}

llvm::Value* CodeGenVisitor::codeGen(minipascal::VoidType* node)
{
        std::cout << "Creating code for " << node->getOutput() << std::endl;;
}
