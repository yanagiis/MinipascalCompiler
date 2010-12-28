/* A Bison parser, made by GNU Bison 2.4.3.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010 Free
   Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

// Take the name prefix into account.
#define yylex   minipascallex

/* First part of user declarations.  */

/* Line 311 of lalr1.cc  */
#line 1 "minipascal_parser.yy"

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


/* Line 311 of lalr1.cc  */
#line 71 "minipascal_parser.cpp"


#include "minipascal_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 78 "minipascal_parser.yy"

#include "minipascal_driver.h"
#include "minipascal_scanner.h"

#undef yylex
#define yylex driver.lexer->lex


/* Line 317 of lalr1.cc  */
#line 89 "minipascal_parser.cpp"

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace minipascal {

/* Line 380 of lalr1.cc  */
#line 155 "minipascal_parser.cpp"
#if YYERROR_VERBOSE

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              /* Fall through.  */
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

#endif

  /// Build a parser object.
  Parser::Parser (class Driver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {
  }

  Parser::~Parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  Parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  Parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  Parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
  
	default:
	  break;
      }
  }

  void
  Parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  int
  Parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[3];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    
/* Line 553 of lalr1.cc  */
#line 37 "minipascal_parser.yy"
{
	yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}

/* Line 553 of lalr1.cc  */
#line 338 "minipascal_parser.cpp"

    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yyn == yypact_ninf_)
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, &yylloc);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yyn == 0 || yyn == yytable_ninf_)
	goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 2:

/* Line 678 of lalr1.cc  */
#line 126 "minipascal_parser.yy"
    {
                driver.program = new NPorgram();
                driver.program->setName((yysemantic_stack_[(2) - (2)].stringVal));
                driver.program->setLineNo(yylloc->begin.line);
        }
    break;

  case 3:

