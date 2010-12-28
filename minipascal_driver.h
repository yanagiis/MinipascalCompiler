#ifndef MINIPASCAL_DRIVER_H
#define MINIPASCAL_DRIVER_H

#include <string>
#include <vector>

// #include "minipascal_nprogram.h"
//#include "minipascal_symboltable_handler.h"

namespace minipascal {
        class NProgram;
	class Driver
	{
		public:
			Driver();
			~Driver();
			bool trace_scanning;
			bool trace_parsing;
			std::string streamname;
			bool parse_file(const std::string& filename);
                        bool parse_stream(std::istream& in, const std::string& sname);
                        bool declarationChecking() throw();
                        bool typeChecking();
			void error(const class location& l, const std::string& m);
			void error(const std::string& m);

			class Scanner* lexer;
                        NProgram* program;
//                         SymbolTable_Handler* handler;
	};
}
#endif
