#ifndef MINIPASCAL_NINT_H
#define MINIPASCAL_NINT_H

#include "minipascal_nvalue.h"

namespace minipascal {
        class NInt : public NValue {
        public:
                NInt(int value = 0);
                virtual ~NInt();
                int getValue();
                void setValue(int value);
                // Implement Node pure virtual method
                std::string getOutput();
        private:
                int value;
        };
        typedef boost::shared_ptr<NInt> ShareNInt;
}

#endif // MINIPASCAL_NINT_H
