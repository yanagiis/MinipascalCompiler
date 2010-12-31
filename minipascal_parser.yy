%code requires {
#include "minipascal_node.h"
#include "minipascal_nassignment.h"
#include "minipascal_nbinaryoperator.h"
#include "minipascal_nblock.h"
#include "minipascal_nboolean.h"
#include "minipascal_ncontrol.h"
#include "minipascal_ndeclaration.h"
#include "minipascal_ndouble.h"
#include "minipascal_nexpression.h"
#include "minipascal_nint.h"
#include "minipascal_nloop.h"
#include "minipascal_nmethodcall.h"
#include "minipascal_nmethoddeclaration.h"
#include "minipascal_nprogram.h"
#include "minipascal_nstatement.h"
#include "minipascal_nstatementexpression.h"
#include "minipascal_nstring.h"
#include "minipascal_nvalue.h"
#include "minipascal_nvariable.h"
#include "minipascal_nvariabledeclaration.h"
#include "minipascal_type.h"
#include "minipascal_lists.h"
}

%{
#include <stdio.h>
#include <string>
#include <vector>

#include "minipascal_node.h"
#include "minipascal_nassignment.h"
#include "minipascal_nbinaryoperator.h"
#include "minipascal_nblock.h"
#include "minipascal_nboolean.h"
#include "minipascal_ncontrol.h"
#include "minipascal_ndeclaration.h"
#include "minipascal_ndouble.h"
#include "minipascal_nexpression.h"
#include "minipascal_nint.h"
#include "minipascal_nloop.h"
#include "minipascal_nmethodcall.h"
#include "minipascal_nmethoddeclaration.h"
#include "minipascal_nprogram.h"
#include "minipascal_nstatement.h"
#include "minipascal_nstatementexpression.h"
#include "minipascal_nstring.h"
#include "minipascal_nvalue.h"
#include "minipascal_nvariable.h"
#include "minipascal_nvariabledeclaration.h"
#include "minipascal_type.h"
#include "minipascal_lists.h"
%}

%require "2.3"
%debug
%defines
%skeleton "lalr1.cc"
%name-prefix="minipascal"

%locations
%initial-action
{
	@$.begin.filename = @$.end.filename = &driver.streamname;
}

%parse-param{ class Driver& driver }
%error-verbose
%define "parser_class_name" "Parser"

%union {
	int integerVal;
	double doubleVal;
	std::string* stringVal;
        
        NStatement* stmt;
        NStatementExpression* stmtexps;
        NLoop* loop;
        NBlock* block;
        NControl* control;
        NAssignment* assignment;
        
        NExpression* exps;
        NVariable* var;
        NBinaryOperator* binaryoperator;
        NMethodCall* methodcall;
        NBinaryOperator::BOP op;
        NValue* value;
        
        NDeclaration* decl;
        NVariableDeclaration* vardecl;
        NMethodDeclaration* methoddecl;
        
        Stmt_list* stmt_list;
        Exps_list* exps_list;
        Decls_list* decls_list;
        Mhd_list* mhd_list;
        Id_list* id_list;
        Index_list* index_list;
        
        Type* type;
}

%{
#include "minipascal_driver.h"
#include "minipascal_scanner.h"

#undef yylex
#define yylex driver.lexer->lex
%}

%token EF 0
%token <integerVal> INTEGER
%token <doubleVal> REAL
%token <stringVal> STRING
%token INTEGER_T REAL_T STRING_T
%token <stringVal>ID 
%token PROGRAM OF FUNCTION PROCEDURE BEGAN END ARRAY VAR IF THEN ELSE WHILE DO
%token SEMICOLON COLON RANGE COMMA LPAREN RPAREN ASSIGN L_SQUARE_BRACKET R_SQUARE_BRACKET
%token LT GT EQ LE GE NE
%token PLUS MINUS MUL DIV NOT
%token EOL PERIOD 

%type <id_list> identifier_list
%type <decls_list> declarations
%type <type> standard_type
%type <type> type
%type <mhd_list> subprogram_declarations
%type <methoddecl> subprogram_declaration
%type <methoddecl> subprogram_head
%type <decls_list> arguments
%type <decls_list> parameter_list
%type <exps_list> expression_list
%type <block> compound_statement
%type <stmt_list> optional_statements
%type <stmt_list> statement_list
%type <stmt> statement
%type <var> variable
%type <exps_list> tail
%type <methodcall> procedure_statement
%type <exps> expression simple_expression term factor
%type <op> addop mulop relop
%type <value> num

%right ASSIGN
%left PLUS MINUS MUL DIV NOT LT GT EQ LE GE NE

%%

start 
        : PROGRAM ID 
        {
                driver.program = new NProgram();
                driver.program->setName($2);
                driver.program->setLineNo(yylloc.begin.line);
        }
        LPAREN identifier_list RPAREN SEMICOLON declarations subprogram_declarations compound_statement PERIOD
        {
                driver.program->setIds($5);
                driver.program->setDecls($8);
                driver.program->setMhds($9);
                driver.program->setBlock($10);
        }
        ;
	

