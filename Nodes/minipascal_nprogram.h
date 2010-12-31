#ifndef MINIPASCAL_NPROGRAM_H
#define MINIPASCAL_NPROGRAM_H

#include "minipascal_lists.h"
#include "minipascal_nblock.h"
#include "minipascal_ndeclaration.h"
#include "minipascal_nexpression.h"
#include "minipascal_nstatement.h"
#include "minipascal_nmethoddeclaration.h"

namespace minipascal {
        class NProgram : public NDeclaration {
        public:
                NProgram();
                virtual ~NProgram();
                // set methods
                void setIds(Id_list* ids);
                void setDecls(Decls_list* decl_list);
                void setMhds(Mhd_list* mhd_list);
                void setBlock(NBlock* block);
                // get methods
                Id_list* getIds();
                Decls_list* getDecls();
                Mhd_list* getMhds();
                ShareNBlock getBlock();
                // Implement Node pure virtual method
                std::string getOutput();
        private:
                Id_list* ids;
                Decls_list* decl_list;
                Mhd_list* mhd_list;
                ShareNBlock block;
        };
        typedef boost::shared_ptr<NProgram> ShareNProgram;
}

#endif // MINIPASCAL_NPROGRAM_H
