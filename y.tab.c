/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
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


#line 89 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 212 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_FOR = 5,                        /* FOR  */
  YYSYMBOL_WHILE = 6,                      /* WHILE  */
  YYSYMBOL_INT = 7,                        /* INT  */
  YYSYMBOL_FLOAT = 8,                      /* FLOAT  */
  YYSYMBOL_VOID = 9,                       /* VOID  */
  YYSYMBOL_RETURN = 10,                    /* RETURN  */
  YYSYMBOL_ASSIGNOP = 11,                  /* ASSIGNOP  */
  YYSYMBOL_NOT = 12,                       /* NOT  */
  YYSYMBOL_LPAREN = 13,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 14,                    /* RPAREN  */
  YYSYMBOL_LCURL = 15,                     /* LCURL  */
  YYSYMBOL_RCURL = 16,                     /* RCURL  */
  YYSYMBOL_LTHIRD = 17,                    /* LTHIRD  */
  YYSYMBOL_RTHIRD = 18,                    /* RTHIRD  */
  YYSYMBOL_COMMA = 19,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 20,                 /* SEMICOLON  */
  YYSYMBOL_PRINTLN = 21,                   /* PRINTLN  */
  YYSYMBOL_ID = 22,                        /* ID  */
  YYSYMBOL_ADDOP = 23,                     /* ADDOP  */
  YYSYMBOL_INCOP = 24,                     /* INCOP  */
  YYSYMBOL_DECOP = 25,                     /* DECOP  */
  YYSYMBOL_MULOP = 26,                     /* MULOP  */
  YYSYMBOL_RELOP = 27,                     /* RELOP  */
  YYSYMBOL_LOGICOP = 28,                   /* LOGICOP  */
  YYSYMBOL_CONST_INT = 29,                 /* CONST_INT  */
  YYSYMBOL_CONST_FLOAT = 30,               /* CONST_FLOAT  */
  YYSYMBOL_LOWER_THAN_RPAREN = 31,         /* LOWER_THAN_RPAREN  */
  YYSYMBOL_LOWER_THAN_ELSE = 32,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 33,                  /* $accept  */
  YYSYMBOL_start = 34,                     /* start  */
  YYSYMBOL_35_1 = 35,                      /* $@1  */
  YYSYMBOL_program = 36,                   /* program  */
  YYSYMBOL_unit = 37,                      /* unit  */
  YYSYMBOL_func_declaration = 38,          /* func_declaration  */
  YYSYMBOL_func_definition = 39,           /* func_definition  */
  YYSYMBOL_40_2 = 40,                      /* $@2  */
  YYSYMBOL_41_3 = 41,                      /* $@3  */
  YYSYMBOL_parameter_list = 42,            /* parameter_list  */
  YYSYMBOL_compound_statement = 43,        /* compound_statement  */
  YYSYMBOL_44_4 = 44,                      /* $@4  */
  YYSYMBOL_45_5 = 45,                      /* $@5  */
  YYSYMBOL_var_declaration = 46,           /* var_declaration  */
  YYSYMBOL_type_specifier = 47,            /* type_specifier  */
  YYSYMBOL_declaration_list = 48,          /* declaration_list  */
  YYSYMBOL_statements = 49,                /* statements  */
  YYSYMBOL_statement = 50,                 /* statement  */
  YYSYMBOL_51_6 = 51,                      /* $@6  */
  YYSYMBOL_52_7 = 52,                      /* $@7  */
  YYSYMBOL_53_8 = 53,                      /* $@8  */
  YYSYMBOL_54_9 = 54,                      /* $@9  */
  YYSYMBOL_55_10 = 55,                     /* $@10  */
  YYSYMBOL_label_if = 56,                  /* label_if  */
  YYSYMBOL_else_if_label = 57,             /* else_if_label  */
  YYSYMBOL_while_label = 58,               /* while_label  */
  YYSYMBOL_expression_statement = 59,      /* expression_statement  */
  YYSYMBOL_variable = 60,                  /* variable  */
  YYSYMBOL_expression = 61,                /* expression  */
  YYSYMBOL_logic_expression = 62,          /* logic_expression  */
  YYSYMBOL_rel_expression = 63,            /* rel_expression  */
  YYSYMBOL_simple_expression = 64,         /* simple_expression  */
  YYSYMBOL_term = 65,                      /* term  */
  YYSYMBOL_unary_expression = 66,          /* unary_expression  */
  YYSYMBOL_factor = 67,                    /* factor  */
  YYSYMBOL_argument_list = 68,             /* argument_list  */
  YYSYMBOL_arguments = 69                  /* arguments  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

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
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  131

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   287


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    44,    44,    44,    55,    61,    69,    75,    81,    89,
      97,   108,   107,   121,   120,   134,   141,   150,   157,   170,
     169,   182,   181,   193,   201,   207,   213,   221,   228,   235,
     242,   251,   258,   267,   273,   279,   285,   289,   297,   285,
     308,   315,   325,   329,   325,   340,   349,   359,   365,   375,
     377,   382,   394,   400,   410,   416,   426,   432,   443,   449,
     460,   467,   476,   482,   492,   499,   506,   514,   528,   535,
     542,   548,   554,   561,   570,   577,   583,   591
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "FOR",
  "WHILE", "INT", "FLOAT", "VOID", "RETURN", "ASSIGNOP", "NOT", "LPAREN",
  "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "COMMA", "SEMICOLON",
  "PRINTLN", "ID", "ADDOP", "INCOP", "DECOP", "MULOP", "RELOP", "LOGICOP",
  "CONST_INT", "CONST_FLOAT", "LOWER_THAN_RPAREN", "LOWER_THAN_ELSE",
  "$accept", "start", "$@1", "program", "unit", "func_declaration",
  "func_definition", "$@2", "$@3", "parameter_list", "compound_statement",
  "$@4", "$@5", "var_declaration", "type_specifier", "declaration_list",
  "statements", "statement", "$@6", "$@7", "$@8", "$@9", "$@10",
  "label_if", "else_if_label", "while_label", "expression_statement",
  "variable", "expression", "logic_expression", "rel_expression",
  "simple_expression", "term", "unary_expression", "factor",
  "argument_list", "arguments", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-71)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-22)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
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

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
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

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -71,   -71,   -71,   -71,   134,   -71,   -71,   -71,   -71,   -71,
     -19,   -71,   -71,    57,     4,   -71,   -71,   -57,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -68,   -43,   -46,   -70,
      54,    53,    55,   -42,   -71,   -71,   -71
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     7,     8,     9,    10,    35,    26,    21,
      55,    38,    39,    56,    57,    15,    58,    59,   108,   120,
     126,   109,   121,   114,   125,    94,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    99,   100
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
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

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
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

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
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

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
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


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 44 "1805047.y"
        {
	initiateAssembly();
}
#line 1356 "y.tab.c"
    break;

  case 3: /* start: $@1 program  */
