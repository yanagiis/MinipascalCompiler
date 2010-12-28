%{
#include <stdlib.h>
#include <string>
#include "minipascal_scanner.h"

typedef minipascal::Parser::token token;
typedef minipascal::Parser::token_type token_type;

#undef yywrap
#define yywrap() 1

#define yyterminate() return token::EF
#define YY_NO_UNISTD_H
%}

%option c++
%option prefix="minipascal"
%option stack
%option batch
%option debug
%option noyywrap
%option yylineno

digit [0-9]
letter [A-Za-z]

%{
#define YY_USER_ACTION yylloc->columns(yyleng);
%}

%%

%{
	yylloc->step();
%}

"PROGRAM"	{ print_output("PROGRAM"); return token::PROGRAM; }
"program"	{ print_output("PROGRAM"); return token::PROGRAM; }
"of"		{ print_output("OF"); return token::OF; }
"function"	{ print_output("FUNCTION"); return token::FUNCTION; }
"procedure"	{ print_output("PROCEDURE"); return token::PROCEDURE; }
"begin"		{ print_output("BEGIN"); return token::BEGAN; }
"end"		{ print_output("END"); return token::END; }
"array"		{ print_output("ARRAY"); return token::ARRAY; }
"var"		{ print_output("VAR"); return token::VAR; }
"if"		{ print_output("IF"); return token::IF; }
"then"		{ print_output("THEN"); return token::THEN; }
"else"		{ print_output("ELSE"); return token::ELSE; }
"while"		{ print_output("WHILE"); return token::WHILE; }
"do"		{ print_output("DO"); return token::DO; }
"integer"	{ print_output("INTEGER_T"); return token::INTEGER_T; }
"real"		{ print_output("REAL_T"); return token::REAL_T; }
";"		{ print_output("SEMICOLON"); return token::SEMICOLON; }
":"		{ print_output("COLON"); return token::COLON; }
".."		{ print_output("RANGE"); return token::RANGE; }
","		{ print_output("COMMA"); return token::COMMA; }
"("		{ print_output("LPAREN"); return token::LPAREN; }
")"		{ print_output("RPAREN"); return token::RPAREN; }
":="		{ print_output("ASSIGN"); return token::ASSIGN; }
"["		{ print_output("L_SQUARE_BRACKET"); return token::L_SQUARE_BRACKET; }
"]"		{ print_output("R_SQUARE_BRACKET"); return token::R_SQUARE_BRACKET; }
"."		{ print_output("PERIOD"); return token::PERIOD; }
"<"		{ print_output("LT"); return token::LT; }
">"		{ print_output("GT"); return token::GT; }
"="		{ print_output("EQ"); return token::EQ; }
"<="		{ print_output("LE"); return token::LE; }
">="		{ print_output("GE"); return token::GE; }
"!="		{ print_output("NE"); return token::NE; }
"+"		{ print_output("PLUS"); return token::PLUS; }
"-"		{ print_output("MINUS"); return token::MINUS; }
"*"		{ print_output("MUL"); return token::MUL; }
"/"		{ print_output("DIV"); return token::DIV; }
"not"		{ print_output("NOT"); return token::NOT; }

{digit}+ 	{
	
	print_output("INT");
	yylval->integerVal = atoi(yytext);
	return token::INTEGER;
}

{digit}+/\.\.	{

	print_output("INT");
	yylval->integerVal = atoi(yytext);
	return token::INTEGER;
}

{digit}+\.{digit}* {
	
	print_output("REAL");
	yylval->doubleVal = atof(yytext);
	return token::REAL;
}

[A-Za-z_][A-Za-z0-9_]* {
	
	print_output("ID");
	yylval->stringVal = new std::string(yytext, yyleng);
	return token::ID;
}

'(\\.|''|[^'\n])*' {
	print_output("STRING");
	yylval->stringVal = new std::string(yytext, yyleng);
	return token::STRING;
}

\"(\\.|''|[^'\n])*\" {
	print_output("STRING");
	yylval->stringVal = new std::string(yytext, yyleng);
	return token::STRING;
}

[ \t\r]+ {
	
	yylloc->step();
}

\n {
	yylloc->lines();
	yylloc->step();
}

"/*" {
	int c;
	int count = 0;

	
	while((c = yyinput()) != 0)
	{
		++count;
		if(c == '*')
		{
			if((c = yyinput()) == '/')
				break;
			else
			{
				--count;
				unput(c);
			}
		}
		else if(c == '\n')
			yylloc->lines();
	}
	if(c == 0)
		return token::EF;
	yylloc->step();
}

"//" {
	int c;

	while((c = yyinput()) != 0)
	{
		if(c == '\n')
		{
			yylloc->lines();
			break;
		}
	}
	if(c == 0)
		return token::EF;
	yylloc->step();
}

. {
	print_output("LEX_ERROR");
	return static_cast<token_type>(*yytext);
}
%%

namespace minipascal{

	Scanner::Scanner(std::istream* in,
			std::ostream* out)
		: yyFlexLexer(in, out)
	{
	}

	Scanner::~Scanner()
	{
	}

	void Scanner::set_debug(bool b)
	{
		yy_flex_debug = b;
	}

	void Scanner::print_output(const char* name)
	{
		//std::cout << "line: " << yylineno << ", token type: " << name << ", token: " << yytext << std::endl;
	}
}

#ifdef yylex
#undef yylex
#endif

int yyFlexLexer::yylex()
{
	std::cerr << "in yyFlexLexer::yylex() !" << std::endl;
	return 0;
}
/*
int yyFlexLexer::yywrap()
{
	return 1;
}
*/
