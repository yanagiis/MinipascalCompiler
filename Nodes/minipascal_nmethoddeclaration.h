#ifndef MINIPASCAL_NMETHODDECLARATION_H
#define MINIPASCAL_NMETHODDECLARATION_H

#include <vector>
#include <boost/shared_ptr.hpp>

#include "minipascal_ndeclaration.h"
#include "minipascal_nblock.h"

namespace minipascal {
        class NBlock;
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
                virtual void accept(minipascal::Visitor* visitor);
                virtual llvm::Value* codeGen(CodeGenContext* context);
        private:
                Decls_list* args;
                Decls_list* decl;
                ShareNBlock block;
        };
        typedef boost::shared_ptr<NMethodDeclaration> ShareNMethodDeclaration;
        typedef std::vector<ShareNMethodDeclaration> Mhd_list;
}

#endif // MINIPASCAL_NMETHODDECLARATION_H