#line 47 "1805047.y"
{
	string str = stackPop(program);
	stackPush(start, str);
	printLog("start", "program", "");
	printLineAndErrors();
}
#line 1367 "y.tab.c"
    break;

  case 4: /* program: program unit  */
#line 56 "1805047.y"
{
	string str = stackPop(program) + "\n" + stackPop(unit);
	stackPush(program, str);
	printLog("program", "program unit", str + "\n");
}
#line 1377 "y.tab.c"
    break;

  case 5: /* program: unit  */
#line 62 "1805047.y"
{
	string str = stackPop(unit);
	stackPush(program, str);
	printLog("program", "unit", str + "\n");
}
#line 1387 "y.tab.c"
    break;

  case 6: /* unit: var_declaration  */
#line 70 "1805047.y"
{
	string str = stackPop(var_declaration);
	stackPush(unit, str);
	printLog("unit", "var_declaration", str + "\n");
}
#line 1397 "y.tab.c"
    break;

  case 7: /* unit: func_declaration  */
#line 76 "1805047.y"
{
	string str = stackPop(func_declaration);
	stackPush(unit, str);
	printLog("unit", "func_declaration", str + "\n");
}
#line 1407 "y.tab.c"
    break;

  case 8: /* unit: func_definition  */
#line 82 "1805047.y"
{
	string str = stackPop(func_definition);
	stackPush(unit, str);
	printLog("unit", "func_definition", str + "\n");
}
#line 1417 "y.tab.c"
    break;

  case 9: /* func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON  */
#line 90 "1805047.y"
{
	string str = stackPop(type_specifier) + " " + (yyvsp[-4].symbolValue)->getName() + "(" + stackPop(parameter_list) + ");";
	setFunctionValues(*(yyvsp[-5].input_string), (yyvsp[-4].symbolValue), false);
	setAndClearFunctionThings();
	stackPush(func_declaration, str);
	printLog("func_declaration", "type_specifier ID LPAREN parameter_list RPAREN SEMICOLON", str + "\n");
}
#line 1429 "y.tab.c"
    break;

  case 10: /* func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON  */
#line 98 "1805047.y"
{
	string str = stackPop(type_specifier) + " " + (yyvsp[-3].symbolValue)->getName() + "();";
	setFunctionValues(*(yyvsp[-4].input_string), (yyvsp[-3].symbolValue), false);
	setAndClearFunctionThings();
	stackPush(func_declaration, str);
	printLog("func_declaration", "type_specifier ID LPAREN RPAREN SEMICOLON", str + "\n");
}
#line 1441 "y.tab.c"
    break;

  case 11: /* $@2: %empty  */