identifier_list 
        : ID
        {
                $$ = new Id_list();
                $$->push_back($1);
        }
        | identifier_list COMMA ID
        {
                $1->push_back($3);
                $$ = $1;
        }
        | identifier_list error 
	{
                error(yylloc, " Error: miss ','");
	}
	ID
        {
                $1->push_back($4);
                $$ = $1;
        }
        ;

declarations	
        : declarations VAR identifier_list COLON type SEMICOLON
        {
                NVariableDeclaration* declaration;
                ShareNVariableDeclaration sharedeclaration;
                for(Id_list::iterator it = $3->begin(); it != $3->end(); ++it)
                {
                        sharedeclaration = ShareNVariableDeclaration(new NVariableDeclaration(*it, $5));
                        sharedeclaration->setLineNo(yylloc.begin.line);
                        $1->push_back(sharedeclaration);
                }
                $$ = $1;
        }
        | 
        {
                $$ = new Decls_list();
        }
        | declarations error identifier_list COLON type SEMICOLON
        {
                error(yylloc, " Error: miss keyword : var");
        }
        | declarations VAR identifier_list error 
	{
                error(yylloc, " Error: miss ':'");
	}
	type SEMICOLON
        {
        }
        | declarations VAR identifier_list COLON type error
        {
                error(yylloc, " Error: miss ';'");
        }
        ;

type	
        : standard_type
        {
                $$ = $1;
        }
        | ARRAY L_SQUARE_BRACKET INTEGER RANGE INTEGER R_SQUARE_BRACKET OF type
        {
                ArrayType* temp = new ArrayType($8);
                ArrayType::Range range = ArrayType::Range($3, $5);
                temp->setRange(range);
                $$ = temp;
        }
        | ARRAY error INTEGER RANGE INTEGER R_SQUARE_BRACKET OF type
        {
                error(yylloc, " Error: miss '['");
        }
        | ARRAY L_SQUARE_BRACKET INTEGER error INTEGER R_SQUARE_BRACKET OF type
        {
                error(yylloc, " Error: miss '..'");
        }
        | ARRAY L_SQUARE_BRACKET INTEGER RANGE INTEGER error OF type
        {
                error(yylloc, " Error: miss ']'");
        }
        | ARRAY L_SQUARE_BRACKET INTEGER RANGE INTEGER R_SQUARE_BRACKET error type
        {
                error(yylloc, " Error: miss keyword : of");
        }
        ;

standard_type	
        : INTEGER_T
        {
                $$ = new IntType();
        }
        | REAL_T
        {
                $$ = new RealType();
        }
        ;

subprogram_declarations	
        : subprogram_declarations subprogram_declaration SEMICOLON
        {
                ShareNMethodDeclaration share = ShareNMethodDeclaration($2);
                $1->push_back(share);
                $$ = $1;
        }
        |
        {
                $$ = new Mhd_list();
        }
        | subprogram_declarations subprogram_declaration error 
        {
                error(yylloc, " Error: miss ';'");
        }
        ;

subprogram_declaration	
        : subprogram_head declarations compound_statement
        {
                $1->setDecl($2);
                $1->setBlock($3);
                $$ = $1;
        }
        ;

subprogram_head	
        : FUNCTION ID arguments COLON standard_type SEMICOLON
        {
                $$ = new NMethodDeclaration();
                $$->setName($2);
                $$->setArgs($3);
                $$->setType($5);
                $$->setLineNo(yylloc.begin.line);
        }
        | PROCEDURE ID arguments SEMICOLON
        {
                VoidType* temp = new VoidType();
                $$ = new NMethodDeclaration();
                $$->setName($2);
                $$->setArgs($3);
                $$->setType(temp);
                $$->setLineNo(yylloc.begin.line);
        }
        ;

arguments	
        : LPAREN parameter_list RPAREN
        {
                $$ = $2;
        }
        |
        {
                $$ = new Decls_list();
        }
        | LPAREN parameter_list error
        {
                error(yylloc, " Error: miss ')'");
        }
        ;

parameter_list	
        : identifier_list COLON type
        {
                $$ = new Decls_list();
                NVariableDeclaration* declaration;
                ShareNVariableDeclaration sharedeclaration;
                for(Id_list::iterator it = $1->begin(); it != $1->end(); ++it)
                {
                        sharedeclaration = ShareNVariableDeclaration(new NVariableDeclaration(*it, $3));
                        $$->push_back(sharedeclaration);
                }
        }
        | parameter_list SEMICOLON identifier_list COLON type
        {
                NVariableDeclaration* declaration;
                ShareNVariableDeclaration sharedeclaration;
                for(Id_list::iterator it = $3->begin(); it != $3->end(); ++it)
                {
                        sharedeclaration = ShareNVariableDeclaration(new NVariableDeclaration(*it, $5));
                        $1->push_back(sharedeclaration);
                }
                $$ = $1;
        }
        | identifier_list error 
        {
                error(yylloc, " Error: miss ':'");
        }
        type
        {
        }
        | parameter_list error 
        {
                error(yylloc, " Error: miss ';'");
        }
        identifier_list COLON type
        {
        }
        | parameter_list SEMICOLON identifier_list error 
        {
                error(yylloc, " Error: miss ':'");
        }
        type
        {
        }
        ;

