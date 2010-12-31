#ifndef MINIPASCAL_TYPE_H
#define MINIPASCAL_TYPE_H

#include <string>

namespace minipascal {
        
        class Type {
        public:
                Type();
                virtual ~Type();
                std::string getName();
                void setName(std::string name);
                virtual bool operator==(minipascal::Type* copytype) = 0;
        private:
                std::string name;
        };
        
        
        class ArrayType : public Type {
        public:
                typedef std::pair<int, int> Range;
        public:
                ArrayType(Type* type = NULL);
                ArrayType(ArrayType& copytype);
                virtual ~ArrayType();
                virtual ArrayType operator=(ArrayType& copytype);
                virtual bool operator==(minipascal::Type* copytype);
                // set methods
                void setType(Type* type);
                void setRange(int lowerbound, int upperbound);
                void setRange(Range range);
                // get methods
                Type* getType();
                Range getRange();
        private:
                Type* type;
                Range range;
        };
        
        class IntType : public Type {
        public:
                IntType();
                virtual ~IntType();
                virtual bool operator==(minipascal::Type* copytype);
        };
        
        class RealType : public Type {
        public:
                RealType();
                virtual ~RealType();
                virtual bool operator==(minipascal::Type* copytype);
        };
        
        class StringType : public Type {
        public:
                StringType();
                virtual ~StringType();
                virtual bool operator==(minipascal::Type* copytype);
        };
        
        class BooleanType : public Type {
        public:
                BooleanType();
                virtual ~BooleanType();
                virtual bool operator==(minipascal::Type* copytype);
        };
        
        class VoidType : public Type {
        public:
                VoidType();
                virtual ~VoidType();
                virtual bool operator==(minipascal::Type* copytype);
        };
}
#endif // MINIPASCAL_TYPE_H
