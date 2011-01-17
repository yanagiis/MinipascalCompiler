#include <fstream>
#include <sstream>
#include <iostream>

#include "minipascal_driver.h"
#include "minipascal_scanner.h"
#include "Checkers/initializevisitor.h"
#include "Checkers/typevisitor.h"
#include "Checkers/codegencontext.h"

namespace minipascal{

	Driver::Driver()
	{
		trace_scanning = false;
		trace_parsing = false;
                context = new CodeGenContext();
	}

	Driver::~Driver()
	{
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

        bool Driver::declarationChecking() throw()
        {
                InitializeVisitor visitor = InitializeVisitor(context);
                visitor.visit(program);
        }

        bool Driver::typeChecking()
        {
                TypeVisitor visitor = TypeVisitor();
                visitor.visit(program);
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
