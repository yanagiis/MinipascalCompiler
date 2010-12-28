#include "minipascal_type.h"

#include <boost/cast.hpp>

minipascal::Type::Type()
{

}

minipascal::Type::~Type()
{

}

minipascal::ArrayType::ArrayType()
{

}

minipascal::ArrayType::ArrayType(minipascal::ArrayType& copytype)
{
        setRange(copytype.getRange());
        setType(copytype.getType());
}

Range minipascal::ArrayType::getRange()
{
        return range;
}

minipascal::Type* minipascal::ArrayType::getType()
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

void minipascal::ArrayType::setType(minipascal::Type* type)
{
        this->type = type;
}

minipascal::ArrayType minipascal::ArrayType::operator=(minipascal::ArrayType& copytype)
{
        setRange(copytype.getRange());
        setType(copytype.getType());
        return *this;
}

bool minipascal::ArrayType::operator==(const minipascal::Type& copytype)
{
        try{
                ArrayType* temp = boost::polymorphic_cast<ArrayType*>(&copytype);
                if(this->getRange() == temp->getRange() && this->getType() == temp->getType())
                        return true;
                else
                        return false;
        } catch(std::bad_cast& e){
                return false;
        }
}

minipascal::BooleanType::BooleanType()
{

}

minipascal::BooleanType::~BooleanType()
{

}

bool minipascal::BooleanType::operator==(const minipascal::Type& copytype)
{
        try{
                BooleanType* temp = boost::polymorphic_cast<BooleanType*>(&copytype);
        } catch(std::bad_cast& e){
                return false;
        }
        return true;
}

minipascal::IntType::IntType()
{

}

minipascal::IntType::~IntType()
{

}

bool minipascal::IntType::operator==(const minipascal::Type& copytype)
{
        try{
                IntType* temp = boost::polymorphic_cast<IntType*>(&copytype);
        } catch(std::bad_cast& e){
                return false;
        }
        return true;
}

minipascal::RealType::RealType()
{

}

minipascal::RealType::~RealType()
{

}

bool minipascal::RealType::operator==(const minipascal::Type& copytype)
{
        try{
                RealType* temp = boost::polymorphic_cast<RealType*>(&copytype);
        } catch(std::bad_cast& e){
                return false;
        }
        return true;
}

minipascal::StringType::StringType()
{

}

minipascal::StringType::~StringType()
{

}

bool minipascal::StringType::operator==(const minipascal::Type& copytype)
{
        try{
                StringType* temp = boost::polymorphic_cast<StringType*>(&copytype);
        } catch(std::bad_cast& e){
                return false;
        }
        return true;
}