#line 108 "1805047.y"
{
	setFunctionValues(*(yyvsp[-4].input_string), (yyvsp[-3].symbolValue), true);
}
#line 1449 "y.tab.c"
    break;

  case 12: /* func_definition: type_specifier ID LPAREN parameter_list RPAREN $@2 compound_statement  */
#line 111 "1805047.y"
{
	string str = stackPop(type_specifier) + " " + (yyvsp[-5].symbolValue)->getName() + "(" + stackPop(parameter_list) + ")" + stackPop(compound_statement);
	stackPush(func_definition, str);
	printLog("func_definition", "type_specifier ID LPAREN parameter_list RPAREN compound_statement", str);
	addFunctionEndStatementInAsm(current_function->getName(), current_function->sequence_of_parameters.size(), current_function->return_label);

	printCurrentStatement((yyvsp[-5].symbolValue)->getName() + " function ended\n\n");
	current_function = nullptr;
}
#line 1463 "y.tab.c"
    break;

  case 13: /* $@3: %empty  */
#line 121 "1805047.y"
{
	setFunctionValues(*(yyvsp[-3].input_string), (yyvsp[-2].symbolValue), true);
}
#line 1471 "y.tab.c"
    break;

  case 14: /* func_definition: type_specifier ID LPAREN RPAREN $@3 compound_statement  */
#line 124 "1805047.y"
{
	string str = stackPop(type_specifier) + " " + (yyvsp[-4].symbolValue)->getName() + "()" + stackPop(compound_statement);
	stackPush(func_definition, str);
	printLog("func_definition", "type_specifier ID LPAREN RPAREN compound_statement", str);
	addFunctionEndStatementInAsm(current_function->getName(), current_function->sequence_of_parameters.size(), current_function->return_label);
	current_function = nullptr;
}
#line 1483 "y.tab.c"
    break;

  case 15: /* parameter_list: parameter_list COMMA type_specifier ID  */
#line 135 "1805047.y"
{
	string str = stackPop(parameter_list) + "," + stackPop(type_specifier) + " " + (yyvsp[0].symbolValue)->getName();
	stackPush(parameter_list, str);
	insertIntoParameters((yyvsp[0].symbolValue), *(yyvsp[-1].input_string));
	printLog("parameter_list", "parameter_list COMMA type_specifier ID", str);
}
#line 1494 "y.tab.c"
    break;

  case 16: /* parameter_list: parameter_list COMMA type_specifier  */
#line 142 "1805047.y"
{
	string str = stackPop(parameter_list) + "," + stackPop(type_specifier);
	stackPush(parameter_list, str);
	string name("#");
	name = name + to_string(count_of_parameters_without_name++);
	insertIntoParameters(new symbol_info(name, "ID"), *(yyvsp[0].input_string));
	printLog("parameter_list", "parameter_list COMMA type_specifier", str);
}
#line 1507 "y.tab.c"
    break;

  case 17: /* parameter_list: type_specifier ID  */
#line 151 "1805047.y"
{
	string str = stackPop(type_specifier) + " " + (yyvsp[0].symbolValue)->getName();
	stackPush(parameter_list, str);
	insertIntoParameters((yyvsp[0].symbolValue), *(yyvsp[-1].input_string));
	printLog("parameter_list", "type_specifier ID", str);
}
#line 1518 "y.tab.c"
    break;

  case 18: /* parameter_list: type_specifier  */
#line 158 "1805047.y"
{
	string str = stackPop(type_specifier);
	stackPush(parameter_list, str);
	string name("#");
	name = name + to_string(count_of_parameters_without_name++);
	insertIntoParameters(new symbol_info(name, "ID"), *(yyvsp[0].input_string));
	printLog("parameter_list", "type_specifier", str);
}
#line 1531 "y.tab.c"
    break;

  case 19: /* $@4: %empty  */
#line 170 "1805047.y"
{
	enterNewScope();
}
#line 1539 "y.tab.c"
    break;

  case 20: /* compound_statement: LCURL $@4 statements RCURL  */
#line 173 "1805047.y"
{
	string str = "{\n" + stackPop(statements) + "\n}";
	stackPush(compound_statement, str);
	printLog("compound_statement", "LCURL statements RCURL", str + "\n");

	printTable();
	exitScope();
}
#line 1552 "y.tab.c"
    break;

  case 21: /* $@5: %empty  */
#line 182 "1805047.y"
{
	enterNewScope();
}
#line 1560 "y.tab.c"
    break;

  case 22: /* compound_statement: LCURL $@5 RCURL  */
#line 185 "1805047.y"
{
	string str = "{}";
	stackPush(compound_statement, str);
	exitScope();
	printLog("compound_statement", "LCURL RCURL", str + "\n");
}
#line 1571 "y.tab.c"
    break;

  case 23: /* var_declaration: type_specifier declaration_list SEMICOLON  */
