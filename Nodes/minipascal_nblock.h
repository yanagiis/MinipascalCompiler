#ifndef MINIPASCAL_NBLOCK_H
#define MINIPASCAL_NBLOCK_H

#include "minipascal_lists.h"
#include "minipascal_nstatement.h"

namespace minipascal{
        class NBlock : public NStatement {
        public:
                NBlock(Stmt_list* stmts = NULL);
                virtual ~NBlock();
                // set methods
                void setStmts(Stmt_list* stmts);
                // get methods
                const Stmt_list* getStmts();
                // Implement Node pure virtual method
                std::string getOutput();
        private:
                Stmt_list* stmts;
        };
        typedef boost::shared_ptr<NBlock> ShareNBlock;
}

#endif // MINIPASCAL_NBLOCK_H
