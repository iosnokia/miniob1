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
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "yacc_sql.y"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unordered_set>
#include <algorithm>
#include <utility>

#include "common/log/log.h"
#include "common/lang/string.h"
#include "sql/parser/parse_defs.h"
#include "sql/parser/yacc_sql.hpp"
#include "sql/parser/lex_sql.h"
#include "sql/expr/expression.h"

using namespace std;

string token_name(const char *sql_string, YYLTYPE *llocp)
{
  return string(sql_string + llocp->first_column, llocp->last_column - llocp->first_column + 1);
}

int yyerror(YYLTYPE *llocp, const char *sql_string, ParsedSqlResult *sql_result, yyscan_t scanner, const char *msg)
{
  std::unique_ptr<ParsedSqlNode> error_sql_node = std::make_unique<ParsedSqlNode>(SCF_ERROR);
  error_sql_node->error.error_msg = msg;
  error_sql_node->error.line = llocp->first_line;
  error_sql_node->error.column = llocp->first_column;
  sql_result->add_sql_node(std::move(error_sql_node));
  return 0;
}

ArithmeticExpr *create_arithmetic_expression(ArithmeticExpr::Type type,
                                             Expression *left,
                                             Expression *right,
                                             const char *sql_string,
                                             YYLTYPE *llocp)
{
  ArithmeticExpr *expr = new ArithmeticExpr(type, left, right);
  expr->set_name(token_name(sql_string, llocp));
  return expr;
}


#line 117 "yacc_sql.cpp"

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