/* Line 678 of lalr1.cc  */
#line 132 "minipascal_parser.yy"
    {
                dirver.program->setIds((yysemantic_stack_[(11) - (5)].id_list));
                driver.program->setDecls((yysemantic_stack_[(11) - (8)].decls_list));
                driver.program->setMhds((yysemantic_stack_[(11) - (9)].mhd_list));
                driver.program->setBlock((yysemantic_stack_[(11) - (10)].block));
        }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 143 "minipascal_parser.yy"
    {
                (yyval.id_list) = new Id_list();
                (yyval.id_list)->push_back((yysemantic_stack_[(1) - (1)].stringVal));
        }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 148 "minipascal_parser.yy"
    {
                (yysemantic_stack_[(3) - (1)].id_list)->push_back((yysemantic_stack_[(3) - (3)].stringVal));
                (yyval.id_list) = (yysemantic_stack_[(3) - (1)].id_list);
        }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 153 "minipascal_parser.yy"
    {
                error(yylloc, " Error: miss ','");
	}
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 157 "minipascal_parser.yy"
    {
                (yysemantic_stack_[(4) - (1)].id_list)->push_back((yysemantic_stack_[(4) - (4)].stringVal));
                (yyval.id_list) = (yysemantic_stack_[(4) - (1)].id_list);
        }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 165 "minipascal_parser.yy"
    {
                NVariableDeclaration* declaration;
                for(Id_list::iterator it = (yysemantic_stack_[(6) - (3)].id_list)->begin(); it != (yysemantic_stack_[(6) - (3)].id_list)->end(); ++it)
                {
                        declaration = new NVariableDeclaration(*it, (yysemantic_stack_[(6) - (5)].type));
                        declaration->setLineNo(yylloc->begin.line);
                        (yysemantic_stack_[(6) - (1)].decls_list)->push_back(declaration);
                }
                (yyval.decls_list) = (yysemantic_stack_[(6) - (1)].decls_list);
        }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 176 "minipascal_parser.yy"
    {
                (yyval.decls_list) = new Decls_list();
        }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 180 "minipascal_parser.yy"
    {
                error(yylloc, " Error: miss keyword : var");
        }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 184 "minipascal_parser.yy"
    {
                error(yylloc, " Error: miss ':'");
	}
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 188 "minipascal_parser.yy"
    {
        }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 191 "minipascal_parser.yy"
    {
                error(yylloc, " Error: miss ';'");
        }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 198 "minipascal_parser.yy"
    {
                (yyval.type) = (yysemantic_stack_[(1) - (1)].type);
        }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 202 "minipascal_parser.yy"
    {
                ArrayType* temp = new ArrayType((yysemantic_stack_[(8) - (8)].type));
                ArrayType::Range range = ArrayType::Range((yysemantic_stack_[(8) - (3)].integerVal), (yysemantic_stack_[(8) - (5)].integerVal));
                temp->setRange(range);
                (yyval.type) = temp;
        }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 209 "minipascal_parser.yy"
    {
                error(yylloc, " Error: miss '['");
        }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 213 "minipascal_parser.yy"
    {
                error(yylloc, " Error: miss '..'");
        }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 217 "minipascal_parser.yy"
    {
                error(yylloc, " Error: miss ']'");
        }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 221 "minipascal_parser.yy"
    {
                error(yylloc, " Error: miss keyword : of");
        }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 228 "minipascal_parser.yy"
    {
                (yyval.type) = new Type();
                (yyval.type)->setBuildInType(INT_T);
        }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 233 "minipascal_parser.yy"
    {
                (yyval.type) = new Type();
                (yyval.type)->setBuildInType(DOUBLE_T);
        }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 241 "minipascal_parser.yy"
    {
                (yysemantic_stack_[(3) - (1)].mhd_list)->push_back((yysemantic_stack_[(3) - (2)].methoddecl));
                (yyval.mhd_list) = (yysemantic_stack_[(3) - (1)].mhd_list);
        }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 246 "minipascal_parser.yy"
    {
                (yyval.mhd_list) = new Mhd_list();
        }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 250 "minipascal_parser.yy"
    {
                (yysemantic_stack_[(3) - (1)].mhd_list)->push_back((yysemantic_stack_[(3) - (2)].methoddecl));
                (yyval.mhd_list) = (yysemantic_stack_[(3) - (1)].mhd_list);
                error(yylloc, " Error: miss ';'");
        }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 259 "minipascal_parser.yy"
    {
                (yysemantic_stack_[(3) - (1)].methoddecl)->setDecl((yysemantic_stack_[(3) - (2)].decls_list));
                (yysemantic_stack_[(3) - (1)].methoddecl)->setBlock((yysemantic_stack_[(3) - (3)].block));
                (yyval.methoddecl) = (yysemantic_stack_[(3) - (1)].methoddecl);
        }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 268 "minipascal_parser.yy"
    {
                (yyval.methoddecl) = new NMethodDeclaration((yysemantic_stack_[(6) - (2)].stringVal), (yysemantic_stack_[(6) - (3)].decls_list), (yysemantic_stack_[(6) - (5)].type));
        }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 272 "minipascal_parser.yy"
    {
                Type* temp = new Type();
                temp->setBuildInType(VOID_T);
                (yyval.methoddecl) = new NMethodDeclaration((yysemantic_stack_[(4) - (2)].stringVal), (yysemantic_stack_[(4) - (3)].decls_list), temp);
        }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 281 "minipascal_parser.yy"
    {
                (yyval.decls_list) = (yysemantic_stack_[(3) - (2)].decls_list);
        }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 285 "minipascal_parser.yy"
    {
                (yyval.decls_list) = new Decls_list();
        }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 289 "minipascal_parser.yy"
    {
                error(yylloc, " Error: miss ')'");
        }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 296 "minipascal_parser.yy"
    {
                (yyval.decls_list) = new Decls_list();
                NVariableDeclaration* declaration;
                for(Id_list::iterator it = (yysemantic_stack_[(3) - (1)].id_list)->begin(); it != (yysemantic_stack_[(3) - (1)].id_list)->end(); ++it)
                {
                        declaration = new NVariableDeclaration(*it, (yysemantic_stack_[(3) - (3)].type));
                        (yyval.decls_list)->push_back(declaration);
                }
        }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 306 "minipascal_parser.yy"
    {
                NVariableDeclaration* declaration;
                for(Id_list::iterator it = (yysemantic_stack_[(5) - (3)].id_list)->begin(); it != (yysemantic_stack_[(5) - (3)].id_list)->end(); ++it)
                {
                        declaration = new NVariableDeclaration(*it, (yysemantic_stack_[(5) - (5)].type));
                        (yysemantic_stack_[(5) - (1)].decls_list)->push_back(declaration);
                }
                (yyval.decls_list) = (yysemantic_stack_[(5) - (1)].decls_list);
        }
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 316 "minipascal_parser.yy"
    {
                error(yylloc, " Error: miss ':'");
        }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 320 "minipascal_parser.yy"
    {
        }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 323 "minipascal_parser.yy"
    {
                error(yylloc, " Error: miss ';'");
        }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 327 "minipascal_parser.yy"
    {
        }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 330 "minipascal_parser.yy"
    {
                error(yylloc, " Error: miss ':'");
        }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 334 "minipascal_parser.yy"
    {
        }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 340 "minipascal_parser.yy"
    {
                (yyval.block) = new NBlock((yysemantic_stack_[(3) - (2)].stmt_list));
        }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 344 "minipascal_parser.yy"
    {
                error(yylloc, " Error: miss keyword : end");
        }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 351 "minipascal_parser.yy"
    {
                (yyval.stmt_list) = (yysemantic_stack_[(1) - (1)].stmt_list);
        }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 355 "minipascal_parser.yy"
    {
                (yyval.stmt_list) = new Stmt_list();
        }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 362 "minipascal_parser.yy"
    {
                (yyval.stmt_list) = new Stmt_list();
                (yyval.stmt_list)->push_back((yysemantic_stack_[(1) - (1)].stmt));
        }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 367 "minipascal_parser.yy"
    {
                (yysemantic_stack_[(3) - (1)].stmt_list)->push_back((yysemantic_stack_[(3) - (3)].stmt));
                (yyval.stmt_list) = (yysemantic_stack_[(3) - (1)].stmt_list);
        }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 375 "minipascal_parser.yy"
    {
                (yyval.stmt) = new NAssignment((yysemantic_stack_[(3) - (1)].var), (yysemantic_stack_[(3) - (3)].exps));
        }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 379 "minipascal_parser.yy"
    {
                NStatementExpression* temp = new NStatementExpression((yysemantic_stack_[(1) - (1)].methodcall));
                (yyval.stmt) = temp;
        }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 384 "minipascal_parser.yy"
    {
                (yyval.stmt) = (yysemantic_stack_[(1) - (1)].block);
        }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 388 "minipascal_parser.yy"
    {
                (yyval.stmt) = new NControl((yysemantic_stack_[(6) - (2)].exps), (yysemantic_stack_[(6) - (4)].stmt), (yysemantic_stack_[(6) - (6)].stmt));
        }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 392 "minipascal_parser.yy"
    {
                (yyval.stmt) = new NLoop((yysemantic_stack_[(4) - (2)].exps), (yysemantic_stack_[(4) - (4)].stmt));
        }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 396 "minipascal_parser.yy"
    {
                error(yylloc, " Error: miss keyword : then");
        }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 400 "minipascal_parser.yy"
    {
                error(yylloc, " Error: miss keyword : else");
        }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 404 "minipascal_parser.yy"
    {
                error(yylloc, " Error: miss keyword : do");
        }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 411 "minipascal_parser.yy"
    {
                (yyval.var) = new NVariable((yysemantic_stack_[(2) - (1)].stringVal));
                (yyval.var)->setExps((yysemantic_stack_[(2) - (2)].exps_list));
        }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 419 "minipascal_parser.yy"
    {
                (yysemantic_stack_[(4) - (4)].exps_list)->push_front((yysemantic_stack_[(4) - (2)].exps));
                (yyval.exps_list) = (yysemantic_stack_[(4) - (4)].exps_list);
        }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 424 "minipascal_parser.yy"
    {
                (yyval.exps_list) = new Exps_list();
        }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 428 "minipascal_parser.yy"
    {
                error(yylloc, " Error: miss ']'");
        }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 435 "minipascal_parser.yy"
    {
                (yyval.methodcall) = new NMethodCall((yysemantic_stack_[(1) - (1)].stringVal), new Exps_list());
        }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 439 "minipascal_parser.yy"
    {
                (yyval.methodcall) = new NMethodCall((yysemantic_stack_[(4) - (1)].stringVal), (yysemantic_stack_[(4) - (3)].exps_list));
        }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 443 "minipascal_parser.yy"
    {
                error(yylloc, " Error: miss ')'");
        }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 450 "minipascal_parser.yy"
    {
                (yyval.exps_list) = new Exps_list();
                (yyval.exps_list)->push_back((yysemantic_stack_[(1) - (1)].exps));
        }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 455 "minipascal_parser.yy"
    {
                (yysemantic_stack_[(3) - (1)].exps_list)->push_back((yysemantic_stack_[(3) - (3)].exps));
                (yyval.exps_list) = (yysemantic_stack_[(3) - (1)].exps_list);
        }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 460 "minipascal_parser.yy"
    {
                error(yylloc, " Error: miss ',' between two expressions");
        }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 467 "minipascal_parser.yy"
    {
                (yyval.exps) = (yysemantic_stack_[(1) - (1)].exps);
        }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 471 "minipascal_parser.yy"
    {
                (yyval.exps) = new NBinaryOperator((yysemantic_stack_[(3) - (1)].exps), (yysemantic_stack_[(3) - (2)].op), (yysemantic_stack_[(3) - (3)].exps));
        }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 478 "minipascal_parser.yy"
    {
                (yyval.exps) = (yysemantic_stack_[(1) - (1)].exps);
        }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 482 "minipascal_parser.yy"
    {
                (yyval.exps) = new NBinaryOperator((yysemantic_stack_[(3) - (1)].exps), (yysemantic_stack_[(3) - (2)].op), (yysemantic_stack_[(3) - (3)].exps));
        }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 489 "minipascal_parser.yy"
    {
                (yyval.exps) = (yysemantic_stack_[(1) - (1)].exps);
        }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 493 "minipascal_parser.yy"
    {
                (yyval.exps) = new NBinaryOperator((yysemantic_stack_[(3) - (1)].exps), (yysemantic_stack_[(3) - (2)].op), (yysemantic_stack_[(3) - (3)].exps));
        }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 500 "minipascal_parser.yy"
    {
                NVariable* var = new NVariable((yysemantic_stack_[(2) - (1)].stringVal));
                var->setExps((yysemantic_stack_[(2) - (2)].exps_list));
                (yyval.exps) = var;
        }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 506 "minipascal_parser.yy"
    {
                (yyval.exps) = new NMethodCall((yysemantic_stack_[(4) - (1)].stringVal), (yysemantic_stack_[(4) - (3)].exps_list));
        }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 510 "minipascal_parser.yy"
    {
                (yyval.exps) = (yysemantic_stack_[(1) - (1)].value);
        }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 514 "minipascal_parser.yy"
    {
                (yyval.exps) = new NString(*(yysemantic_stack_[(1) - (1)].stringVal));
        }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 518 "minipascal_parser.yy"
    {
                (yyval.exps) = (yysemantic_stack_[(3) - (2)].exps);
        }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 522 "minipascal_parser.yy"
    {
                (yysemantic_stack_[(2) - (2)].exps)->setOpposite();
                (yyval.exps) = (yysemantic_stack_[(2) - (2)].exps);
        }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 530 "minipascal_parser.yy"
    {
                (yyval.op) = NBinaryOperator::ADD;
        }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 534 "minipascal_parser.yy"
    {
                (yyval.op) = NBinaryOperator::SUB;
        }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 540 "minipascal_parser.yy"
    {
                (yyval.op) = NBinaryOperator::MUL;
        }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 544 "minipascal_parser.yy"
    {
                (yyval.op) = NBinaryOperator::DIV;
        }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 551 "minipascal_parser.yy"
    {
                (yyval.op) = NBinaryOperator::LT;
        }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 555 "minipascal_parser.yy"
    {
                (yyval.op) = NBinaryOperator::GT;
        }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 559 "minipascal_parser.yy"
    {
                (yyval.op) = NBinaryOperator::EQ;
        }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 563 "minipascal_parser.yy"
    {
                (yyval.op) = NBinaryOperator::LE;
        }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 567 "minipascal_parser.yy"
    {
                (yyval.op) = NBinaryOperator::GE;
        }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 571 "minipascal_parser.yy"
    {
                (yyval.op) = NBinaryOperator::NE;
        }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 578 "minipascal_parser.yy"
    {
                (yyval.value) = new NInt((yysemantic_stack_[(1) - (1)].integerVal));
        }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 582 "minipascal_parser.yy"
    {
                (yyval.value) = new NDouble((yysemantic_stack_[(1) - (1)].doubleVal));
        }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 586 "minipascal_parser.yy"
    {
                (yyval.value) = new NInt(-(yysemantic_stack_[(2) - (2)].integerVal));
        }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 590 "minipascal_parser.yy"
    {
                (yyval.value) = new NDouble(-(yysemantic_stack_[(2) - (2)].doubleVal));
        }
    break;



