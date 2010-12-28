#ifndef MINIPASCAL_NMETHODDECLARATION_H
#define MINIPASCAL_NMETHODDECLARATION_H

#include <boost/shared_ptr.hpp>
#include "minipascal_ndeclaration.h"
#include "minipascal_nblock.h"

namespace minipascal {
        class NMethodDeclaration : public NDeclaration {
        public:
                NMethodDeclaration();
                virtual ~NMethodDeclaration();
                // set methods
                void setArgs(Decls_list* args);
                void setDecl(Decls_list* decl);
                void setBlock(NBlock* block);
                // get methods
                Decls_list* getArgs();
                Decls_list* getDecl();
                ShareNBlock getBlock();
                // Implement Node pure virtual method
                std::string getOutput();
        private:
                Decls_list* args;
                Decls_list* decl;
                ShareNBlock block;
        };
        typedef boost::shared_ptr<NMethodDeclaration> ShareNMethodDeclaration;
}

#endif // MINIPASCAL_NMETHODDECLARATION_H
