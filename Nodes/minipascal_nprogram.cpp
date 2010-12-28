#include "minipascal_nprogram.h"

minipascal::NProgram::NProgram()
{

}

minipascal::NProgram::~NProgram()
{
        decl_list->clear();
        ids->clear();
        mhd_list->clear();
        delete decl_list;
        delete ids;
        delete mhd_list;
}

minipascal::ShareBlock minipascal::NProgram::getBlock()
{
        return block;
}

Decls_list* minipascal::NProgram::getDecls()
{
        return decl_list;
}

Id_list* minipascal::NProgram::getIds()
{
        return ids;
}

Mhd_list* minipascal::NProgram::getMhds()
{
        return mhd_list;
}

void minipascal::NProgram::setBlock(minipascal::NBlock* block)
{
        this->block.reset(block);
}

void minipascal::NProgram::setDecls(Decls_list* decl_list)
{
        this->decl_list = decl_list;
}

void minipascal::NProgram::setIds(Id_list* ids)
{
        this->ids = ids;
}

void minipascal::NProgram::setMhds(Mhd_list* mhd_list)
{
        this->mhd_list = mhd_list;
}

std::string minipascal::NProgram::getOutput()
{
        std::string output = "new program " + getName();
}