#include "yacc_sql.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SEMICOLON = 3,                  /* SEMICOLON  */
  YYSYMBOL_CREATE = 4,                     /* CREATE  */
  YYSYMBOL_DROP = 5,                       /* DROP  */
  YYSYMBOL_TABLE = 6,                      /* TABLE  */
  YYSYMBOL_VIEW = 7,                       /* VIEW  */
  YYSYMBOL_TABLES = 8,                     /* TABLES  */
  YYSYMBOL_INDEX = 9,                      /* INDEX  */
  YYSYMBOL_CALC = 10,                      /* CALC  */
  YYSYMBOL_SELECT = 11,                    /* SELECT  */
  YYSYMBOL_DESC = 12,                      /* DESC  */
  YYSYMBOL_SHOW = 13,                      /* SHOW  */
  YYSYMBOL_SYNC = 14,                      /* SYNC  */
  YYSYMBOL_INSERT = 15,                    /* INSERT  */
  YYSYMBOL_DELETE = 16,                    /* DELETE  */
  YYSYMBOL_UPDATE = 17,                    /* UPDATE  */
  YYSYMBOL_LBRACE = 18,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 19,                    /* RBRACE  */
  YYSYMBOL_UNIQUE = 20,                    /* UNIQUE  */
  YYSYMBOL_ORDER = 21,                     /* ORDER  */
  YYSYMBOL_BY = 22,                        /* BY  */
  YYSYMBOL_ASC = 23,                       /* ASC  */
  YYSYMBOL_COMMA = 24,                     /* COMMA  */
  YYSYMBOL_TRX_BEGIN = 25,                 /* TRX_BEGIN  */
  YYSYMBOL_TRX_COMMIT = 26,                /* TRX_COMMIT  */
  YYSYMBOL_TRX_ROLLBACK = 27,              /* TRX_ROLLBACK  */
  YYSYMBOL_INT_T = 28,                     /* INT_T  */
  YYSYMBOL_STRING_T = 29,                  /* STRING_T  */
  YYSYMBOL_FLOAT_T = 30,                   /* FLOAT_T  */
  YYSYMBOL_DATE_T = 31,                    /* DATE_T  */
  YYSYMBOL_NULL_T = 32,                    /* NULL_T  */
  YYSYMBOL_TEXT_T = 33,                    /* TEXT_T  */
  YYSYMBOL_HELP = 34,                      /* HELP  */
  YYSYMBOL_EXIT = 35,                      /* EXIT  */
  YYSYMBOL_DOT = 36,                       /* DOT  */
  YYSYMBOL_INTO = 37,                      /* INTO  */
  YYSYMBOL_VALUES = 38,                    /* VALUES  */
  YYSYMBOL_FROM = 39,                      /* FROM  */
  YYSYMBOL_WHERE = 40,                     /* WHERE  */
  YYSYMBOL_AND = 41,                       /* AND  */
  YYSYMBOL_OR = 42,                        /* OR  */
  YYSYMBOL_SET = 43,                       /* SET  */
  YYSYMBOL_ON = 44,                        /* ON  */
  YYSYMBOL_LOAD = 45,                      /* LOAD  */
  YYSYMBOL_DATA = 46,                      /* DATA  */
  YYSYMBOL_INFILE = 47,                    /* INFILE  */
  YYSYMBOL_EXPLAIN = 48,                   /* EXPLAIN  */
  YYSYMBOL_IS = 49,                        /* IS  */
  YYSYMBOL_EQ = 50,                        /* EQ  */
  YYSYMBOL_LT = 51,                        /* LT  */
  YYSYMBOL_GT = 52,                        /* GT  */
  YYSYMBOL_LE = 53,                        /* LE  */
  YYSYMBOL_GE = 54,                        /* GE  */
  YYSYMBOL_NE = 55,                        /* NE  */
  YYSYMBOL_SUM = 56,                       /* SUM  */
  YYSYMBOL_MAX = 57,                       /* MAX  */
  YYSYMBOL_MIN = 58,                       /* MIN  */
  YYSYMBOL_COUNT = 59,                     /* COUNT  */
  YYSYMBOL_AVG = 60,                       /* AVG  */
  YYSYMBOL_INNER = 61,                     /* INNER  */
  YYSYMBOL_JOIN = 62,                      /* JOIN  */
  YYSYMBOL_GROUP = 63,                     /* GROUP  */
  YYSYMBOL_IN = 64,                        /* IN  */
  YYSYMBOL_NOT = 65,                       /* NOT  */
  YYSYMBOL_EXISTS = 66,                    /* EXISTS  */
  YYSYMBOL_AS = 67,                        /* AS  */
  YYSYMBOL_LENGTH = 68,                    /* LENGTH  */
  YYSYMBOL_ROUND = 69,                     /* ROUND  */
  YYSYMBOL_DATE_FORMAT = 70,               /* DATE_FORMAT  */
  YYSYMBOL_LIKE = 71,                      /* LIKE  */
  YYSYMBOL_HAVING = 72,                    /* HAVING  */
  YYSYMBOL_NUMBER = 73,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 74,                     /* FLOAT  */
  YYSYMBOL__id = 75,                       /* _id  */
  YYSYMBOL_DATE_STR = 76,                  /* DATE_STR  */
  YYSYMBOL_SSS = 77,                       /* SSS  */
  YYSYMBOL_78_ = 78,                       /* '+'  */
  YYSYMBOL_79_ = 79,                       /* '-'  */
  YYSYMBOL_80_ = 80,                       /* '*'  */
  YYSYMBOL_81_ = 81,                       /* '/'  */
  YYSYMBOL_UMINUS = 82,                    /* UMINUS  */
  YYSYMBOL_83_ = 83,                       /* '~'  */
  YYSYMBOL_YYACCEPT = 84,                  /* $accept  */
  YYSYMBOL_commands = 85,                  /* commands  */
  YYSYMBOL_command_wrapper = 86,           /* command_wrapper  */
  YYSYMBOL_exit_stmt = 87,                 /* exit_stmt  */
  YYSYMBOL_help_stmt = 88,                 /* help_stmt  */
  YYSYMBOL_sync_stmt = 89,                 /* sync_stmt  */
  YYSYMBOL_begin_stmt = 90,                /* begin_stmt  */
  YYSYMBOL_commit_stmt = 91,               /* commit_stmt  */
  YYSYMBOL_rollback_stmt = 92,             /* rollback_stmt  */
  YYSYMBOL_ID = 93,                        /* ID  */
  YYSYMBOL_drop_table_stmt = 94,           /* drop_table_stmt  */
  YYSYMBOL_show_tables_stmt = 95,          /* show_tables_stmt  */
  YYSYMBOL_desc_table_stmt = 96,           /* desc_table_stmt  */
  YYSYMBOL_create_index_stmt = 97,         /* create_index_stmt  */
  YYSYMBOL_unique_flag = 98,               /* unique_flag  */
  YYSYMBOL_index_list = 99,                /* index_list  */
  YYSYMBOL_drop_index_stmt = 100,          /* drop_index_stmt  */
  YYSYMBOL_table_type = 101,               /* table_type  */
  YYSYMBOL_create_table_stmt = 102,        /* create_table_stmt  */
  YYSYMBOL_attr_def_list = 103,            /* attr_def_list  */
  YYSYMBOL_attr_def = 104,                 /* attr_def  */
  YYSYMBOL_number = 105,                   /* number  */
  YYSYMBOL_type = 106,                     /* type  */
  YYSYMBOL_insert_stmt = 107,              /* insert_stmt  */
  YYSYMBOL_value_list = 108,               /* value_list  */
  YYSYMBOL_value = 109,                    /* value  */
  YYSYMBOL_delete_stmt = 110,              /* delete_stmt  */
  YYSYMBOL_update_stmt = 111,              /* update_stmt  */
  YYSYMBOL_table_name = 112,               /* table_name  */
  YYSYMBOL_select_stmt = 113,              /* select_stmt  */
  YYSYMBOL_order_by_list_all = 114,        /* order_by_list_all  */
  YYSYMBOL_order_by_list = 115,            /* order_by_list  */
  YYSYMBOL_order_by_ = 116,                /* order_by_  */
  YYSYMBOL_calc_stmt = 117,                /* calc_stmt  */
  YYSYMBOL_expression_list = 118,          /* expression_list  */
  YYSYMBOL_expression = 119,               /* expression  */
  YYSYMBOL_select_list = 120,              /* select_list  */
  YYSYMBOL_rel_attr = 121,                 /* rel_attr  */
  YYSYMBOL_aggr = 122,                     /* aggr  */
  YYSYMBOL_aggr_func = 123,                /* aggr_func  */
  YYSYMBOL_rel_list = 124,                 /* rel_list  */
  YYSYMBOL_inner_join_list = 125,          /* inner_join_list  */
  YYSYMBOL_update_list = 126,              /* update_list  */
  YYSYMBOL_where = 127,                    /* where  */
  YYSYMBOL_having = 128,                   /* having  */
  YYSYMBOL_group_by = 129,                 /* group_by  */
  YYSYMBOL_condition_tree = 130,           /* condition_tree  */
  YYSYMBOL_condition = 131,                /* condition  */
  YYSYMBOL_comp_op = 132,                  /* comp_op  */
  YYSYMBOL_load_data_stmt = 133,           /* load_data_stmt  */
  YYSYMBOL_explain_stmt = 134,             /* explain_stmt  */
  YYSYMBOL_set_variable_stmt = 135,        /* set_variable_stmt  */
  YYSYMBOL_opt_semicolon = 136             /* opt_semicolon  */
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
typedef yytype_int16 yy_state_t;

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  85
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1000

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  84
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  165
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  324

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   333


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
       2,     2,    80,    78,     2,    79,     2,    81,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    83,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    82
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   230,   230,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   261,   267,   272,   278,   284,   290,   296,
     299,   302,   308,   315,   321,   329,   347,   350,   357,   376,
     387,   390,   396,   405,   424,   443,   466,   469,   482,   491,
     500,   509,   516,   528,   540,   554,   557,   558,   559,   560,
     561,   564,   580,   583,   594,   599,   604,   609,   614,   623,
     628,   637,   648,   665,   669,   674,   681,   737,   740,   747,
     753,   766,   773,   780,   787,   796,   805,   816,   823,   833,
     838,   844,   850,   859,   869,   881,   884,   887,   890,   893,
     897,   900,   905,   910,   916,   923,   929,   936,   946,   958,
     970,   983,   998,  1001,  1009,  1025,  1040,  1048,  1063,  1081,
    1084,  1088,  1093,  1100,  1112,  1113,  1114,  1115,  1116,  1121,
    1124,  1137,  1140,  1152,  1155,  1168,  1171,  1177,  1180,  1186,
    1189,  1201,  1204,  1207,  1211,  1217,  1225,  1231,  1236,  1241,
    1248,  1258,  1259,  1260,  1261,  1262,  1263,  1264,  1265,  1266,
    1267,  1271,  1284,  1292,  1302,  1303
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
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "CREATE",
  "DROP", "TABLE", "VIEW", "TABLES", "INDEX", "CALC", "SELECT", "DESC",
  "SHOW", "SYNC", "INSERT", "DELETE", "UPDATE", "LBRACE", "RBRACE",
  "UNIQUE", "ORDER", "BY", "ASC", "COMMA", "TRX_BEGIN", "TRX_COMMIT",
  "TRX_ROLLBACK", "INT_T", "STRING_T", "FLOAT_T", "DATE_T", "NULL_T",
  "TEXT_T", "HELP", "EXIT", "DOT", "INTO", "VALUES", "FROM", "WHERE",
  "AND", "OR", "SET", "ON", "LOAD", "DATA", "INFILE", "EXPLAIN", "IS",
  "EQ", "LT", "GT", "LE", "GE", "NE", "SUM", "MAX", "MIN", "COUNT", "AVG",
  "INNER", "JOIN", "GROUP", "IN", "NOT", "EXISTS", "AS", "LENGTH", "ROUND",
  "DATE_FORMAT", "LIKE", "HAVING", "NUMBER", "FLOAT", "_id", "DATE_STR",
  "SSS", "'+'", "'-'", "'*'", "'/'", "UMINUS", "'~'", "$accept",
  "commands", "command_wrapper", "exit_stmt", "help_stmt", "sync_stmt",
  "begin_stmt", "commit_stmt", "rollback_stmt", "ID", "drop_table_stmt",
  "show_tables_stmt", "desc_table_stmt", "create_index_stmt",
  "unique_flag", "index_list", "drop_index_stmt", "table_type",
  "create_table_stmt", "attr_def_list", "attr_def", "number", "type",
  "insert_stmt", "value_list", "value", "delete_stmt", "update_stmt",
  "table_name", "select_stmt", "order_by_list_all", "order_by_list",
  "order_by_", "calc_stmt", "expression_list", "expression", "select_list",
  "rel_attr", "aggr", "aggr_func", "rel_list", "inner_join_list",
  "update_list", "where", "having", "group_by", "condition_tree",
  "condition", "comp_op", "load_data_stmt", "explain_stmt",
  "set_variable_stmt", "opt_semicolon", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-207)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-113)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     930,    17,   109,   792,   760,   104,     9,  -207,   -30,   -18,
    -207,  -207,  -207,  -207,  -207,   104,   -19,   930,    19,    33,
    -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,
    -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,
    -207,  -207,  -207,    66,   104,   104,   104,   792,  -207,  -207,
    -207,  -207,  -207,  -207,  -207,    65,    69,    78,  -207,  -207,
    -207,  -207,  -207,   824,  -207,    62,  -207,  -207,   350,  -207,
    -207,    91,   792,    -8,  -207,   404,    87,  -207,  -207,  -207,
     104,   104,    67,    90,  -207,  -207,  -207,  -207,   104,   -15,
    -207,   111,    -1,   -26,   -26,   -26,  -207,  -207,    95,   223,
     792,   104,   792,   792,   792,   792,   146,   313,   512,   104,
     792,   104,   824,   856,   307,   566,  -207,   104,   136,   143,
      12,   121,   142,   104,   177,   104,  -207,     0,   180,   182,
     148,   149,   179,   181,  -207,  -207,  -207,   183,   -25,    95,
      95,    73,   792,   187,   104,   620,  -207,   161,   458,   674,
     110,   792,  -207,   104,   620,   861,   189,   196,   706,  -207,
    -207,   184,   104,   103,   191,   760,  -207,  -207,  -207,  -207,
    -207,  -207,  -207,    12,  -207,    12,   139,   140,   792,  -207,
    -207,   760,  -207,   792,   104,   307,   792,  -207,   760,   104,
    -207,   104,   158,    12,   706,   154,   204,   917,   135,  -207,
     217,   220,  -207,  -207,  -207,  -207,  -207,    25,   104,   216,
     221,   222,   225,   227,  -207,  -207,   -20,   674,  -207,   189,
     186,   143,   215,   178,    82,   233,   177,   188,  -207,  -207,
    -207,  -207,  -207,  -207,   234,    29,  -207,   792,   706,   706,
     104,   104,   197,  -207,   228,   191,     5,  -207,  -207,  -207,
    -207,   104,   143,  -207,   104,   192,    12,   252,  -207,   177,
     254,  -207,   792,   258,  -207,    73,  -207,   236,  -207,  -207,
     259,  -207,   265,  -207,  -207,   177,  -207,   237,  -207,   242,
     266,   219,   215,  -207,   270,  -207,   275,   792,  -207,   -27,
    -207,   792,   706,   792,   706,   274,  -207,  -207,  -207,   277,
    -207,   268,   -20,   -16,  -207,   135,   279,  -207,  -207,  -207,
    -207,  -207,   104,   102,  -207,   273,  -207,  -207,   104,   104,
      58,  -207,  -207,  -207
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    36,     0,     0,   112,     0,     0,    25,     0,     0,
      26,    27,    28,    24,    23,     0,     0,     0,     0,   164,
      22,    21,    14,    15,    16,    17,     9,    10,    11,    12,
      13,     8,     5,     7,     6,     4,     3,    18,    19,    20,
      41,    40,    37,     0,     0,     0,     0,     0,    69,    30,
     125,   127,   128,   126,   124,     0,     0,     0,    64,    65,
      29,    68,    70,     0,   119,   120,   101,    87,    89,   102,
     111,    31,     0,   120,    88,    89,     0,    34,    31,    33,
       0,     0,     0,     0,   162,     1,   165,     2,     0,     0,
      32,     0,     0,     0,     0,     0,    64,    65,   100,     0,
       0,     0,     0,     0,     0,     0,    90,     0,   112,     0,
       0,     0,     0,   119,   120,   112,   113,     0,     0,   135,
       0,     0,     0,     0,     0,     0,    99,     0,     0,     0,
       0,     0,     0,     0,   122,   121,    92,    91,    96,    97,
      98,    95,     0,     0,     0,   120,   116,     0,    89,    91,
      96,     0,   114,     0,   120,    73,   129,     0,   141,    71,
     163,     0,     0,    51,    46,   112,    42,    39,    66,    67,
     103,   104,   105,     0,   106,     0,     0,     0,     0,    93,
     123,   112,   117,     0,     0,   120,     0,   115,   112,     0,
      75,     0,   131,     0,   141,     0,     0,     0,   136,   143,
       0,     0,    56,    57,    58,    59,    60,    52,     0,     0,
       0,     0,     0,     0,    94,   118,   133,    91,    74,   129,
       0,   135,    62,     0,     0,     0,     0,   157,   151,   152,
     153,   154,   155,   156,     0,     0,   159,     0,   141,   141,
       0,     0,     0,    53,     0,    46,    45,   107,   108,   109,
     110,     0,   135,   130,     0,   139,     0,     0,   142,     0,
       0,   158,     0,     0,   160,   146,   144,   145,   161,    38,
       0,    55,     0,    54,    47,     0,    44,     0,    72,     0,
       0,   137,    62,    61,     0,   147,     0,     0,    35,    48,
      43,     0,   141,     0,   141,    77,    63,   148,   149,     0,
      49,     0,   133,   131,   140,   138,     0,    76,   150,    50,
     134,   132,     0,    81,    78,    79,    83,    82,     0,     0,
      84,    80,    86,    85
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -207,  -207,   285,  -207,  -207,  -207,  -207,  -207,  -207,    -4,
    -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,    60,
      98,  -207,  -207,  -207,    30,   -81,  -207,  -207,  -189,  -116,
    -207,    -3,  -207,  -207,     6,   162,   -46,    34,  -207,   101,
      92,    14,    16,  -206,  -207,  -207,  -172,  -207,  -207,  -207,
    -207,  -207,  -207
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    18,    19,    20,    21,    22,    23,    24,    25,    65,
      26,    27,    28,    29,    43,   270,    30,    44,    31,   209,
     164,   272,   207,    32,   257,    66,    33,    34,   156,    35,
     307,   314,   315,    36,   136,   115,    76,    69,    70,    71,
     192,   221,   252,   159,   295,   281,   198,   199,   237,    37,
      38,    39,    87
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      73,    77,   219,   123,   251,   300,    48,    80,   166,    67,
      74,    82,   128,   130,   132,   255,   165,    79,   126,    85,
      49,    81,   224,    40,    41,   238,   239,    83,    99,   116,
      50,    51,    52,    53,    54,   109,    86,    42,   301,   160,
      89,    90,    91,   242,    48,   220,   278,    58,    59,    60,
      61,    62,   124,   127,    64,   103,   104,   243,   105,   102,
     103,   104,   146,   105,   106,   279,   266,   267,   152,   116,
     322,   114,   275,   168,   169,    88,   118,   119,   102,   103,
     104,   323,   105,    93,   122,    58,    59,    94,    61,    62,
     244,   127,   210,   263,   211,   135,    95,   137,    99,   182,
     264,   258,   146,   187,   145,   147,    78,   149,   152,   107,
     260,   154,   222,   155,   316,    45,    78,   120,    46,   163,
     303,   167,   305,   238,   239,   317,   117,   129,   131,   133,
     276,   202,   203,   204,   205,   215,   206,   121,   318,   182,
     181,   143,   187,   284,   185,    78,    78,    78,   179,   188,
      49,   190,   102,   103,   104,   125,   105,   179,   201,   290,
      50,    51,    52,    53,    54,    68,    75,   172,   174,    78,
     142,   215,   173,   175,   157,   282,   238,   239,   105,    60,
     217,    78,    78,   158,   214,   218,   162,   155,   165,    78,
    -100,  -100,   214,   105,    78,    78,    78,   126,   161,   170,
      78,   171,    78,   176,   163,   177,   180,   178,    78,    92,
      78,   183,    78,   191,   193,   208,   212,   213,    78,   220,
     225,   200,   226,   240,    78,    98,    78,   227,   228,   229,
     230,   231,   232,   233,   108,   246,   268,   269,   241,   256,
     247,   248,   234,   235,   249,    78,   250,   277,   254,   236,
     155,   259,   262,   261,    78,   280,    78,   102,   103,   104,
     273,   105,    68,    78,   138,   139,   140,   141,   286,    49,
     271,   283,   148,   285,   150,   139,   287,   238,   288,    50,
      51,    52,    53,    54,   289,    78,   292,   291,   293,   297,
      78,   294,    78,   299,   298,   306,   308,   319,    60,   304,
     309,   312,    84,   134,    68,   274,   245,   -90,   313,    78,
     -90,   253,   296,   148,   320,   313,   321,   311,   310,     0,
     197,     0,     0,     0,     0,    47,     0,     0,     0,     0,
       0,   151,     0,     0,     0,     0,     0,     0,     0,    48,
      68,    78,    78,    99,     0,   216,  -112,     0,   148,     0,
       0,     0,    78,    49,     0,    78,   223,     0,     0,    49,
       0,     0,     0,    50,    51,    52,    53,    54,     0,    50,
      51,    52,    53,    54,   100,    55,    56,    57,     0,     0,
      58,    59,    60,    61,    62,     0,    63,    64,    60,     0,
       0,     0,     0,    64,     0,     0,    49,     0,     0,   265,
     197,   197,     0,     0,     0,     0,    50,    51,    52,    53,
      54,     0,     0,    78,     0,     0,     0,   101,     0,    78,
      78,     0,    47,     0,    68,    60,     0,     0,   110,   102,
     103,   104,     0,   105,     0,     0,    48,     0,     0,     0,
       0,     0,     0,  -112,     0,     0,     0,     0,     0,    68,
      49,     0,     0,   302,   197,    68,   197,     0,     0,     0,
      50,    51,    52,    53,    54,     0,     0,     0,     0,     0,
       0,   111,    55,    56,    57,     0,    47,    58,    59,    60,
      61,    62,   110,   112,   113,   104,     0,   105,     0,     0,
      48,     0,     0,     0,     0,     0,     0,  -112,     0,     0,
       0,     0,     0,     0,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,    51,    52,    53,    54,     0,
       0,     0,     0,     0,     0,   184,    55,    56,    57,     0,
      47,    58,    59,    60,    61,    62,    72,   112,   113,   104,
       0,   105,     0,     0,    48,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,    51,
      52,    53,    54,     0,     0,     0,     0,     0,     0,   144,
      55,    56,    57,     0,    47,    58,    59,    60,    61,    62,
      72,   112,   113,   104,     0,   105,     0,     0,    48,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    49,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    50,    51,    52,    53,    54,     0,     0,     0,
       0,     0,     0,   153,    55,    56,    57,     0,    47,    58,
      59,    60,    61,    62,    72,   112,   113,   104,     0,   105,
       0,     0,    48,     0,     0,     0,    99,     0,     0,  -112,
       0,     0,     0,     0,     0,     0,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,    51,    52,    53,
      54,     0,     0,     0,     0,     0,     0,     0,    55,    56,
      57,     0,    47,    58,    59,    60,    61,    62,   186,    63,
      64,     0,     0,     0,     0,     0,    48,     0,     0,     0,
       0,     0,     0,  -112,     0,     0,     0,     0,     0,     0,
      49,     0,     0,     0,   194,     0,     0,     0,     0,     0,
      50,    51,    52,    53,    54,     0,     0,     0,    48,     0,
       0,     0,    55,    56,    57,     0,     0,    58,    59,    60,
      61,    62,    49,    63,    64,     0,     0,     0,     0,     0,
       0,     0,    50,    51,    52,    53,    54,     0,     0,     0,
       0,   195,   196,     0,    55,    56,    57,     0,    47,    58,
      59,    60,    61,    62,    72,    63,    64,     0,     0,     0,
       0,     0,    48,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    49,     0,     0,     0,
      47,     0,     0,     0,     0,     0,    50,    51,    52,    53,
      54,     0,     0,     0,    48,     0,     0,     0,    55,    56,
      57,     0,     0,    58,    59,    60,    61,    62,    49,    63,
      64,     0,    47,     0,     0,     0,     0,     0,    50,    51,
      52,    53,    54,     0,     0,     0,    48,     0,     0,     0,
      55,    56,    57,     0,     0,    58,    59,    60,    61,    62,
      49,    63,    64,     0,    47,     0,     0,     0,     0,     0,
      50,    51,    52,    53,    54,     0,     0,     0,    48,     0,
       0,     0,    55,    56,    57,     0,     0,    96,    97,    60,
      61,    62,    49,    63,    64,     0,     0,    49,     0,     0,
       0,     0,    50,    51,    52,    53,    54,    50,    51,    52,
      53,    54,     0,     0,    55,    56,    57,     0,   189,    58,
      59,    60,    61,    62,     1,     2,    60,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,    12,     0,     0,
       0,     0,     0,     0,    13,    14,   227,   228,   229,   230,
     231,   232,   233,    15,     0,    16,     0,     0,    17,     0,
       0,   234,   235,     0,     0,     0,     0,     0,   236,     0,
       0,     0,     0,     0,     0,     0,   102,   103,   104,     0,
     105
};