/* Line 678 of lalr1.cc  */
#line 1285 "minipascal_parser.cpp"
	default:
          break;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[1] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
	  }
      }

    /* Else will try to reuse lookahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[1] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (yyn != yypact_ninf_)
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[1] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[2] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval, &yylloc);

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (int yystate, int tok)
  {
    std::string res;
    YYUSE (yystate);
#if YYERROR_VERBOSE
    int yyn = yypact_[yystate];
    if (yypact_ninf_ < yyn && yyn <= yylast_)
      {
	/* Start YYX at -YYN if negative to avoid negative indexes in
	   YYCHECK.  */
	int yyxbegin = yyn < 0 ? -yyn : 0;

	/* Stay within bounds of both yycheck and yytname.  */
	int yychecklim = yylast_ - yyn + 1;
	int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
	int count = 0;
	for (int x = yyxbegin; x < yyxend; ++x)
	  if (yycheck_[x + yyn] == x && x != yyterror_)
	    ++count;

	// FIXME: This method of building the message is not compatible
	// with internationalization.  It should work like yacc.c does it.
	// That is, first build a string that looks like this:
	// "syntax error, unexpected %s or %s or %s"
	// Then, invoke YY_ on this string.
	// Finally, use the string as a format to output
	// yytname_[tok], etc.
	// Until this gets fixed, this message appears in English only.
	res = "syntax error, unexpected ";
	res += yytnamerr_ (yytname_[tok]);
	if (count < 5)
	  {
	    count = 0;
	    for (int x = yyxbegin; x < yyxend; ++x)
	      if (yycheck_[x + yyn] == x && x != yyterror_)
		{
		  res += (!count++) ? ", expecting " : " or ";
		  res += yytnamerr_ (yytname_[x]);
		}
	  }
      }
    else
