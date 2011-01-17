#ifndef MINIPASCAL_NBOOLEAN_H
#define MINIPASCAL_NBOOLEAN_H

#include "minipascal_nvalue.h"

namespace minipascal{
        class NBoolean : public NValue {
        public:
                NBoolean(bool value = true);
                virtual ~NBoolean();
                void setOpposite();
                bool getValue();
                void setValue(bool value);
                // Implement Node pure virtual method
                std::string getOutput();
                virtual void accept(minipascal::Visitor* visitor);
        private:
                bool value;
        };
        typedef boost::shared_ptr<NBoolean> ShareNBoolean;
}

#endif // MINIPASCAL_NBOOLEAN_H
