#ifndef MINIPASCAL_NVARIABLEDECLARATION_H
#define MINIPASCAL_NVARIABLEDECLARATION_H

#include <vector>
#include <boost/shared_ptr.hpp>

#include "minipascal_ndeclaration.h"
#include "minipascal_type.h"

namespace minipascal {
        class NVariableDeclaration : public NDeclaration{
        public:
                NVariableDeclaration(const std::string* name = new std::string(), minipascal::NType* type = NULL);
                virtual ~NVariableDeclaration();
                // Implement Node pure virtual method
                std::string getOutput();
                virtual void accept(minipascal::Visitor* visitor);
        };
        typedef boost::shared_ptr<NVariableDeclaration> ShareNVariableDeclaration;
}

#endif // MINIPASCAL_NVARIABLEDECLARATION_H
