#ifndef MINIPASCAL_NVARIABLEDECLARATION_H
#define MINIPASCAL_NVARIABLEDECLARATION_H

#include "minipascal_ndeclaration.h"
#include "minipascal_type.h"

namespace minipascal {
        class NVariableDeclaration : public NDeclaration{
        public:
                NVariableDeclaration(const std::string* name = new std::string(), const Type* type = NULL);
                virtual ~NVariableDeclaration();
                // Implement Node pure virtual method
                std::string getOutput();
        };
}

#endif // MINIPASCAL_NVARIABLEDECLARATION_H