static const yytype_int16 yycheck[] =
{
       4,     5,   191,    18,    24,    32,    32,    37,   124,     3,
       4,    15,    93,    94,    95,   221,    11,     8,    19,     0,
      46,    39,   194,     6,     7,    41,    42,    46,    36,    75,
      56,    57,    58,    59,    60,    43,     3,    20,    65,   120,
      44,    45,    46,    18,    32,    61,   252,    73,    74,    75,
      76,    77,    67,    79,    80,    80,    81,    32,    83,    79,
      80,    81,   108,    83,    68,   254,   238,   239,   114,   115,
      12,    75,    67,    73,    74,     9,    80,    81,    79,    80,
      81,    23,    83,    18,    88,    73,    74,    18,    76,    77,
      65,    79,   173,    64,   175,    99,    18,   101,    36,   145,
      71,    19,   148,   149,   108,   109,     5,   111,   154,    18,
     226,   115,   193,   117,    12,     6,    15,    50,     9,   123,
     292,   125,   294,    41,    42,    23,    39,    93,    94,    95,
     246,    28,    29,    30,    31,   181,    33,    47,    36,   185,
     144,   107,   188,   259,   148,    44,    45,    46,   142,   153,
      46,   155,    79,    80,    81,    44,    83,   151,   162,   275,
      56,    57,    58,    59,    60,     3,     4,    19,    19,    68,
      24,   217,    24,    24,    38,   256,    41,    42,    83,    75,
     184,    80,    81,    40,   178,   189,    44,   191,    11,    88,
      80,    81,   186,    83,    93,    94,    95,    19,    77,    19,
      99,    19,   101,    24,   208,    24,    19,    24,   107,    47,
     109,    50,   111,    24,    18,    24,    77,    77,   117,    61,
      66,    37,    18,     6,   123,    63,   125,    49,    50,    51,
      52,    53,    54,    55,    72,    19,   240,   241,    18,    24,
      19,    19,    64,    65,    19,   144,    19,   251,    62,    71,
     254,    18,    18,    65,   153,    63,   155,    79,    80,    81,
      32,    83,   100,   162,   102,   103,   104,   105,   262,    46,
      73,    19,   110,    19,   112,   113,    18,    41,    19,    56,
      57,    58,    59,    60,    19,   184,    44,    50,    22,    19,
     189,    72,   191,   287,    19,    21,    19,    24,    75,   293,
      32,    22,    17,    80,   142,   245,   208,     0,   312,   208,
       3,   219,   282,   151,   318,   319,   319,   303,   302,    -1,
     158,    -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
     178,   240,   241,    36,    -1,   183,    39,    -1,   186,    -1,
      -1,    -1,   251,    46,    -1,   254,   194,    -1,    -1,    46,
      -1,    -1,    -1,    56,    57,    58,    59,    60,    -1,    56,
      57,    58,    59,    60,    24,    68,    69,    70,    -1,    -1,
      73,    74,    75,    76,    77,    -1,    79,    80,    75,    -1,
      -1,    -1,    -1,    80,    -1,    -1,    46,    -1,    -1,   237,
     238,   239,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      60,    -1,    -1,   312,    -1,    -1,    -1,    67,    -1,   318,
     319,    -1,    18,    -1,   262,    75,    -1,    -1,    24,    79,
      80,    81,    -1,    83,    -1,    -1,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,   287,
      46,    -1,    -1,   291,   292,   293,   294,    -1,    -1,    -1,
      56,    57,    58,    59,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    70,    -1,    18,    73,    74,    75,
      76,    77,    24,    79,    80,    81,    -1,    83,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,    -1,
      18,    73,    74,    75,    76,    77,    24,    79,    80,    81,
      -1,    83,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      68,    69,    70,    -1,    18,    73,    74,    75,    76,    77,
      24,    79,    80,    81,    -1,    83,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    68,    69,    70,    -1,    18,    73,
      74,    75,    76,    77,    24,    79,    80,    81,    -1,    83,
      -1,    -1,    32,    -1,    -1,    -1,    36,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,
      70,    -1,    18,    73,    74,    75,    76,    77,    24,    79,
      80,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    60,    -1,    -1,    -1,    32,    -1,
      -1,    -1,    68,    69,    70,    -1,    -1,    73,    74,    75,
      76,    77,    46,    79,    80,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    60,    -1,    -1,    -1,
      -1,    65,    66,    -1,    68,    69,    70,    -1,    18,    73,
      74,    75,    76,    77,    24,    79,    80,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      18,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      60,    -1,    -1,    -1,    32,    -1,    -1,    -1,    68,    69,
      70,    -1,    -1,    73,    74,    75,    76,    77,    46,    79,
      80,    -1,    18,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    60,    -1,    -1,    -1,    32,    -1,    -1,    -1,
      68,    69,    70,    -1,    -1,    73,    74,    75,    76,    77,
      46,    79,    80,    -1,    18,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    60,    -1,    -1,    -1,    32,    -1,
      -1,    -1,    68,    69,    70,    -1,    -1,    73,    74,    75,
      76,    77,    46,    79,    80,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    60,    56,    57,    58,
      59,    60,    -1,    -1,    68,    69,    70,    -1,    67,    73,
      74,    75,    76,    77,     4,     5,    75,    -1,    -1,    -1,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,    49,    50,    51,    52,
      53,    54,    55,    43,    -1,    45,    -1,    -1,    48,    -1,
      -1,    64,    65,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    79,    80,    81,    -1,
      83
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,    10,    11,    12,    13,    14,    15,    16,
      25,    26,    27,    34,    35,    43,    45,    48,    85,    86,
      87,    88,    89,    90,    91,    92,    94,    95,    96,    97,
     100,   102,   107,   110,   111,   113,   117,   133,   134,   135,
       6,     7,    20,    98,   101,     6,     9,    18,    32,    46,
      56,    57,    58,    59,    60,    68,    69,    70,    73,    74,
      75,    76,    77,    79,    80,    93,   109,   118,   119,   121,
     122,   123,    24,    93,   118,   119,   120,    93,   123,     8,
      37,    39,    93,    46,    86,     0,     3,   136,     9,    93,
      93,    93,   119,    18,    18,    18,    73,    74,   119,    36,
      24,    67,    79,    80,    81,    83,    93,    18,   119,    43,
      24,    67,    79,    80,    93,   119,   120,    39,    93,    93,
      50,    47,    93,    18,    67,    44,    19,    79,   109,   121,
     109,   121,   109,   121,    80,    93,   118,    93,   119,   119,
     119,   119,    24,   121,    67,    93,   120,    93,   119,    93,
     119,    24,   120,    67,    93,    93,   112,    38,    40,   127,
     109,    77,    44,    93,   104,    11,   113,    93,    73,    74,
      19,    19,    19,    24,    19,    24,    24,    24,    24,   118,
      19,    93,   120,    50,    67,    93,    24,   120,    93,    67,
      93,    24,   124,    18,    18,    65,    66,   119,   130,   131,
      37,    93,    28,    29,    30,    31,    33,   106,    24,   103,
     109,   109,    77,    77,   118,   120,   119,    93,    93,   112,
      61,   125,   109,   119,   130,    66,    18,    49,    50,    51,
      52,    53,    54,    55,    64,    65,    71,   132,    41,    42,
       6,    18,    18,    32,    65,   104,    19,    19,    19,    19,
      19,    24,   126,   124,    62,   127,    24,   108,    19,    18,
     113,    65,    18,    64,    71,   119,   130,   130,    93,    93,
      99,    73,   105,    32,   103,    67,   113,    93,   127,   112,
      63,   129,   109,    19,   113,    19,   118,    18,    19,    19,
     113,    50,    44,    22,    72,   128,   108,    19,    19,   118,
      32,    65,   119,   130,   118,   130,    21,   114,    19,    32,
     126,   125,    22,    93,   115,   116,    12,    23,    36,    24,
      93,   115,    12,    23
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    84,    85,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    87,    88,    89,    90,    91,    92,    93,
      93,    93,    94,    95,    96,    97,    98,    98,    99,   100,
     101,   101,   102,   102,   102,   102,   103,   103,   104,   104,
     104,   104,   104,   104,   104,   105,   106,   106,   106,   106,
     106,   107,   108,   108,   109,   109,   109,   109,   109,   109,
     109,   110,   111,   112,   112,   112,   113,   114,   114,   115,
     115,   116,   116,   116,   116,   116,   116,   117,   117,   118,
     118,   118,   118,   118,   118,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   120,   120,   120,   120,   120,   120,   120,   121,
     121,   121,   121,   122,   123,   123,   123,   123,   123,   124,
     124,   125,   125,   126,   126,   127,   127,   128,   128,   129,
     129,   130,   130,   130,   130,   130,   131,   131,   131,   131,
     131,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   133,   134,   135,   136,   136
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     2,     9,     0,     1,     1,     5,
       1,     1,     5,     9,     8,     7,     0,     3,     5,     6,
       7,     1,     2,     3,     4,     1,     1,     1,     1,     1,
       1,     8,     0,     3,     1,     1,     2,     2,     1,     1,
       1,     4,     8,     1,     3,     2,    10,     0,     3,     1,
       3,     1,     2,     2,     3,     4,     4,     2,     2,     1,
       2,     3,     3,     4,     5,     3,     3,     3,     3,     3,
       2,     1,     1,     4,     4,     4,     4,     6,     6,     6,
       6,     1,     0,     2,     3,     4,     3,     4,     5,     1,
       1,     3,     3,     4,     1,     1,     1,     1,     1,     0,
       3,     0,     6,     0,     5,     0,     2,     0,     2,     0,
       3,     0,     3,     1,     3,     3,     3,     4,     5,     5,
       6,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       2,     7,     2,     4,     0,     1
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
        yyerror (&yylloc, sql_string, sql_result, scanner, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, sql_string, sql_result, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (sql_string);
  YY_USE (sql_result);
  YY_USE (scanner);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, sql_string, sql_result, scanner);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), sql_string, sql_result, scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, sql_string, sql_result, scanner); \
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
  YYLTYPE *yylloc;
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (sql_string);
  YY_USE (sql_result);
  YY_USE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yychar = yylex (&yylval, &yylloc, scanner);
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
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* commands: command_wrapper opt_semicolon  */
#line 231 "yacc_sql.y"
  {
    std::unique_ptr<ParsedSqlNode> sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[-1].sql_node));
    sql_result->add_sql_node(std::move(sql_node));
  }
