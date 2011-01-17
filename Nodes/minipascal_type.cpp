#include "minipascal_type.h"

#include <stdio.h>
#include <boost/cast.hpp>
#include <llvm/Type.h>
#include <llvm/DerivedTypes.h>
#include <llvm/LLVMContext.h>

#include "minipascal_visitor.h"

minipascal::NType::NType()
{
        setFail(false);
}

minipascal::NType::~NType()
{

}

std::string minipascal::NType::getName()
{
        return name;
}

void minipascal::NType::setName(std::string name)
{
        this->name = name;
}

minipascal::ArrayType::ArrayType(NType* type)
{
        setType(type);
        setName("ArrayType");
        setFail(false);
}

minipascal::ArrayType::ArrayType(minipascal::ArrayType& copytype)
{
        setRange(copytype.getRange());
        setType(copytype.getType());
        setName("ArrayType");
        setFail(false);
}

minipascal::ArrayType::~ArrayType()
{
        
}

void minipascal::ArrayType::accept(minipascal::Visitor* visitor)
{
        return visitor->visit(this);
}

bool minipascal::ArrayType::compare(minipascal::NType* copytype)
{
        try{
                ArrayType* temp = boost::polymorphic_cast<ArrayType*>(copytype);
                if(this->getRange() == temp->getRange() && this->getType()->compare(temp->getType()))
                        return true;
                else
                        return false;
        } catch(std::bad_cast& e){
                return false;
        }
}

std::string minipascal::ArrayType::getOutput()
{
        char buf[512];
        int count = sprintf(buf, "ArrayType with range [%d, %d] and type %s", range.first, range.second, getType()->getName().c_str());
        return std::string(buf, count);
}

minipascal::ArrayType::Range minipascal::ArrayType::getRange()
{
        return range;
}

minipascal::NType* minipascal::ArrayType::getType()
{
        return type;
}

void minipascal::ArrayType::setRange(int lowerbound, int upperbound)
{
        range = Range(lowerbound, upperbound);
}

void minipascal::ArrayType::setRange(Range range)
{
        this->range = range;
}

void minipascal::ArrayType::setType(minipascal::NType* type)
{
        this->type = type;
}

minipascal::ArrayType minipascal::ArrayType::operator=(minipascal::ArrayType& copytype)
{
        setRange(copytype.getRange());
        setType(copytype.getType());
        return *this;
}

bool minipascal::ArrayType::operator==(minipascal::NType* copytype)
{
        return compare(copytype);
}

minipascal::BooleanType::BooleanType()
{
        setName("BooleanType");
        setFail(false);
}

minipascal::BooleanType::~BooleanType()
{

}

void minipascal::BooleanType::accept(minipascal::Visitor* visitor)
{
        return visitor->visit(this);
}

bool minipascal::BooleanType::compare(minipascal::NType* copytype)
{
        try{
                BooleanType* temp = boost::polymorphic_cast<BooleanType*>(copytype);
        } catch(std::bad_cast& e){
                return false;
        }
        return true;
}

std::string minipascal::BooleanType::getOutput()
{
        return this->getName();
}

bool minipascal::BooleanType::operator==(minipascal::NType* copytype)
{
        return compare(copytype);
}

minipascal::IntType::IntType()
{
        setName("IntType");
        setFail(false);
}

minipascal::IntType::~IntType()
{

}

void minipascal::IntType::accept(minipascal::Visitor* visitor)
{
        return visitor->visit(this);
}

bool minipascal::IntType::compare(minipascal::NType* copytype)
{
        try{
                IntType* temp = boost::polymorphic_cast<IntType*>(copytype);
        } catch(std::bad_cast& e){
                return false;
        }
        return true;
}

std::string minipascal::IntType::getOutput()
{
        return this->getName();
}

bool minipascal::IntType::operator==(minipascal::NType* copytype)
{
        return compare(copytype);
}

minipascal::RealType::RealType()
{
        setName("RealType");
        setFail(false);
}

minipascal::RealType::~RealType()
{

}

void minipascal::RealType::accept(minipascal::Visitor* visitor)
{
        return visitor->visit(this);
}

bool minipascal::RealType::compare(minipascal::NType* copytype)
{
        try{
                RealType* temp = boost::polymorphic_cast<RealType*>(copytype);
        } catch(std::bad_cast& e){
                return false;
        }
        return true;
}

std::string minipascal::RealType::getOutput()
{
        return this->getName();
}

bool minipascal::RealType::operator==(minipascal::NType* copytype)
{
        return compare(copytype);
}

minipascal::StringType::StringType()
{
        setName("StringType");
        setFail(false);
}

minipascal::StringType::~StringType()
{

}

void minipascal::StringType::accept(minipascal::Visitor* visitor)
{
        return visitor->visit(this);
}

bool minipascal::StringType::compare(minipascal::NType* copytype)
{
        try{
                StringType* temp = boost::polymorphic_cast<StringType*>(copytype);
        } catch(std::bad_cast& e){
                return false;
        }
        return true;
}

std::string minipascal::StringType::getOutput()
{
        return this->getName();
}

bool minipascal::StringType::operator==(minipascal::NType* copytype)
{
        return compare(copytype);
}

minipascal::VoidType::VoidType()
{
        setName("VoidType");
        setFail(false);
}

minipascal::VoidType::~VoidType()
{

}

void minipascal::VoidType::accept(minipascal::Visitor* visitor)
{
        return visitor->visit(this);
}

bool minipascal::VoidType::compare(minipascal::NType* copytype)
{
        try{
                VoidType* temp = boost::polymorphic_cast<VoidType*>(copytype);
        } catch(std::bad_cast& e){
                return false;
        }
        return true;
}

std::string minipascal::VoidType::getOutput()
{
        return this->getName();
}

bool minipascal::VoidType::operator==(minipascal::NType* copytype)
{
        return compare(copytype);
}

const llvm::Type* minipascal::ArrayType::getLLVMType()
{
        Range range = getRange();
        return llvm::ArrayType::get(this->getType()->getLLVMType(), range.second - range.first);
}

const llvm::Type* minipascal::BooleanType::getLLVMType()
{
        return llvm::Type::getInt8Ty(llvm::getGlobalContext());
}

const llvm::Type* minipascal::IntType::getLLVMType()
{
        return llvm::Type::getInt32Ty(llvm::getGlobalContext());
}

const llvm::Type* minipascal::RealType::getLLVMType()
{
        return llvm::Type::getDoubleTy(llvm::getGlobalContext());
}

const llvm::Type* minipascal::StringType::getLLVMType()
{
        return llvm::Type::getInt8PtrTy(llvm::getGlobalContext());
}

const llvm::Type* minipascal::VoidType::getLLVMType()
{
        return llvm::Type::getVoidTy(llvm::getGlobalContext());
}