#endif
      res = YY_("syntax error");
    return res;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const signed char Parser::yypact_ninf_ = -70;
  const short int
  Parser::yypact_[] =
  {
        60,    83,    25,   -70,   -70,    71,    86,   -70,    21,   -70,
      91,   101,   116,   -70,   -70,   -70,    90,    86,    86,    54,
      35,    38,   117,   119,    92,    59,   -70,    85,   102,   121,
     102,   105,   105,    87,     6,     6,   -70,    16,   110,   -70,
     106,   -70,   -70,   -70,    98,   -70,   -70,   -70,    11,   111,
     -70,   102,    64,    86,   112,   118,     6,     6,   -70,   -70,
     -70,   -70,    -7,     6,    77,     6,    78,   115,   -22,   -70,
     -70,    68,   -70,   -70,    92,     6,   -70,   134,   135,   -70,
     132,   -70,   -70,    49,    12,   114,   -70,    28,   -70,     7,
       6,   -70,   128,   -70,   -70,   -70,    92,    92,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,     6,     6,   -70,   -70,
       6,    92,    92,   -70,   -70,   133,    33,   -70,   121,   102,
     148,    86,   -70,   136,     6,     6,   -70,   130,   130,    29,
     -70,   141,    76,   -22,    84,   -70,   -70,   -70,   159,   160,
     161,   102,   -70,    86,    50,   -70,   -70,   -70,   -70,   -70,
       6,   -70,    92,    92,    92,   137,   138,    15,   -70,    62,
     121,   102,   -70,   -70,   -70,   154,   155,   156,    13,   102,
     102,   -70,   102,   102,   102,   102,   102,   -70,   -70,   -70,
     -70,   -70,   -70,   -70
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  Parser::yydefact_[] =
  {
         0,     0,     0,     2,     1,     0,     0,     4,     0,     6,
       0,     0,     0,     5,     9,     7,     0,     0,     0,     0,
       0,     0,     0,     0,    42,     0,     9,     0,     0,    11,
       0,    29,    29,    57,     0,     0,    47,     0,    41,    43,
       0,    46,    24,    22,     0,     3,    20,    21,     0,     0,
      14,     0,     0,     0,     0,     0,     0,     0,    53,    85,
      86,    72,    55,     0,     0,     0,     0,    63,    65,    67,
      71,     0,    40,    39,     0,     0,    25,     0,     0,    10,
       0,    13,     8,     0,     0,     0,    27,     0,    60,     0,
       0,    69,     0,    87,    88,    74,     0,     0,    79,    80,
      81,    82,    83,    84,    75,    76,     0,     0,    77,    78,
       0,     0,     0,    44,    45,     0,     0,    12,    33,     0,
      30,     0,    28,     0,    59,     0,    58,    55,    55,     0,
      73,     0,     0,    66,    64,    68,    52,    49,     0,     0,
       0,     0,    31,     0,     0,    26,    62,    61,    56,    54,
       0,    70,     0,     0,     0,     0,     0,     0,    34,     0,
      37,     0,    50,    51,    48,     0,     0,     0,     0,     0,
       0,    32,     0,     0,     0,     0,     0,    36,    38,    16,
      17,    18,    19,    15
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
       -70,   -70,   -70,   -16,   -70,   144,   -70,   -30,    88,   -70,
     -70,   -70,   139,   -70,   -70,   -70,   -70,    34,   -70,   -70,
     -69,   -70,   -56,   -70,    82,   -31,    67,    69,   -58,   -70,
     -70,   -70,   -70
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,     2,     5,     8,    12,    16,    51,    49,    50,    19,
      25,    26,    54,    84,   141,   143,   170,    36,    37,    38,
      39,    40,    58,    41,    87,    88,    67,    68,    69,   106,
     110,   107,    70
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Parser::yytable_ninf_ = -56;
  const short int
  Parser::yytable_[] =
  {
        52,    20,    21,    66,    71,   113,    91,    95,   127,    59,
      60,    61,    77,   120,   175,    62,   167,    72,   108,   109,
      90,    80,     9,    57,   176,     4,    89,   131,   132,   124,
     150,    73,    92,    63,   139,   121,     9,    83,   128,    29,
     122,    78,   136,   137,   114,    64,   168,    10,    65,    11,
     118,   160,   135,    27,   125,   125,   126,   151,   140,    28,
      42,    10,    30,     9,    10,    81,    22,    23,    24,   111,
       1,   148,   149,   119,   161,    10,    10,   153,    76,    96,
      93,    94,    43,   162,   163,   164,   169,    82,    10,   142,
     112,    17,     3,   146,   147,     7,   154,    97,     6,    17,
      13,    33,   -23,   -23,   -23,   144,    24,    18,    46,    47,
      34,   158,    24,    35,    56,    18,   -55,    57,    48,   146,
      46,    47,   104,   105,    14,    15,    31,   159,    32,    45,
      -6,   171,    53,    74,    79,    75,    85,   115,   116,   177,
     178,    86,   179,   180,   181,   182,   183,    98,    99,   100,
     101,   102,   103,   104,   105,   117,   130,   -35,   138,   145,
      57,   152,   155,   156,   157,   172,   173,   174,   165,   166,
      44,    55,   129,   123,   134,   133
  };

  /* YYCHECK.  */
  const unsigned char
  Parser::yycheck_[] =
  {
        30,    17,    18,    34,    35,    74,    62,    65,     1,     3,
       4,     5,     1,     1,     1,     9,     1,     1,    40,    41,
      27,    51,     1,    30,    11,     0,    57,    96,    97,     1,
       1,    15,    63,    27,     1,    23,     1,    53,    31,     1,
      28,    30,   111,   112,    75,    39,    31,    26,    42,    28,
       1,     1,   110,    19,    26,    26,    28,    28,    25,    24,
       1,    26,    24,     1,    26,     1,    12,    13,    14,     1,
      10,   127,   128,    24,    24,    26,    26,     1,    44,     1,
       3,     4,    23,   152,   153,   154,    24,    23,    26,   119,
      22,     1,     9,   124,   125,     9,    20,    19,    27,     1,
       9,     9,    12,    13,    14,   121,    14,    17,     6,     7,
      18,   141,    14,    21,    27,    17,    29,    30,    16,   150,
       6,     7,    38,    39,    23,     9,     9,   143,     9,    44,
       9,   161,    27,    23,    23,    29,    24,     3,     3,   169,
     170,    23,   172,   173,   174,   175,   176,    32,    33,    34,
      35,    36,    37,    38,    39,    23,    28,     9,    25,    23,
      30,    20,     3,     3,     3,    11,    11,    11,    31,    31,
      26,    32,    90,    85,   107,   106
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Parser::yystos_[] =
  {
         0,    10,    46,     9,     0,    47,    27,     9,    48,     1,
      26,    28,    49,     9,    23,     9,    50,     1,    17,    54,
      48,    48,    12,    13,    14,    55,    56,    62,    24,     1,
      24,     9,     9,     9,    18,    21,    62,    63,    64,    65,
      66,    68,     1,    23,    50,    44,     6,     7,    16,    52,
      53,    51,    52,    27,    57,    57,    27,    30,    67,     3,
       4,     5,     9,    27,    39,    42,    70,    71,    72,    73,
      77,    70,     1,    15,    23,    29,    62,     1,    30,    23,
      52,     1,    23,    48,    58,    24,    23,    69,    70,    70,
      27,    67,    70,     3,     4,    73,     1,    19,    32,    33,
      34,    35,    36,    37,    38,    39,    74,    76,    40,    41,
      75,     1,    22,    65,    70,     3,     3,    23,     1,    24,
       1,    23,    28,    53,     1,    26,    28,     1,    31,    69,
      28,    65,    65,    72,    71,    73,    65,    65,    25,     1,
      25,    59,    52,    60,    48,    23,    70,    70,    67,    67,
       1,    28,    20,     1,    20,     3,     3,     3,    52,    48,
       1,    24,    65,    65,    65,    31,    31,     1,    31,    24,
      61,    52,    11,    11,    11,     1,    11,    52,    52,    52,
      52,    52,    52,    52
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  Parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Parser::yyr1_[] =
  {
         0,    45,    47,    46,    48,    48,    49,    48,    50,    50,
      50,    51,    50,    50,    52,    52,    52,    52,    52,    52,
      53,    53,    54,    54,    54,    55,    56,    56,    57,    57,
      57,    58,    58,    59,    58,    60,    58,    61,    58,    62,
      62,    63,    63,    64,    64,    65,    65,    65,    65,    65,
      65,    65,    65,    66,    67,    67,    67,    68,    68,    68,
      69,    69,    69,    70,    70,    71,    71,    72,    72,    73,
      73,    73,    73,    73,    73,    74,    74,    75,    75,    76,
      76,    76,    76,    76,    76,    77,    77,    77,    77
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     0,    11,     1,     3,     0,     4,     6,     0,
       6,     0,     7,     6,     1,     8,     8,     8,     8,     8,
       1,     1,     3,     0,     3,     3,     6,     4,     3,     0,
       3,     3,     5,     0,     4,     0,     6,     0,     6,     3,
       3,     1,     0,     1,     3,     3,     1,     1,     6,     4,
       6,     6,     4,     2,     4,     0,     4,     1,     4,     4,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     2,
       4,     1,     1,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Parser::yytname_[] =
  {
    "EF", "error", "$undefined", "INTEGER", "REAL", "STRING", "INTEGER_T",
  "REAL_T", "STRING_T", "ID", "PROGRAM", "OF", "FUNCTION", "PROCEDURE",
  "BEGAN", "END", "ARRAY", "VAR", "IF", "THEN", "ELSE", "WHILE", "DO",
  "SEMICOLON", "COLON", "RANGE", "COMMA", "LPAREN", "RPAREN", "ASSIGN",
  "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "LT", "GT", "EQ", "LE", "GE",
  "NE", "PLUS", "MINUS", "MUL", "DIV", "NOT", "EOL", "PERIOD", "$accept",
  "start", "$@1", "identifier_list", "$@2", "declarations", "$@3", "type",
  "standard_type", "subprogram_declarations", "subprogram_declaration",
  "subprogram_head", "arguments", "parameter_list", "$@4", "$@5", "$@6",
  "compound_statement", "optional_statements", "statement_list",
  "statement", "variable", "tail", "procedure_statement",
  "expression_list", "expression", "simple_expression", "term", "factor",
  "addop", "mulop", "relop", "num", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
        46,     0,    -1,    -1,    10,     9,    47,    27,    48,    28,
      23,    50,    54,    62,    44,    -1,     9,    -1,    48,    26,
       9,    -1,    -1,    48,     1,    49,     9,    -1,    50,    17,
      48,    24,    52,    23,    -1,    -1,    50,     1,    48,    24,
      52,    23,    -1,    -1,    50,    17,    48,     1,    51,    52,
      23,    -1,    50,    17,    48,    24,    52,     1,    -1,    53,
      -1,    16,    30,     3,    25,     3,    31,    11,    52,    -1,
      16,     1,     3,    25,     3,    31,    11,    52,    -1,    16,
      30,     3,     1,     3,    31,    11,    52,    -1,    16,    30,
       3,    25,     3,     1,    11,    52,    -1,    16,    30,     3,
      25,     3,    31,     1,    52,    -1,     6,    -1,     7,    -1,
      54,    55,    23,    -1,    -1,    54,    55,     1,    -1,    56,
      50,    62,    -1,    12,     9,    57,    24,    53,    23,    -1,
      13,     9,    57,    23,    -1,    27,    58,    28,    -1,    -1,
      27,    58,     1,    -1,    48,    24,    52,    -1,    58,    23,
      48,    24,    52,    -1,    -1,    48,     1,    59,    52,    -1,
      -1,    58,     1,    60,    48,    24,    52,    -1,    -1,    58,
      23,    48,     1,    61,    52,    -1,    14,    63,    15,    -1,
      14,    63,     1,    -1,    64,    -1,    -1,    65,    -1,    64,
      23,    65,    -1,    66,    29,    70,    -1,    68,    -1,    62,
      -1,    18,    70,    19,    65,    20,    65,    -1,    21,    70,
      22,    65,    -1,    18,    70,     1,    65,    20,    65,    -1,
      18,    70,    19,    65,     1,    65,    -1,    21,    70,     1,
      65,    -1,     9,    67,    -1,    30,    70,    31,    67,    -1,
      -1,    30,    70,     1,    67,    -1,     9,    -1,     9,    27,
      69,    28,    -1,     9,    27,    69,     1,    -1,    70,    -1,
      69,    26,    70,    -1,    69,     1,    70,    -1,    71,    -1,
      71,    76,    71,    -1,    72,    -1,    71,    74,    72,    -1,
      73,    -1,    72,    75,    73,    -1,     9,    67,    -1,     9,
      27,    69,    28,    -1,    77,    -1,     5,    -1,    27,    70,
      28,    -1,    42,    73,    -1,    38,    -1,    39,    -1,    40,
      -1,    41,    -1,    32,    -1,    33,    -1,    34,    -1,    35,
      -1,    36,    -1,    37,    -1,     3,    -1,     4,    -1,    39,
       3,    -1,    39,     4,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Parser::yyprhs_[] =
  {
         0,     0,     3,     4,    16,    18,    22,    23,    28,    35,
      36,    43,    44,    52,    59,    61,    70,    79,    88,    97,
     106,   108,   110,   114,   115,   119,   123,   130,   135,   139,
     140,   144,   148,   154,   155,   160,   161,   168,   169,   176,
     180,   184,   186,   187,   189,   193,   197,   199,   201,   208,
     213,   220,   227,   232,   235,   240,   241,   246,   248,   253,
     258,   260,   264,   268,   270,   274,   276,   280,   282,   286,
     289,   294,   296,   298,   302,   305,   307,   309,   311,   313,
     315,   317,   319,   321,   323,   325,   327,   329,   332
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   126,   126,   125,   142,   147,   153,   152,   164,   176,
     179,   184,   183,   190,   197,   201,   208,   212,   216,   220,
     227,   232,   240,   246,   249,   258,   267,   271,   280,   285,
     288,   295,   305,   316,   315,   323,   322,   330,   329,   339,
     343,   350,   355,   361,   366,   374,   378,   383,   387,   391,
     395,   399,   403,   410,   418,   424,   427,   434,   438,   442,
     449,   454,   459,   466,   470,   477,   481,   488,   492,   499,
     505,   509,   513,   517,   521,   529,   533,   539,   543,   550,
     554,   558,   562,   566,   570,   577,   581,   585,   589
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 175;
  const int Parser::yynnts_ = 33;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 4;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 45;

  const unsigned int Parser::yyuser_token_number_max_ = 299;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


} // minipascal

/* Line 1054 of lalr1.cc  */
#line 1867 "minipascal_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 594 "minipascal_parser.yy"


void minipascal::Parser::error(const Parser::location_type& l, const std::string& m)
{
	driver.error(l, m);
}

