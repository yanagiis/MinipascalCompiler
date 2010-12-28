#ifndef MINIPASCAL_NVALUE_H
#define MINIPASCAL_NVALUE_H
#include "minipascal_nexpression.h"

namespace minipascal{
        class NValue : public NExpression{
        public:
                NValue();
                virtual ~NValue();
        };
}

#endif // MINIPASCAL_NVALUE_H
