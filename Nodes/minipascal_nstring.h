#ifndef MINIPASCAL_NSTRING_H
#define MINIPASCAL_NSTRING_H

#include <string>

#include "minipascal_nvalue.h"

namespace minipascal {
        class NString : public NValue {
        public:
                NString(std::string* value = NULL);
                virtual ~NString();
                std::string getValue();
                void setValue(std::string* value);
                // Implement Node pure virtual method
                std::string getOutput();
                virtual void accept(minipascal::Visitor* visitor);
        private:
                std::string value;
        };
}

#endif // MINIPASCAL_NSTRING_H
