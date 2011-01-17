#ifndef SYMBOL_H
#define SYMBOL_H

#include <map>
#include "minipascal_ndeclaration.h"

namespace llvm {
        class Value;
}
namespace minipascal {
        struct Symbol {
                llvm::Value* value;
                NDeclaration* declaration;
        };
        
        typedef std::map<std::string, Symbol*> SymbolTable;
        typedef std::pair<std::string, Symbol*> SymbolTableItem;
}

#endif // SYMBOL_H