#line 194 "1805047.y"
{
	setVariableAndArrayValues(*(yyvsp[-2].input_string));
	stackPush(var_declaration, stackPop(type_specifier) + " " + stackPop(declaration_list) + ";");
	printLog("var_declaration", "type_specifier declaration_list SEMICOLON", *((yyvsp[-2].input_string)) + " " + *(yyvsp[-1].input_string) + ";");
}
#line 1581 "y.tab.c"
    break;

  case 24: /* type_specifier: INT  */
#line 202 "1805047.y"
{
	(yyval.input_string) = new string(yytext);
	printLog("type_specifier", "INT", yytext);
	stackPush(type_specifier, integer);
}
#line 1591 "y.tab.c"
    break;

  case 25: /* type_specifier: FLOAT  */
#line 208 "1805047.y"
{
	(yyval.input_string) = new string(yytext);
	printLog("type_specifier", "FLOAT", yytext);
	stackPush(type_specifier, fraction);
}
#line 1601 "y.tab.c"
    break;

  case 26: /* type_specifier: VOID  */
#line 214 "1805047.y"
{
	(yyval.input_string) = new string(yytext);
	printLog("type_specifier", "VOID", yytext);
	stackPush(type_specifier, "void");
}
#line 1611 "y.tab.c"
    break;

  case 27: /* declaration_list: declaration_list COMMA ID  */
#line 222 "1805047.y"
{
	(yyval.input_string) = new string((*(yyvsp[-2].input_string)) + ","+ (yyvsp[0].symbolValue)->getName());
	insertDeclarationListRecord((yyvsp[0].symbolValue));
	stackPush(declaration_list, stackPop(declaration_list) + "," + (yyvsp[0].symbolValue)->getName());
	printLog("declaration_list", "declaration_list COMMA ID", *(yyval.input_string));
}
#line 1622 "y.tab.c"
    break;

  case 28: /* declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD  */
#line 229 "1805047.y"
{
	(yyval.input_string) = new string((*(yyvsp[-5].input_string)) + ","+ (yyvsp[-3].symbolValue)->getName() + "[" + *(yyvsp[-1].input_string) + "]");
	insertDeclarationListRecord((yyvsp[-3].symbolValue), true, stoi(*(yyvsp[-1].input_string)));
	stackPush(declaration_list, stackPop(declaration_list) + "," +  (yyvsp[-3].symbolValue)->getName() + "[" + *(yyvsp[-1].input_string) + "]");
	printLog("declaration_list", "declaration_list COMMA ID LTHIRD CONST_INT RTHIRD", *(yyval.input_string));
}
#line 1633 "y.tab.c"
    break;

  case 29: /* declaration_list: ID  */
#line 236 "1805047.y"
{
	(yyval.input_string) = new string((yyvsp[0].symbolValue) -> getName());
	insertDeclarationListRecord((yyvsp[0].symbolValue));
	stackPush(declaration_list, (yyvsp[0].symbolValue)->getName());
	printLog("declaration_list", "ID", *(yyval.input_string));
}
#line 1644 "y.tab.c"
    break;

  case 30: /* declaration_list: ID LTHIRD CONST_INT RTHIRD  */
#line 243 "1805047.y"
{
	(yyval.input_string) = new string((yyvsp[-3].symbolValue)->getName() + "[" + *(yyvsp[-1].input_string) + "]");
	insertDeclarationListRecord((yyvsp[-3].symbolValue), true, stoi(*(yyvsp[-1].input_string)));
	stackPush(declaration_list, *(yyval.input_string));
	printLog("declaration_list", "ID LTHIRD CONST_INT RTHIRD", *(yyval.input_string));
}
#line 1655 "y.tab.c"
    break;

  case 31: /* statements: statement  */
#line 252 "1805047.y"
{
	string str = stackPop(statement);
	stackPush(statements, str);
	// fprintf(asmCodeOut, ";fuck me\npop ax\n");
	printLog("statements", "statement", str + "\n");
}
#line 1666 "y.tab.c"
    break;

  case 32: /* statements: statements statement  */
#line 259 "1805047.y"
{
	// fprintf(asmCodeOut, ";fuck me\npop ax\n");
	string str = stackPop(statements) + "\n" + stackPop(statement);
	stackPush(statements, str);
	printLog("statements", "statements statement", str + "\n");
}
#line 1677 "y.tab.c"
    break;

  case 33: /* statement: var_declaration  */
#line 268 "1805047.y"
{
	string str =  stackPop(var_declaration);
	stackPush(statement, str);
	printLog("statement", "var_declaration", str + "\n");
}
#line 1687 "y.tab.c"
    break;

  case 34: /* statement: expression_statement  */
