/* A Bison parser, made by GNU Bison 3.7.5.  */

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
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "1705070_backup.y"

#include<bits/stdc++.h>
#include "SymbolTable.cpp"

using namespace std;

int yyparse(void);
int yylex(void);
extern FILE *yyin;

extern int numberOfLines;
extern int numberOfErrors;

FILE* logs;
FILE* errors;

SymbolTable symbolTable(30);
// Symbol Set(s)
map<string, string> SymbolSet;
vector< pair<string,string> >temp_param_list;
vector< pair<string,string> >arg_param_list;
vector<SymbolInfo*>v;

string type_of_var, statement_solver, return_type_solver, named;
bool is_func = false;
int control_arg;
int scope_counter = 1;
int scope_counter_2 = 0;
string running_f_name = "";
string scope_holder = "";

// error detection
void yyerror(const char *s){
	numberOfErrors++;
    fprintf(errors, "Line no %d: %s\n", numberOfLines, s);
}

string stringAdder(int count, ...){
	va_list varStringList;
	int counter;
	const char* t;
	string s;
	va_start(varStringList, count);
	for(int counter=0;counter<count;counter++){
		t = va_arg(varStringList, const char*);
		string temp(t);
		s += temp;
	}
	va_end(varStringList);
	return s;
}

void symbolSet()
{
    SymbolSet["comma"] = ",";
	SymbolSet["semicolon"] = ";";
	SymbolSet["left_third"] = "[";
	SymbolSet["right_third"] = "]";
	SymbolSet["newline"] = "\n";
	SymbolSet["left_first"] = "(";
	SymbolSet["right_first"] = ")";
	SymbolSet["equal"] = "=";
	SymbolSet["plus"] = "+";
	SymbolSet["minus"] = "-";
	SymbolSet["left_curl"] = "{";
	SymbolSet["right_curl"] = "}";
	SymbolSet["incop"] = "++";
	SymbolSet["decop"] = "--";
}
// get it
string getFromSymbolSet(string name)
{
	return SymbolSet.at(name);
}

#line 147 "1705070_backup.tab.c"

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

#include "1705070_backup.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_FOR = 3,                        /* FOR  */
  YYSYMBOL_IF = 4,                         /* IF  */
  YYSYMBOL_DO = 5,                         /* DO  */
  YYSYMBOL_INT = 6,                        /* INT  */
  YYSYMBOL_FLOAT = 7,                      /* FLOAT  */
  YYSYMBOL_VOID = 8,                       /* VOID  */
  YYSYMBOL_COMMA = 9,                      /* COMMA  */
  YYSYMBOL_SEMICOLON = 10,                 /* SEMICOLON  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_WHILE = 12,                     /* WHILE  */
  YYSYMBOL_DOUBLE = 13,                    /* DOUBLE  */
  YYSYMBOL_CHAR = 14,                      /* CHAR  */
  YYSYMBOL_RETURN = 15,                    /* RETURN  */
  YYSYMBOL_CONTINUE = 16,                  /* CONTINUE  */
  YYSYMBOL_PRINTLN = 17,                   /* PRINTLN  */
  YYSYMBOL_ASSIGNOP = 18,                  /* ASSIGNOP  */
  YYSYMBOL_LPAREN = 19,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 20,                    /* RPAREN  */
  YYSYMBOL_LCURL = 21,                     /* LCURL  */
  YYSYMBOL_RCURL = 22,                     /* RCURL  */
  YYSYMBOL_LTHIRD = 23,                    /* LTHIRD  */
  YYSYMBOL_RTHIRD = 24,                    /* RTHIRD  */
  YYSYMBOL_CONST_INT = 25,                 /* CONST_INT  */
  YYSYMBOL_CONST_FLOAT = 26,               /* CONST_FLOAT  */
  YYSYMBOL_CONST_CHAR = 27,                /* CONST_CHAR  */
  YYSYMBOL_ADDOP = 28,                     /* ADDOP  */
  YYSYMBOL_MULOP = 29,                     /* MULOP  */
  YYSYMBOL_LOGICOP = 30,                   /* LOGICOP  */
  YYSYMBOL_BITOP = 31,                     /* BITOP  */
  YYSYMBOL_RELOP = 32,                     /* RELOP  */
  YYSYMBOL_INCOP = 33,                     /* INCOP  */
  YYSYMBOL_DECOP = 34,                     /* DECOP  */
  YYSYMBOL_ID = 35,                        /* ID  */
  YYSYMBOL_NOT = 36,                       /* NOT  */
  YYSYMBOL_LOWER_PREC_THAN_ELSE = 37,      /* LOWER_PREC_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 38,                  /* $accept  */
  YYSYMBOL_start = 39,                     /* start  */
  YYSYMBOL_program = 40,                   /* program  */
  YYSYMBOL_unit = 41,                      /* unit  */
  YYSYMBOL_func_declaration = 42,          /* func_declaration  */
  YYSYMBOL_func_definition = 43,           /* func_definition  */
  YYSYMBOL_44_1 = 44,                      /* $@1  */
  YYSYMBOL_45_2 = 45,                      /* $@2  */
  YYSYMBOL_parameter_list = 46,            /* parameter_list  */
  YYSYMBOL_compound_statement = 47,        /* compound_statement  */
  YYSYMBOL_48_3 = 48,                      /* $@3  */
  YYSYMBOL_49_4 = 49,                      /* $@4  */
  YYSYMBOL_var_declaration = 50,           /* var_declaration  */
  YYSYMBOL_type_specifier = 51,            /* type_specifier  */
  YYSYMBOL_declaration_list = 52,          /* declaration_list  */
  YYSYMBOL_statements = 53,                /* statements  */
  YYSYMBOL_statement = 54,                 /* statement  */
  YYSYMBOL_expression_statement = 55,      /* expression_statement  */
  YYSYMBOL_variable = 56,                  /* variable  */
  YYSYMBOL_expression = 57,                /* expression  */
  YYSYMBOL_logic_expression = 58,          /* logic_expression  */
  YYSYMBOL_rel_expression = 59,            /* rel_expression  */
  YYSYMBOL_simple_expression = 60,         /* simple_expression  */
  YYSYMBOL_term = 61,                      /* term  */
  YYSYMBOL_unary_expression = 62,          /* unary_expression  */
  YYSYMBOL_factor = 63,                    /* factor  */
  YYSYMBOL_argument_list = 64,             /* argument_list  */
  YYSYMBOL_arguments = 65                  /* arguments  */
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
typedef yytype_int8 yy_state_t;

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

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   148

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  122

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   114,   114,   119,   124,   130,   134,   138,   144,   212,
     243,   243,   353,   353,   393,   400,   407,   415,   423,   423,
     455,   455,   487,   495,   504,   512,   522,   541,   562,   582,
     609,   613,   620,   624,   628,   632,   647,   658,   670,   681,
     685,   699,   703,   710,   738,   776,   781,   819,   825,   840,
     846,   863,   868,   896,   901,   979,   989,  1000,  1009,  1014,
    1079,  1088,  1098,  1107,  1112,  1119,  1131,  1136,  1152
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "FOR", "IF", "DO",
  "INT", "FLOAT", "VOID", "COMMA", "SEMICOLON", "ELSE", "WHILE", "DOUBLE",
  "CHAR", "RETURN", "CONTINUE", "PRINTLN", "ASSIGNOP", "LPAREN", "RPAREN",
  "LCURL", "RCURL", "LTHIRD", "RTHIRD", "CONST_INT", "CONST_FLOAT",
  "CONST_CHAR", "ADDOP", "MULOP", "LOGICOP", "BITOP", "RELOP", "INCOP",
  "DECOP", "ID", "NOT", "LOWER_PREC_THAN_ELSE", "$accept", "start",
  "program", "unit", "func_declaration", "func_definition", "$@1", "$@2",
  "parameter_list", "compound_statement", "$@3", "$@4", "var_declaration",
  "type_specifier", "declaration_list", "statements", "statement",
  "expression_statement", "variable", "expression", "logic_expression",
  "rel_expression", "simple_expression", "term", "unary_expression",
  "factor", "argument_list", "arguments", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292
};
#endif

#define YYPACT_NINF (-69)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-21)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      84,   -69,   -69,   -69,    25,    84,   -69,   -69,   -69,   -69,
      -2,   -69,   -69,    30,    50,     6,    22,    20,   -69,    47,
      -5,    35,    48,    54,   -69,    58,    84,    71,   -69,   -69,
      59,    63,   -69,    53,   -69,    58,    69,    95,    72,   -69,
     -69,   -69,    76,    81,   -69,    85,    99,    87,    99,   -69,
     -69,    99,    33,    99,   -69,   -69,    73,    61,   -69,   -69,
       3,   101,   -69,    79,    26,    86,   -69,   -69,   -69,    -8,
      99,    99,   103,    82,   102,    41,   -69,    99,    99,   -69,
      96,   -69,   -69,    99,   -69,   -69,   -69,    99,    99,    99,
      99,    -8,   106,   108,   -69,   109,   -69,   -69,   112,   124,
     113,   -69,   -69,    86,   110,   -69,    99,    95,    95,   126,
     -69,    99,   -69,   119,   129,   -69,   -69,   -69,    95,    95,
     -69,   -69
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    23,    24,    25,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    28,     0,     0,     0,     0,    22,    12,
       0,    17,     0,    26,     9,     0,     0,    10,    16,    29,
       0,    18,    13,    15,     8,     0,     0,     0,     0,    14,
      11,    27,     0,     0,    41,     0,     0,     0,     0,    61,
      62,     0,    43,     0,    34,    32,     0,     0,    30,    33,
      58,     0,    45,    47,    49,    51,    53,    57,    21,     0,
       0,     0,     0,     0,     0,    58,    55,    66,     0,    56,
      28,    19,    31,     0,    63,    64,    42,     0,     0,     0,
       0,     0,     0,     0,    40,     0,    60,    68,     0,    65,
       0,    46,    48,    52,    50,    54,     0,     0,     0,     0,
      59,     0,    44,     0,    36,    38,    39,    67,     0,     0,
      35,    37
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -69,   -69,   -69,   136,   -69,   -69,   -69,   -69,   -69,    -3,
     -69,   -69,    43,    19,   -69,   -69,   -57,   -68,   -48,   -40,
     -67,    55,    56,    60,   -44,   -69,   -69,   -69
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,    35,    25,    20,    54,
      37,    38,    55,    56,    14,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    98,    99
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      82,    91,    44,    75,    26,    75,    72,    76,    74,    79,
      97,    48,     1,     2,     3,    27,   101,    49,    50,    10,
      51,    83,    32,   106,    10,    11,    19,    52,    53,    75,
      92,    93,    40,    13,    21,    75,    84,    85,   100,    75,
      75,    75,    75,     9,   117,    33,   105,    22,     9,    15,
     114,   115,    77,    16,    88,    23,    78,    24,    89,    17,
      18,   120,   121,    75,    42,    43,   113,     1,     2,     3,
      28,    44,    29,    45,    84,    85,    46,    30,    47,    31,
      48,    34,    31,    81,    36,   -20,    49,    50,    39,    51,
       1,     2,     3,    41,    68,    69,    52,    53,    42,    43,
      70,     1,     2,     3,    71,    44,    73,    45,    80,    87,
      46,    86,    47,    94,    48,    90,    31,    95,    48,    16,
      49,    50,    96,    51,    49,    50,   107,    51,   108,   109,
      52,    53,   110,   111,    52,    53,   116,   112,    88,   118,
     119,    12,   102,     0,     0,   104,     0,     0,   103
};