#line 2013 "yacc_sql.cpp"
    break;

  case 23: /* exit_stmt: EXIT  */
#line 261 "yacc_sql.y"
         {
      (void)yynerrs;  // 这么写为了消除yynerrs未使用的告警。如果你有更好的方法欢迎提PR
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXIT);
    }
#line 2022 "yacc_sql.cpp"
    break;

  case 24: /* help_stmt: HELP  */
#line 267 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_HELP);
    }
#line 2030 "yacc_sql.cpp"
    break;

  case 25: /* sync_stmt: SYNC  */
#line 272 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SYNC);
    }
#line 2038 "yacc_sql.cpp"
    break;

  case 26: /* begin_stmt: TRX_BEGIN  */
#line 278 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_BEGIN);
    }
#line 2046 "yacc_sql.cpp"
    break;

  case 27: /* commit_stmt: TRX_COMMIT  */
#line 284 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_COMMIT);
    }
#line 2054 "yacc_sql.cpp"
    break;

  case 28: /* rollback_stmt: TRX_ROLLBACK  */
#line 290 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_ROLLBACK);
    }
#line 2062 "yacc_sql.cpp"
    break;

  case 29: /* ID: _id  */
#line 296 "yacc_sql.y"
        {
      (yyval.string) = (yyvsp[0].string);
    }
#line 2070 "yacc_sql.cpp"
    break;

  case 30: /* ID: DATA  */
#line 299 "yacc_sql.y"
           {
      (yyval.string) = strdup(token_name(sql_string, &(yyloc)).c_str());
    }
#line 2078 "yacc_sql.cpp"
    break;

  case 31: /* ID: aggr_func  */
#line 302 "yacc_sql.y"
                {
      (yyval.string) = strdup(token_name(sql_string, &(yyloc)).c_str());
    }
#line 2086 "yacc_sql.cpp"
    break;

  case 32: /* drop_table_stmt: DROP TABLE ID  */
#line 308 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_TABLE);
      (yyval.sql_node)->drop_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2096 "yacc_sql.cpp"
    break;

  case 33: /* show_tables_stmt: SHOW TABLES  */
#line 315 "yacc_sql.y"
                {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_TABLES);
    }
#line 2104 "yacc_sql.cpp"
    break;

  case 34: /* desc_table_stmt: DESC ID  */
#line 321 "yacc_sql.y"
             {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DESC_TABLE);
      (yyval.sql_node)->desc_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2114 "yacc_sql.cpp"
    break;

  case 35: /* create_index_stmt: CREATE unique_flag INDEX ID ON ID LBRACE index_list RBRACE  */
#line 330 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = (yyval.sql_node)->create_index;
      if((yyvsp[-7].unique_flag_type) == true){
        create_index.is_unique = true ;
      }
      create_index.index_name = (yyvsp[-5].string);
      create_index.relation_name = (yyvsp[-3].string);
      create_index.attribute_name.swap(*(yyvsp[-1].index_list_attr));
      free((yyvsp[-5].string));
      free((yyvsp[-3].string));
      free((yyvsp[-1].index_list_attr));
    }
#line 2132 "yacc_sql.cpp"
    break;

  case 36: /* unique_flag: %empty  */
#line 347 "yacc_sql.y"
    {
      (yyval.unique_flag_type) = false;
    }
#line 2140 "yacc_sql.cpp"
    break;

  case 37: /* unique_flag: UNIQUE  */
#line 351 "yacc_sql.y"
    {
      (yyval.unique_flag_type) = true ;
    }
#line 2148 "yacc_sql.cpp"
    break;

  case 38: /* index_list: ID  */
#line 358 "yacc_sql.y"
    {
      (yyval.index_list_attr) = new std::vector<std::string> ;
      (yyval.index_list_attr)->emplace_back((yyvsp[0].string)) ;
    }
#line 2157 "yacc_sql.cpp"
    break;

  case 39: /* drop_index_stmt: DROP INDEX ID ON ID  */
#line 377 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_INDEX);
      (yyval.sql_node)->drop_index.index_name = (yyvsp[-2].string);
      (yyval.sql_node)->drop_index.relation_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2169 "yacc_sql.cpp"
    break;

  case 40: /* table_type: VIEW  */
#line 387 "yacc_sql.y"
         {
        (yyval.table_type) = VIEW_T;
    }
#line 2177 "yacc_sql.cpp"
    break;

  case 41: /* table_type: TABLE  */
#line 390 "yacc_sql.y"
            {
        (yyval.table_type) = TABLE_T;
    }
#line 2185 "yacc_sql.cpp"
    break;

  case 42: /* create_table_stmt: CREATE table_type ID AS select_stmt  */
#line 397 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_TABLE);
      (yyval.sql_node)->create_table.relation_name = (yyvsp[-2].string);
      (yyval.sql_node)->create_table.select = std::make_unique<SqlExpr>((yyvsp[0].sql_node));
      (yyval.sql_node)->create_table.is_from_select = true;
      (yyval.sql_node)->create_table.type = (yyvsp[-3].table_type);
      free((yyvsp[-2].string));
    }
#line 2198 "yacc_sql.cpp"
    break;

  case 43: /* create_table_stmt: CREATE table_type ID LBRACE attr_def attr_def_list RBRACE AS select_stmt  */
#line 405 "yacc_sql.y"
                                                                               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_TABLE);
      CreateTableSqlNode &create_table = (yyval.sql_node)->create_table;
      create_table.relation_name = (yyvsp[-6].string);
      free((yyvsp[-6].string));

      std::vector<AttrInfoSqlNode> *src_attrs = (yyvsp[-3].attr_infos);

      if (src_attrs != nullptr) {
        create_table.attr_infos.swap(*src_attrs);
      }
      create_table.attr_infos.emplace_back(*(yyvsp[-4].attr_info));
      std::reverse(create_table.attr_infos.begin(), create_table.attr_infos.end());
      delete (yyvsp[-4].attr_info);

      (yyval.sql_node)->create_table.select = std::make_unique<SqlExpr>((yyvsp[0].sql_node));
      (yyval.sql_node)->create_table.is_from_select = true;
      (yyval.sql_node)->create_table.type = (yyvsp[-7].table_type);
    }
#line 2222 "yacc_sql.cpp"
    break;

  case 44: /* create_table_stmt: CREATE table_type ID LBRACE attr_def attr_def_list RBRACE select_stmt  */
#line 424 "yacc_sql.y"
                                                                            {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_TABLE);
      CreateTableSqlNode &create_table = (yyval.sql_node)->create_table;
      create_table.relation_name = (yyvsp[-5].string);
      free((yyvsp[-5].string));

      std::vector<AttrInfoSqlNode> *src_attrs = (yyvsp[-2].attr_infos);

      if (src_attrs != nullptr) {
        create_table.attr_infos.swap(*src_attrs);
      }
      create_table.attr_infos.emplace_back(*(yyvsp[-3].attr_info));
      std::reverse(create_table.attr_infos.begin(), create_table.attr_infos.end());
      delete (yyvsp[-3].attr_info);

      (yyval.sql_node)->create_table.select = std::make_unique<SqlExpr>((yyvsp[0].sql_node));
      (yyval.sql_node)->create_table.is_from_select = true;
      (yyval.sql_node)->create_table.type = (yyvsp[-6].table_type);
    }
#line 2246 "yacc_sql.cpp"
    break;

  case 45: /* create_table_stmt: CREATE table_type ID LBRACE attr_def attr_def_list RBRACE  */
