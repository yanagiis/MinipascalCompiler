#include <fstream>
#include <sstream>
#include <iostream>

#include <llvm/Module.h>
#include "minipascal_driver.h"
#include "minipascal_scanner.h"
#include "Checkers/initializevisitor.h"
#include "Checkers/typevisitor.h"
#include "Checkers/codegencontext.h"
#include "Checkers/codegenvisitor.h"

#include <boost/concept_check.hpp>

namespace minipascal{

	Driver::Driver()
	{
		trace_scanning = false;
		trace_parsing = false;
                context = new CodeGenContext();
	}

	Driver::~Driver()
	{
                delete context;
	}

	bool Driver::parse_file(const std::string& filename)
	{
		std::ifstream in(filename.c_str());
		if(!in.good())
			return false;
		return parse_stream(in, filename);
	}

	bool Driver::parse_stream(std::istream& in, const std::string& sname)
	{
		streamname = sname;

		Scanner scanner(&in);
		scanner.set_debug(trace_scanning);
		this->lexer = &scanner;

		Parser parser(*this);
		parser.set_debug_level(trace_parsing);
		return (parser.parse() == 0);
        }

        bool Driver::codeGen()
        {
                program->codeGen(context);
                if(!context->fail)
                        context->getModule()->dump();
        }

	void Driver::error(const class location& l, const std::string& m)
	{
		std::cerr << l << ": " << m << std::endl;
	}
	void Driver::error(const std::string& m)
	{
		std::cerr << m << std::endl;
	}
}
