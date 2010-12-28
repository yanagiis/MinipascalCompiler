#ifndef MINIPASCAL_NLOOP_H
#define MINIPASCAL_NLOOP_H

#include <boost/shared_ptr.hpp>

#include "minipascal_nstatement.h"
#include "minipascal_nexpression.h"

namespace minipascal {
        class NLoop : public NStatement{
        public:
                NLoop(const NExpression* cond = NULL, const NStatement* stmt = NULL);
                virtual ~NLoop();
                // set methods
                void setCond(const NExpression* cond);
                void setStmt(const minipascal::NStatement* stmt);
                // get methods
                const ShareNExpression getCond();
                const ShareNStatement getStmt();
                // Implement Node pure virtual method
                std::string getOutput();
        private:
                ShareNExpression cond;
                ShareNStatement stmt;
        };
        typedef boost::shared_ptr<NLoop> ShareNLoop;
}

#endif // MINIPASCAL_NLOOP_H
