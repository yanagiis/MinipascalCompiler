#ifndef MINIPASCAL_NDECLARATION_H
#define MINIPASCAL_NDECLARATION_H

#include <vector>
#include <string>
#include <boost/shared_ptr.hpp>

#include "minipascal_node.h"
#include "minipascal_type.h"

namespace minipascal {
        class NDeclaration : public Node{
        public:
                virtual ~NDeclaration();
                // get methods
                virtual std::string getName();
                virtual NType* getType();
                // set methods
                virtual void setName(const char* name);
                virtual void setName(const std::string* name);
                virtual void setType(minipascal::NType* type);
                // pure method
//                 virtual llvm::Value* codeGen(CodeGenContext* context) = 0;
        protected:
                NDeclaration();
                NDeclaration(const std::string* name, minipascal::NType* type);
        private:
                std::string name;
                NType* type;
        };
        typedef boost::shared_ptr<NDeclaration> ShareNDeclaration;
        typedef std::vector<ShareNDeclaration> Decls_list;
}

#endif // MINIPASCAL_NDECLARATION_H
