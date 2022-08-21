/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IF = 258,
     ELSE = 259,
     FOR = 260,
     WHILE = 261,
     INT = 262,
     FLOAT = 263,
     VOID = 264,
     RETURN = 265,
     ASSIGNOP = 266,
     NOT = 267,
     LPAREN = 268,
     RPAREN = 269,
     LCURL = 270,
     RCURL = 271,
     LTHIRD = 272,
     RTHIRD = 273,
     COMMA = 274,
     SEMICOLON = 275,
     PRINTLN = 276,
     ID = 277,
     ADDOP = 278,
     INCOP = 279,
     DECOP = 280,
     MULOP = 281,
     RELOP = 282,
     LOGICOP = 283,
     CONST_INT = 284,
     CONST_FLOAT = 285,
     LOWER_THAN_RPAREN = 286,
     LOWER_THAN_ELSE = 287
   };
#endif
/* Tokens.  */
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




/* Copy the first part of user declarations.  */
#line 1 "1805047.y"

#include<iostream>

#include<cstdlib>
#include<cstring>
#include<cmath>
#include "1805047_symbol_table.h"
#include "asmUtils.h"
#include "utils.h"


using namespace std;
int yyparse(void);
int yylex(void);
extern FILE *yyin;



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 19 "1805047.y"
{
	symbol_info* symbolValue;
	string *input_string;
	string *temp;
}
/* Line 193 of yacc.c.  */
#line 184 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 197 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   144

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNRULES -- Number of states.  */
#define YYNSTATES  131

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    12,    14,    16,    18,
      25,    31,    32,    40,    41,    48,    53,    57,    60,    62,
      63,    68,    69,    73,    77,    79,    81,    83,    87,    94,
      96,   101,   103,   106,   108,   110,   112,   113,   114,   115,
     126,   133,   143,   144,   145,   154,   160,   164,   165,   166,
     167,   169,   172,   174,   179,   181,   185,   187,   191,   193,
     197,   199,   203,   205,   209,   212,   215,   217,   219,   224,
     228,   230,   232,   235,   238,   240,   241,   245
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      34,     0,    -1,    -1,    35,    36,    -1,    36,    37,    -1,
      37,    -1,    46,    -1,    38,    -1,    39,    -1,    47,    22,
      13,    42,    14,    20,    -1,    47,    22,    13,    14,    20,
      -1,    -1,    47,    22,    13,    42,    14,    40,    43,    -1,
      -1,    47,    22,    13,    14,    41,    43,    -1,    42,    19,
      47,    22,    -1,    42,    19,    47,    -1,    47,    22,    -1,
      47,    -1,    -1,    15,    44,    49,    16,    -1,    -1,    15,
      45,    16,    -1,    47,    48,    20,    -1,     7,    -1,     8,
      -1,     9,    -1,    48,    19,    22,    -1,    48,    19,    22,
      17,    29,    18,    -1,    22,    -1,    22,    17,    29,    18,
      -1,    50,    -1,    49,    50,    -1,    46,    -1,    59,    -1,
      43,    -1,    -1,    -1,    -1,     5,    13,    59,    51,    59,
      52,    61,    53,    14,    50,    -1,     3,    13,    61,    14,
      56,    50,    -1,     3,    13,    61,    14,    56,    50,     4,
      57,    50,    -1,    -1,    -1,     6,    13,    58,    54,    61,
      55,    14,    50,    -1,    21,    13,    22,    14,    20,    -1,
      10,    61,    20,    -1,    -1,    -1,    -1,    20,    -1,    61,
      20,    -1,    22,    -1,    22,    17,    61,    18,    -1,    62,
      -1,    60,    11,    62,    -1,    63,    -1,    63,    28,    63,
      -1,    64,    -1,    64,    27,    64,    -1,    65,    -1,    64,
      23,    65,    -1,    66,    -1,    65,    26,    66,    -1,    23,
      66,    -1,    12,    66,    -1,    67,    -1,    60,    -1,    22,
      13,    68,    14,    -1,    13,    61,    14,    -1,    29,    -1,
      30,    -1,    60,    24,    -1,    60,    25,    -1,    69,    -1,
      -1,    69,    19,    62,    -1,    62,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    44,    44,    44,    55,    61,    69,    75,    81,    89,
      97,   108,   107,   123,   122,   136,   143,   152,   159,   172,
     171,   196,   195,   211,   219,   225,   231,   239,   246,   253,
     260,   269,   275,   283,   289,   295,   301,   305,   314,   301,
     325,   332,   342,   346,   342,   357,   373,   383,   389,   399,
     401,   406,   418,   424,   439,   445,   455,   461,   472,   478,
     489,   496,   505,   511,   521,   528,   535,   543,   577,   584,
     591,   597,   603,   610,   619,   626,   632,   640
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "FOR", "WHILE", "INT",
  "FLOAT", "VOID", "RETURN", "ASSIGNOP", "NOT", "LPAREN", "RPAREN",
  "LCURL", "RCURL", "LTHIRD", "RTHIRD", "COMMA", "SEMICOLON", "PRINTLN",
  "ID", "ADDOP", "INCOP", "DECOP", "MULOP", "RELOP", "LOGICOP",
  "CONST_INT", "CONST_FLOAT", "LOWER_THAN_RPAREN", "LOWER_THAN_ELSE",
  "$accept", "start", "@1", "program", "unit", "func_declaration",
  "func_definition", "@2", "@3", "parameter_list", "compound_statement",
  "@4", "@5", "var_declaration", "type_specifier", "declaration_list",
  "statements", "statement", "@6", "@7", "@8", "@9", "@10", "label_if",
  "else_if_label", "while_label", "expression_statement", "variable",
  "expression", "logic_expression", "rel_expression", "simple_expression",
  "term", "unary_expression", "factor", "argument_list", "arguments", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    33,    35,    34,    36,    36,    37,    37,    37,    38,
      38,    40,    39,    41,    39,    42,    42,    42,    42,    44,
      43,    45,    43,    46,    47,    47,    47,    48,    48,    48,
      48,    49,    49,    50,    50,    50,    51,    52,    53,    50,
      50,    50,    54,    55,    50,    50,    50,    56,    57,    58,
      59,    59,    60,    60,    61,    61,    62,    62,    63,    63,
      64,    64,    65,    65,    66,    66,    66,    67,    67,    67,
      67,    67,    67,    67,    68,    68,    69,    69
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     1,     1,     6,
       5,     0,     7,     0,     6,     4,     3,     2,     1,     0,
       4,     0,     3,     3,     1,     1,     1,     3,     6,     1,
       4,     1,     2,     1,     1,     1,     0,     0,     0,    10,
       6,     9,     0,     0,     8,     5,     3,     0,     0,     0,
       1,     2,     1,     4,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     2,     2,     1,     1,     4,     3,
       1,     1,     2,     2,     1,     0,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,    24,    25,    26,     3,     5,     7,
       8,     6,     0,     4,    29,     0,     0,     0,     0,    23,
      13,     0,    18,     0,    27,    10,     0,    11,     0,    17,
      30,     0,    19,    14,     9,     0,    16,     0,     0,     0,
      12,    15,    28,     0,     0,     0,     0,     0,     0,    50,
       0,    52,     0,    70,    71,    35,    33,     0,     0,    31,
      34,    67,     0,    54,    56,    58,    60,    62,    66,    22,
       0,     0,    49,     0,    67,    65,     0,     0,    75,     0,
      64,    29,    20,    32,     0,    72,    73,    51,     0,     0,
       0,     0,     0,    36,    42,    46,    69,     0,    77,     0,
      74,     0,    55,    57,    61,    59,    63,    47,     0,     0,
       0,    68,     0,    53,     0,    37,    43,    45,    76,    40,
       0,     0,    48,    38,     0,     0,     0,    44,    41,     0,
      39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     7,     8,     9,    10,    35,    26,    21,
      55,    38,    39,    56,    57,    15,    58,    59,   108,   120,
     126,   109,   121,   114,   125,    94,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    99,   100
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -71
static const yytype_int16 yypact[] =
{
     -71,    28,    80,   -71,   -71,   -71,   -71,    80,   -71,   -71,
     -71,   -71,     9,   -71,     2,    -2,    46,    10,    48,   -71,
      30,    42,    49,    63,    67,   -71,    79,    75,    80,   -71,
     -71,    68,    82,   -71,   -71,    79,    74,    84,    98,    93,
     -71,   -71,   -71,    99,   101,   102,     0,     0,     0,   -71,
     103,     8,     0,   -71,   -71,   -71,   -71,    95,    70,   -71,
     -71,    27,   104,   -71,    94,    35,    97,   -71,   -71,   -71,
       0,    14,   -71,   105,    41,   -71,   112,   107,     0,     0,
     -71,   113,   -71,   -71,     0,   -71,   -71,   -71,     0,     0,
       0,     0,   117,   -71,   -71,   -71,   -71,   118,   -71,   119,
     115,   120,   -71,   -71,    97,   114,   -71,   -71,    14,     0,
     116,   -71,     0,   -71,    98,   -71,   -71,   -71,   -71,   131,
       0,   125,   -71,   -71,    98,    98,   126,   -71,   -71,    98,
     -71
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -71,   -71,   -71,   -71,   134,   -71,   -71,   -71,   -71,   -71,
     -19,   -71,   -71,    57,     4,   -71,   -71,   -57,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -68,   -43,   -46,   -70,
      54,    53,    55,   -42,   -71,   -71,   -71
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -22
static const yytype_int16 yytable[] =
{
      73,    83,    76,    93,    74,    75,    12,    33,    98,    74,
      80,    12,    47,    48,   102,    16,    40,    18,    19,    17,
      22,    78,    51,    52,    92,    79,    47,    48,     3,    53,
      54,    14,    36,   101,    49,    74,    51,    52,    84,    23,
     115,    74,   118,    53,    54,    74,    74,    74,    74,   106,
      25,    85,    86,     4,     5,     6,    27,   119,    89,    11,
      20,    28,    90,   116,    11,    85,    86,   127,   128,    74,
      24,    29,   130,    43,   123,    44,    45,     4,     5,     6,
      46,    30,    47,    48,    31,    32,    82,     4,     5,     6,
      49,    50,    51,    52,    32,    34,    41,    37,   -21,    53,
      54,    43,    42,    44,    45,     4,     5,     6,    46,    69,
      47,    48,    70,    32,    71,    72,    77,    81,    49,    50,
      51,    52,    88,    91,    87,    95,    96,    53,    54,    97,
      17,   107,   110,   111,   112,   122,   117,    89,   113,   124,
     129,    13,   103,   105,   104
};

static const yytype_uint8 yycheck[] =
{
      46,    58,    48,    71,    47,    47,     2,    26,    78,    52,
      52,     7,    12,    13,    84,    13,    35,    19,    20,    17,
      16,    13,    22,    23,    70,    17,    12,    13,     0,    29,
      30,    22,    28,    79,    20,    78,    22,    23,    11,    29,
     108,    84,   112,    29,    30,    88,    89,    90,    91,    91,
      20,    24,    25,     7,     8,     9,    14,   114,    23,     2,
      14,    19,    27,   109,     7,    24,    25,   124,   125,   112,
      22,    22,   129,     3,   120,     5,     6,     7,     8,     9,
      10,    18,    12,    13,    17,    15,    16,     7,     8,     9,
      20,    21,    22,    23,    15,    20,    22,    29,    16,    29,
      30,     3,    18,     5,     6,     7,     8,     9,    10,    16,
      12,    13,    13,    15,    13,    13,    13,    22,    20,    21,
      22,    23,    28,    26,    20,    20,    14,    29,    30,    22,
      17,    14,    14,    14,    19,     4,    20,    23,    18,    14,
      14,     7,    88,    90,    89
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    34,    35,     0,     7,     8,     9,    36,    37,    38,
      39,    46,    47,    37,    22,    48,    13,    17,    19,    20,
      14,    42,    47,    29,    22,    20,    41,    14,    19,    22,
      18,    17,    15,    43,    20,    40,    47,    29,    44,    45,
      43,    22,    18,     3,     5,     6,    10,    12,    13,    20,
      21,    22,    23,    29,    30,    43,    46,    47,    49,    50,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    16,
      13,    13,    13,    61,    60,    66,    61,    13,    13,    17,
      66,    22,    16,    50,    11,    24,    25,    20,    28,    23,
      27,    26,    61,    59,    58,    20,    14,    22,    62,    68,
      69,    61,    62,    63,    65,    64,    66,    14,    51,    54,
      14,    14,    19,    18,    56,    59,    61,    20,    62,    50,
      52,    55,     4,    61,    14,    57,    53,    50,    50,    14,
      50
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 44 "1805047.y"
    {
	initiateAssembly();
}
    break;

  case 3:
#line 47 "1805047.y"
    {
	string str = stackPop(program);
	stackPush(start, str);
	printLog("start", "program", "");
	printLineAndErrors();
}
    break;

  case 4:
#line 56 "1805047.y"
    {
	string str = stackPop(program) + "\n" + stackPop(unit);
	stackPush(program, str);
	printLog("program", "program unit", str + "\n");
}
    break;

  case 5:
#line 62 "1805047.y"
    {
	string str = stackPop(unit);
	stackPush(program, str);
	printLog("program", "unit", str + "\n");
}
    break;

  case 6:
#line 70 "1805047.y"
    {
	string str = stackPop(var_declaration);
	stackPush(unit, str);
	printLog("unit", "var_declaration", str + "\n");
}
    break;

  case 7:
#line 76 "1805047.y"
    {
	string str = stackPop(func_declaration);
	stackPush(unit, str);
	printLog("unit", "func_declaration", str + "\n");
}
    break;

  case 8:
#line 82 "1805047.y"
    {
	string str = stackPop(func_definition);
	stackPush(unit, str);
	printLog("unit", "func_definition", str + "\n");
}
    break;

  case 9:
#line 90 "1805047.y"
    {
	string str = stackPop(type_specifier) + " " + (yyvsp[(2) - (6)].symbolValue)->getName() + "(" + stackPop(parameter_list) + ");";
	setFunctionValues(*(yyvsp[(1) - (6)].input_string), (yyvsp[(2) - (6)].symbolValue), false);
	setAndClearFunctionThings();
	stackPush(func_declaration, str);
	printLog("func_declaration", "type_specifier ID LPAREN parameter_list RPAREN SEMICOLON", str + "\n");
}
    break;

  case 10:
#line 98 "1805047.y"
    {
	string str = stackPop(type_specifier) + " " + (yyvsp[(2) - (5)].symbolValue)->getName() + "();";
	setFunctionValues(*(yyvsp[(1) - (5)].input_string), (yyvsp[(2) - (5)].symbolValue), false);
	setAndClearFunctionThings();
	stackPush(func_declaration, str);
	printLog("func_declaration", "type_specifier ID LPAREN RPAREN SEMICOLON", str + "\n");
}
    break;

  case 11:
#line 108 "1805047.y"
    {
	setFunctionValues(*(yyvsp[(1) - (5)].input_string), (yyvsp[(2) - (5)].symbolValue), true);
}
    break;

  case 12:
#line 111 "1805047.y"
    {

	// fprintf(asmCodeOut, "add sp, %d\n", $7->offset * 2);
	string str = stackPop(type_specifier) + " " + (yyvsp[(2) - (7)].symbolValue)->getName() + "(" + stackPop(parameter_list) + ")" + stackPop(compound_statement);
	stackPush(func_definition, str);
	printLog("func_definition", "type_specifier ID LPAREN parameter_list RPAREN compound_statement", str);
	addFunctionEndStatementInAsm(current_function->getName(), current_function->sequence_of_parameters.size(), current_function->return_label, (yyvsp[(7) - (7)].symbolValue)->offset);

	printCurrentStatement((yyvsp[(2) - (7)].symbolValue)->getName() + " function ended\n\n");
	current_function = nullptr;
}
    break;

  case 13:
#line 123 "1805047.y"
    {
	setFunctionValues(*(yyvsp[(1) - (4)].input_string), (yyvsp[(2) - (4)].symbolValue), true);
}
    break;

  case 14:
#line 126 "1805047.y"
    {
	string str = stackPop(type_specifier) + " " + (yyvsp[(2) - (6)].symbolValue)->getName() + "()" + stackPop(compound_statement);
	stackPush(func_definition, str);
	printLog("func_definition", "type_specifier ID LPAREN RPAREN compound_statement", str);
	addFunctionEndStatementInAsm(current_function->getName(), current_function->sequence_of_parameters.size(), current_function->return_label, (yyvsp[(6) - (6)].symbolValue)->offset);
	current_function = nullptr;
}
    break;

  case 15:
#line 137 "1805047.y"
    {
	string str = stackPop(parameter_list) + "," + stackPop(type_specifier) + " " + (yyvsp[(4) - (4)].symbolValue)->getName();
	stackPush(parameter_list, str);
	insertIntoParameters((yyvsp[(4) - (4)].symbolValue), *(yyvsp[(3) - (4)].input_string));
	printLog("parameter_list", "parameter_list COMMA type_specifier ID", str);
}
    break;

  case 16:
#line 144 "1805047.y"
    {
	string str = stackPop(parameter_list) + "," + stackPop(type_specifier);
	stackPush(parameter_list, str);
	string name("#");
	name = name + to_string(count_of_parameters_without_name++);
	insertIntoParameters(new symbol_info(name, "ID"), *(yyvsp[(3) - (3)].input_string));
	printLog("parameter_list", "parameter_list COMMA type_specifier", str);
}
    break;

  case 17:
#line 153 "1805047.y"
    {
	string str = stackPop(type_specifier) + " " + (yyvsp[(2) - (2)].symbolValue)->getName();
	stackPush(parameter_list, str);
	insertIntoParameters((yyvsp[(2) - (2)].symbolValue), *(yyvsp[(1) - (2)].input_string));
	printLog("parameter_list", "type_specifier ID", str);
}
    break;

  case 18:
#line 160 "1805047.y"
    {
	string str = stackPop(type_specifier);
	stackPush(parameter_list, str);
	string name("#");
	name = name + to_string(count_of_parameters_without_name++);
	insertIntoParameters(new symbol_info(name, "ID"), *(yyvsp[(1) - (1)].input_string));
	printLog("parameter_list", "type_specifier", str);
}
    break;

  case 19:
#line 172 "1805047.y"
    {

  	variables_stack.push_back(vector<var_info>());
	enterNewScope();
}
    break;

  case 20:
#line 177 "1805047.y"
    {
	string str = "{\n" + stackPop(statements) + "\n}";
	stackPush(compound_statement, str);
	printLog("compound_statement", "LCURL statements RCURL", str + "\n");

	printTable();
	exitScope();
	// cout << variables_stack.size() << endl;
	int c = 0;
	for(int i = 0; i < variables_stack[variables_stack.size() - 1].size(); i++) {
		c += variables_stack[variables_stack.size() - 1][i].size;
	}
	fprintf(asmCodeOut, "add sp, %d\n", c * 2);
	(yyval.symbolValue)->offset = c * 2;
	variables_stack.pop_back();
	// cout << variables_stack.size() << endl;

}
    break;

  case 21:
#line 196 "1805047.y"
    {

  	variables_stack.push_back(vector<var_info>());
	enterNewScope();
}
    break;

  case 22:
#line 201 "1805047.y"
    {
	fprintf(asmCodeOut, "add sp, %d\n", variables_stack[variables_stack.size() - 1].size() * 2);
	variables_stack.pop_back();
	string str = "{}";
	stackPush(compound_statement, str);
	exitScope();
	printLog("compound_statement", "LCURL RCURL", str + "\n");
}
    break;

  case 23:
#line 212 "1805047.y"
    {
	setVariableAndArrayValues(*(yyvsp[(1) - (3)].input_string));
	stackPush(var_declaration, stackPop(type_specifier) + " " + stackPop(declaration_list) + ";");
	printLog("var_declaration", "type_specifier declaration_list SEMICOLON", *((yyvsp[(1) - (3)].input_string)) + " " + *(yyvsp[(2) - (3)].input_string) + ";");
}
    break;

  case 24:
#line 220 "1805047.y"
    {
	(yyval.input_string) = new string(yytext);
	printLog("type_specifier", "INT", yytext);
	stackPush(type_specifier, integer);
}
    break;

  case 25:
#line 226 "1805047.y"
    {
	(yyval.input_string) = new string(yytext);
	printLog("type_specifier", "FLOAT", yytext);
	stackPush(type_specifier, fraction);
}
    break;

  case 26:
#line 232 "1805047.y"
    {
	(yyval.input_string) = new string(yytext);
	printLog("type_specifier", "VOID", yytext);
	stackPush(type_specifier, "void");
}
    break;

  case 27:
#line 240 "1805047.y"
    {
	(yyval.input_string) = new string((*(yyvsp[(1) - (3)].input_string)) + ","+ (yyvsp[(3) - (3)].symbolValue)->getName());
	insertDeclarationListRecord((yyvsp[(3) - (3)].symbolValue));
	stackPush(declaration_list, stackPop(declaration_list) + "," + (yyvsp[(3) - (3)].symbolValue)->getName());
	printLog("declaration_list", "declaration_list COMMA ID", *(yyval.input_string));
}
    break;

  case 28:
#line 247 "1805047.y"
    {
	(yyval.input_string) = new string((*(yyvsp[(1) - (6)].input_string)) + ","+ (yyvsp[(3) - (6)].symbolValue)->getName() + "[" + *(yyvsp[(5) - (6)].input_string) + "]");
	insertDeclarationListRecord((yyvsp[(3) - (6)].symbolValue), true, stoi(*(yyvsp[(5) - (6)].input_string)));
	stackPush(declaration_list, stackPop(declaration_list) + "," +  (yyvsp[(3) - (6)].symbolValue)->getName() + "[" + *(yyvsp[(5) - (6)].input_string) + "]");
	printLog("declaration_list", "declaration_list COMMA ID LTHIRD CONST_INT RTHIRD", *(yyval.input_string));
}
    break;

  case 29:
#line 254 "1805047.y"
    {
	(yyval.input_string) = new string((yyvsp[(1) - (1)].symbolValue) -> getName());
	insertDeclarationListRecord((yyvsp[(1) - (1)].symbolValue));
	stackPush(declaration_list, (yyvsp[(1) - (1)].symbolValue)->getName());
	printLog("declaration_list", "ID", *(yyval.input_string));
}
    break;

  case 30:
#line 261 "1805047.y"
    {
	(yyval.input_string) = new string((yyvsp[(1) - (4)].symbolValue)->getName() + "[" + *(yyvsp[(3) - (4)].input_string) + "]");
	insertDeclarationListRecord((yyvsp[(1) - (4)].symbolValue), true, stoi(*(yyvsp[(3) - (4)].input_string)));
	stackPush(declaration_list, *(yyval.input_string));
	printLog("declaration_list", "ID LTHIRD CONST_INT RTHIRD", *(yyval.input_string));
}
    break;

  case 31:
#line 270 "1805047.y"
    {
	string str = stackPop(statement);
	stackPush(statements, str);
	printLog("statements", "statement", str + "\n");
}
    break;

  case 32:
#line 276 "1805047.y"
    {
	string str = stackPop(statements) + "\n" + stackPop(statement);
	stackPush(statements, str);
	printLog("statements", "statements statement", str + "\n");
}
    break;

  case 33:
#line 284 "1805047.y"
    {
	string str =  stackPop(var_declaration);
	stackPush(statement, str);
	printLog("statement", "var_declaration", str + "\n");
}
    break;

  case 34:
#line 290 "1805047.y"
    {
	string str =  stackPop(expression_statement);
	stackPush(statement, str);
	printLog("statement", "expression_statement", str + "\n");
}
    break;

  case 35:
#line 296 "1805047.y"
    {
	string str =  stackPop(compound_statement);
	stackPush(statement, str);
	printLog("statement", "compound_statement", str + "\n");
}
    break;

  case 36:
#line 301 "1805047.y"
    {
		string condition_label = newLabel();
		fprintf(asmCodeOut, "%s:\n", condition_label.c_str());
		(yyvsp[(3) - (3)].symbolValue)->inh_label = condition_label;
	  }
    break;

  case 37:
#line 305 "1805047.y"
    {
		string condition_false_label = newLabel();
		string start_statement = newLabel();
		string indecop_label = newLabel();

		fprintf(asmCodeOut, "mov cx, ax\ncmp cx, 0\nje %s\njmp %s\n%s:\n", condition_false_label.c_str(), start_statement.c_str(), indecop_label.c_str());
		(yyvsp[(5) - (5)].symbolValue)->inh_label = condition_false_label;
		(yyvsp[(5) - (5)].symbolValue)->inh_label2 = start_statement;
		(yyvsp[(5) - (5)].symbolValue)->inh_label3 = indecop_label;
	  }
    break;

  case 38:
#line 314 "1805047.y"
    {
		fprintf(asmCodeOut, "pop ax\njmp %s\n%s:\n", (yyvsp[(3) - (7)].symbolValue)->inh_label.c_str(), (yyvsp[(5) - (7)].symbolValue)->inh_label2.c_str());
	  }
    break;

  case 39:
#line 317 "1805047.y"
    {
	string str1 = stackPop(expression_statement);
	string str2 = stackPop(expression_statement);
	string str = "for(" + str2 + str1 + stackPop(expression) + ")" + stackPop(statement);
	stackPush(statement, str);
	printLog("statement", "FOR LPAREN expression_statement expression_statement expression RPAREN statement", str + "\n");
	fprintf(asmCodeOut, "jmp %s\n%s:\n", (yyvsp[(5) - (10)].symbolValue)->inh_label3.c_str(), (yyvsp[(5) - (10)].symbolValue)->inh_label.c_str());
}
    break;

  case 40:
#line 326 "1805047.y"
    {
	string str = "if(" + stackPop(expression) + ")" + stackPop(statement);
	stackPush(statement, str);
	printLog("statement", "IF LPAREN expression RPAREN statement", str + "\n");
	fprintf(asmCodeOut, "%s:\n", (yyvsp[(5) - (6)].temp)->c_str());
}
    break;

  case 41:
#line 333 "1805047.y"
    {
	string str1 = stackPop(statement);
	string str2 = stackPop(statement);
	string str = "if (" + stackPop(expression) + ")" + str2 + "\nelse " + str1;
	stackPush(statement, str);
	printLog("statement", "IF LPAREN expression RPAREN statement ELSE statement", str + "\n");
	else_if_label = "";
	fprintf(asmCodeOut, "%s:\n", (yyvsp[(8) - (9)].temp)->c_str());
}
    break;

  case 42:
#line 342 "1805047.y"
    {
		string condition_check_label = newLabel();
		fprintf(asmCodeOut, "%s:\n", condition_check_label.c_str());
		(yyvsp[(3) - (3)].temp) = new string(condition_check_label);
	  }
    break;

  case 43:
#line 346 "1805047.y"
    {
		string condition_false_label = newLabel();
		fprintf(asmCodeOut, "pop cx\ncmp cx, 0\nje %s\n", condition_false_label.c_str());
		(yyvsp[(5) - (5)].symbolValue)->inh_label = condition_false_label;
	  }
    break;

  case 44:
#line 351 "1805047.y"
    {
	string str = "while (" + stackPop(expression) + ")" + stackPop(statement);
	stackPush(statement, str);
	printLog("statement", "WHILE LPAREN expression RPAREN statement", str + "\n");
	fprintf(asmCodeOut, "jmp %s\n%s:\n", (yyvsp[(3) - (8)].temp)->c_str(), (yyvsp[(5) - (8)].symbolValue)->inh_label.c_str());
}
    break;

  case 45:
#line 358 "1805047.y"
    {
	findVariable((yyvsp[(3) - (5)].symbolValue));
	string str = "println(" + (yyvsp[(3) - (5)].symbolValue)->getName() + ");";
	stackPush(statement, str);
	printCurrentStatement(str);
	if((yyvsp[(3) - (5)].symbolValue)->offset == 0) {
		fprintf(asmCodeOut, "mov ax, %s\ncall print_number\n", (yyvsp[(3) - (5)].symbolValue)->getName().c_str());
	}
	else {
		string plus = (yyvsp[(3) - (5)].symbolValue)->offset > 0 ? "+": "";
		fprintf(asmCodeOut, "mov ax, [bp%s%d]\ncall print_number\n", plus.c_str(), (yyvsp[(3) - (5)].symbolValue)->offset);
	}

	printLog("statement", "PRINTLN LPAREN ID RPAREN SEMICOLON", str + "\n");
}
    break;

  case 46:
#line 374 "1805047.y"
    {
	checkFuncReturnCompatibility((yyvsp[(2) - (3)].symbolValue));
	string str = "return " + stackPop(expression) + ";";
	stackPush(statement, str);
	printLog("statement", "RETURN expression SEMICOLON", str + "\n");
}
    break;

  case 47:
#line 383 "1805047.y"
    {
			(yyval.temp) = new string(newLabel());
			fprintf(asmCodeOut, "pop cx\ncmp cx, 0\nje %s\n", (yyval.temp)->c_str());
		}
    break;

  case 48:
#line 389 "1805047.y"
    {
			if(else_if_label == "") 
				(yyval.temp) = new string(newLabel());
			else 
				(yyval.temp) = new string(else_if_label);
			fprintf(asmCodeOut, "jmp %s\n", (yyval.temp)->c_str());
			string temp = *(yyvsp[(-2) - (0)].temp);
			fprintf(asmCodeOut, "%s:\n", temp.c_str());
		}
    break;

  case 49:
#line 399 "1805047.y"
    {}
    break;

  case 50:
#line 402 "1805047.y"
    {
	stackPush(expression_statement, ";");
	printLog("expression_statement", "SEMICOLON", ";");
}
    break;

  case 51:
#line 407 "1805047.y"
    {

	fprintf(asmCodeOut, "pop ax\n");
	string str = stackPop(expression) + ";";
	stackPush(expression_statement, str);
	printLog("expression_statement", "expression SEMICOLON", str);
}
    break;

  case 52:
#line 419 "1805047.y"
    {
	(yyval.symbolValue) = findVariable((yyvsp[(1) - (1)].symbolValue));
	stackPush(variable, (yyvsp[(1) - (1)].symbolValue)->getName());
	printLog("variable", "ID", (yyvsp[(1) - (1)].symbolValue)->getName());
}
    break;

  case 53:
#line 425 "1805047.y"
    {
	(yyval.symbolValue) = checkArrayIndex((yyvsp[(1) - (4)].symbolValue)->getName(), (yyvsp[(3) - (4)].symbolValue));
	symbol_info* si = findVariable((yyvsp[(1) - (4)].symbolValue));
	(yyval.symbolValue)->offset = si->offset;

	// cout << $$ -> offset << endl;

	string str = (yyvsp[(1) - (4)].symbolValue)->getName() + "["
	+ stackPop(expression) + "]";
	stackPush(variable, str);
	printLog("variable", "ID LTHIRD expression RTHIRD ", str);
}
    break;

  case 54:
#line 440 "1805047.y"
    {
	string str = stackPop(logic_expression);
	stackPush(expression, str);
	printLog("expression", "logic_expression", str);
}
    break;

  case 55:
#line 446 "1805047.y"
    {
	string str = stackPop(variable) + "=" + stackPop(logic_expression);
	stackPush(expression, str);
	printLog("expression", "variable ASSIGNOP logic_expression", str);

	(yyval.symbolValue) = checkAssignCompatibility((yyvsp[(1) - (3)].symbolValue), (yyvsp[(3) - (3)].symbolValue));
}
    break;

  case 56:
#line 456 "1805047.y"
    {
	string str = stackPop(rel_expression);
	stackPush(logic_expression, str);
	printLog("logic_expression", "rel_expression", str);
}
    break;

  case 57:
#line 462 "1805047.y"
    {
	(yyval.symbolValue) = checkLogicCompetibility((yyvsp[(1) - (3)].symbolValue), *(yyvsp[(2) - (3)].input_string), (yyvsp[(3) - (3)].symbolValue));
	string str1 = stackPop(rel_expression);
	string str2 = stackPop(rel_expression);
	string str = str2 + *(yyvsp[(2) - (3)].input_string) + str1;
	stackPush(logic_expression, str);
	printLog("logic_expression", "rel_expression LOGICOP rel_expression ", str);
}
    break;

  case 58:
#line 473 "1805047.y"
    {
	string str = stackPop(simple_expression);
	stackPush(rel_expression, str);
	printLog("rel_expression", "simple_expression", str);
}
    break;

  case 59:
#line 479 "1805047.y"
    {
	(yyval.symbolValue) = checkRELOPCompetibility((yyvsp[(1) - (3)].symbolValue), *(yyvsp[(2) - (3)].input_string), (yyvsp[(3) - (3)].symbolValue));
	string str1 = stackPop(simple_expression);
	string str2 = stackPop(simple_expression);
	string str = str2 + *(yyvsp[(2) - (3)].input_string) + str1;
	stackPush(rel_expression, str);
	printLog("rel_expression", "simple_expression RELOP simple_expression	", str);
}
    break;

  case 60:
#line 490 "1805047.y"
    {
	(yyval.symbolValue) = (yyvsp[(1) - (1)].symbolValue);
	string str = stackPop(term);
	stackPush(simple_expression, str);
	printLog("simple_expression", "term", str);
}
    break;

  case 61:
#line 497 "1805047.y"
    {
	(yyval.symbolValue) = checkAdditionCompatibility((yyvsp[(1) - (3)].symbolValue), *(yyvsp[(2) - (3)].input_string), (yyvsp[(3) - (3)].symbolValue));
	string str = stackPop(simple_expression) + *(yyvsp[(2) - (3)].input_string) + stackPop(term);
	stackPush(simple_expression, str);
	printLog("simple_expression", "simple_expression ADDOP term", str);
}
    break;

  case 62:
#line 506 "1805047.y"
    {
	string str = stackPop(unary_expression);
	stackPush(term, str);
	printLog("term", "unary_expression", str);
}
    break;

  case 63:
#line 512 "1805047.y"
    {

	(yyval.symbolValue) = checkAndDoMulopThings((yyvsp[(1) - (3)].symbolValue), *(yyvsp[(2) - (3)].input_string), (yyvsp[(3) - (3)].symbolValue));
	string str = stackPop(term) + *(yyvsp[(2) - (3)].input_string) + stackPop(unary_expression);
	stackPush(term, str);
	printLog("term", "term MULOP unary_expression", str);
}
    break;

  case 64:
#line 522 "1805047.y"
    {
	(yyval.symbolValue) = checkUnaryADDOPThings(*(yyvsp[(1) - (2)].input_string), (yyvsp[(2) - (2)].symbolValue));
	string str = *(yyvsp[(1) - (2)].input_string) + stackPop(unary_expression);
	stackPush(unary_expression, str);
	printLog("unary_expression", "ADDOP unary_expression", str);
}
    break;

  case 65:
#line 529 "1805047.y"
    {
	(yyval.symbolValue) = checkNotCompatibility((yyvsp[(2) - (2)].symbolValue));
	string str = "!" + stackPop(unary_expression);
	stackPush(unary_expression, str);
	printLog("unary_expression", "ADDOP unary_expression", str);
}
    break;

  case 66:
#line 536 "1805047.y"
    {
	string str = stackPop(factor);
	stackPush(unary_expression, str);
	printLog("unary_expression", "factor", str);
}
    break;

  case 67:
#line 544 "1805047.y"
    {
	
	string str = stackPop(variable);
	stackPush(factor, str);
	printLog("factor", "variable", str);
	printCurrentStatement(str);
	// if($1->offset == 0) {
	// 	fprintf(asmCodeOut, "push %s\n", $1->getName().c_str());
	// }
	// else {
	// 	string plus = $1->offset > 0 ? "+": "";
	// 	fprintf(asmCodeOut, "push [bp%s%d]\n", plus.c_str(), $1->offset);
	// }
	if((yyvsp[(1) - (1)].symbolValue)->offset == 0) {
		if (isArray((yyvsp[(1) - (1)].symbolValue)))
		{
			fprintf(asmCodeOut, "pop bx\npush %s[bx]\n", (yyvsp[(1) - (1)].symbolValue)->temp_id.c_str());
		} 
		else {
			fprintf(asmCodeOut, "push %s\n", (yyvsp[(1) - (1)].symbolValue)->getName().c_str());
		}
	}
	else {
		if (isArray((yyvsp[(1) - (1)].symbolValue)))
		{
			fprintf(asmCodeOut, "pop bx\npush bp\nsub bx, %d\nsub bp, bx\nmov cx, [bp]\npop bp\npush cx\n", (yyvsp[(1) - (1)].symbolValue)->offset);
		} 
		else {
			string plus = (yyvsp[(1) - (1)].symbolValue)->offset > 0 ? "+": "";
			fprintf(asmCodeOut, "push [bp%s%d]\n", plus.c_str(), (yyvsp[(1) - (1)].symbolValue)->offset);
		}
	}
}
    break;

  case 68:
#line 578 "1805047.y"
    {
	string str = (yyvsp[(1) - (4)].symbolValue)->getName() + "(" + stackPop(argument_list) + ")";
	stackPush(factor, str);
	printLog("factor", "ID LPAREN argument_list RPAREN", str);
	(yyval.symbolValue) = checkFunctionArguments((yyvsp[(1) - (4)].symbolValue));
}
    break;

  case 69:
#line 585 "1805047.y"
    {
	(yyval.symbolValue) = checkLPAREN_Expression_RPAREN((yyvsp[(2) - (3)].symbolValue));
	string str = "(" + stackPop(expression) + ")";
	stackPush(factor, str);
	printLog("factor", "LPAREN expression RPAREN", str);
}
    break;

  case 70:
#line 592 "1805047.y"
    {
	(yyval.symbolValue) = setIntermediateValues("intermediate", integer, stoi(*(yyvsp[(1) - (1)].input_string)));
	stackPush(factor, *(yyvsp[(1) - (1)].input_string));
	printLog("factor", "CONST_INT", *(yyvsp[(1) - (1)].input_string));
}
    break;

  case 71:
#line 598 "1805047.y"
    {
	(yyval.symbolValue) = setIntermediateValues("intermediate", "float", stof(*(yyvsp[(1) - (1)].input_string)));
	stackPush(factor, *(yyvsp[(1) - (1)].input_string));
	printLog("factor", "CONST_FLOAT", *(yyvsp[(1) - (1)].input_string));
}
    break;

  case 72:
#line 604 "1805047.y"
    {
	(yyval.symbolValue) = checkINCOPCompatibility((yyvsp[(1) - (2)].symbolValue));
	string str = stackPop(variable) + "++";
	stackPush(factor, str);
	printLog("factor", "variable INCOP", str);
}
    break;

  case 73:
#line 611 "1805047.y"
    {
	(yyval.symbolValue) = checkDECOPCompatibility((yyvsp[(1) - (2)].symbolValue));
	string str = stackPop(variable) + "--";
	stackPush(factor, str);
	printLog("factor", "variable DECOP", str);
}
    break;

  case 74:
#line 620 "1805047.y"
    {
	string str = stackPop(arguments);
	stackPush(argument_list, str);
	printLog("argument_list", "arguments", str);
}
    break;

  case 75:
#line 626 "1805047.y"
    {
	stackPush(argument_list, "");
	printLog("argument_list", "", "");
}
    break;

  case 76:
#line 633 "1805047.y"
    {
	args.push_back((yyvsp[(3) - (3)].symbolValue));
	// pushToStackTemp();
	string str = stackPop(arguments) + "," + stackPop(logic_expression);
	stackPush(arguments, str);
	printLog("arguments", "arguments COMMA logic_expression", str);
}
    break;

  case 77:
#line 641 "1805047.y"
    {
	args.push_back((yyvsp[(1) - (1)].symbolValue));
	string str = stackPop(logic_expression);
	stackPush(arguments, str);
	printLog("arguments", "logic_expression", str);
}
    break;


/* Line 1267 of yacc.c.  */
#line 2314 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 650 "1805047.y"


void concatFile(FILE* wholeasm, FILE* asmDataOut, FILE* asmCodeOut, FILE* asmPrintOut){
	char ch;
	// cout << has_main_function << endl;
	if(!has_main_function || syntax_error_count + lexical_error_count > 0) {
		if(!has_main_function) 
			printError("program has no main function");
		return;
	}
	/* do {
        ch = fgetc(asmDataOut);
		if(ch == EOF) break;
        fprintf(wholeasm, "%c", ch);
 
        // Checking if character is not EOF.
        // If it is EOF stop eading.
    } while (ch != EOF); */
	do {
        ch = fgetc(asmCodeOut);

		if(ch == EOF) break;
        fprintf(wholeasm, "%c", ch);
 
        // Checking if character is not EOF.
        // If it is EOF stop eading.
    } while (ch != EOF);

	fclose(wholeasm);
	wholeasm = fopen("code.asm", "r");

	FILE *optimizeCode = fopen("optimized_code.asm", "w");

	runOptimization(wholeasm, optimizeCode);
	fclose(optimizeCode);
	// fclose(wholeas)
	optimizeCode = fopen("optimized_code.asm", "a");

	do {
        ch = fgetc(asmPrintOut);

		if(ch == EOF) break;
        fprintf(optimizeCode, "%c", ch);
 
        // Checking if character is not EOF.
        // If it is EOF stop eading.
    } while (ch != EOF);
	fclose(optimizeCode);
}


int main(int argc,char *argv[])
{
	FILE *fp, *wholeasm, *asmPrintOut;
	if((fp=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}

	logout= fopen("log.txt","w");
 	errorout= fopen("error.txt","w");
 	asmDataOut= fopen("asmData.asm","w");
 	asmCodeOut= fopen("asmCode.asm","w");
	

	yyin=fp;
	yyparse();


	fclose(yyin);
	fclose(asmDataOut);
	fclose(asmCodeOut);

	asmDataOut = fopen("asmData.asm", "r");
	asmCodeOut = fopen("asmCode.asm", "r");
 	asmPrintOut= fopen("println.asm", "r");
	wholeasm = fopen("code.asm", "w");

	concatFile(wholeasm, asmDataOut, asmCodeOut,asmPrintOut);

	fclose(asmDataOut);
	fclose(asmCodeOut);
	fclose(wholeasm);
	fclose(logout);
	fclose(errorout);
	return 0;
}
