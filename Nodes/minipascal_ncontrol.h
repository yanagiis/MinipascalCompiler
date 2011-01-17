#ifndef MINIPASCAL_NCONTROL_H
#define MINIPASCAL_NCONTROL_H

#include "minipascal_nexpression.h"
#include "minipascal_nstatement.h"

namespace minipascal {
        class NControl : public NStatement{
        public:
                NControl(NExpression* cond = NULL, NStatement* iftrue = NULL, NStatement* iffalse = NULL);
                virtual ~NControl();
                // set methods
                void setCond(NExpression* cond);
                void setTrue(NStatement* iftrue);
                void setFalse(NStatement* iffalse);
                // get methods
                const ShareNExpression getCond();
                const ShareNStatement getTrue();
                const ShareNStatement getFalse();
                // Implement Node pure virtual method
                std::string getOutput();
                virtual void accept(minipascal::Visitor* visitor);
        private:
                ShareNExpression cond;
                ShareNStatement iftrue;
                ShareNStatement iffalse;
        };
        typedef boost::shared_ptr<NControl> ShareNControl;
}

#endif // MINIPASCAL_NCONTROL_H
