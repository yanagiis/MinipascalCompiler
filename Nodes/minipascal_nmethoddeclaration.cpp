#include "minipascal_nmethoddeclaration.h"

minipascal::NMethodDeclaration::NMethodDeclaration()
{

}

minipascal::NMethodDeclaration::~NMethodDeclaration()
{

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
        std::string output = "method declaration" + getName();
        return output;
}