#line 274 "1805047.y"
{
	string str =  stackPop(expression_statement);
	stackPush(statement, str);
	printLog("statement", "expression_statement", str + "\n");
}
#line 1697 "y.tab.c"
    break;

  case 35: /* statement: compound_statement  */
#line 280 "1805047.y"
{
	string str =  stackPop(compound_statement);
	stackPush(statement, str);
	printLog("statement", "compound_statement", str + "\n");
}
#line 1707 "y.tab.c"
    break;

  case 36: /* $@6: %empty  */
#line 285 "1805047.y"
                                            {
		string condition_label = newLabel();
		fprintf(asmCodeOut, "%s:\n", condition_label.c_str());
		(yyvsp[0].symbolValue)->inh_label = condition_label;
	  }
#line 1717 "y.tab.c"
    break;

  case 37: /* $@7: %empty  */
#line 289 "1805047.y"
                                 {
		string condition_false_label = newLabel();
		string start_statement = newLabel();
		string indecop_label = newLabel();
		fprintf(asmCodeOut, "mov ax, cx\ncmp ax, 0\nje %s\njmp %s\n%s:\n", condition_false_label.c_str(), start_statement.c_str(), indecop_label.c_str());
		(yyvsp[0].symbolValue)->inh_label = condition_false_label;
		(yyvsp[0].symbolValue)->inh_label2 = start_statement;
		(yyvsp[0].symbolValue)->inh_label3 = indecop_label;
	  }
#line 1731 "y.tab.c"
    break;

  case 38: /* $@8: %empty  */
#line 297 "1805047.y"
                       {
		fprintf(asmCodeOut, "pop cx\njmp %s\n%s:\n", (yyvsp[-4].symbolValue)->inh_label.c_str(), (yyvsp[-2].symbolValue)->inh_label2.c_str());
	  }
#line 1739 "y.tab.c"
    break;

  case 39: /* statement: FOR LPAREN expression_statement $@6 expression_statement $@7 expression $@8 RPAREN statement  */
#line 300 "1805047.y"
{
	string str1 = stackPop(expression_statement);
	string str2 = stackPop(expression_statement);
	string str = "for(" + str2 + str1 + stackPop(expression) + ")" + stackPop(statement);
	stackPush(statement, str);
	printLog("statement", "FOR LPAREN expression_statement expression_statement expression RPAREN statement", str + "\n");
	fprintf(asmCodeOut, "jmp %s\n%s:\n", (yyvsp[-5].symbolValue)->inh_label3.c_str(), (yyvsp[-5].symbolValue)->inh_label.c_str());
}
#line 1752 "y.tab.c"
    break;

  case 40: /* statement: IF LPAREN expression RPAREN label_if statement  */
#line 309 "1805047.y"
{
	string str = "if(" + stackPop(expression) + ")" + stackPop(statement);
	stackPush(statement, str);
	printLog("statement", "IF LPAREN expression RPAREN statement", str + "\n");
	fprintf(asmCodeOut, "%s:\n", (yyvsp[-1].temp)->c_str());
}
#line 1763 "y.tab.c"
    break;

  case 41: /* statement: IF LPAREN expression RPAREN label_if statement ELSE else_if_label statement  */
#line 316 "1805047.y"
{
	string str1 = stackPop(statement);
	string str2 = stackPop(statement);
	string str = "if (" + stackPop(expression) + ")" + str2 + "\nelse " + str1;
	stackPush(statement, str);
	printLog("statement", "IF LPAREN expression RPAREN statement ELSE statement", str + "\n");
	else_if_label = "";
	fprintf(asmCodeOut, "%s:\n", (yyvsp[-1].temp)->c_str());
}
#line 1777 "y.tab.c"
    break;

  case 42: /* $@9: %empty  */
#line 325 "1805047.y"
                                     {
		string condition_check_label = newLabel();
		fprintf(asmCodeOut, "%s:\n", condition_check_label.c_str());
		(yyvsp[0].temp) = new string(condition_check_label);
	  }
#line 1787 "y.tab.c"
    break;

  case 43: /* $@10: %empty  */
#line 329 "1805047.y"
                       {
		string condition_false_label = newLabel();
		fprintf(asmCodeOut, "pop ax\ncmp ax, 0\nje %s\n", condition_false_label.c_str());
		(yyvsp[0].symbolValue)->inh_label = condition_false_label;
	  }
#line 1797 "y.tab.c"
    break;

  case 44: /* statement: WHILE LPAREN while_label $@9 expression $@10 RPAREN statement  */
#line 334 "1805047.y"
{
	string str = "while (" + stackPop(expression) + ")" + stackPop(statement);
	stackPush(statement, str);
	printLog("statement", "WHILE LPAREN expression RPAREN statement", str + "\n");
	fprintf(asmCodeOut, "jmp %s\n%s:\n", (yyvsp[-5].temp)->c_str(), (yyvsp[-3].symbolValue)->inh_label.c_str());
}
#line 1808 "y.tab.c"
    break;

  case 45: /* statement: PRINTLN LPAREN ID RPAREN SEMICOLON  */
