#ifndef MINIPASCAL_NDECLARATION_H
#define MINIPASCAL_NDECLARATION_H

#include <boost/shared_ptr.hpp>
#include <string>

#include "minipascal_node.h"
#include "minipascal_type.h"

namespace minipascal {
        class NDeclaration : public Node{
        public:
                virtual ~NDeclaration();
                //get methods
                virtual std::string getName() const;
                virtual const Type* getType() const;
                //set methods
                virtual void setName(const char* name);
                virtual void setName(const std::string* name);
                virtual void setType(const Type* type);
        protected:
                NDeclaration(const std::string* name, const Type* type);
        private:
                NDeclaration();
        private:
                std::string name;
                const Type* type;
        };
        typedef boost::shared_ptr<NDeclaration> ShareNDeclaration;
        typedef std::vector< ShareNDeclaration > Decls_list;
}

#endif // MINIPASCAL_NDECLARATION_H
