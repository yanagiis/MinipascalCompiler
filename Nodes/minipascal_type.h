#ifndef MINIPASCAL_TYPE_H
#define MINIPASCAL_TYPE_H

#include <string>
#include <llvm/Constant.h>
#include "minipascal_node.h"

namespace llvm {
        class Type;
}
namespace minipascal {
        
        class NType : public Node{
        public:
                NType();
                virtual ~NType();
                // get methods
                std::string getName();
                // set methods
                void setName(std::string name);
                // pure methods
                virtual bool compare(minipascal::NType* copytype) = 0;
                virtual bool operator==(minipascal::NType* copytype) = 0;
                virtual const llvm::Type* getLLVMType() = 0;
                virtual llvm::Value* codeGen(CodeGenContext* context) = 0;
                virtual llvm::Constant* initializer() = 0;
        private:
                std::string name;
        };
        
        
        class ArrayType : public NType {
        public:
                typedef std::pair<int, int> Range;
        public:
                ArrayType(NType* type = NULL);
                ArrayType(ArrayType& copytype);
                virtual ~ArrayType();
                virtual std::string getOutput();
                virtual void accept(minipascal::Visitor* visitor);
                virtual bool compare(minipascal::NType* copytype);
                virtual ArrayType operator=(ArrayType& copytype);
                virtual bool operator==(minipascal::NType* copytype);
                virtual const llvm::Type* getLLVMType();
                virtual llvm::Value* codeGen(CodeGenContext* context);
                virtual llvm::Constant* initializer();
                // set methods
                void setType(NType* type);
                void setRange(int lowerbound, int upperbound);
                void setRange(Range range);
                // get methods
                NType* getType();
                Range getRange();
        private:
                NType* type;
                Range range;
        };
        
        class IntType : public NType {
        public:
                IntType();
                virtual ~IntType();
                virtual std::string getOutput();
                virtual void accept(minipascal::Visitor* visitor);
                virtual bool compare(minipascal::NType* copytype);
                virtual bool operator==(minipascal::NType* copytype);
                virtual const llvm::Type* getLLVMType();
                virtual llvm::Value* codeGen(CodeGenContext* context);
                virtual llvm::Constant* initializer();
        };
        
        class RealType : public NType {
        public:
                RealType();
                virtual ~RealType();
                virtual std::string getOutput();
                virtual void accept(minipascal::Visitor* visitor);
                virtual bool compare(minipascal::NType* copytype);
                virtual bool operator==(minipascal::NType* copytype);
                virtual const llvm::Type* getLLVMType();
                virtual llvm::Value* codeGen(CodeGenContext* context);
                virtual llvm::Constant* initializer();
        };
        
        class StringType : public NType {
        public:
                StringType();
                virtual ~StringType();
                virtual std::string getOutput();
                virtual void accept(minipascal::Visitor* visitor);
                virtual bool compare(minipascal::NType* copytype);
                virtual bool operator==(minipascal::NType* copytype);
                virtual const llvm::Type* getLLVMType();
                virtual llvm::Value* codeGen(CodeGenContext* context);
                virtual llvm::Constant* initializer();
        };
        
        class BooleanType : public NType {
        public:
                BooleanType();
                virtual ~BooleanType();
                virtual std::string getOutput();
                virtual void accept(minipascal::Visitor* visitor);
                virtual bool compare(minipascal::NType* copytype);
                virtual bool operator==(minipascal::NType* copytype);
                virtual const llvm::Type* getLLVMType();
                virtual llvm::Value* codeGen(CodeGenContext* context);
                virtual llvm::Constant* initializer();
        };
        
        class VoidType : public NType {
        public:
                VoidType();
                virtual ~VoidType();
                virtual std::string getOutput();
                virtual void accept(minipascal::Visitor* visitor);
                virtual bool compare(minipascal::NType* copytype);
                virtual bool operator==(minipascal::NType* copytype);
                virtual const llvm::Type* getLLVMType();
                virtual llvm::Value* codeGen(CodeGenContext* context);
                virtual llvm::Constant* initializer();
        };
}
#endif // MINIPASCAL_TYPE_H