#line 341 "1805047.y"
{
	findVariable((yyvsp[-2].symbolValue));
	string str = "println(" + (yyvsp[-2].symbolValue)->getName() + ");";
	stackPush(statement, str);
	printCurrentStatement(str);
	printInAsm((yyvsp[-2].symbolValue)->temp_id);
	printLog("statement", "PRINTLN LPAREN ID RPAREN SEMICOLON", str + "\n");
}
#line 1821 "y.tab.c"
    break;

  case 46: /* statement: RETURN expression SEMICOLON  */
#line 350 "1805047.y"
{
	checkFuncReturnCompatibility((yyvsp[-1].symbolValue));
	string str = "return " + stackPop(expression) + ";";
	stackPush(statement, str);
	printLog("statement", "RETURN expression SEMICOLON", str + "\n");
}
#line 1832 "y.tab.c"
    break;

  case 47: /* label_if: %empty  */
#line 359 "1805047.y"
                {
			(yyval.temp) = new string(newLabel());
			fprintf(asmCodeOut, "pop ax\ncmp ax, 0\nje %s\n", (yyval.temp)->c_str());
		}
#line 1841 "y.tab.c"
    break;

  case 48: /* else_if_label: %empty  */
#line 365 "1805047.y"
                {
			if(else_if_label == "") 
				(yyval.temp) = new string(newLabel());
			else 
				(yyval.temp) = new string(else_if_label);
			fprintf(asmCodeOut, "jmp %s\n", (yyval.temp)->c_str());
			string temp = *(yyvsp[(-2) - (0)].temp);
			fprintf(asmCodeOut, "%s:\n", temp.c_str());
		}
#line 1855 "y.tab.c"
    break;

  case 49: /* while_label: %empty  */
#line 375 "1805047.y"
              {}
#line 1861 "y.tab.c"
    break;

  case 50: /* expression_statement: SEMICOLON  */
#line 378 "1805047.y"
{
	stackPush(expression_statement, ";");
	printLog("expression_statement", "SEMICOLON", ";");
}
#line 1870 "y.tab.c"
    break;

  case 51: /* expression_statement: expression SEMICOLON  */
#line 383 "1805047.y"
{

	fprintf(asmCodeOut, "pop cx\n");
	string str = stackPop(expression) + ";";
	stackPush(expression_statement, str);
	printLog("expression_statement", "expression SEMICOLON", str);
}
#line 1882 "y.tab.c"
    break;

  case 52: /* variable: ID  */
#line 395 "1805047.y"
{
	(yyval.symbolValue) = findVariable((yyvsp[0].symbolValue));
	stackPush(variable, (yyvsp[0].symbolValue)->getName());
	printLog("variable", "ID", (yyvsp[0].symbolValue)->getName());
}
#line 1892 "y.tab.c"
    break;

  case 53: /* variable: ID LTHIRD expression RTHIRD  */
#line 401 "1805047.y"
{
	(yyval.symbolValue) = checkArrayIndex((yyvsp[-3].symbolValue)->getName(), (yyvsp[-1].symbolValue));
	string str = (yyvsp[-3].symbolValue)->getName() + "["
	+ stackPop(expression) + "]";
	stackPush(variable, str);
	printLog("variable", "ID LTHIRD expression RTHIRD ", str);
}
#line 1904 "y.tab.c"
    break;

  case 54: /* expression: logic_expression  */
#line 411 "1805047.y"
{
	string str = stackPop(logic_expression);
	stackPush(expression, str);
	printLog("expression", "logic_expression", str);
}
#line 1914 "y.tab.c"
    break;

  case 55: /* expression: variable ASSIGNOP logic_expression  */
#line 417 "1805047.y"
{
	string str = stackPop(variable) + "=" + stackPop(logic_expression);
	stackPush(expression, str);
	printLog("expression", "variable ASSIGNOP logic_expression", str);

	(yyval.symbolValue) = checkAssignCompatibility((yyvsp[-2].symbolValue), (yyvsp[0].symbolValue));
}
#line 1926 "y.tab.c"
    break;

  case 56: /* logic_expression: rel_expression  */
#line 427 "1805047.y"
{
	string str = stackPop(rel_expression);
	stackPush(logic_expression, str);
	printLog("logic_expression", "rel_expression", str);
}
#line 1936 "y.tab.c"
    break;

  case 57: /* logic_expression: rel_expression LOGICOP rel_expression  */
