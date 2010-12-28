#ifndef MINIPASCAL_SCANNER_H
#define MINIPASCAL_SACNNER_H

#ifndef YY_DECL
#define YY_DECL							\
	minipascal::Parser::token_type				\
	minipascal::Scanner::lex(				\
		minipascal::Parser::semantic_type* yylval,	\
		minipascal::Parser::location_type* yylloc)	
#endif

#ifndef __FLEX_LEXER_H
#define yyFlexLexer minipascalFlexLexer
#include <FlexLexer.h>
#undef yyFlexLexer
#endif

#include "minipascal_parser.hpp"

namespace minipascal {
	class Scanner : public minipascalFlexLexer {
		public:
			Scanner(std::istream* arg_yyin = 0,
				std::ostream* arg_yyout = 0);
			virtual ~Scanner();
			virtual Parser::token_type lex(
				Parser::semantic_type* yylval,
				Parser::location_type* yylloc);

			void set_debug(bool b);
			void print_output(const char* token_name);
		private:
			int pos;
	};
}

#endif
