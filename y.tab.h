/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IF = 258,                      /* IF  */
    ELSE = 259,                    /* ELSE  */
    FOR = 260,                     /* FOR  */
    WHILE = 261,                   /* WHILE  */
    INT = 262,                     /* INT  */
    FLOAT = 263,                   /* FLOAT  */
    VOID = 264,                    /* VOID  */
    RETURN = 265,                  /* RETURN  */
    ASSIGNOP = 266,                /* ASSIGNOP  */
    NOT = 267,                     /* NOT  */
    LPAREN = 268,                  /* LPAREN  */
    RPAREN = 269,                  /* RPAREN  */
    LCURL = 270,                   /* LCURL  */
    RCURL = 271,                   /* RCURL  */
    LTHIRD = 272,                  /* LTHIRD  */
    RTHIRD = 273,                  /* RTHIRD  */
    COMMA = 274,                   /* COMMA  */
    SEMICOLON = 275,               /* SEMICOLON  */
    PRINTLN = 276,                 /* PRINTLN  */
    ID = 277,                      /* ID  */
    ADDOP = 278,                   /* ADDOP  */
    INCOP = 279,                   /* INCOP  */
    DECOP = 280,                   /* DECOP  */
    MULOP = 281,                   /* MULOP  */
    RELOP = 282,                   /* RELOP  */
    LOGICOP = 283,                 /* LOGICOP  */
    CONST_INT = 284,               /* CONST_INT  */
    CONST_FLOAT = 285,             /* CONST_FLOAT  */
    LOWER_THAN_RPAREN = 286,       /* LOWER_THAN_RPAREN  */
    LOWER_THAN_ELSE = 287          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IF 258
#define ELSE 259
#define FOR 260
#define WHILE 261
#define INT 262
#define FLOAT 263
#define VOID 264
#define RETURN 265
#define ASSIGNOP 266
#define NOT 267
#define LPAREN 268
#define RPAREN 269
#define LCURL 270
#define RCURL 271
#define LTHIRD 272
#define RTHIRD 273
#define COMMA 274
#define SEMICOLON 275
#define PRINTLN 276
#define ID 277
#define ADDOP 278
#define INCOP 279
#define DECOP 280
#define MULOP 281
#define RELOP 282
#define LOGICOP 283
#define CONST_INT 284
#define CONST_FLOAT 285
#define LOWER_THAN_RPAREN 286
#define LOWER_THAN_ELSE 287

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "1805047.y"

	symbol_info* symbolValue;
	string *input_string;
	string *temp;

#line 137 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