#line 433 "1805047.y"
{
	(yyval.symbolValue) = checkLogicCompetibility((yyvsp[-2].symbolValue), *(yyvsp[-1].input_string), (yyvsp[0].symbolValue));
	string str1 = stackPop(rel_expression);
	string str2 = stackPop(rel_expression);
	string str = str2 + *(yyvsp[-1].input_string) + str1;
	stackPush(logic_expression, str);
	printLog("logic_expression", "rel_expression LOGICOP rel_expression ", str);
}
#line 1949 "y.tab.c"
    break;

  case 58: /* rel_expression: simple_expression  */
#line 444 "1805047.y"
{
	string str = stackPop(simple_expression);
	stackPush(rel_expression, str);
	printLog("rel_expression", "simple_expression", str);
}
#line 1959 "y.tab.c"
    break;

  case 59: /* rel_expression: simple_expression RELOP simple_expression  */
#line 450 "1805047.y"
{
	(yyval.symbolValue) = checkRELOPCompetibility((yyvsp[-2].symbolValue), *(yyvsp[-1].input_string), (yyvsp[0].symbolValue));
	string str1 = stackPop(simple_expression);
	string str2 = stackPop(simple_expression);
	string str = str2 + *(yyvsp[-1].input_string) + str1;
	stackPush(rel_expression, str);
	printLog("rel_expression", "simple_expression RELOP simple_expression	", str);
}
#line 1972 "y.tab.c"
    break;

  case 60: /* simple_expression: term  */
#line 461 "1805047.y"
{
	(yyval.symbolValue) = (yyvsp[0].symbolValue);
	string str = stackPop(term);
	stackPush(simple_expression, str);
	printLog("simple_expression", "term", str);
}
#line 1983 "y.tab.c"
    break;

  case 61: /* simple_expression: simple_expression ADDOP term  */
#line 468 "1805047.y"
{
	(yyval.symbolValue) = checkAdditionCompatibility((yyvsp[-2].symbolValue), *(yyvsp[-1].input_string), (yyvsp[0].symbolValue));
	string str = stackPop(simple_expression) + *(yyvsp[-1].input_string) + stackPop(term);
	stackPush(simple_expression, str);
	printLog("simple_expression", "simple_expression ADDOP term", str);
}
#line 1994 "y.tab.c"
    break;

  case 62: /* term: unary_expression  */
#line 477 "1805047.y"
{
	string str = stackPop(unary_expression);
	stackPush(term, str);
	printLog("term", "unary_expression", str);
}
#line 2004 "y.tab.c"
    break;

  case 63: /* term: term MULOP unary_expression  */
#line 483 "1805047.y"
{

	(yyval.symbolValue) = checkAndDoMulopThings((yyvsp[-2].symbolValue), *(yyvsp[-1].input_string), (yyvsp[0].symbolValue));
	string str = stackPop(term) + *(yyvsp[-1].input_string) + stackPop(unary_expression);
	stackPush(term, str);
	printLog("term", "term MULOP unary_expression", str);
}
#line 2016 "y.tab.c"
    break;

  case 64: /* unary_expression: ADDOP unary_expression  */
#line 493 "1805047.y"
{
	(yyval.symbolValue) = checkUnaryADDOPThings(*(yyvsp[-1].input_string), (yyvsp[0].symbolValue));
	string str = *(yyvsp[-1].input_string) + stackPop(unary_expression);
	stackPush(unary_expression, str);
	printLog("unary_expression", "ADDOP unary_expression", str);
}
#line 2027 "y.tab.c"
    break;

  case 65: /* unary_expression: NOT unary_expression  */
#line 500 "1805047.y"
{
	(yyval.symbolValue) = checkNotCompatibility((yyvsp[0].symbolValue));
	string str = "!" + stackPop(unary_expression);
	stackPush(unary_expression, str);
	printLog("unary_expression", "ADDOP unary_expression", str);
}
#line 2038 "y.tab.c"
    break;

  case 66: /* unary_expression: factor  */
#line 507 "1805047.y"
{
	string str = stackPop(factor);
	stackPush(unary_expression, str);
	printLog("unary_expression", "factor", str);
}
#line 2048 "y.tab.c"
    break;

  case 67: /* factor: variable  */
#line 515 "1805047.y"
{
	
	string str = stackPop(variable);
	stackPush(factor, str);
	printLog("factor", "variable", str);
	printCurrentStatement(str);
	// string temp = newTemp();
	// $$ = new symbol_info(str, "intermediate");
	// $$->setAllValueOf($1);
	// bufferingVariable(temp, $1->temp_id, $$->temp_index);
	// $$->temp_id = temp;
	pushToStackTemp((yyvsp[0].symbolValue)->temp_id);
}
#line 2066 "y.tab.c"
    break;

  case 68: /* factor: ID LPAREN argument_list RPAREN  */
