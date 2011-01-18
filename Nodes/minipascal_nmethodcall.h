#ifndef MINIPASCAL_NMETHODCALL_H
#define MINIPASCAL_NMETHODCALL_H

#include <string>

#include "minipascal_lists.h"
#include "minipascal_nexpression.h"

namespace minipascal{
        class NMethodCall : public NExpression{
        public:
                NMethodCall(std::string* name, Exps_list* exps = 0);
                virtual ~NMethodCall();
                // set methods
                void setName(std::string* name);
                void setExps(Exps_list* exps);
                // get methods
                std::string getName();
                Exps_list* getExps();
                // Implement Node pure virtual method
                std::string getOutput();
                virtual void accept(minipascal::Visitor* visitor);
                virtual llvm::Value* codeGen(CodeGenContext* context);
        private:
                std::string name;
                Exps_list* exps;
        };
        typedef boost::shared_ptr<NMethodCall> ShareNMethodCall;
}

#endif // MINIPASCAL_NMETHODCALL_H
