#include <fstream>
#include <sstream>
#include <iostream>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <llvm/Module.h>
#include <llvm/PassManager.h>
#include <llvm/Assembly/PrintModulePass.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/JIT.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/Target/TargetSelect.h>

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
                {
                        context->getModule()->dump();
                        int filefd = open("output.ll", O_WRONLY | O_CREAT | O_TRUNC, 0666);
                        llvm::PassManager PM;
                        llvm::raw_fd_ostream out(filefd, true);
                        
                        PM.add(llvm::createPrintModulePass(&out));
                        PM.run(*(context->getModule()));
                        
//                         runCode();
                }
        }
        
        void Driver::runCode()
        {
                llvm::InitializeNativeTarget();
                llvm::llvm_start_multithreaded();
                
                std::cout << "Running code ... " << std::endl;
                llvm::EngineBuilder builder = llvm::EngineBuilder(context->getModule());
                builder.setEngineKind(llvm::EngineKind::Interpreter);
                builder.setOptLevel(llvm::CodeGenOpt::Default);
//                 llvm::ExecutionEngine* ee = llvm::ExecutionEngine::create(context->getModule(), false);
                llvm::ExecutionEngine* ee = builder.create();
                std::vector<llvm::GenericValue> noargs;
                llvm::GenericValue v = ee->runFunction(context->getMainFunction(), noargs);
                std::cout << "Code was run." << std::endl;
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