#line 444 "yacc_sql.y"
    {
      if ((yyvsp[-5].table_type) != TABLE_T) {
        yyerror(&(yyloc), sql_string, sql_result, scanner, "only table can be created");
      }
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_TABLE);
      CreateTableSqlNode &create_table = (yyval.sql_node)->create_table;
      create_table.relation_name = (yyvsp[-4].string);
      free((yyvsp[-4].string));

      std::vector<AttrInfoSqlNode> *src_attrs = (yyvsp[-1].attr_infos);

      if (src_attrs != nullptr) {
        create_table.attr_infos.swap(*src_attrs);
      }
      create_table.attr_infos.emplace_back(*(yyvsp[-2].attr_info));
      std::reverse(create_table.attr_infos.begin(), create_table.attr_infos.end());
      delete (yyvsp[-2].attr_info);
      (yyval.sql_node)->create_table.type = (yyvsp[-5].table_type);
    }
#line 2270 "yacc_sql.cpp"
    break;

  case 46: /* attr_def_list: %empty  */
#line 466 "yacc_sql.y"
    {
      (yyval.attr_infos) = nullptr;
    }
#line 2278 "yacc_sql.cpp"
    break;

  case 47: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 470 "yacc_sql.y"
    {
      if ((yyvsp[0].attr_infos) != nullptr) {
        (yyval.attr_infos) = (yyvsp[0].attr_infos);
      } else {
        (yyval.attr_infos) = new std::vector<AttrInfoSqlNode>;
      }
      (yyval.attr_infos)->emplace_back(*(yyvsp[-1].attr_info));
      delete (yyvsp[-1].attr_info);
    }
#line 2292 "yacc_sql.cpp"
    break;

  case 48: /* attr_def: ID type LBRACE number RBRACE  */
#line 483 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-3].number);
      (yyval.attr_info)->name = (yyvsp[-4].string);
      (yyval.attr_info)->length = (yyvsp[-1].number);
      (yyval.attr_info)->is_allow_null = false;
      free((yyvsp[-4].string));
    }
#line 2305 "yacc_sql.cpp"
    break;

  case 49: /* attr_def: ID type LBRACE number RBRACE NULL_T  */
#line 492 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-4].number);
      (yyval.attr_info)->name = (yyvsp[-5].string);
      (yyval.attr_info)->length = (yyvsp[-2].number);
      (yyval.attr_info)->is_allow_null = true;
      free((yyvsp[-5].string));
    }
#line 2318 "yacc_sql.cpp"
    break;

  case 50: /* attr_def: ID type LBRACE number RBRACE NOT NULL_T  */
#line 501 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-5].number);
      (yyval.attr_info)->name = (yyvsp[-6].string);
       (yyval.attr_info)->length = (yyvsp[-3].number);
       (yyval.attr_info)->is_allow_null = false;
       free((yyvsp[-6].string));
    }
#line 2331 "yacc_sql.cpp"
    break;

  case 51: /* attr_def: ID  */
#line 509 "yacc_sql.y"
         {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->name = (yyvsp[0].string);
      (yyval.attr_info)->length = 4;
      (yyval.attr_info)->is_allow_null = false;
      free((yyvsp[0].string));
    }
#line 2343 "yacc_sql.cpp"
    break;

  case 52: /* attr_def: ID type  */
#line 517 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[0].number);
      (yyval.attr_info)->name = (yyvsp[-1].string);
      (yyval.attr_info)->length = 4;
      if ((yyval.attr_info)->type == TEXTS) {
        (yyval.attr_info)->length = 36;
      }
      (yyval.attr_info)->is_allow_null = false;
      free((yyvsp[-1].string));
    }
#line 2359 "yacc_sql.cpp"
    break;

  case 53: /* attr_def: ID type NULL_T  */
#line 529 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-1].number);
      (yyval.attr_info)->name = (yyvsp[-2].string);
      (yyval.attr_info)->length = 4;
      if ((yyval.attr_info)->type == TEXTS) {
        (yyval.attr_info)->length = 36;
      }
      (yyval.attr_info)->is_allow_null = true;
      free((yyvsp[-2].string));
    }
#line 2375 "yacc_sql.cpp"
    break;

  case 54: /* attr_def: ID type NOT NULL_T  */
#line 541 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-2].number);
      (yyval.attr_info)->name = (yyvsp[-3].string);
      (yyval.attr_info)->length = 4;
      if ((yyval.attr_info)->type == TEXTS) {
        (yyval.attr_info)->length = 36;
      }
      (yyval.attr_info)->is_allow_null = false;
      free((yyvsp[-3].string));
    }
#line 2391 "yacc_sql.cpp"
    break;

  case 55: /* number: NUMBER  */
#line 554 "yacc_sql.y"
           {(yyval.number) = (yyvsp[0].number);}
#line 2397 "yacc_sql.cpp"
    break;

  case 56: /* type: INT_T  */
#line 557 "yacc_sql.y"
               { (yyval.number)=INTS; }
#line 2403 "yacc_sql.cpp"
    break;

  case 57: /* type: STRING_T  */
#line 558 "yacc_sql.y"
               { (yyval.number)=CHARS; }
#line 2409 "yacc_sql.cpp"
    break;

  case 58: /* type: FLOAT_T  */
#line 559 "yacc_sql.y"
               { (yyval.number)=FLOATS; }
#line 2415 "yacc_sql.cpp"
    break;

  case 59: /* type: DATE_T  */
#line 560 "yacc_sql.y"
               { (yyval.number)=DATES;  }
#line 2421 "yacc_sql.cpp"
    break;

  case 60: /* type: TEXT_T  */
#line 561 "yacc_sql.y"
               { (yyval.number)=TEXTS;}
#line 2427 "yacc_sql.cpp"
    break;

  case 61: /* insert_stmt: INSERT INTO ID VALUES LBRACE value value_list RBRACE  */
#line 565 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_INSERT);
      (yyval.sql_node)->insertion.relation_name = (yyvsp[-5].string);
      if ((yyvsp[-1].value_list) != nullptr) {
        (yyval.sql_node)->insertion.values.swap(*(yyvsp[-1].value_list));
      }
      (yyval.sql_node)->insertion.values.emplace_back(*(yyvsp[-2].value));
      std::reverse((yyval.sql_node)->insertion.values.begin(), (yyval.sql_node)->insertion.values.end());
      delete (yyvsp[-2].value);
      free((yyvsp[-5].string));
    }
#line 2443 "yacc_sql.cpp"
    break;

  case 62: /* value_list: %empty  */
#line 580 "yacc_sql.y"
    {
      (yyval.value_list) = nullptr;
    }
#line 2451 "yacc_sql.cpp"
    break;

  case 63: /* value_list: COMMA value value_list  */
#line 583 "yacc_sql.y"
                              { 
      if ((yyvsp[0].value_list) != nullptr) {
        (yyval.value_list) = (yyvsp[0].value_list);
      } else {
        (yyval.value_list) = new std::vector<Value>;
      }
      (yyval.value_list)->emplace_back(*(yyvsp[-1].value));
      delete (yyvsp[-1].value);
    }
#line 2465 "yacc_sql.cpp"
    break;

  case 64: /* value: NUMBER  */
#line 594 "yacc_sql.y"
           {
      (yyval.value) = new Value((int)(yyvsp[0].number));
      (yyval.value)->set_name(token_name(sql_string, &(yyloc)));
      (yyloc) = (yylsp[0]);
    }
#line 2475 "yacc_sql.cpp"
    break;

  case 65: /* value: FLOAT  */
#line 599 "yacc_sql.y"
            {
      (yyval.value) = new Value((float)(yyvsp[0].floats));
      (yyval.value)->set_name(token_name(sql_string, &(yyloc)));
      (yyloc) = (yylsp[0]);
    }
#line 2485 "yacc_sql.cpp"
    break;

  case 66: /* value: '-' NUMBER  */
#line 604 "yacc_sql.y"
                 {
      (yyval.value) = new Value((int)-(yyvsp[0].number));
      (yyval.value)->set_name(token_name(sql_string, &(yyloc)));
      (yyloc) = (yylsp[-1]);
    }
#line 2495 "yacc_sql.cpp"
    break;

  case 67: /* value: '-' FLOAT  */
#line 609 "yacc_sql.y"
                {
      (yyval.value) = new Value((float)-(yyvsp[0].floats));
      (yyval.value)->set_name(token_name(sql_string, &(yyloc)));
      (yyloc) = (yylsp[-1]);
    }
#line 2505 "yacc_sql.cpp"
    break;

  case 68: /* value: DATE_STR  */
#line 614 "yacc_sql.y"
              {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.value) = value_init_date(tmp);
      (yyval.value)->set_name(token_name(sql_string, &(yyloc)));
      free(tmp);
      if (!(yyval.value)->get_date().isValid()) {
        return -1;
      }
    }
#line 2519 "yacc_sql.cpp"
    break;

  case 69: /* value: NULL_T  */
#line 623 "yacc_sql.y"
            {
      (yyval.value) = new Value("");
      (yyval.value)->set_name(token_name(sql_string, &(yyloc)));
      (yyval.value)->set_null();
    }
#line 2529 "yacc_sql.cpp"
    break;

  case 70: /* value: SSS  */
#line 628 "yacc_sql.y"
         {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.value)  = new Value(tmp);
      free(tmp);
    }
#line 2539 "yacc_sql.cpp"
    break;

  case 71: /* delete_stmt: DELETE FROM ID where  */
#line 638 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DELETE);
      (yyval.sql_node)->deletion.relation_name = (yyvsp[-1].string);
      if ((yyvsp[0].condition_tree) != nullptr) {
        (yyval.sql_node)->deletion.conditions.reset((yyvsp[0].condition_tree));
      }
      free((yyvsp[-1].string));
    }
#line 2552 "yacc_sql.cpp"
    break;

  case 72: /* update_stmt: SELECT ID SET ID EQ expression update_list where  */
#line 649 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_UPDATE);
      (yyval.sql_node)->update.relation_name = (yyvsp[-6].string);
      if ((yyvsp[-1].update_list) != nullptr) {
         (yyval.sql_node)->update.update_list.swap(*(yyvsp[-1].update_list));
         delete (yyvsp[-1].update_list);
      }
      (yyval.sql_node)->update.update_list.insert(std::make_pair((yyvsp[-4].string), std::unique_ptr<Expression>((yyvsp[-2].expression))));
      if ((yyvsp[0].condition_tree) != nullptr) {
        (yyval.sql_node)->update.conditions.reset((yyvsp[0].condition_tree));
      }
      free((yyvsp[-6].string));
      free((yyvsp[-4].string));
    }
#line 2571 "yacc_sql.cpp"
    break;

  case 73: /* table_name: ID  */
#line 665 "yacc_sql.y"
       {
      (yyval.name_with_alias) = new NameWithAlias((yyvsp[0].string), "");
      free((yyvsp[0].string));
    }
#line 2580 "yacc_sql.cpp"
    break;

  case 74: /* table_name: ID AS ID  */