compound_statement	
        : BEGAN optional_statements END
        {
                $$ = new NBlock($2);
        }
        | BEGAN optional_statements error
        {
                error(yylloc, " Error: miss keyword : end");
        }
        ;

optional_statements 
        : statement_list
        {
                $$ = $1;
        }
        |
        {
                $$ = new Stmt_list();
        }
        ;

statement_list	
        : statement
        {
                $$ = new Stmt_list();
                $$->push_back(ShareNStatement($1));
        }
        | statement_list SEMICOLON statement
        {
                $1->push_back(ShareNStatement($3));
                $$ = $1;
        }
        ;

statement	
        : variable ASSIGN expression
        {
                $$ = new NAssignment($1, $3);
        }
        | procedure_statement
        {
                NStatementExpression* temp = new NStatementExpression($1);
                $$ = temp;
        }
        | compound_statement
        {
                $$ = $1;
        }
        | IF expression THEN statement ELSE statement
        {
                $$ = new NControl($2, $4, $6);
        }
        | WHILE expression DO statement
        {
                $$ = new NLoop($2, $4);
        }
        | IF expression error statement ELSE statement
        {
                error(yylloc, " Error: miss keyword : then");
        }
        | IF expression THEN statement error statement
        {
                error(yylloc, " Error: miss keyword : else");
        }
        | WHILE expression error statement
        {
                error(yylloc, " Error: miss keyword : do");
        }
        ;

variable	
        : ID tail
        {
                $$ = new NVariable();
                $$->setName($1);
                $$->setExps($2);
        }
        ;

tail	
        : L_SQUARE_BRACKET expression R_SQUARE_BRACKET tail
        {
                ShareNExpression shareexpression = ShareNExpression($2);
                $4->push_front(shareexpression);
                $$ = $4;
        }
        |
        {
                $$ = new Exps_list();
        }
        | L_SQUARE_BRACKET expression error tail
        {
                error(yylloc, " Error: miss ']'");
        }
        ;

procedure_statement	
        : ID
        {
                $$ = new NMethodCall($1, new Exps_list());
        }
        | ID LPAREN expression_list RPAREN
        {
                $$ = new NMethodCall($1, $3);
        }
        | ID LPAREN expression_list error
        {
                error(yylloc, " Error: miss ')'");
        }
        ;

expression_list	
        : expression
        {
                $$ = new Exps_list();
                $$->push_back(ShareNExpression($1));
        }
        | expression_list COMMA expression
        {
                $1->push_back(ShareNExpression($3));
                $$ = $1;
        }
        | expression_list error expression
        {
                error(yylloc, " Error: miss ',' between two expressions");
        }
        ;

expression	
        : simple_expression
        {
                $$ = $1;
        }
        | simple_expression relop simple_expression
        {
                $$ = new NBinaryOperator($2, $1, $3);
        }
        ;

simple_expression	
        : term
        {
                $$ = $1;
        }
        | simple_expression addop term
        {
                $$ = new NBinaryOperator($2, $1, $3);
        }
        ;

term	
	: factor
	{
                $$ = $1;
        }
	| term mulop factor
	{
                $$ = new NBinaryOperator($2, $1, $3);
        }
	;

factor	
	: ID tail
	{
                NVariable* var = new NVariable();
                var->setName($1);
                var->setExps($2);
                $$ = var;
        }
	| ID LPAREN expression_list RPAREN
	{
                $$ = new NMethodCall($1, $3);
        }
	| num 
	{
                $$ = $1;
        }
	| STRING
	{
                $$ = new NString($1);
        }
	| LPAREN expression RPAREN
	{
                $$ = $2;
        }
	| NOT factor
	{
                $2->setOpposite();
                $$ = $2;
        }
	;

addop	
	: PLUS 
	{
                $$ = NBinaryOperator::ADD;
        }
	| MINUS
        {
                $$ = NBinaryOperator::SUB;
        }
	;
mulop	
	: MUL 
	{
                $$ = NBinaryOperator::MUL;
        }
	| DIV
        {
                $$ = NBinaryOperator::DIV;
        }
	;

relop	
	: LT
	{
                $$ = NBinaryOperator::LT;
        }
	| GT
	{
                $$ = NBinaryOperator::GT;
        }
	| EQ
	{
                $$ = NBinaryOperator::EQ;
        }
	| LE
	{
                $$ = NBinaryOperator::LE;
        }
	| GE
	{
                $$ = NBinaryOperator::GE;
        }
	| NE
	{
                $$ = NBinaryOperator::NE;
        }
	;

num	
	: INTEGER
	{
                $$ = new NInt($1);
        }
	| REAL
	{
                $$ = new NDouble($1);
        }
	| MINUS INTEGER
	{
                $$ = new NInt(-$2);
        }
	| MINUS REAL
	{
                $$ = new NDouble(-$2);
        }
	;
%%

void minipascal::Parser::error(const Parser::location_type& l, const std::string& m)
{
	driver.error(l, m);
}
