#ifndef MINIPASCAL_NDOUBLE_H
#define MINIPASCAL_NDOUBLE_H

#include "minipascal_nvalue.h"

namespace minipascal {
        class NDouble : public NValue {
        public:
                NDouble(double value = 0);
                virtual ~NDouble();
                double getValue();
                void setValue(double value);
                // Implement Node pure virtual method
                std::string getOutput();
                virtual void accept(minipascal::Visitor* visitor);
        private:
                double value;
        };
        typedef boost::shared_ptr<NDouble> ShareNDouble;
}

#endif // MINIPASCAL_NDOUBLE_H