#line 669 "yacc_sql.y"
               {
      (yyval.name_with_alias) = new NameWithAlias((yyvsp[-2].string), (yyvsp[0].string));
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2590 "yacc_sql.cpp"
    break;

  case 75: /* table_name: ID ID  */
#line 674 "yacc_sql.y"
            {
      (yyval.name_with_alias) = new NameWithAlias((yyvsp[-1].string), (yyvsp[0].string));
      free((yyvsp[-1].string));
      free((yyvsp[0].string));
    }
#line 2600 "yacc_sql.cpp"
    break;

  case 76: /* select_stmt: SELECT select_list FROM table_name rel_list inner_join_list where group_by having order_by_list_all  */
#line 682 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      if ((yyvsp[-8].select_list) != nullptr) {
        //std::reverse($2->nodes.begin(), $2->nodes.end());
        (yyval.sql_node)->selection.select_exprs.swap((yyvsp[-8].select_list)->exprs);
        delete (yyvsp[-8].select_list);
      }
      if ((yyvsp[-5].relation_list) != nullptr) {
        (yyval.sql_node)->selection.relations.swap(*(yyvsp[-5].relation_list));
        delete (yyvsp[-5].relation_list);
      }
      (yyval.sql_node)->selection.relations.push_back(*(yyvsp[-6].name_with_alias));
      std::reverse((yyval.sql_node)->selection.relations.begin(), (yyval.sql_node)->selection.relations.end());

      // check relations' validity
      std::unordered_set<std::string> aliases;
        for (auto &rel : (yyval.sql_node)->selection.relations) {
            const auto& alias = rel.second;
            if (alias.empty()) continue;
            if (aliases.find(alias) != aliases.end()) {
            yyerror(&(yyloc), sql_string, sql_result, scanner, "duplicate alias");
            }
            aliases.insert(alias);
        }

      if ((yyvsp[-4].join_list) != nullptr) {
        (yyval.sql_node)->selection.join_list = (*(yyvsp[-4].join_list));
        (yyval.sql_node)->selection.join_list.relations.push_back(*(yyvsp[-6].name_with_alias));
        std::reverse((yyval.sql_node)->selection.join_list.relations.begin(),(yyval.sql_node)->selection.join_list.relations.end());
        std::reverse((yyval.sql_node)->selection.join_list.conditions.begin(),(yyval.sql_node)->selection.join_list.conditions.end());
        (yyval.sql_node)->selection.relations=(yyval.sql_node)->selection.join_list.relations;
      }

      if ((yyvsp[-3].condition_tree) != nullptr) {
        (yyval.sql_node)->selection.conditions.reset((yyvsp[-3].condition_tree));
      }

      if ((yyvsp[-2].group_by) != nullptr) {
        (yyval.sql_node)->selection.group_by = std::move(*(yyvsp[-2].group_by));
        delete (yyvsp[-2].group_by);
      }
      if ((yyvsp[-1].condition_tree) != nullptr) {
        (yyval.sql_node)->selection.having.reset((yyvsp[-1].condition_tree));
      }
      if ((yyvsp[0].rel_attr_list) != nullptr) {
        (yyval.sql_node)->selection.order_lists.swap(*(yyvsp[0].rel_attr_list));
        delete (yyvsp[0].rel_attr_list);
      }

      delete (yyvsp[-6].name_with_alias);
    }
#line 2656 "yacc_sql.cpp"
    break;

  case 77: /* order_by_list_all: %empty  */
#line 737 "yacc_sql.y"
    {
      (yyval.rel_attr_list) = nullptr;
    }
#line 2664 "yacc_sql.cpp"
    break;

  case 78: /* order_by_list_all: ORDER BY order_by_list  */
#line 741 "yacc_sql.y"
    {
      (yyval.rel_attr_list) = (yyvsp[0].rel_attr_list);
    }
#line 2672 "yacc_sql.cpp"
    break;

  case 79: /* order_by_list: order_by_  */
#line 748 "yacc_sql.y"
    {
      (yyval.rel_attr_list) = new std::vector<RelAttrSqlNode>;
      (yyval.rel_attr_list)->emplace_back(*(yyvsp[0].rel_attr));
      delete (yyvsp[0].rel_attr);
    }
#line 2682 "yacc_sql.cpp"
    break;

  case 80: /* order_by_list: order_by_ COMMA order_by_list  */
#line 754 "yacc_sql.y"
    {
      if ((yyvsp[0].rel_attr_list) != nullptr) {
        (yyval.rel_attr_list) = (yyvsp[0].rel_attr_list);
      } else {
        (yyval.rel_attr_list) = new std::vector<RelAttrSqlNode>;
      }
      (yyval.rel_attr_list)->emplace_back(*(yyvsp[-2].rel_attr));
      delete (yyvsp[-2].rel_attr);
    }
#line 2696 "yacc_sql.cpp"
    break;

  case 81: /* order_by_: ID  */
#line 767 "yacc_sql.y"
    {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->attribute_name  = (yyvsp[0].string);
      (yyval.rel_attr)->sort_way = "ASC";
      free((yyvsp[0].string));
    }
#line 2707 "yacc_sql.cpp"
    break;

  case 82: /* order_by_: ID ASC  */
#line 774 "yacc_sql.y"
    {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->attribute_name  = (yyvsp[-1].string);
      (yyval.rel_attr)->sort_way = "ASC";
      free((yyvsp[-1].string));
    }
#line 2718 "yacc_sql.cpp"
    break;

  case 83: /* order_by_: ID DESC  */
#line 781 "yacc_sql.y"
    {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->attribute_name  = (yyvsp[-1].string);
      (yyval.rel_attr)->sort_way = "DESC";
      free((yyvsp[-1].string));
    }
#line 2729 "yacc_sql.cpp"
    break;

  case 84: /* order_by_: ID DOT ID  */
#line 788 "yacc_sql.y"
    {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-2].string);
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      (yyval.rel_attr)->sort_way = "ASC";
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2742 "yacc_sql.cpp"
    break;

  case 85: /* order_by_: ID DOT ID ASC  */
#line 797 "yacc_sql.y"
    {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-3].string);
      (yyval.rel_attr)->attribute_name = (yyvsp[-1].string);
      (yyval.rel_attr)->sort_way = "ASC";
      free((yyvsp[-3].string));
      free((yyvsp[-1].string));
    }
#line 2755 "yacc_sql.cpp"
    break;

  case 86: /* order_by_: ID DOT ID DESC  */
#line 806 "yacc_sql.y"
    {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-3].string);
      (yyval.rel_attr)->attribute_name = (yyvsp[-1].string);
      (yyval.rel_attr)->sort_way = "DESC";
      free((yyvsp[-3].string));
      free((yyvsp[-1].string));
    }
#line 2768 "yacc_sql.cpp"
    break;

  case 87: /* calc_stmt: CALC expression_list  */
#line 817 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CALC);
      std::reverse((yyvsp[0].expression_list)->begin(), (yyvsp[0].expression_list)->end());
      (yyval.sql_node)->calc.expressions.swap(*(yyvsp[0].expression_list));
      delete (yyvsp[0].expression_list);
    }
#line 2779 "yacc_sql.cpp"
    break;

  case 88: /* calc_stmt: SELECT expression_list  */
#line 824 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CALC);
      std::reverse((yyvsp[0].expression_list)->begin(), (yyvsp[0].expression_list)->end());
      (yyval.sql_node)->calc.expressions.swap(*(yyvsp[0].expression_list));
      delete (yyvsp[0].expression_list);
    }
#line 2790 "yacc_sql.cpp"
    break;

  case 89: /* expression_list: expression  */
#line 834 "yacc_sql.y"
    {
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back((yyvsp[0].expression));
    }
#line 2799 "yacc_sql.cpp"
    break;

  case 90: /* expression_list: expression ID  */
#line 839 "yacc_sql.y"
    {
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyvsp[-1].expression)->set_name((yyvsp[0].string)); free((yyvsp[0].string));
      (yyval.expression_list)->emplace_back((yyvsp[-1].expression));
    }
#line 2809 "yacc_sql.cpp"
    break;

  case 91: /* expression_list: expression AS ID  */
#line 845 "yacc_sql.y"
    {
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyvsp[-2].expression)->set_name((yyvsp[0].string)); free((yyvsp[0].string));
      (yyval.expression_list)->emplace_back((yyvsp[-2].expression));
    }
#line 2819 "yacc_sql.cpp"
    break;

  case 92: /* expression_list: expression COMMA expression_list  */
#line 851 "yacc_sql.y"
    {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression *>;
      }
      (yyval.expression_list)->emplace_back((yyvsp[-2].expression));
    }
#line 2832 "yacc_sql.cpp"
    break;

  case 93: /* expression_list: expression ID COMMA expression_list  */
#line 860 "yacc_sql.y"
    {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression *>;
      }
      (yyvsp[-3].expression)->set_name((yyvsp[-2].string)); free((yyvsp[-2].string));
      (yyval.expression_list)->emplace_back((yyvsp[-3].expression));
    }
#line 2846 "yacc_sql.cpp"
    break;

  case 94: /* expression_list: expression AS ID COMMA expression_list  */
#line 870 "yacc_sql.y"
    {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression *>;
      }
      (yyvsp[-4].expression)->set_name((yyvsp[-2].string)); free((yyvsp[-2].string));
      (yyval.expression_list)->emplace_back((yyvsp[-4].expression));
    }
#line 2860 "yacc_sql.cpp"
    break;

  case 95: /* expression: expression '~' expression  */
#line 881 "yacc_sql.y"
                              {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2868 "yacc_sql.cpp"
    break;

  case 96: /* expression: expression '-' expression  */
#line 884 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2876 "yacc_sql.cpp"
    break;

  case 97: /* expression: expression '*' expression  */
#line 887 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2884 "yacc_sql.cpp"
    break;

  case 98: /* expression: expression '/' expression  */
#line 890 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2892 "yacc_sql.cpp"
    break;

  case 99: /* expression: LBRACE expression RBRACE  */
#line 893 "yacc_sql.y"
                               {
      (yyval.expression) = (yyvsp[-1].expression);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2901 "yacc_sql.cpp"
    break;

  case 100: /* expression: '-' expression  */
#line 897 "yacc_sql.y"
                                  {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::NEGATIVE, (yyvsp[0].expression), nullptr, sql_string, &(yyloc));
    }
#line 2909 "yacc_sql.cpp"
    break;

  case 101: /* expression: value  */
#line 900 "yacc_sql.y"
            {
      (yyval.expression) = new ValueExpr(*(yyvsp[0].value));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].value);
    }
#line 2919 "yacc_sql.cpp"
    break;

  case 102: /* expression: rel_attr  */
#line 905 "yacc_sql.y"
               {
      (yyval.expression) = new FieldExpr(*(yyvsp[0].rel_attr));
      // $$->set_name(token_name(sql_string, &@$));
      delete (yyvsp[0].rel_attr);
    }
#line 2929 "yacc_sql.cpp"
    break;

  case 103: /* expression: LENGTH LBRACE value RBRACE  */
#line 910 "yacc_sql.y"
                                 {
      if (RC::SUCCESS != (yyvsp[-1].value)->apply_length_func()) {
        yyerror(&(yyloc), sql_string, sql_result, scanner, "length function's parameter must be string");
      }
      (yyval.expression) = new ValueExpr(*(yyvsp[-1].value)); delete (yyvsp[-1].value);
    }
#line 2940 "yacc_sql.cpp"
    break;

  case 104: /* expression: LENGTH LBRACE rel_attr RBRACE  */
#line 916 "yacc_sql.y"
                                    {
      let f = new FieldExpr(*(yyvsp[-1].rel_attr));
      (yyval.expression) = f;
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      f->set_func(F_LENGTH);
      delete (yyvsp[-1].rel_attr);
    }
#line 2952 "yacc_sql.cpp"
    break;

  case 105: /* expression: ROUND LBRACE value RBRACE  */
#line 923 "yacc_sql.y"
                                {
      if (RC::SUCCESS != (yyvsp[-1].value)->apply_round_func()) {
          yyerror(&(yyloc), sql_string, sql_result, scanner, "round function's parameter must be float");
      }
      (yyval.expression) = new ValueExpr(*(yyvsp[-1].value)); delete (yyvsp[-1].value);
    }