#line 529 "1805047.y"
{
	string str = (yyvsp[-3].symbolValue)->getName() + "(" + stackPop(argument_list) + ")";
	stackPush(factor, str);
	printLog("factor", "ID LPAREN argument_list RPAREN", str);
	(yyval.symbolValue) = checkFunctionArguments((yyvsp[-3].symbolValue));
}
#line 2077 "y.tab.c"
    break;

  case 69: /* factor: LPAREN expression RPAREN  */
#line 536 "1805047.y"
{
	(yyval.symbolValue) = checkLPAREN_Expression_RPAREN((yyvsp[-1].symbolValue));
	string str = "(" + stackPop(expression) + ")";
	stackPush(factor, str);
	printLog("factor", "LPAREN expression RPAREN", str);
}
#line 2088 "y.tab.c"
    break;

  case 70: /* factor: CONST_INT  */
#line 543 "1805047.y"
{
	(yyval.symbolValue) = setIntermediateValues("intermediate", integer, stoi(*(yyvsp[0].input_string)));
	stackPush(factor, *(yyvsp[0].input_string));
	printLog("factor", "CONST_INT", *(yyvsp[0].input_string));
}
#line 2098 "y.tab.c"
    break;

  case 71: /* factor: CONST_FLOAT  */
#line 549 "1805047.y"
{
	(yyval.symbolValue) = setIntermediateValues("intermediate", "float", stof(*(yyvsp[0].input_string)));
	stackPush(factor, *(yyvsp[0].input_string));
	printLog("factor", "CONST_FLOAT", *(yyvsp[0].input_string));
}
#line 2108 "y.tab.c"
    break;

  case 72: /* factor: variable INCOP  */
#line 555 "1805047.y"
{
	(yyval.symbolValue) = checkINCOPCompatibility((yyvsp[-1].symbolValue));
	string str = stackPop(variable) + "++";
	stackPush(factor, str);
	printLog("factor", "variable INCOP", str);
}
#line 2119 "y.tab.c"
    break;

  case 73: /* factor: variable DECOP  */
#line 562 "1805047.y"
{
	(yyval.symbolValue) = checkDECOPCompatibility((yyvsp[-1].symbolValue));
	string str = stackPop(variable) + "--";
	stackPush(factor, str);
	printLog("factor", "variable DECOP", str);
}
#line 2130 "y.tab.c"
    break;

  case 74: /* argument_list: arguments  */
#line 571 "1805047.y"
{
	string str = stackPop(arguments);
	stackPush(argument_list, str);
	printLog("argument_list", "arguments", str);
}
#line 2140 "y.tab.c"
    break;

  case 75: /* argument_list: %empty  */
#line 577 "1805047.y"
{
	stackPush(argument_list, "");
	printLog("argument_list", "", "");
}
#line 2149 "y.tab.c"
    break;

  case 76: /* arguments: arguments COMMA logic_expression  */
#line 584 "1805047.y"
{
	args.push_back((yyvsp[0].symbolValue));
	// pushToStackTemp();
	string str = stackPop(arguments) + "," + stackPop(logic_expression);
	stackPush(arguments, str);
	printLog("arguments", "arguments COMMA logic_expression", str);
}
#line 2161 "y.tab.c"
    break;

  case 77: /* arguments: logic_expression  */
#line 592 "1805047.y"
{

	// pushToStack($1->temp_id);
	args.push_back((yyvsp[0].symbolValue));
	string str = stackPop(logic_expression);
	stackPush(arguments, str);
	printLog("arguments", "logic_expression", str);
}
#line 2174 "y.tab.c"
    break;


#line 2178 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 603 "1805047.y"


void concatFile(FILE* wholeasm, FILE* asmDataOut, FILE* asmCodeOut, FILE* asmPrintOut){
	char ch;
	// cout << has_main_function << endl;
	if(!has_main_function || syntax_error_count + lexical_error_count > 0) {
		printError("program has no main function");
		return;
	}
	do {
        ch = fgetc(asmDataOut);
		if(ch == EOF) break;
        fprintf(wholeasm, "%c", ch);
 
        // Checking if character is not EOF.
        // If it is EOF stop eading.
    } while (ch != EOF);
	do {
        ch = fgetc(asmCodeOut);

		if(ch == EOF) break;
        fprintf(wholeasm, "%c", ch);
 
        // Checking if character is not EOF.
        // If it is EOF stop eading.
    } while (ch != EOF);

	do {
        ch = fgetc(asmPrintOut);

		if(ch == EOF) break;
        fprintf(wholeasm, "%c", ch);
 
        // Checking if character is not EOF.
        // If it is EOF stop eading.
    } while (ch != EOF);
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
	wholeasm = fopen("1805047.asm", "w");

	concatFile(wholeasm, asmDataOut, asmCodeOut,asmPrintOut);

	fclose(asmDataOut);
	fclose(asmCodeOut);
	fclose(wholeasm);
	fclose(logout);
	fclose(errorout);
	return 0;
}
