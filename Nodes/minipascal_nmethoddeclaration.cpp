#include "minipascal_nmethoddeclaration.h"

#include "minipascal_visitor.h"

minipascal::NMethodDeclaration::NMethodDeclaration()
{
        setFail(false);
}

minipascal::NMethodDeclaration::~NMethodDeclaration()
{

}

void minipascal::NMethodDeclaration::accept(minipascal::Visitor* visitor)
{
        return visitor->visit(this);
}

minipascal::Decls_list* minipascal::NMethodDeclaration::getArgs()
{
        return args;
}

minipascal::ShareNBlock minipascal::NMethodDeclaration::getBlock()
{
        return block;
}

minipascal::Decls_list* minipascal::NMethodDeclaration::getDecl()
{
        return decl;
}

void minipascal::NMethodDeclaration::setArgs(minipascal::Decls_list* args)
{
        this->args = args;
}

void minipascal::NMethodDeclaration::setDecl(minipascal::Decls_list* decl)
{
        this->decl = decl;
}

void minipascal::NMethodDeclaration::setBlock(NBlock* block)
{
        this->block.reset(block);
}

std::string minipascal::NMethodDeclaration::getOutput()
{
        std::string output = "method declaration : '" + getName() + "', type : " + getType()->getName();
        return output;
}