#line 2963 "yacc_sql.cpp"
    break;

  case 106: /* expression: ROUND LBRACE rel_attr RBRACE  */
#line 929 "yacc_sql.y"
                                   {
      let f = new FieldExpr(*(yyvsp[-1].rel_attr));
      (yyval.expression) = f;
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      f->set_func(F_ROUND);
      delete (yyvsp[-1].rel_attr);
    }
#line 2975 "yacc_sql.cpp"
    break;

  case 107: /* expression: ROUND LBRACE value COMMA value RBRACE  */
#line 936 "yacc_sql.y"
                                            {
      if ((yyvsp[-1].value)->attr_type() != AttrType::INTS) {
        yyerror(&(yyloc), sql_string, sql_result, scanner, "round function's second parameter must be int");
      }
      if (RC::SUCCESS != (yyvsp[-3].value)->apply_round_func((yyvsp[-1].value)->get_int())) {
        yyerror(&(yyloc), sql_string, sql_result, scanner, "round function's first parameter must be float");
      }
      delete (yyvsp[-1].value);
      (yyval.expression) = new ValueExpr(*(yyvsp[-3].value)); delete (yyvsp[-3].value);
    }
#line 2990 "yacc_sql.cpp"
    break;

  case 108: /* expression: ROUND LBRACE rel_attr COMMA value RBRACE  */
#line 946 "yacc_sql.y"
                                               {
      let f = new FieldExpr(*(yyvsp[-3].rel_attr));
      (yyval.expression) = f;
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      f->set_func(F_ROUND);
      if ((yyvsp[-1].value)->attr_type() != AttrType::INTS) {
        yyerror(&(yyloc), sql_string, sql_result, scanner, "round function's second parameter must be int");
      }
      f->decimals = (yyvsp[-1].value)->get_int();
      delete (yyvsp[-1].value);
      delete (yyvsp[-3].rel_attr);
    }
#line 3007 "yacc_sql.cpp"
    break;

  case 109: /* expression: DATE_FORMAT LBRACE value COMMA SSS RBRACE  */
#line 958 "yacc_sql.y"
                                                {
      if ((yyvsp[-3].value)->attr_type() != AttrType::DATES) {
        yyerror(&(yyloc), sql_string, sql_result, scanner, "date_format function's first parameter must be date");
      }
      char *tmp = common::substr((yyvsp[-1].string),1,strlen((yyvsp[-1].string))-2);
      if (RC::SUCCESS != (yyvsp[-3].value)->apply_date_format_func(tmp)) {
        yyerror(&(yyloc), sql_string, sql_result, scanner, "date_format function's second parameter must be string");
      }
      (yyval.expression) = new ValueExpr(*(yyvsp[-3].value)); delete (yyvsp[-3].value);
      free(tmp);
      free((yyvsp[-1].string));
    }
#line 3024 "yacc_sql.cpp"
    break;

  case 110: /* expression: DATE_FORMAT LBRACE rel_attr COMMA SSS RBRACE  */
#line 970 "yacc_sql.y"
                                                   {
      let f = new FieldExpr(*(yyvsp[-3].rel_attr));
      (yyval.expression) = f;
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      f->set_func(F_DATE_FORMAT);

      char *tmp = common::substr((yyvsp[-1].string),1,strlen((yyvsp[-1].string))-2);
      f->date_format = tmp;
      free(tmp);
      free((yyvsp[-1].string));

      delete (yyvsp[-3].rel_attr);
    }
#line 3042 "yacc_sql.cpp"
    break;

  case 111: /* expression: aggr  */
#line 983 "yacc_sql.y"
           {
      (yyval.expression) = new AggregateExpr(*(yyvsp[0].aggregate_node), nullptr);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].aggregate_node);
    }
#line 3052 "yacc_sql.cpp"
    break;

  case 112: /* select_list: %empty  */
#line 998 "yacc_sql.y"
    {
      (yyval.select_list) = nullptr;
    }
#line 3060 "yacc_sql.cpp"
    break;

  case 113: /* select_list: expression select_list  */
#line 1001 "yacc_sql.y"
                             {
      if ((yyvsp[0].select_list) != nullptr) {
        (yyval.select_list) = (yyvsp[0].select_list);
      } else {
        (yyval.select_list) = new ExprList;
      }
      (yyval.select_list)->exprs.emplace_back((yyvsp[-1].expression));
    }
#line 3073 "yacc_sql.cpp"
    break;

  case 114: /* select_list: expression ID select_list  */
#line 1009 "yacc_sql.y"
                                {
        if (auto* t = dynamic_cast<FieldExpr*>((yyvsp[-2].expression))) {
            if (t->node().attribute_name == "*") {
                yyerror(&(yyloc), sql_string, sql_result, scanner, "can not use * AS alias in select list");
            }
        }

      if ((yyvsp[0].select_list) != nullptr) {
        (yyval.select_list) = (yyvsp[0].select_list);
      } else {
        (yyval.select_list) = new ExprList;
      }
      (yyvsp[-2].expression)->set_name((yyvsp[-1].string));
      free((yyvsp[-1].string));
      (yyval.select_list)->exprs.emplace_back((yyvsp[-2].expression));
    }
#line 3094 "yacc_sql.cpp"
    break;

  case 115: /* select_list: expression AS ID select_list  */
#line 1025 "yacc_sql.y"
                                   {
        if (auto* t = dynamic_cast<FieldExpr*>((yyvsp[-3].expression))) {
            if (t->node().attribute_name == "*") {
                yyerror(&(yyloc), sql_string, sql_result, scanner, "can not use * AS alias in select list");
            }
        }
      if ((yyvsp[0].select_list) != nullptr) {
        (yyval.select_list) = (yyvsp[0].select_list);
      } else {
        (yyval.select_list) = new ExprList;
      }
      (yyvsp[-3].expression)->set_name((yyvsp[-1].string));
      free((yyvsp[-1].string));
      (yyval.select_list)->exprs.emplace_back((yyvsp[-3].expression));
    }
#line 3114 "yacc_sql.cpp"
    break;

  case 116: /* select_list: COMMA expression select_list  */
#line 1040 "yacc_sql.y"
                                   {
      if ((yyvsp[0].select_list) != nullptr) {
        (yyval.select_list) = (yyvsp[0].select_list);
      } else {
        (yyval.select_list) = new ExprList;
      }
      (yyval.select_list)->exprs.emplace_back((yyvsp[-1].expression));
    }
#line 3127 "yacc_sql.cpp"
    break;

  case 117: /* select_list: COMMA expression ID select_list  */
#line 1048 "yacc_sql.y"
                                      {
        if (auto* t = dynamic_cast<FieldExpr*>((yyvsp[-2].expression))) {
            if (t->node().attribute_name == "*") {
                yyerror(&(yyloc), sql_string, sql_result, scanner, "can not use * AS alias in select list");
            }
        }
      if ((yyvsp[0].select_list) != nullptr) {
        (yyval.select_list) = (yyvsp[0].select_list);
      } else {
        (yyval.select_list) = new ExprList;
      }
      (yyvsp[-2].expression)->set_name((yyvsp[-1].string));
      free((yyvsp[-1].string));
      (yyval.select_list)->exprs.emplace_back((yyvsp[-2].expression));
    }
#line 3147 "yacc_sql.cpp"
    break;

  case 118: /* select_list: COMMA expression AS ID select_list  */
#line 1063 "yacc_sql.y"
                                         {
        if (auto* t = dynamic_cast<FieldExpr*>((yyvsp[-3].expression))) {
            if (t->node().attribute_name == "*") {
                yyerror(&(yyloc), sql_string, sql_result, scanner, "can not use * AS alias in select list");
            }
        }
      if ((yyvsp[0].select_list) != nullptr) {
        (yyval.select_list) = (yyvsp[0].select_list);
      } else {
        (yyval.select_list) = new ExprList;
      }
      (yyvsp[-3].expression)->set_name((yyvsp[-1].string));
      free((yyvsp[-1].string));
      (yyval.select_list)->exprs.emplace_back((yyvsp[-3].expression));
    }
#line 3167 "yacc_sql.cpp"
    break;

  case 119: /* rel_attr: '*'  */
#line 1081 "yacc_sql.y"
        {
      (yyval.rel_attr) = make_single_field("*");
    }
#line 3175 "yacc_sql.cpp"
    break;

  case 120: /* rel_attr: ID  */
#line 1084 "yacc_sql.y"
         {
      (yyval.rel_attr) = make_single_field((yyvsp[0].string));
      free((yyvsp[0].string));
    }
#line 3184 "yacc_sql.cpp"
    break;

  case 121: /* rel_attr: ID DOT ID  */
