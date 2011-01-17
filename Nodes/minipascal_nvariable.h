#ifndef MINIPASCAL_NVARIABLE_H
#define MINIPASCAL_NVARIABLE_H

#include "minipascal_lists.h"
#include "minipascal_nexpression.h"

#include <string>

namespace minipascal{
        class NVariable : public NExpression {
        public:
                NVariable(std::string name = "");
                virtual ~NVariable();
                void setName(std::string* name);
                void setExps(Exps_list* exps_list);
                std::string getName();
                Exps_list* getExps();
                // Implement Node pure virtual method
                std::string getOutput();
                virtual void accept(minipascal::Visitor* visitor);
        private:
                std::string name;
                Exps_list* exps_list;
        };
        typedef boost::shared_ptr<NVariable> ShareNVariable;
}

#endif // MINIPASCAL_NVARIABLE_H