static const yytype_int8 yycheck[] =
{
      57,    69,    10,    51,     9,    53,    46,    51,    48,    53,
      77,    19,     6,     7,     8,    20,    83,    25,    26,     0,
      28,    18,    25,    91,     5,     0,    20,    35,    36,    77,
      70,    71,    35,    35,    15,    83,    33,    34,    78,    87,
      88,    89,    90,     0,   111,    26,    90,    25,     5,    19,
     107,   108,    19,    23,    28,    35,    23,    10,    32,     9,
      10,   118,   119,   111,     3,     4,   106,     6,     7,     8,
      35,    10,    24,    12,    33,    34,    15,    23,    17,    21,
      19,    10,    21,    22,    25,    22,    25,    26,    35,    28,
       6,     7,     8,    24,    22,    19,    35,    36,     3,     4,
      19,     6,     7,     8,    19,    10,    19,    12,    35,    30,
      15,    10,    17,    10,    19,    29,    21,    35,    19,    23,
      25,    26,    20,    28,    25,    26,    20,    28,    20,    20,
      35,    36,    20,     9,    35,    36,    10,    24,    28,    20,
      11,     5,    87,    -1,    -1,    89,    -1,    -1,    88
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     7,     8,    39,    40,    41,    42,    43,    50,
      51,     0,    41,    35,    52,    19,    23,     9,    10,    20,
      46,    51,    25,    35,    10,    45,     9,    20,    35,    24,
      23,    21,    47,    51,    10,    44,    25,    48,    49,    35,
      47,    24,     3,     4,    10,    12,    15,    17,    19,    25,
      26,    28,    35,    36,    47,    50,    51,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    22,    19,
      19,    19,    57,    19,    57,    56,    62,    19,    23,    62,
      35,    22,    54,    18,    33,    34,    10,    30,    28,    32,
      29,    55,    57,    57,    10,    35,    20,    58,    64,    65,
      57,    58,    59,    61,    60,    62,    55,    20,    20,    20,
      20,     9,    24,    57,    54,    54,    10,    58,    20,    11,
      54,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    41,    42,    42,
      44,    43,    45,    43,    46,    46,    46,    46,    48,    47,
      49,    47,    50,    51,    51,    51,    52,    52,    52,    52,
      53,    53,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    55,    55,    56,    56,    57,    57,    58,    58,    59,
      59,    60,    60,    61,    61,    62,    62,    62,    63,    63,
      63,    63,    63,    63,    63,    64,    64,    65,    65
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       0,     7,     0,     6,     4,     3,     2,     1,     0,     4,
       0,     3,     3,     1,     1,     1,     3,     6,     1,     4,
       1,     2,     1,     1,     1,     7,     5,     7,     5,     5,
       3,     1,     2,     1,     4,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     2,     2,     1,     1,     4,
       3,     1,     1,     2,     2,     1,     0,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
  case 2: /* start: program  */
#line 114 "1705070_backup.y"
                {
	fprintf(logs, "Line %d: start : program\n\n\n",numberOfLines-1);
	symbolTable.printAllTable(logs);
}
#line 1568 "1705070_backup.tab.c"
    break;

  case 3: /* program: program unit  */
#line 119 "1705070_backup.y"
                       {
	fprintf(logs, "Line %d: program : program unit\n\n", numberOfLines);
	(yyval.symbolInfoPointer) -> extraSymbolInfo.stringAdder(getFromSymbolSet("newline") + (yyvsp[0].symbolInfoPointer) -> extraSymbolInfo.stringConcatenator);
	fprintf(logs,"%s\n\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
	}
#line 1578 "1705070_backup.tab.c"
    break;

  case 4: /* program: unit  */
#line 124 "1705070_backup.y"
               {
	fprintf(logs, "Line %d: program : unit\n\n", numberOfLines);
	(yyval.symbolInfoPointer) -> extraSymbolInfo.stringConcatenator = (yyvsp[0].symbolInfoPointer) -> extraSymbolInfo.stringConcatenator;
	fprintf(logs,"%s\n\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 1588 "1705070_backup.tab.c"
    break;

  case 5: /* unit: var_declaration  */
#line 130 "1705070_backup.y"
                      {
	fprintf(logs, "Line %d: unit : var_declaration\n\n", numberOfLines);
	(yyval.symbolInfoPointer) -> extraSymbolInfo.stringConcatenator = (yyvsp[0].symbolInfoPointer) -> extraSymbolInfo.stringConcatenator;
	fprintf(logs,"%s\n\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 1598 "1705070_backup.tab.c"
    break;

  case 6: /* unit: func_declaration  */
#line 134 "1705070_backup.y"
                    {
	fprintf(logs, "Line %d: unit : func_declaration\n\n", numberOfLines);
	(yyval.symbolInfoPointer) -> extraSymbolInfo.stringConcatenator = (yyvsp[0].symbolInfoPointer)-> extraSymbolInfo.stringConcatenator;
	fprintf(logs,"%s\n\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 1608 "1705070_backup.tab.c"
    break;

  case 7: /* unit: func_definition  */
#line 138 "1705070_backup.y"
                   {
	fprintf(logs, "Line %d: unit : func_definition\n\n", numberOfLines);
	(yyval.symbolInfoPointer) -> extraSymbolInfo.stringConcatenator = (yyvsp[0].symbolInfoPointer)-> extraSymbolInfo.stringConcatenator;
	fprintf(logs,"%s\n\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 1618 "1705070_backup.tab.c"
    break;

  case 8: /* func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON  */
#line 144 "1705070_backup.y"
                                                                           {
	/* We need to check some properties of function declaration in this step:
			1. Check return type is same
			2. Check number of parameter is same
			3. Check parameter sequence is same
			4. No void Parameters are declared
			*/
	fprintf(logs, "Line %d: func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n\n", numberOfLines);
	SymbolInfo* temp = symbolTable.LookUp((yyvsp[-4].symbolInfoPointer)->getName());

	// if it found in symbol table
	if(temp != 0){

		// Checking return type
		if(temp->extraSymbolInfo.returnTypeOfFunction != (yyvsp[-5].symbolInfoPointer)->getType()){
			numberOfErrors++;
			fprintf(errors, "Error at line %d : Return Type Mismatch of function declaration\n\n", numberOfLines);
		}

		// Checking parameter
		if(temp->extraSymbolInfo.functionParamList.size()!=temp_param_list.size()){
			numberOfErrors++;
			fprintf(errors, "Error at line %d: Unequal number of parameters\n\n", numberOfLines++);
			temp_param_list.clear();
		}
		// Checking parameter sequence
		else{
			for(int i=0;i<temp_param_list.size();i++){
				if(temp_param_list[i].second != temp->extraSymbolInfo.functionParamList[i].second){
					numberOfErrors++;
					fprintf(errors, "Argument Type Mismatch with previous function declaration \n\n", numberOfLines);
				}
			}
			temp_param_list.clear();
		}
	}
	// if not found in symbol table
	else{
		// variable to check void type
		bool isVoid = false;
		// checking no void parameter is declared
		for(int i=0;i<temp_param_list.size();i++){
			if(temp_param_list[i].second=="VOID"){
				isVoid = true; 
				break;
			}
		}
		SymbolInfo* temp = new SymbolInfo();
		temp->extraSymbolInfo.typeOfID = "FUNCTION";
		temp->extraSymbolInfo.returnTypeOfFunction = (yyvsp[-5].symbolInfoPointer)->getType();
		temp->extraSymbolInfo.isFunction = true;
		temp->extraSymbolInfo.isFunctionDeclared = true;
		temp->setName((yyvsp[-4].symbolInfoPointer)->getName());
		temp->setType((yyvsp[-4].symbolInfoPointer)->getType());

		if(isVoid){
			numberOfErrors++;
			fprintf(errors, "Error at line %d: Parameter cannot be void \n\n", numberOfLines);
			temp->extraSymbolInfo.isFunction = false;
		}
		for(int i=0;i<temp_param_list.size();i++){
			temp->extraSymbolInfo.functionParamList.push_back(make_pair(temp_param_list[i].first, temp_param_list[i].second));
		}
		temp_param_list.clear();
		symbolTable.InsertModified(temp);
	}
	(yyval.symbolInfoPointer) -> extraSymbolInfo.stringConcatenator = (yyvsp[-5].symbolInfoPointer)->extraSymbolInfo.stringConcatenator + (yyvsp[-4].symbolInfoPointer)->getName()+getFromSymbolSet("left_first")+(yyvsp[-2].symbolInfoPointer)->extraSymbolInfo.stringConcatenator+getFromSymbolSet("right_first")+getFromSymbolSet("semicolon");
	fprintf(logs, "%s\n\n\n", (yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 1692 "1705070_backup.tab.c"
    break;

  case 9: /* func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON  */
#line 212 "1705070_backup.y"
                                              {
	fprintf(logs, "Line %d: func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n\n", numberOfLines);
	SymbolInfo* temp = symbolTable.LookUp((yyvsp[-3].symbolInfoPointer)->getName());
	if(temp != 0){
		if(temp->extraSymbolInfo.returnTypeOfFunction != (yyvsp[-4].symbolInfoPointer)->getType()){
			numberOfErrors++;
			fprintf(errors, "Error at Line %d: Return Type Mismatch of function declaration \n\n", numberOfLines);
		}
		if(temp->extraSymbolInfo.functionParamList.size()!=0){
			numberOfErrors++;
			fprintf(errors, "Error at Line %d : Unequal number of parameters\n\n", numberOfLines);
			temp_param_list.clear();
		} }else{
			SymbolInfo* temp = new SymbolInfo();
			temp->extraSymbolInfo.typeOfID = "FUNCTION";
			temp->extraSymbolInfo.returnTypeOfFunction = (yyvsp[-4].symbolInfoPointer)->getType();
			temp->extraSymbolInfo.isFunction = true;
			temp->extraSymbolInfo.isFunctionDeclared = true;
			temp->setName((yyvsp[-3].symbolInfoPointer)->getName());
			temp->setType((yyvsp[-3].symbolInfoPointer)->getType());

			for(int i=0;i<temp_param_list.size();i++){
				temp->extraSymbolInfo.functionParamList.push_back(make_pair(temp_param_list[i].first, temp_param_list[i].second));
			}
			temp_param_list.clear();
			symbolTable.InsertModified(temp);
		}
		(yyval.symbolInfoPointer) -> extraSymbolInfo.stringConcatenator = (yyvsp[-4].symbolInfoPointer)->extraSymbolInfo.stringConcatenator + (yyvsp[-3].symbolInfoPointer)->getName()+getFromSymbolSet("left_first")+getFromSymbolSet("right_first")+getFromSymbolSet("semicolon");
	fprintf(logs, "%s\n\n\n", (yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 1727 "1705070_backup.tab.c"
    break;

  case 10: /* $@1: %empty  */
#line 243 "1705070_backup.y"
                                                                {
		// scope_counter = scope_counter + 1
		fprintf(logs, "Line %d: func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n", numberOfLines);
		SymbolInfo *s = symbolTable.LookUp((yyvsp[-3].symbolInfoPointer)->getName());
		SymbolInfo *temp = new SymbolInfo();
		bool flag = true;
		// if it doest not exixts in any scope then insert the ID into
		if(s==0){
			bool check = false;
			for(int i=0;i<temp_param_list.size();i++){
				if(temp_param_list[i].second == "VOID"){
					check = true;
				}
			}

			// make a new object to insert into Symbol Table
			temp->extraSymbolInfo.typeOfID = "FUNCTION";
			temp->extraSymbolInfo.returnTypeOfFunction = (yyvsp[-4].symbolInfoPointer)->getType();
			temp->extraSymbolInfo.isFunction = true;
			temp->extraSymbolInfo.isFunctionDefined = true;
			temp->setName((yyvsp[-3].symbolInfoPointer)->getName());
			temp->setType((yyvsp[-3].symbolInfoPointer)->getType());

			if(check){
				numberOfErrors++;
				fprintf(errors, "Error at line %d : Parameter cannot be VOID\n\n", numberOfLines);
				temp->extraSymbolInfo.isFunction=false;
			}

			for(int i=0;i<temp_param_list.size();i++){
				temp->extraSymbolInfo.functionParamList.push_back(make_pair(temp_param_list[i].first, temp_param_list[i].second));
				// string t = temp_param_list[i].first+to_string(scope_counter);
				// temp->extraSymbolInfo.modfd_param_list.push_back(t);               
				// pushing to the modified paramater list of the pointer
			}

			/*if(return_type_solver!=$1->getType())
			{
				numberOfErrors++;
				fprintf(errors,"Error at Line %d : return type error \n\n",numberOfLines);
				return_type_solver="";
				temp->extraSymbolInfo.isFunction=false;
			}*/
			symbolTable.InsertModified(temp);
			//temp_param_list.clear();
		}
		// if it already exists in global scope
		else{
			// function already exists
			if(s->extraSymbolInfo.isFunctionDefined){
				numberOfErrors++;
				fprintf(errors, "Error at line %d: Multiple definition of function\n\n", numberOfLines);
				temp_param_list.clear();
			}else if(s->extraSymbolInfo.isFunctionDeclared){
				/* Three case to handle here 
				1. Return type check 
				2. Check number of parameters and
				3. Check for sequence of parameters */
				s->extraSymbolInfo.isFunctionDefined = true;
				string actReturnType = (yyvsp[-4].symbolInfoPointer)->getType();
				string declaredReturnType = s->extraSymbolInfo.returnTypeOfFunction;
				int declaredParamSize = s->extraSymbolInfo.functionParamList.size();
				int definedParamSize = temp_param_list.size();

				// Case 1: Return type Check
				if(actReturnType != declaredReturnType){
					numberOfErrors++;
					fprintf(errors, "Error at line %d: Return type mismatch\n\n", numberOfLines);
					flag = false;
				}
				// Case 2: Check for size of paramter list
				else if(definedParamSize != definedParamSize){
					numberOfErrors++;
					fprintf(errors, "Error at line %d: Unequal number of parameters\n\n", numberOfLines);
					temp_param_list.clear();
					flag = false;
				}
				// Case 3: Check for sequence of parameter list 
				else{
					for(int i = 0;i<temp_param_list.size();i++){
						if(temp_param_list[i].second != s->extraSymbolInfo.functionParamList[i].second){
							numberOfErrors++;
							fprintf(errors, "Error at line %d: Argument Type Mismathch with function declaration\n\n", numberOfLines);
							flag=false;
							break;
						}
					}
					temp_param_list.clear();
					/* for(int i =0;i<temp_param_list.size();i++)
					{
						string t = temp_param_list[i].first+to_string(scope_counter);
						s->extraSymbolInfo.modfd_param_list.push_back(t);               //pushing to the modified paramater list of the pointer
					} */
				}
				if(return_type_solver!=(yyvsp[-4].symbolInfoPointer)->getType())
				{

					numberOfErrors++;
					fprintf(errors,"Error at Line %d : return type error \n\n",numberOfLines);
					return_type_solver="";
					flag=false;
				}
			}
		}
		// $$->extraSymbolInfo.stringConcatenator = $1->extraSymbolInfo.stringConcatenator+$2->getName()+getFromSymbolSet("left_first")+$4->extraSymbolInfo.stringConcatenator+getFromSymbolSet("right_first")+$6->extraSymbolInfo.stringConcatenator;
		//fprintf(logs,"%s\n\n",$$->extraSymbolInfo.stringConcatenator.c_str());
}
#line 1839 "1705070_backup.tab.c"
    break;

  case 11: /* func_definition: type_specifier ID LPAREN parameter_list RPAREN $@1 compound_statement  */
#line 349 "1705070_backup.y"
                   {
	fprintf(logs, "Line %d: func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n", numberOfLines);
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = (yyvsp[-6].symbolInfoPointer)->extraSymbolInfo.stringConcatenator+(yyvsp[-5].symbolInfoPointer)->getName()+getFromSymbolSet("left_first")+(yyvsp[-3].symbolInfoPointer)->extraSymbolInfo.stringConcatenator+getFromSymbolSet("right_first")+(yyvsp[0].symbolInfoPointer)->extraSymbolInfo.stringConcatenator;
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 1849 "1705070_backup.tab.c"
    break;

  case 12: /* $@2: %empty  */
#line 353 "1705070_backup.y"
                                  {
	fprintf(logs, "Line %d: func_definition : type_specifier ID LPAREN RPAREN compound_statement\n\n", numberOfLines);

	// scope_counter++;
	SymbolInfo *s = symbolTable.LookUp((yyvsp[-2].symbolInfoPointer)->getName());

	if(s==0){
		SymbolInfo* temp = new SymbolInfo();
		temp->extraSymbolInfo.typeOfID = "FUNCTION";
		temp->extraSymbolInfo.returnTypeOfFunction = (yyvsp[-3].symbolInfoPointer)->getType();
		temp->extraSymbolInfo.isFunction = true;
		temp->extraSymbolInfo.isFunctionDefined = true;
		temp->setName((yyvsp[-2].symbolInfoPointer)->getName());
		temp->setType((yyvsp[-2].symbolInfoPointer)->getType());

		symbolTable.InsertModified(temp);
	}else{
		if(s->extraSymbolInfo.isFunctionDeclared){
			string actReturnType = (yyvsp[-3].symbolInfoPointer)->getType();
			string funcReturnType = s->extraSymbolInfo.returnTypeOfFunction;

			if(actReturnType != funcReturnType){
				numberOfErrors++;
				fprintf(errors, "Error at line %d: Return type mismatch\n\n", numberOfLines);
				s->extraSymbolInfo.isFunction = false;
			}
		}else if(s->extraSymbolInfo.isFunctionDefined){
			numberOfErrors++;
			fprintf(errors,"Error at Line %d :Multiple defination of function\n\n",numberOfLines);
			temp_param_list.clear();
		}
	}
	//$$->extraSymbolInfo.stringConcatenator = $1->extraSymbolInfo.stringConcatenator+$2->getName()+getFromSymbolSet("left_first")+getFromSymbolSet("right_first")+$5->extraSymbolInfo.stringConcatenator;
	//fprintf(logs,"%s\n\n",$$->extraSymbolInfo.stringConcatenator.c_str());
}
#line 1889 "1705070_backup.tab.c"
    break;

  case 13: /* func_definition: type_specifier ID LPAREN RPAREN $@2 compound_statement  */
#line 387 "1705070_backup.y"
                   {
	fprintf(logs,"Line %d: func_definition : type_specifier ID LPAREN RPAREN compound_statement\n\n",numberOfLines);
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = (yyvsp[-5].symbolInfoPointer)->extraSymbolInfo.stringConcatenator+(yyvsp[-4].symbolInfoPointer)->getName()+getFromSymbolSet("left_first")+getFromSymbolSet("right_first")+(yyvsp[0].symbolInfoPointer)->extraSymbolInfo.stringConcatenator;
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 1899 "1705070_backup.tab.c"
    break;

  case 14: /* parameter_list: parameter_list COMMA type_specifier ID  */
#line 394 "1705070_backup.y"
{
		fprintf(logs,"Line %d: parameter_list : parameter_list COMMA type_specifier ID\n\n",numberOfLines);
		temp_param_list.push_back(make_pair((yyvsp[0].symbolInfoPointer)->getName(),(yyvsp[-1].symbolInfoPointer)->getType()));
		(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = (yyvsp[-3].symbolInfoPointer)->extraSymbolInfo.stringConcatenator+getFromSymbolSet("comma")+(yyvsp[-1].symbolInfoPointer)->extraSymbolInfo.stringConcatenator+(yyvsp[0].symbolInfoPointer)->getName();
		fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 1910 "1705070_backup.tab.c"
    break;

  case 15: /* parameter_list: parameter_list COMMA type_specifier  */
#line 401 "1705070_backup.y"
{
		fprintf(logs,"Line %d: parameter_list : parameter_list COMMA type_specifier\n\n",numberOfLines);
		temp_param_list.push_back(make_pair("",(yyvsp[0].symbolInfoPointer)->getType()));
		(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = (yyvsp[-2].symbolInfoPointer)->getName()+getFromSymbolSet("comma")+(yyvsp[0].symbolInfoPointer)->extraSymbolInfo.stringConcatenator;
		fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 1921 "1705070_backup.tab.c"
    break;

  case 16: /* parameter_list: type_specifier ID  */
#line 408 "1705070_backup.y"
{
		fprintf(logs,"Line %d: parameter_list : type_specifier ID\n\n", numberOfLines);
		temp_param_list.push_back(make_pair((yyvsp[0].symbolInfoPointer)->getName(),(yyvsp[-1].symbolInfoPointer)->getType()));
		(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = (yyvsp[-1].symbolInfoPointer)->extraSymbolInfo.stringConcatenator.append((yyvsp[0].symbolInfoPointer)->getName());
		fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());

}
#line 1933 "1705070_backup.tab.c"
    break;

  case 17: /* parameter_list: type_specifier  */
#line 416 "1705070_backup.y"
{
		fprintf(logs,"Line %d: parameter_list : type_specifier\n\n",numberOfLines);
		temp_param_list.push_back(make_pair("",(yyvsp[0].symbolInfoPointer)->getType()));
		(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator =(yyvsp[0].symbolInfoPointer)->extraSymbolInfo.stringConcatenator;
		fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 1944 "1705070_backup.tab.c"
    break;

  case 18: /* $@3: %empty  */
#line 423 "1705070_backup.y"
                           {
	symbolTable.EnterScope(logs);
	// fprintf(logs,"Line %d: Entering Scope compound_statement LCURL\n\n",numberOfLines);
	// cout << "Entering scope 1" << endl;

	// scope_counter_2 = symbolTable.getTableIdTracker();
	// scope_holder = symbolTable.getStringifyID();

	if(temp_param_list.size()!=0){
		for(int i=0;i<temp_param_list.size();i++){
			string name = temp_param_list[i].first;
			string type = temp_param_list[i].second;

			SymbolInfo *s = new SymbolInfo();
			s->setName(name);
			s->setType("ID");
			s->extraSymbolInfo.typeOfVar = type;
			bool check = symbolTable.InsertModified(s);

			if(check == 0){
				numberOfErrors++;
				fprintf(errors, "Error at line %d: Duplicate Parameter Name of function\n\n", numberOfLines);
			}
		}
	}
	temp_param_list.clear();
}
#line 1976 "1705070_backup.tab.c"
    break;

  case 19: /* compound_statement: LCURL $@3 statements RCURL  */
#line 449 "1705070_backup.y"
                   {
	fprintf(logs,"Line %d: compound_statement : LCURL statements RCURL\n\n",numberOfLines);
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = getFromSymbolSet("left_curl")+"\n"+(yyvsp[-1].symbolInfoPointer)->extraSymbolInfo.stringConcatenator+getFromSymbolSet("right_curl");
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
	symbolTable.printAllTable(logs);
	symbolTable.ExitScope(logs);
}
#line 1988 "1705070_backup.tab.c"
    break;

  case 20: /* $@4: %empty  */
#line 455 "1705070_backup.y"
          {
	symbolTable.EnterScope(logs);
	// fprintf(logs,"Line %d: LCURL Entering Scope LCURL\n\n",numberOfLines);
	// cout << "At line " << numberOfLines << " " << endl;
	// scope_counter_2 = symbolTable.getTableIDTracker();

	for(int i=0;i<temp_param_list.size();i++){
		string name = temp_param_list[i].first;
		string type = temp_param_list[i].second;

		SymbolInfo *s = new SymbolInfo();
		s->setName(name);
		s->setType("ID");
		s->extraSymbolInfo.typeOfVar = type;
		bool check = symbolTable.InsertModified(s);
		symbolTable.printAllTable(logs);
		//decld_var_carrier.push_back(make_pair(name+to_string(scope_counter),""));

		if(check == 0){
			numberOfErrors++;
			fprintf(errors, "Error at line %d : Duplicate Parameter Name of function\n\n", numberOfLines);
		}
	}
	temp_param_list.clear();
}
#line 2018 "1705070_backup.tab.c"
    break;

  case 21: /* compound_statement: LCURL $@4 RCURL  */
#line 479 "1705070_backup.y"
        {
	fprintf(logs,"Line %d: compound_statement : LCURL  RCURL\n\n",numberOfLines);
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = getFromSymbolSet("left_curl")+"\n"+getFromSymbolSet("right_curl");
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
	symbolTable.printAllTable(logs);
	symbolTable.ExitScope(logs);
}
#line 2030 "1705070_backup.tab.c"
    break;

  case 22: /* var_declaration: type_specifier declaration_list SEMICOLON  */
#line 487 "1705070_backup.y"
                                                            {
	fprintf(logs,"Line %d: var_declaration : type_specifier declaration_list SEMICOLON\n\n",numberOfLines);

	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = stringAdder(3,(yyvsp[-2].symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str(),(yyvsp[-1].symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str(),getFromSymbolSet("semicolon").c_str());

	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 2042 "1705070_backup.tab.c"
    break;

  case 23: /* type_specifier: INT  */
#line 495 "1705070_backup.y"
                     {
	fprintf(logs, "Line %d: type_specifier : INT\n\n", numberOfLines);

	SymbolInfo* s = new SymbolInfo("", "INT");
	type_of_var = "INT";
	(yyval.symbolInfoPointer) = s;
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = "int ";
	// named = $$->extraSymbolInfo.stringConcatenator + " ";
	fprintf(logs, "%s\n\n", (yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 2057 "1705070_backup.tab.c"
    break;

  case 24: /* type_specifier: FLOAT  */
#line 504 "1705070_backup.y"
          {
	fprintf(logs,"Line %d: type_specifier : FLOAT\n\n",numberOfLines);
	SymbolInfo* s = new SymbolInfo("","FLOAT");
	type_of_var = "FLOAT";
	(yyval.symbolInfoPointer) = s;
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = "float ";
	//named = $$->extraSymbolInfo.stringConcatenator + " ";
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 2071 "1705070_backup.tab.c"
    break;

  case 25: /* type_specifier: VOID  */
#line 512 "1705070_backup.y"
         {
	fprintf(logs,"Line %d: type_specifier : VOID\n\n",numberOfLines);
	SymbolInfo* s = new SymbolInfo("","VOID");
	type_of_var = "VOID";
	(yyval.symbolInfoPointer) = s;
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = "void ";
	// named = $$->extraSymbolInfo.stringConcatenator + " ";
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 2085 "1705070_backup.tab.c"
    break;

  case 26: /* declaration_list: declaration_list COMMA ID  */
#line 522 "1705070_backup.y"
                                             {
	if(type_of_var!="VOID"){
		fprintf(logs,"Line %d: declaration_list : declaration_list COMMA ID\n\n",numberOfLines);

		SymbolInfo* test = symbolTable.currentScopeLookUp((yyvsp[0].symbolInfoPointer)->getName());
		if(test!=0){
			fprintf(errors,"Error at Line %d  : Multiple Declaration of %s\n\n",numberOfLines,(yyvsp[0].symbolInfoPointer)->getName().c_str());
			numberOfErrors++;
		} else {
			SymbolInfo* obj = new SymbolInfo((yyvsp[0].symbolInfoPointer)->getName(),(yyvsp[0].symbolInfoPointer)->getType());
			obj->extraSymbolInfo.typeOfID = "VARIABLE";
			obj->extraSymbolInfo.typeOfVar = type_of_var;
			symbolTable.InsertModified(obj);
		}

		(yyvsp[-2].symbolInfoPointer)->extraSymbolInfo.stringConcatenator.append(getFromSymbolSet("comma"));
		(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.append((yyvsp[0].symbolInfoPointer)->getName());
		fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
	}
}
#line 2110 "1705070_backup.tab.c"
    break;

  case 27: /* declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD  */
#line 541 "1705070_backup.y"
                                                      {
	if(type_of_var!="VOID") {
		fprintf(logs,"Line %d: declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n\n",numberOfLines);
		SymbolInfo* test = symbolTable.currentScopeLookUp((yyvsp[-3].symbolInfoPointer)->getName());

		if(test!=0) {
			fprintf(errors,"Error at Line %d  : Multiple Declaration of %s\n\n",numberOfLines,(yyvsp[-3].symbolInfoPointer)->getName().c_str());
			numberOfErrors++;
		} else {
			SymbolInfo* obj = new SymbolInfo((yyvsp[-3].symbolInfoPointer)->getName(),(yyvsp[-3].symbolInfoPointer)->getType());

			obj->extraSymbolInfo.typeOfID = "ARRAY";
			obj->extraSymbolInfo.typeOfVar = type_of_var;
			obj->extraSymbolInfo.sizeOfArray = (yyvsp[-1].symbolInfoPointer)->getName();
			symbolTable.InsertModified(obj);
		}
		string temp = (yyvsp[-3].symbolInfoPointer)->getName()+getFromSymbolSet("left_third")+(yyvsp[-1].symbolInfoPointer)->getName()+getFromSymbolSet("right_third");
		(yyvsp[-5].symbolInfoPointer)->extraSymbolInfo.stringConcatenator.append(getFromSymbolSet("comma"));
		(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.append(temp);
		fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
	}
}
#line 2137 "1705070_backup.tab.c"
    break;

  case 28: /* declaration_list: ID  */
#line 562 "1705070_backup.y"
       {
	fprintf(logs,"Line %d: declaration_list : ID\n\n",numberOfLines);

	if(type_of_var!="VOID"){
		SymbolInfo* temp = symbolTable.currentScopeLookUp((yyvsp[0].symbolInfoPointer)->getName());
		if(temp!=0) {
			numberOfErrors++;
			fprintf(errors,"Error at Line %d  : Multiple declration of %s\n\n",numberOfLines,(yyvsp[0].symbolInfoPointer)->getName().c_str());
		} else{
			SymbolInfo* obj = new SymbolInfo((yyvsp[0].symbolInfoPointer)->getName(),(yyvsp[0].symbolInfoPointer)->getType());
			obj->extraSymbolInfo.typeOfID = "VARIABLE";
			obj->extraSymbolInfo.typeOfVar = type_of_var;
			symbolTable.InsertModified(obj);
		}
	} else{
		numberOfErrors++;
		fprintf(errors,"Error at Line %d  : Variable declared void\n\n",numberOfLines);
	}
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = (yyvsp[0].symbolInfoPointer)->getName();
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 2163 "1705070_backup.tab.c"
    break;

  case 29: /* declaration_list: ID LTHIRD CONST_INT RTHIRD  */
#line 582 "1705070_backup.y"
                               {
	fprintf(logs,"Line %d: declaration_list : ID LTHIRD CONST_INT RTHIRD\n\n",numberOfLines);

	//checking to see if array type is void or not
	if(type_of_var!="VOID")
	{
		SymbolInfo* temp = symbolTable.currentScopeLookUp((yyvsp[-3].symbolInfoPointer)->getName());
		if(temp!=0){
			fprintf(errors,"Error at Line %d  : Multiple declration of %s\n\n",numberOfLines,(yyvsp[-3].symbolInfoPointer)->getName().c_str());
			numberOfErrors++;
		} else{
			SymbolInfo* obj = new SymbolInfo((yyvsp[-3].symbolInfoPointer)->getName(),(yyvsp[-3].symbolInfoPointer)->getType());
			obj->extraSymbolInfo.typeOfID = "ARRAY";
			obj->extraSymbolInfo.typeOfVar = type_of_var;
			obj->extraSymbolInfo.sizeOfArray = (yyvsp[-1].symbolInfoPointer)->getName();
			symbolTable.InsertModified(obj);
		}
	} else {
		fprintf(errors,"Error at Line %d  :  Array %s declared as void\n\n", numberOfLines,(yyvsp[-3].symbolInfoPointer)->getName().c_str());
		numberOfErrors++;
	}
    string temp = getFromSymbolSet("left_third")+(yyvsp[-1].symbolInfoPointer)->getName()+getFromSymbolSet("right_third");
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = (yyvsp[-3].symbolInfoPointer)->getName();
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.append(temp);
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 2194 "1705070_backup.tab.c"
    break;

  case 30: /* statements: statement  */
#line 609 "1705070_backup.y"
                      {
	fprintf(logs,"Line %d: statements : statement\n\n",numberOfLines);
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = (yyvsp[0].symbolInfoPointer)->extraSymbolInfo.stringConcatenator+"\n";
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 2204 "1705070_backup.tab.c"
    break;

  case 31: /* statements: statements statement  */
#line 613 "1705070_backup.y"
                         {
	fprintf(logs,"Line %d: statements : statements statement\n\n", numberOfLines);
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = (yyvsp[-1].symbolInfoPointer)->extraSymbolInfo.stringConcatenator+((yyvsp[0].symbolInfoPointer)->extraSymbolInfo.stringConcatenator+"\n");
	statement_solver = (yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator;
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 2215 "1705070_backup.tab.c"
    break;

  case 32: /* statement: var_declaration  */
#line 620 "1705070_backup.y"
                            {
	fprintf(logs,"Line %d: statement : var_declaration\n\n",numberOfLines);
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = (yyvsp[0].symbolInfoPointer)->extraSymbolInfo.stringConcatenator;
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 2225 "1705070_backup.tab.c"
    break;

  case 33: /* statement: expression_statement  */
#line 624 "1705070_backup.y"
                         {
	fprintf(logs,"Line %d: statement : expression_statement\n\n",numberOfLines);
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = (yyvsp[0].symbolInfoPointer)->extraSymbolInfo.stringConcatenator;
	fprintf(logs,"%s\n\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 2235 "1705070_backup.tab.c"
    break;

  case 34: /* statement: compound_statement  */
#line 628 "1705070_backup.y"
                       {
	fprintf(logs,"Line %d: statement : compound_statement\n\n",numberOfLines);
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = (yyvsp[0].symbolInfoPointer)->extraSymbolInfo.stringConcatenator;
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 2245 "1705070_backup.tab.c"
    break;

  case 35: /* statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement  */
#line 632 "1705070_backup.y"
                                                                                     {
	fprintf(logs,"Line %d: statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n",numberOfLines);
	string temp = (yyvsp[-4].symbolInfoPointer)->extraSymbolInfo.stringAdder((yyvsp[-3].symbolInfoPointer)->extraSymbolInfo.stringAdder((yyvsp[-2].symbolInfoPointer)->extraSymbolInfo.stringConcatenator));
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = "for"+getFromSymbolSet("left_first")+temp+getFromSymbolSet("right_first")+(yyvsp[0].symbolInfoPointer)->extraSymbolInfo.stringConcatenator;
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());

	//var type of expression_statements and expression
	string a = (yyvsp[-4].symbolInfoPointer)->extraSymbolInfo.typeOfVar;
	string b = (yyvsp[-3].symbolInfoPointer)->extraSymbolInfo.typeOfVar;
	string c = (yyvsp[-2].symbolInfoPointer)->extraSymbolInfo.typeOfVar;

	if((a=="VOID")||(b=="VOID")||(c=="VOID")){
		numberOfErrors++;
		fprintf(errors,"Error at Line %d : Expression can not be void\n\n",numberOfLines);
	}
}
#line 2266 "1705070_backup.tab.c"
    break;

  case 36: /* statement: IF LPAREN expression RPAREN statement  */
#line 647 "1705070_backup.y"
                                                                    {
	fprintf(logs,"Line %d: IF LPAREN expression RPAREN statement\n\n",numberOfLines);
	string temp = (yyvsp[-2].symbolInfoPointer)->extraSymbolInfo.stringAdder(getFromSymbolSet("right_first"));
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = "if"+getFromSymbolSet("left_first")+temp+(yyvsp[0].symbolInfoPointer)->extraSymbolInfo.stringConcatenator;
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());

	string a = (yyvsp[-2].symbolInfoPointer)->extraSymbolInfo.typeOfVar;
	if(a=="VOID"){
		numberOfErrors++;
		fprintf(errors,"Error at Line %d : Expression can not be void\n\n",numberOfLines);
	}
}
#line 2283 "1705070_backup.tab.c"
    break;

  case 37: /* statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 658 "1705070_backup.y"
                                                         {
		fprintf(logs,"Line %d: IF LPAREN expression RPAREN statement ELSE statement\n\n",numberOfLines);
		string temp = (yyvsp[-4].symbolInfoPointer)->extraSymbolInfo.stringAdder(getFromSymbolSet("right_first"));
		string temp2 = (yyvsp[-2].symbolInfoPointer)->extraSymbolInfo.stringAdder("else"+(yyvsp[0].symbolInfoPointer)->extraSymbolInfo.stringConcatenator);
		(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = "if"+getFromSymbolSet("left_first")+temp+temp2;
		fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());

		string a = (yyvsp[-4].symbolInfoPointer)->extraSymbolInfo.typeOfVar;
		if(a=="VOID"){
			numberOfErrors++;
			fprintf(errors,"Error at Line %d : Expression can not be void\n\n",numberOfLines);
		}
}
#line 2301 "1705070_backup.tab.c"
    break;

  case 38: /* statement: WHILE LPAREN expression RPAREN statement  */
#line 670 "1705070_backup.y"
                                             {
	fprintf(logs,"Line %d: WHILE LPAREN expression RPAREN statement\n\n",numberOfLines);
	string temp = (yyvsp[-2].symbolInfoPointer)->extraSymbolInfo.stringAdder(getFromSymbolSet("right_first")+(yyvsp[0].symbolInfoPointer)->extraSymbolInfo.stringConcatenator);
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = "while"+getFromSymbolSet("left_first")+temp;
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());

	string a = (yyvsp[-2].symbolInfoPointer)->extraSymbolInfo.typeOfVar;
	if(a=="VOID"){
		numberOfErrors++;
		fprintf(errors,"Error at Line %d : Expression can not be void\n\n",numberOfLines);
	}
}
#line 2318 "1705070_backup.tab.c"
    break;

  case 39: /* statement: PRINTLN LPAREN ID RPAREN SEMICOLON  */
#line 681 "1705070_backup.y"
                                       {
	fprintf(logs,"Line %d: statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n",numberOfLines);
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = "println"+getFromSymbolSet("left_first")+(yyvsp[-2].symbolInfoPointer)->getName()+getFromSymbolSet("right_first")+getFromSymbolSet("semicolon");
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 2328 "1705070_backup.tab.c"
    break;

  case 40: /* statement: RETURN expression SEMICOLON  */
#line 685 "1705070_backup.y"
                                {
	fprintf(logs,"Line %d: statement : RETURN expression SEMICOLON\n\n",numberOfLines);
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = "return "+(yyvsp[-1].symbolInfoPointer)->extraSymbolInfo.stringAdder(getFromSymbolSet("semicolon"));
	fprintf(logs,"%s\n\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());

	string a = (yyvsp[-1].symbolInfoPointer)->extraSymbolInfo.typeOfVar;

	if(a=="VOID"){
		numberOfErrors++;
		fprintf(errors,"Error at Line %d : Expression can not be void\n\n",numberOfLines);
	}
	return_type_solver = a;
}
#line 2346 "1705070_backup.tab.c"
    break;

  case 41: /* expression_statement: SEMICOLON  */
#line 699 "1705070_backup.y"
                                 {
	fprintf(logs,"Line %d: expression_statement : SEMICOLON\n\n",numberOfLines);
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = getFromSymbolSet("semicolon");
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 2356 "1705070_backup.tab.c"
    break;

  case 42: /* expression_statement: expression SEMICOLON  */
#line 703 "1705070_backup.y"
                         {
	fprintf(logs,"Line %d: expression_statement : expression SEMICOLON\n\n",numberOfLines);
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = (yyvsp[-1].symbolInfoPointer)->extraSymbolInfo.stringAdder(getFromSymbolSet("semicolon"));
	(yyval.symbolInfoPointer)->extraSymbolInfo.typeOfVar = (yyvsp[-1].symbolInfoPointer)->extraSymbolInfo.typeOfVar;
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 2367 "1705070_backup.tab.c"
    break;

  case 43: /* variable: ID  */
#line 710 "1705070_backup.y"
              {
	fprintf(logs,"Line %d: variable : ID\n\n",numberOfLines);
	SymbolInfo* temp =  symbolTable.LookUp((yyvsp[0].symbolInfoPointer)->getName());
	string type="";

	if(temp!=0){
		if(temp->extraSymbolInfo.typeOfID=="ARRAY"){
			numberOfErrors++;
			fprintf(errors,"Error at Line %d : No index on array\n\n",numberOfLines,(yyvsp[0].symbolInfoPointer)->getName().c_str());
			type = temp->extraSymbolInfo.typeOfVar;
		} else if(temp->extraSymbolInfo.isFunction){
			numberOfErrors++;
			fprintf(errors,"Error at Line %d : Improper Function call\n\n",numberOfLines,(yyvsp[0].symbolInfoPointer)->getName().c_str());
			type = temp->extraSymbolInfo.returnTypeOfFunction;
		} else{
			type = temp->extraSymbolInfo.typeOfVar;
		}

		(yyval.symbolInfoPointer)->extraSymbolInfo.typeOfVar = type;
		(yyval.symbolInfoPointer)->extraSymbolInfo.typeOfID = temp->extraSymbolInfo.typeOfID;
		(yyval.symbolInfoPointer)->setName(temp->getName());
		(yyval.symbolInfoPointer)->setType(temp->getType());
	} else{
		numberOfErrors++;
		fprintf(errors,"Error at Line %d : Undeclared variable : %s\n\n",numberOfLines,(yyvsp[0].symbolInfoPointer)->getName().c_str());
	}
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = (yyvsp[0].symbolInfoPointer)->getName();
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 2401 "1705070_backup.tab.c"
    break;

  case 44: /* variable: ID LTHIRD expression RTHIRD  */
#line 738 "1705070_backup.y"
                                {
	fprintf(logs,"Line %d: variable : ID LTHIRD expression RTHIRD\n\n",numberOfLines);

	// check that id exixts in scope table or not
	SymbolInfo* temp = symbolTable.LookUp((yyvsp[-3].symbolInfoPointer)->getName());

	if(temp!=0){
		string typeOfID = temp->extraSymbolInfo.typeOfID;

		if(typeOfID!="ARRAY"){
			numberOfErrors++;
			fprintf(errors,"Error at Line %d : Index Not on Array\n\n",numberOfLines);
		} else{
			string type = (yyvsp[-1].symbolInfoPointer)->extraSymbolInfo.typeOfVar; //index expression type
			string arr_type = (yyvsp[-3].symbolInfoPointer)->extraSymbolInfo.typeOfVar;
			if(type!="INT"){
				numberOfErrors++;
				fprintf(errors,"Error at Line %d : Non Integer Array Index\n\n",numberOfLines);
			}
		}

		temp->extraSymbolInfo.isFunction ? (yyval.symbolInfoPointer)->extraSymbolInfo.typeOfVar = temp->extraSymbolInfo.returnTypeOfFunction :	(yyval.symbolInfoPointer)->extraSymbolInfo.typeOfVar = temp->extraSymbolInfo.typeOfVar;

		(yyval.symbolInfoPointer)->extraSymbolInfo.typeOfID = temp->extraSymbolInfo.typeOfID;
		(yyval.symbolInfoPointer)->setName(temp->getName());
		(yyval.symbolInfoPointer)->setType(temp->getType());
		(yyval.symbolInfoPointer)->extraSymbolInfo.indexOfArray  = temp->extraSymbolInfo.indexOfArray;
		(yyval.symbolInfoPointer)->extraSymbolInfo.sizeOfArray = temp->extraSymbolInfo.sizeOfArray;
	} else {
		numberOfErrors++;
		fprintf(errors,"Error at Line %d : Undeclared variable : %s\n\n",numberOfLines,(yyvsp[-3].symbolInfoPointer)->getName().c_str());
	}

	string t = getFromSymbolSet("left_third")+(yyvsp[-1].symbolInfoPointer)->extraSymbolInfo.stringAdder(getFromSymbolSet("right_third"));
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = (yyvsp[-3].symbolInfoPointer)->getName()+t;
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 2443 "1705070_backup.tab.c"
    break;

  case 45: /* expression: logic_expression  */
#line 776 "1705070_backup.y"
                              {
	fprintf(logs,"Line %d: expression : logic expression\n\n",numberOfLines);
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = (yyvsp[0].symbolInfoPointer)->extraSymbolInfo.stringConcatenator;
	(yyval.symbolInfoPointer)->extraSymbolInfo.typeOfVar = (yyvsp[0].symbolInfoPointer)->extraSymbolInfo.typeOfVar;
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 2454 "1705070_backup.tab.c"
    break;

  case 46: /* expression: variable ASSIGNOP logic_expression  */
#line 781 "1705070_backup.y"
                                       {
	fprintf(logs,"Line %d: expression : variable ASSIGNOP logic_expression\n\n",numberOfLines);

	SymbolInfo* s = symbolTable.LookUp((yyvsp[-2].symbolInfoPointer)->getName());

	if(s!=0){
		string v_type = s->extraSymbolInfo.typeOfVar;
		string log_exp_type = (yyvsp[0].symbolInfoPointer)->extraSymbolInfo.typeOfVar;

		if((yyvsp[0].symbolInfoPointer)->extraSymbolInfo.typeOfVar=="VOID"){
				numberOfErrors++;
				fprintf(errors,"Error at Line %d : Type Mismatch: cannot assign to VOID type\n\n",numberOfLines);
		} else {
			if(v_type!=log_exp_type)
			{
				numberOfErrors++;
				fprintf(errors,"Error at Line %d : Type Mismatch\n\n",numberOfLines);
			}
			if((v_type=="FLOAT")&&(log_exp_type=="INT")){
				// it's a warning not error
				//numberOfErrors++;
				fprintf(errors,"Warning at Line %d : Integer assigned to Float\n\n",numberOfLines);
			}
			else if((v_type=="INT")&&(log_exp_type=="FLOAT"))
			{
				// it's a warning not error
				//numberOfErrors++;
				fprintf(errors,"Warning at Line %d : Float assigned to Integer\n\n",numberOfLines);
			}
		}
    }

	(yyval.symbolInfoPointer)->extraSymbolInfo.typeOfVar = (yyvsp[-2].symbolInfoPointer)->extraSymbolInfo.typeOfVar;

	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = (yyvsp[-2].symbolInfoPointer)->extraSymbolInfo.stringConcatenator+getFromSymbolSet("equal")+(yyvsp[0].symbolInfoPointer)->extraSymbolInfo.stringConcatenator;
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 2496 "1705070_backup.tab.c"
    break;

  case 47: /* logic_expression: rel_expression  */
#line 819 "1705070_backup.y"
                                  {
	fprintf(logs,"Line %d: logic_expression : rel_expression\n\n",numberOfLines);
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = (yyvsp[0].symbolInfoPointer)->extraSymbolInfo.stringConcatenator;
	(yyval.symbolInfoPointer)->extraSymbolInfo.typeOfVar = (yyvsp[0].symbolInfoPointer)->extraSymbolInfo.typeOfVar;

	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 2508 "1705070_backup.tab.c"
    break;

  case 48: /* logic_expression: rel_expression LOGICOP rel_expression  */
#line 825 "1705070_backup.y"
                                          {
	fprintf(logs,"Line %d: logic_expression : rel_expression LOGICOP rel_expression\n\n",numberOfLines);
	string a_type  = (yyvsp[-2].symbolInfoPointer)->extraSymbolInfo.typeOfVar;
	string b_type  =  (yyvsp[-1].symbolInfoPointer)->extraSymbolInfo.typeOfVar;
	if((a_type=="VOID") || (b_type =="VOID")){
		numberOfErrors++;
		fprintf(errors,"Error at Line %d  : Type Mismatch: cannot operate on VOID type\n\n",numberOfLines);
	}
	string ret_type = "INT";
	(yyval.symbolInfoPointer)->extraSymbolInfo.typeOfVar = ret_type;
	string temp = (yyvsp[-2].symbolInfoPointer)->extraSymbolInfo.stringAdder((yyvsp[-1].symbolInfoPointer)->getName()+(yyvsp[0].symbolInfoPointer)->extraSymbolInfo.stringConcatenator);
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = temp;
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 2527 "1705070_backup.tab.c"
    break;

  case 49: /* rel_expression: simple_expression  */
#line 840 "1705070_backup.y"
                                    {
	fprintf(logs,"Line %d: rel_expression : simple_expression\n\n",numberOfLines);
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = (yyvsp[0].symbolInfoPointer)->extraSymbolInfo.stringConcatenator;
	(yyval.symbolInfoPointer)->extraSymbolInfo.typeOfVar = (yyvsp[0].symbolInfoPointer)->extraSymbolInfo.typeOfVar;

	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 2539 "1705070_backup.tab.c"
    break;

  case 50: /* rel_expression: simple_expression RELOP simple_expression  */
#line 846 "1705070_backup.y"
                                              {
	fprintf(logs,"Line %d: rel_expression : simple_expression RELOP simple_expression\n\n",numberOfLines);

	string a_type  = (yyvsp[-2].symbolInfoPointer)->extraSymbolInfo.typeOfVar;
	string b_type  =  (yyvsp[-1].symbolInfoPointer)->extraSymbolInfo.typeOfVar;
	if((a_type=="VOID") || (b_type =="VOID")){
		numberOfErrors++;
		fprintf(errors,"Error at Line %d  : Type Mismatch: cannot operate on VOID type\n\n",numberOfLines);
	}

	string ret_type = "INT";
	(yyval.symbolInfoPointer)->extraSymbolInfo.typeOfVar = ret_type;
	string temp = (yyvsp[-2].symbolInfoPointer)->extraSymbolInfo.stringAdder((yyvsp[-1].symbolInfoPointer)->getName()+(yyvsp[0].symbolInfoPointer)->extraSymbolInfo.stringConcatenator);
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = temp;
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 2560 "1705070_backup.tab.c"
    break;

  case 51: /* simple_expression: term  */
#line 863 "1705070_backup.y"
                         {
	fprintf(logs,"Line %d: simple_expression : term\n\n",numberOfLines);
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = (yyvsp[0].symbolInfoPointer)->extraSymbolInfo.stringConcatenator;
	(yyval.symbolInfoPointer)->extraSymbolInfo.typeOfVar = (yyvsp[0].symbolInfoPointer)->extraSymbolInfo.typeOfVar;
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 2571 "1705070_backup.tab.c"
    break;

  case 52: /* simple_expression: simple_expression ADDOP term  */
#line 868 "1705070_backup.y"
                                 {
	fprintf(logs,"Line %d: simple_expression : simple_expression ADDOP term\n\n",numberOfLines);

	string a_type = (yyvsp[-2].symbolInfoPointer)->extraSymbolInfo.typeOfVar;
	string b_type = (yyvsp[0].symbolInfoPointer)->extraSymbolInfo.typeOfVar;
	string ret_type  = "";

	//type checking for operands to be added and type conversion
	if((a_type=="VOID")||(b_type=="VOID"))
	{
		numberOfErrors++;
		fprintf(errors,"Error at Line %d  : Add operation with void\n\n",numberOfLines);
		ret_type = "INT";
	} else if((a_type=="FLOAT")||(b_type=="FLOAT")){
		if(((a_type=="FLOAT")&&(b_type=="INT"))||((a_type=="INT")&&(b_type=="FLOAT")))
			fprintf(errors,"Warning at Line %d  : Integer converted to float during Addition.\n\n",numberOfLines);
			ret_type = "FLOAT";
	} else if((a_type=="INT")&&(b_type=="INT")){
			ret_type = "INT";
	}

	SymbolInfo* s = new SymbolInfo("",ret_type);
	(yyval.symbolInfoPointer) = s;
	(yyval.symbolInfoPointer)->extraSymbolInfo.typeOfVar = ret_type;
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = (yyvsp[-2].symbolInfoPointer)->extraSymbolInfo.stringAdder((yyvsp[-1].symbolInfoPointer)->getName().append((yyvsp[0].symbolInfoPointer)->extraSymbolInfo.stringConcatenator));
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 2603 "1705070_backup.tab.c"
    break;

  case 53: /* term: unary_expression  */
#line 896 "1705070_backup.y"
                         {
	fprintf(logs,"Line %d: term : unary_expression\n\n",numberOfLines);
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = (yyvsp[0].symbolInfoPointer)->extraSymbolInfo.stringConcatenator;
	(yyval.symbolInfoPointer)->extraSymbolInfo.typeOfVar = (yyvsp[0].symbolInfoPointer)->extraSymbolInfo.typeOfVar;
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 2614 "1705070_backup.tab.c"
    break;

  case 54: /* term: term MULOP unary_expression  */
#line 901 "1705070_backup.y"
                                {
	fprintf(logs,"Line %d: term : term MULOP unary_expression\n\n",numberOfLines);

	string term_type = (yyvsp[-2].symbolInfoPointer)->extraSymbolInfo.typeOfVar;
	string unary_type = (yyvsp[0].symbolInfoPointer)->extraSymbolInfo.typeOfVar;
	string mult_operator = (yyvsp[-1].symbolInfoPointer)->getName();
	string ret_type = "";

	map<string,int>command_map;
	command_map["*"] = 1;
	command_map["/"] = 2;
	command_map["%"] = 3;

	switch(command_map[mult_operator])
	{
		case 1:
			{
				if((term_type=="VOID")||(unary_type=="VOID")){
					numberOfErrors++;
					fprintf(errors,"Error at Line %d : Multiplication operation with void\n\n",numberOfLines);
					ret_type = "INT";
				} else if((term_type=="FLOAT")||(unary_type=="FLOAT")){
					if(((term_type=="FLOAT")&&(unary_type=="INT"))||((term_type=="INT")&&(unary_type=="FLOAT")))
						fprintf(errors,"Warning at Line %d : Integer converted to float during Multiplication.\n\n",numberOfLines);
					ret_type = "FLOAT";
				} else if((term_type=="INT")&&(term_type=="INT")){
					ret_type = "INT";
				}
				SymbolInfo* s = new SymbolInfo("",ret_type);
				(yyval.symbolInfoPointer) = s;
				(yyval.symbolInfoPointer)->extraSymbolInfo.typeOfVar = ret_type;
				(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = (yyvsp[-2].symbolInfoPointer)->extraSymbolInfo.stringAdder((yyvsp[-1].symbolInfoPointer)->getName().append((yyvsp[0].symbolInfoPointer)->extraSymbolInfo.stringConcatenator));
				fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
			}
			break;
		case 2:{
				if((term_type=="VOID")||(unary_type=="VOID")){
					numberOfErrors++;
					fprintf(errors,"Error at Line %d : Division operation with void\n\n",numberOfLines);
					ret_type = "INT";
				}else if((term_type=="FLOAT")||(unary_type=="FLOAT")){
					if(((term_type=="FLOAT")&&(unary_type=="INT"))||((term_type=="INT")&&(unary_type=="FLOAT")))
						fprintf(errors,"Warning at Line %d : Integer converted to float during Division.\n\n",numberOfLines);
					ret_type = "FLOAT";
				}else if((term_type=="INT")&&(term_type=="INT"))
				{
					ret_type = "INT";
				}
				SymbolInfo* s = new SymbolInfo("",ret_type);
				(yyval.symbolInfoPointer) = s;
				(yyval.symbolInfoPointer)->extraSymbolInfo.typeOfVar = ret_type;
				(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = (yyvsp[-2].symbolInfoPointer)->extraSymbolInfo.stringAdder((yyvsp[-1].symbolInfoPointer)->getName().append((yyvsp[0].symbolInfoPointer)->extraSymbolInfo.stringConcatenator));
				fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
			}
			break;
		case 3:{
				if((term_type=="VOID")||(unary_type=="VOID")){
					numberOfErrors++;
					fprintf(errors,"Error at Line %d : Integer operand not on modulus operator\n\n",numberOfLines);
					ret_type = "INT";
				} else if((term_type!="INT")||(unary_type!="INT")){
					numberOfErrors++;
					fprintf(errors,"Error at Line %d : Integer operand not on modulus operator\n\n",numberOfLines);
					ret_type = "INT";
				}else if((term_type=="INT")&&(term_type=="INT"))
				{
					ret_type = "INT";
				}
				SymbolInfo* s = new SymbolInfo("",ret_type);
				(yyval.symbolInfoPointer) = s;
				(yyval.symbolInfoPointer)->extraSymbolInfo.typeOfVar = ret_type;
				(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = (yyvsp[-2].symbolInfoPointer)->extraSymbolInfo.stringAdder((yyvsp[-1].symbolInfoPointer)->getName().append((yyvsp[0].symbolInfoPointer)->extraSymbolInfo.stringConcatenator));
				fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
			}
			break;
	}
}
#line 2696 "1705070_backup.tab.c"
    break;

  case 55: /* unary_expression: ADDOP unary_expression  */
#line 979 "1705070_backup.y"
                                          {
	fprintf(logs,"Line %d: unary_expression : ADDOP unary_expression\n\n",numberOfLines);
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = (yyvsp[-1].symbolInfoPointer)->getName().append((yyvsp[0].symbolInfoPointer)->extraSymbolInfo.stringConcatenator);
	(yyval.symbolInfoPointer)->extraSymbolInfo.typeOfVar = (yyvsp[0].symbolInfoPointer)->extraSymbolInfo.typeOfVar;
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
	// VOID check
	if((yyvsp[0].symbolInfoPointer)->extraSymbolInfo.stringConcatenator=="VOID"){
		fprintf(errors,"Error at Line %d : Unary expression cannot be void\n\n",numberOfLines);
		numberOfErrors++;
	}
}
#line 2712 "1705070_backup.tab.c"
    break;

  case 56: /* unary_expression: NOT unary_expression  */
#line 989 "1705070_backup.y"
                         {
	fprintf(logs,"Line %d: unary_expression : NOT unary_expression\n\n",numberOfLines);
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = (yyvsp[-1].symbolInfoPointer)->getName().append((yyvsp[0].symbolInfoPointer)->extraSymbolInfo.stringConcatenator);
	(yyval.symbolInfoPointer)->extraSymbolInfo.typeOfVar = "INT";
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
	// VOID check
	if((yyvsp[0].symbolInfoPointer)->extraSymbolInfo.stringConcatenator=="VOID")
	{
		fprintf(errors,"Error at Line %d : Unary expression cannot be void\n\n",numberOfLines);
		numberOfErrors++;
	}
}
#line 2729 "1705070_backup.tab.c"
    break;

  case 57: /* unary_expression: factor  */
#line 1000 "1705070_backup.y"
           {
	fprintf(logs,"Line %d: unary_expression : factor\n\n",numberOfLines);
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = (yyvsp[0].symbolInfoPointer)->extraSymbolInfo.stringConcatenator;
	(yyval.symbolInfoPointer)->extraSymbolInfo.typeOfVar = (yyvsp[0].symbolInfoPointer)->extraSymbolInfo.typeOfVar;
	// at this point don't need t print variable type
	// fprintf(logs,"%s\n\n",$$->extraSymbolInfo.typeOfVar.c_str());
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 2742 "1705070_backup.tab.c"
    break;

  case 58: /* factor: variable  */
#line 1009 "1705070_backup.y"
                   {
	fprintf(logs,"Line %d: factor : variable\n\n", numberOfLines);
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = (yyvsp[0].symbolInfoPointer)->extraSymbolInfo.stringConcatenator;
	(yyval.symbolInfoPointer)->extraSymbolInfo.typeOfVar = (yyvsp[0].symbolInfoPointer)->extraSymbolInfo.typeOfVar;
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 2753 "1705070_backup.tab.c"
    break;

  case 59: /* factor: ID LPAREN argument_list RPAREN  */
#line 1014 "1705070_backup.y"
                                   {
	fprintf(logs,"Line %d: factor : ID LPAREN argument_list RPAREN\n\n",numberOfLines);

	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = (yyvsp[-3].symbolInfoPointer)->getName()+getFromSymbolSet("left_first")+(yyvsp[-1].symbolInfoPointer)->extraSymbolInfo.stringConcatenator+getFromSymbolSet("right_first");
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());

	SymbolInfo* s = symbolTable.LookUp((yyvsp[-3].symbolInfoPointer)->getName());

	if(s==0){
		numberOfErrors++;
		fprintf(errors,"Error at Line %d : Undefined or Undeclared function\n\n",numberOfLines);
		(yyvsp[-1].symbolInfoPointer)->extraSymbolInfo.functionParamList.clear();
	} else {
		if(s->extraSymbolInfo.typeOfID=="FUNCTION"){
			if(s->extraSymbolInfo.isFunction)
			{
				//check the num of arguments matches or not
				int given_arg_list = (yyvsp[-1].symbolInfoPointer)->extraSymbolInfo.functionParamList.size();
				int defined_arg_list = s->extraSymbolInfo.functionParamList.size();

				// for(int co=0;co<$3->extraSymbolInfo.functionParamList.size();co++){
				// 	cout << $3->extraSymbolInfo.functionParamList[co].first <<  " " << $3->extraSymbolInfo.functionParamList[co].second;
				// }
				// cout << endl << "If not so" << endl;
				// for(int co=0;co<s->extraSymbolInfo.functionParamList.size();co++){
				// 	cout << s->extraSymbolInfo.functionParamList[co].first <<  " " << s->extraSymbolInfo.functionParamList[co].second;
				// }
				// cout << endl << "If not so 1" << endl;;

				if(given_arg_list!=defined_arg_list){
					numberOfErrors++;
					fprintf(errors,"Error at Line %d : Unequal Number of function arguments\n\n",numberOfLines);
					(yyvsp[-1].symbolInfoPointer)->extraSymbolInfo.functionParamList.clear();
				}else{
					//Finally check for argument sequence of defined and called function
					for(int i=0;i<defined_arg_list;i++)
					{
						string temp1 = (yyvsp[-1].symbolInfoPointer)->extraSymbolInfo.functionParamList[i].second;
						string temp2 = s->extraSymbolInfo.functionParamList[i].second;

						if(temp1!=temp2)
						{
							numberOfErrors++;
							fprintf(errors,"Error at Line %d : Argument Type Mismatch with function defination \n\n",numberOfLines);
							break;
						}
					}
					(yyvsp[-1].symbolInfoPointer)->extraSymbolInfo.functionParamList.clear();
				}

				(yyval.symbolInfoPointer)->extraSymbolInfo.typeOfVar = s->extraSymbolInfo.returnTypeOfFunction;
				(yyval.symbolInfoPointer)->extraSymbolInfo.typeOfID = s->extraSymbolInfo.typeOfID;
			} else {
				numberOfErrors++;
				fprintf(errors,"Error at Line %d :function not properly defined or declared \n\n",numberOfLines);
				(yyval.symbolInfoPointer)->extraSymbolInfo.typeOfVar = s->extraSymbolInfo.returnTypeOfFunction;
				(yyval.symbolInfoPointer)->extraSymbolInfo.typeOfID = s->extraSymbolInfo.typeOfID;
			}
		} else{
			numberOfErrors++;
			fprintf(errors,"Error at Line %d : Function call on Non function ID\n\n",numberOfLines);
			(yyval.symbolInfoPointer)->extraSymbolInfo.typeOfVar = "INT";
			arg_param_list.clear();
		}
	}
}
#line 2824 "1705070_backup.tab.c"
    break;

  case 60: /* factor: LPAREN expression RPAREN  */
#line 1079 "1705070_backup.y"
                             {
	fprintf(logs,"Line %d: factor : LPAREN expression RPAREN\n\n",numberOfLines);
	SymbolInfo* s = new SymbolInfo();

	string temp = getFromSymbolSet("left_first")+(yyvsp[-1].symbolInfoPointer)->extraSymbolInfo.stringAdder(getFromSymbolSet("right_first"));
	s->extraSymbolInfo.stringConcatenator = temp;
	s->extraSymbolInfo.typeOfVar = (yyvsp[-1].symbolInfoPointer)->extraSymbolInfo.typeOfVar;
	(yyval.symbolInfoPointer)=s;
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 2839 "1705070_backup.tab.c"
    break;

  case 61: /* factor: CONST_INT  */
#line 1088 "1705070_backup.y"
              {
	fprintf(logs,"Line %d: factor : CONST_INT\n\n",numberOfLines);
	(yyvsp[0].symbolInfoPointer)->extraSymbolInfo.typeOfVar = "INT";
	(yyvsp[0].symbolInfoPointer)->extraSymbolInfo.typeOfID = "CONST_INT";
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = (yyvsp[0].symbolInfoPointer)->getName();
	(yyval.symbolInfoPointer)->extraSymbolInfo.indexOfArray = (yyvsp[0].symbolInfoPointer)->getName();
	(yyval.symbolInfoPointer)->extraSymbolInfo.typeOfID = (yyvsp[0].symbolInfoPointer)->extraSymbolInfo.typeOfID;
	(yyval.symbolInfoPointer)->extraSymbolInfo.typeOfVar = (yyvsp[0].symbolInfoPointer)->extraSymbolInfo.typeOfVar;
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());

}
#line 2855 "1705070_backup.tab.c"
    break;

  case 62: /* factor: CONST_FLOAT  */
#line 1098 "1705070_backup.y"
                {
	(yyvsp[0].symbolInfoPointer)->extraSymbolInfo.typeOfVar = "FLOAT";
	(yyvsp[0].symbolInfoPointer)->extraSymbolInfo.typeOfID = "CONST_FLOAT";
	fprintf(logs,"Line %d: factor : CONST_FLOAT\n\n",numberOfLines);
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = (yyvsp[0].symbolInfoPointer)->getName();
	(yyval.symbolInfoPointer)->extraSymbolInfo.indexOfArray = (yyvsp[0].symbolInfoPointer)->getName();
	(yyval.symbolInfoPointer)->extraSymbolInfo.typeOfID = (yyvsp[0].symbolInfoPointer)->extraSymbolInfo.typeOfID;
	(yyval.symbolInfoPointer)->extraSymbolInfo.typeOfVar = (yyvsp[0].symbolInfoPointer)->extraSymbolInfo.typeOfVar;
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 2870 "1705070_backup.tab.c"
    break;

  case 63: /* factor: variable INCOP  */
#line 1107 "1705070_backup.y"
                   {
	fprintf(logs,"Line %d: factor : variable INCOP\n\n",numberOfLines);
	(yyval.symbolInfoPointer)->extraSymbolInfo.typeOfVar = (yyvsp[-1].symbolInfoPointer)->extraSymbolInfo.typeOfVar;
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = (yyvsp[-1].symbolInfoPointer)->getName()+(yyvsp[0].symbolInfoPointer)->getName();
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 2881 "1705070_backup.tab.c"
    break;

  case 64: /* factor: variable DECOP  */
#line 1112 "1705070_backup.y"
                   {
	fprintf(logs,"Line %d: factor : variable DECOP\n\n",numberOfLines);
	(yyval.symbolInfoPointer)->extraSymbolInfo.typeOfVar = (yyvsp[-1].symbolInfoPointer)->extraSymbolInfo.typeOfVar;
	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = (yyvsp[-1].symbolInfoPointer)->getName()+(yyvsp[0].symbolInfoPointer)->getName();
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 2892 "1705070_backup.tab.c"
    break;

  case 65: /* argument_list: arguments  */
#line 1119 "1705070_backup.y"
                         {
	fprintf(logs,"Line %d: argument_list : arguments\n\n",numberOfLines);

	//so we can get variable name and type Here
	SymbolInfo* s = new SymbolInfo();
	s->extraSymbolInfo.stringConcatenator = (yyvsp[0].symbolInfoPointer)->extraSymbolInfo.stringConcatenator;
	for(int i=0;i<(yyvsp[0].symbolInfoPointer)->extraSymbolInfo.functionParamList.size();i++)
	{
		s->extraSymbolInfo.functionParamList.push_back(make_pair((yyvsp[0].symbolInfoPointer)->extraSymbolInfo.functionParamList[i].first,(yyvsp[0].symbolInfoPointer)->extraSymbolInfo.functionParamList[i].second));
	}
	(yyval.symbolInfoPointer) = s;
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 2910 "1705070_backup.tab.c"
    break;

  case 66: /* argument_list: %empty  */
#line 1131 "1705070_backup.y"
    {
	SymbolInfo* s = new SymbolInfo("","");
	(yyval.symbolInfoPointer)=s;
}
#line 2919 "1705070_backup.tab.c"
    break;

  case 67: /* arguments: arguments COMMA logic_expression  */
#line 1136 "1705070_backup.y"
                                             {
	fprintf(logs,"Line %d: arguments : arguments COMMA logic_expression\n\n",numberOfLines);
	(yyval.symbolInfoPointer)->extraSymbolInfo.typeOfVar = (yyvsp[-2].symbolInfoPointer)->extraSymbolInfo.stringConcatenator.append(getFromSymbolSet("comma")+(yyvsp[0].symbolInfoPointer)->extraSymbolInfo.stringConcatenator);

	string name = (yyvsp[0].symbolInfoPointer)->getName();
	string variable_type = (yyvsp[0].symbolInfoPointer)->extraSymbolInfo.typeOfVar;

	if((yyvsp[0].symbolInfoPointer)->extraSymbolInfo.typeOfVar == "VOID")
	{
		numberOfErrors++;
		fprintf(logs,"Line %d: Void passed as parameter\n\n",numberOfLines);
	}else{
		(yyval.symbolInfoPointer)->extraSymbolInfo.functionParamList.push_back(make_pair(name,variable_type));
	}

	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 2941 "1705070_backup.tab.c"
    break;

  case 68: /* arguments: logic_expression  */
#line 1152 "1705070_backup.y"
                    {
	fprintf(logs,"Line %d: arguments : logic_expression\n\n",numberOfLines);

	string name = (yyvsp[0].symbolInfoPointer)->getName();
	string variable_type = (yyvsp[0].symbolInfoPointer)->extraSymbolInfo.typeOfVar;

	if((yyvsp[0].symbolInfoPointer)->extraSymbolInfo.typeOfVar == "VOID")
	{
		numberOfErrors++;
		fprintf(logs,"Line %d: Void passed as parameter\n\n",numberOfLines);
	}else{
		(yyval.symbolInfoPointer)->extraSymbolInfo.functionParamList.push_back(make_pair(name,variable_type));
	}

	(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator = (yyvsp[0].symbolInfoPointer)->extraSymbolInfo.stringConcatenator;
	fprintf(logs,"%s\n\n",(yyval.symbolInfoPointer)->extraSymbolInfo.stringConcatenator.c_str());
}
#line 2963 "1705070_backup.tab.c"
    break;


#line 2967 "1705070_backup.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1169 "1705070_backup.y"


int main(int argc,char *argv[])
{

	FILE* fp;

	if((fp=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}

	logs = fopen("1705070_log.txt","w");
	errors = fopen("1705070_error.txt","w");

	symbolSet();
	yyin=fp;
	yyparse();

    fprintf(logs,"Total lines: %d\n",numberOfLines-1);
	fprintf(logs,"Total errors: %d\n\n",numberOfErrors);
    fprintf(errors,"Total errors: %d\n\n",numberOfErrors);

	fclose(yyin);
    fclose(errors);
	fclose(logs);

	return 0;
}