#line 1088 "yacc_sql.y"
                {
      (yyval.rel_attr) = make_single_table_field((yyvsp[-2].string), (yyvsp[0].string));
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 3194 "yacc_sql.cpp"
    break;

  case 122: /* rel_attr: ID DOT '*'  */
#line 1093 "yacc_sql.y"
                 {
      (yyval.rel_attr) = make_single_table_field((yyvsp[-2].string), "*");
      free((yyvsp[-2].string));
    }
#line 3203 "yacc_sql.cpp"
    break;

  case 123: /* aggr: aggr_func LBRACE rel_attr RBRACE  */
#line 1100 "yacc_sql.y"
                                     {
        if (get_display_name(*(yyvsp[-1].rel_attr)) == "*" && (yyvsp[-3].aggregate_func) == AggregateFunc::Count) {
            (yyval.aggregate_node) = make_aggr(AggregateFunc::CountStar);
        } else {
            (yyval.aggregate_node) = make_aggr((yyvsp[-3].aggregate_func));
            (yyval.aggregate_node)->attr = *(yyvsp[-1].rel_attr);
        }
        delete (yyvsp[-1].rel_attr);
    }
#line 3217 "yacc_sql.cpp"
    break;

  case 124: /* aggr_func: AVG  */
#line 1112 "yacc_sql.y"
        { (yyval.aggregate_func) = AggregateFunc::Avg; }
#line 3223 "yacc_sql.cpp"
    break;

  case 125: /* aggr_func: SUM  */
#line 1113 "yacc_sql.y"
          { (yyval.aggregate_func) = AggregateFunc::Sum; }
#line 3229 "yacc_sql.cpp"
    break;

  case 126: /* aggr_func: COUNT  */
#line 1114 "yacc_sql.y"
            { (yyval.aggregate_func) = AggregateFunc::Count; }
#line 3235 "yacc_sql.cpp"
    break;

  case 127: /* aggr_func: MAX  */
#line 1115 "yacc_sql.y"
          { (yyval.aggregate_func) = AggregateFunc::Max; }
#line 3241 "yacc_sql.cpp"
    break;

  case 128: /* aggr_func: MIN  */
#line 1116 "yacc_sql.y"
          { (yyval.aggregate_func) = AggregateFunc::Min; }
#line 3247 "yacc_sql.cpp"
    break;

  case 129: /* rel_list: %empty  */
#line 1121 "yacc_sql.y"
    {
      (yyval.relation_list) = nullptr;
    }
#line 3255 "yacc_sql.cpp"
    break;

  case 130: /* rel_list: COMMA table_name rel_list  */
#line 1124 "yacc_sql.y"
                                {
      if ((yyvsp[0].relation_list) != nullptr) {
        (yyval.relation_list) = (yyvsp[0].relation_list);
      } else {
        (yyval.relation_list) = new std::vector<NameWithAlias>;
      }

      (yyval.relation_list)->push_back(std::move(*(yyvsp[-1].name_with_alias)));
      delete (yyvsp[-1].name_with_alias);
    }
#line 3270 "yacc_sql.cpp"
    break;

  case 131: /* inner_join_list: %empty  */
#line 1137 "yacc_sql.y"
    {
      (yyval.join_list) = nullptr;
    }
#line 3278 "yacc_sql.cpp"
    break;

  case 132: /* inner_join_list: INNER JOIN table_name ON condition_tree inner_join_list  */
#line 1140 "yacc_sql.y"
                                                              {
      if ((yyvsp[0].join_list) != nullptr) {
        (yyval.join_list) = (yyvsp[0].join_list);
      } else {
        (yyval.join_list) = new JoinList;
      }
      (yyval.join_list)->conditions.push_back((yyvsp[-1].condition_tree));
      (yyval.join_list)->relations.push_back(std::move(*(yyvsp[-3].name_with_alias)));
      delete (yyvsp[-3].name_with_alias);
    }
#line 3293 "yacc_sql.cpp"
    break;

  case 133: /* update_list: %empty  */
#line 1152 "yacc_sql.y"
    {
    (yyval.update_list) = nullptr;
    }
#line 3301 "yacc_sql.cpp"
    break;

  case 134: /* update_list: COMMA ID EQ expression update_list  */
#line 1155 "yacc_sql.y"
                                         {
      if ((yyvsp[0].update_list) != nullptr) {
        (yyval.update_list) = (yyvsp[0].update_list);
      } else {
        (yyval.update_list) = new std::unordered_map<std::string, std::unique_ptr<Expression>>;

      }
      (yyval.update_list)->insert(std::make_pair((yyvsp[-3].string), std::unique_ptr<Expression>((yyvsp[-1].expression))));
      free((yyvsp[-3].string));
    }
#line 3316 "yacc_sql.cpp"
    break;

  case 135: /* where: %empty  */
#line 1168 "yacc_sql.y"
    {
      (yyval.condition_tree) = nullptr;
    }
#line 3324 "yacc_sql.cpp"
    break;

  case 136: /* where: WHERE condition_tree  */
#line 1171 "yacc_sql.y"
                           {
      (yyval.condition_tree) = (yyvsp[0].condition_tree);  
    }
#line 3332 "yacc_sql.cpp"
    break;

  case 137: /* having: %empty  */
#line 1177 "yacc_sql.y"
    {
      (yyval.condition_tree) = nullptr;
    }
#line 3340 "yacc_sql.cpp"
    break;

  case 138: /* having: HAVING condition_tree  */
#line 1180 "yacc_sql.y"
                            {
      (yyval.condition_tree) = (yyvsp[0].condition_tree);
    }
#line 3348 "yacc_sql.cpp"
    break;

  case 139: /* group_by: %empty  */
#line 1186 "yacc_sql.y"
    {
      (yyval.group_by) = nullptr;
    }
#line 3356 "yacc_sql.cpp"
    break;

  case 140: /* group_by: GROUP BY expression_list  */
#line 1189 "yacc_sql.y"
                               {
      (yyval.group_by) = new GroupBy;
      if ((yyvsp[0].expression_list) != nullptr) {
          for (auto e : *(yyvsp[0].expression_list)) {
              (yyval.group_by)->exprs.emplace_back(e);
          }
          delete (yyvsp[0].expression_list);
      }
    }
#line 3370 "yacc_sql.cpp"
    break;

  case 141: /* condition_tree: %empty  */
#line 1201 "yacc_sql.y"
    {
      (yyval.condition_tree) = nullptr;
    }
#line 3378 "yacc_sql.cpp"
    break;

  case 142: /* condition_tree: LBRACE condition_tree RBRACE  */
#line 1204 "yacc_sql.y"
                                   {
      (yyval.condition_tree) = (yyvsp[-1].condition_tree);
    }
#line 3386 "yacc_sql.cpp"
    break;

  case 143: /* condition_tree: condition  */
#line 1207 "yacc_sql.y"
                {
      (yyval.condition_tree) = new ConditionTree;
      (yyval.condition_tree)->node.reset((yyvsp[0].condition));
    }
#line 3395 "yacc_sql.cpp"
    break;

  case 144: /* condition_tree: condition_tree AND condition_tree  */
#line 1211 "yacc_sql.y"
                                        {
      (yyval.condition_tree) = new ConditionTree;
      (yyval.condition_tree)->op = ConditionTree::AND_OP;
      (yyval.condition_tree)->left.reset((yyvsp[-2].condition_tree));
      (yyval.condition_tree)->right.reset((yyvsp[0].condition_tree));
    }
#line 3406 "yacc_sql.cpp"
    break;

  case 145: /* condition_tree: condition_tree OR condition_tree  */
#line 1217 "yacc_sql.y"
                                       {
      (yyval.condition_tree) = new ConditionTree;
      (yyval.condition_tree)->op = ConditionTree::OR_OP;
      (yyval.condition_tree)->left.reset((yyvsp[-2].condition_tree));
      (yyval.condition_tree)->right.reset((yyvsp[0].condition_tree));
    }
#line 3417 "yacc_sql.cpp"
    break;

  case 146: /* condition: expression comp_op expression  */
#line 1225 "yacc_sql.y"
                                  {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left = std::unique_ptr<Expression>((yyvsp[-2].expression));
        (yyval.condition)->right = std::unique_ptr<Expression>((yyvsp[0].expression));
        (yyval.condition)->comp = (yyvsp[-1].comp);
    }
#line 3428 "yacc_sql.cpp"
    break;

  case 147: /* condition: EXISTS LBRACE select_stmt RBRACE  */
#line 1231 "yacc_sql.y"
                                       {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left.reset(new SqlExpr((yyvsp[-1].sql_node)));
        (yyval.condition)->comp = EXISTS_OP;
    }
#line 3438 "yacc_sql.cpp"
    break;

  case 148: /* condition: NOT EXISTS LBRACE select_stmt RBRACE  */
#line 1236 "yacc_sql.y"
                                           {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left.reset(new SqlExpr((yyvsp[-1].sql_node)));
        (yyval.condition)->comp = NOT_EXISTS_OP;
    }
#line 3448 "yacc_sql.cpp"
    break;

  case 149: /* condition: expression IN LBRACE expression_list RBRACE  */
#line 1241 "yacc_sql.y"
                                                  {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left = std::unique_ptr<Expression>((yyvsp[-4].expression));
        (yyval.condition)->right = std::make_unique<ExpressionsExpr>(std::move(*(yyvsp[-1].expression_list)));
        delete (yyvsp[-1].expression_list);
        (yyval.condition)->comp = IN_OP;
    }
#line 3460 "yacc_sql.cpp"
    break;

  case 150: /* condition: expression NOT IN LBRACE expression_list RBRACE  */
#line 1248 "yacc_sql.y"
                                                      {
        (yyval.condition) = new ConditionSqlNode;
        (yyval.condition)->left = std::unique_ptr<Expression>((yyvsp[-5].expression));
        (yyval.condition)->right = std::make_unique<ExpressionsExpr>(std::move(*(yyvsp[-1].expression_list)));
        delete (yyvsp[-1].expression_list);
        (yyval.condition)->comp = NOT_IN_OP;
    }
#line 3472 "yacc_sql.cpp"
    break;

  case 151: /* comp_op: EQ  */
#line 1258 "yacc_sql.y"
         { (yyval.comp) = EQUAL_TO; }
#line 3478 "yacc_sql.cpp"
    break;

  case 152: /* comp_op: LT  */
#line 1259 "yacc_sql.y"
         { (yyval.comp) = LESS_THAN; }
#line 3484 "yacc_sql.cpp"
    break;

  case 153: /* comp_op: GT  */
#line 1260 "yacc_sql.y"
         { (yyval.comp) = GREAT_THAN; }
#line 3490 "yacc_sql.cpp"
    break;

  case 154: /* comp_op: LE  */
#line 1261 "yacc_sql.y"
         { (yyval.comp) = LESS_EQUAL; }
#line 3496 "yacc_sql.cpp"
    break;

  case 155: /* comp_op: GE  */
#line 1262 "yacc_sql.y"
         { (yyval.comp) = GREAT_EQUAL; }
#line 3502 "yacc_sql.cpp"
    break;

  case 156: /* comp_op: NE  */
#line 1263 "yacc_sql.y"
         { (yyval.comp) = NOT_EQUAL; }
#line 3508 "yacc_sql.cpp"
    break;

  case 157: /* comp_op: IS  */
#line 1264 "yacc_sql.y"
         { (yyval.comp) = IS_OP;}
#line 3514 "yacc_sql.cpp"
    break;

  case 158: /* comp_op: IS NOT  */
#line 1265 "yacc_sql.y"
            { (yyval.comp) = IS_NOT_OP;}
#line 3520 "yacc_sql.cpp"
    break;

  case 159: /* comp_op: LIKE  */
#line 1266 "yacc_sql.y"
           { (yyval.comp) = LIKE_OP; }
#line 3526 "yacc_sql.cpp"
    break;

  case 160: /* comp_op: NOT LIKE  */
#line 1267 "yacc_sql.y"
               { (yyval.comp) = NOT_LIKE_OP; }
#line 3532 "yacc_sql.cpp"
    break;

  case 161: /* load_data_stmt: LOAD DATA INFILE SSS INTO TABLE ID  */
#line 1272 "yacc_sql.y"
    {
      char *tmp_file_name = common::substr((yyvsp[-3].string), 1, strlen((yyvsp[-3].string)) - 2);
      
      (yyval.sql_node) = new ParsedSqlNode(SCF_LOAD_DATA);
      (yyval.sql_node)->load_data.relation_name = (yyvsp[0].string);
      (yyval.sql_node)->load_data.file_name = tmp_file_name;
      free((yyvsp[0].string));
      free(tmp_file_name);
    }
#line 3546 "yacc_sql.cpp"
    break;

  case 162: /* explain_stmt: EXPLAIN command_wrapper  */
#line 1285 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXPLAIN);
      (yyval.sql_node)->explain.sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[0].sql_node));
    }
#line 3555 "yacc_sql.cpp"
    break;

  case 163: /* set_variable_stmt: SET ID EQ value  */
#line 1293 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SET_VARIABLE);
      (yyval.sql_node)->set_variable.name  = (yyvsp[-2].string);
      (yyval.sql_node)->set_variable.value = *(yyvsp[0].value);
      free((yyvsp[-2].string));
      delete (yyvsp[0].value);
    }
#line 3567 "yacc_sql.cpp"
    break;


#line 3571 "yacc_sql.cpp"

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
  *++yylsp = yyloc;

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
          = {yyssp, yytoken, &yylloc};
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
        yyerror (&yylloc, sql_string, sql_result, scanner, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc, sql_string, sql_result, scanner);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, sql_string, sql_result, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

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
  yyerror (&yylloc, sql_string, sql_result, scanner, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc, sql_string, sql_result, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, sql_string, sql_result, scanner);
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

#line 1305 "yacc_sql.y"

//_____________________________________________________________________
extern void scan_string(const char *str, yyscan_t scanner);

int sql_parse(const char *s, ParsedSqlResult *sql_result) {
  yyscan_t scanner;
  yylex_init(&scanner);
  scan_string(s, scanner);
  int result = yyparse(s, sql_result, scanner);
  yylex_destroy(scanner);
  return result;
}
