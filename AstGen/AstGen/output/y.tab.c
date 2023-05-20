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
#line 2 "example.y"

#include <stdio.h>
#include <string.h>

#define YYSTYPE int
extern YYSTYPE yylval;
int yydebu = 1; // debug
int nid = 0;

extern int yylex(void);
extern int yyparse(void);

int yywrap() {
	return 1;
}

// defined in "y.tab.c"
void yyerror(const char* s) {
	printf("[error] %s\n", s);
}

int main() {
	yyparse();
	return 0;
}

#line 98 "y.tab.c"

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
    SEMICOLON = 258,               /* SEMICOLON  */
    COMMA = 259,                   /* COMMA  */
    EQUAL = 260,                   /* EQUAL  */
    LBRACKET = 261,                /* LBRACKET  */
    RBRACKET = 262,                /* RBRACKET  */
    LBRACE = 263,                  /* LBRACE  */
    RBRACE = 264,                  /* RBRACE  */
    LPARE = 265,                   /* LPARE  */
    RPARE = 266,                   /* RPARE  */
    OPE_NOT = 267,                 /* OPE_NOT  */
    OPE_ADD = 268,                 /* OPE_ADD  */
    OPE_SUB = 269,                 /* OPE_SUB  */
    OPE_MUL = 270,                 /* OPE_MUL  */
    OPE_DIV = 271,                 /* OPE_DIV  */
    OPE_MOD = 272,                 /* OPE_MOD  */
    OPE_AND = 273,                 /* OPE_AND  */
    OPE_OR = 274,                  /* OPE_OR  */
    OPE_EQU = 275,                 /* OPE_EQU  */
    OPE_NEQ = 276,                 /* OPE_NEQ  */
    OPE_LEQ = 277,                 /* OPE_LEQ  */
    OPE_GEQ = 278,                 /* OPE_GEQ  */
    OPE_LSS = 279,                 /* OPE_LSS  */
    OPE_GTR = 280,                 /* OPE_GTR  */
    INT_CONST = 281,               /* INT_CONST  */
    FLOAT_CONST = 282,             /* FLOAT_CONST  */
    IDENTIFIER = 283,              /* IDENTIFIER  */
    KEYWORD_CONST = 284,           /* KEYWORD_CONST  */
    KEYWORD_INT = 285,             /* KEYWORD_INT  */
    KEYWORD_FLOAT = 286,           /* KEYWORD_FLOAT  */
    KEYWORD_VOID = 287,            /* KEYWORD_VOID  */
    KEYWORD_IF = 288,              /* KEYWORD_IF  */
    KEYWORD_ELSE = 289,            /* KEYWORD_ELSE  */
    KEYWORD_WHILE = 290,           /* KEYWORD_WHILE  */
    KEYWORD_CONTINUE = 291,        /* KEYWORD_CONTINUE  */
    KEYWORD_BREAK = 292,           /* KEYWORD_BREAK  */
    KEYWORD_RETURN = 293           /* KEYWORD_RETURN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define SEMICOLON 258
#define COMMA 259
#define EQUAL 260
#define LBRACKET 261
#define RBRACKET 262
#define LBRACE 263
#define RBRACE 264
#define LPARE 265
#define RPARE 266
#define OPE_NOT 267
#define OPE_ADD 268
#define OPE_SUB 269
#define OPE_MUL 270
#define OPE_DIV 271
#define OPE_MOD 272
#define OPE_AND 273
#define OPE_OR 274
#define OPE_EQU 275
#define OPE_NEQ 276
#define OPE_LEQ 277
#define OPE_GEQ 278
#define OPE_LSS 279
#define OPE_GTR 280
#define INT_CONST 281
#define FLOAT_CONST 282
#define IDENTIFIER 283
#define KEYWORD_CONST 284
#define KEYWORD_INT 285
#define KEYWORD_FLOAT 286
#define KEYWORD_VOID 287
#define KEYWORD_IF 288
#define KEYWORD_ELSE 289
#define KEYWORD_WHILE 290
#define KEYWORD_CONTINUE 291
#define KEYWORD_BREAK 292
#define KEYWORD_RETURN 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
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
  YYSYMBOL_SEMICOLON = 3,                  /* SEMICOLON  */
  YYSYMBOL_COMMA = 4,                      /* COMMA  */
  YYSYMBOL_EQUAL = 5,                      /* EQUAL  */
  YYSYMBOL_LBRACKET = 6,                   /* LBRACKET  */
  YYSYMBOL_RBRACKET = 7,                   /* RBRACKET  */
  YYSYMBOL_LBRACE = 8,                     /* LBRACE  */
  YYSYMBOL_RBRACE = 9,                     /* RBRACE  */
  YYSYMBOL_LPARE = 10,                     /* LPARE  */
  YYSYMBOL_RPARE = 11,                     /* RPARE  */
  YYSYMBOL_OPE_NOT = 12,                   /* OPE_NOT  */
  YYSYMBOL_OPE_ADD = 13,                   /* OPE_ADD  */
  YYSYMBOL_OPE_SUB = 14,                   /* OPE_SUB  */
  YYSYMBOL_OPE_MUL = 15,                   /* OPE_MUL  */
  YYSYMBOL_OPE_DIV = 16,                   /* OPE_DIV  */
  YYSYMBOL_OPE_MOD = 17,                   /* OPE_MOD  */
  YYSYMBOL_OPE_AND = 18,                   /* OPE_AND  */
  YYSYMBOL_OPE_OR = 19,                    /* OPE_OR  */
  YYSYMBOL_OPE_EQU = 20,                   /* OPE_EQU  */
  YYSYMBOL_OPE_NEQ = 21,                   /* OPE_NEQ  */
  YYSYMBOL_OPE_LEQ = 22,                   /* OPE_LEQ  */
  YYSYMBOL_OPE_GEQ = 23,                   /* OPE_GEQ  */
  YYSYMBOL_OPE_LSS = 24,                   /* OPE_LSS  */
  YYSYMBOL_OPE_GTR = 25,                   /* OPE_GTR  */
  YYSYMBOL_INT_CONST = 26,                 /* INT_CONST  */
  YYSYMBOL_FLOAT_CONST = 27,               /* FLOAT_CONST  */
  YYSYMBOL_IDENTIFIER = 28,                /* IDENTIFIER  */
  YYSYMBOL_KEYWORD_CONST = 29,             /* KEYWORD_CONST  */
  YYSYMBOL_KEYWORD_INT = 30,               /* KEYWORD_INT  */
  YYSYMBOL_KEYWORD_FLOAT = 31,             /* KEYWORD_FLOAT  */
  YYSYMBOL_KEYWORD_VOID = 32,              /* KEYWORD_VOID  */
  YYSYMBOL_KEYWORD_IF = 33,                /* KEYWORD_IF  */
  YYSYMBOL_KEYWORD_ELSE = 34,              /* KEYWORD_ELSE  */
  YYSYMBOL_KEYWORD_WHILE = 35,             /* KEYWORD_WHILE  */
  YYSYMBOL_KEYWORD_CONTINUE = 36,          /* KEYWORD_CONTINUE  */
  YYSYMBOL_KEYWORD_BREAK = 37,             /* KEYWORD_BREAK  */
  YYSYMBOL_KEYWORD_RETURN = 38,            /* KEYWORD_RETURN  */
  YYSYMBOL_YYACCEPT = 39,                  /* $accept  */
  YYSYMBOL_CompUnit = 40,                  /* CompUnit  */
  YYSYMBOL_CompUnitDef = 41,               /* CompUnitDef  */
  YYSYMBOL_Decl = 42,                      /* Decl  */
  YYSYMBOL_ConstDecl = 43,                 /* ConstDecl  */
  YYSYMBOL_BType = 44,                     /* BType  */
  YYSYMBOL_ConstDefList = 45,              /* ConstDefList  */
  YYSYMBOL_ConstDef = 46,                  /* ConstDef  */
  YYSYMBOL_ArrayIndexList = 47,            /* ArrayIndexList  */
  YYSYMBOL_InitVal = 48,                   /* InitVal  */
  YYSYMBOL_InitValList = 49,               /* InitValList  */
  YYSYMBOL_VarDecl = 50,                   /* VarDecl  */
  YYSYMBOL_VarDefList = 51,                /* VarDefList  */
  YYSYMBOL_VarDef = 52,                    /* VarDef  */
  YYSYMBOL_FuncDef = 53,                   /* FuncDef  */
  YYSYMBOL_FuncType = 54,                  /* FuncType  */
  YYSYMBOL_FuncFParams = 55,               /* FuncFParams  */
  YYSYMBOL_FuncFParam = 56,                /* FuncFParam  */
  YYSYMBOL_FuncFParamArrayIndexList = 57,  /* FuncFParamArrayIndexList  */
  YYSYMBOL_Block = 58,                     /* Block  */
  YYSYMBOL_BlockItemList = 59,             /* BlockItemList  */
  YYSYMBOL_BlockItem = 60,                 /* BlockItem  */
  YYSYMBOL_Stmt = 61,                      /* Stmt  */
  YYSYMBOL_Exp = 62,                       /* Exp  */
  YYSYMBOL_Cond = 63,                      /* Cond  */
  YYSYMBOL_LVal = 64,                      /* LVal  */
  YYSYMBOL_PrimaryExp = 65,                /* PrimaryExp  */
  YYSYMBOL_Number = 66,                    /* Number  */
  YYSYMBOL_UnaryExp = 67,                  /* UnaryExp  */
  YYSYMBOL_UnaryOp = 68,                   /* UnaryOp  */
  YYSYMBOL_FuncRPAREms = 69,               /* FuncRPAREms  */
  YYSYMBOL_MulExp = 70,                    /* MulExp  */
  YYSYMBOL_MulOp = 71,                     /* MulOp  */
  YYSYMBOL_AddExp = 72,                    /* AddExp  */
  YYSYMBOL_AddOp = 73,                     /* AddOp  */
  YYSYMBOL_RelExp = 74,                    /* RelExp  */
  YYSYMBOL_RelOp = 75,                     /* RelOp  */
  YYSYMBOL_EqExp = 76,                     /* EqExp  */
  YYSYMBOL_EqOp = 77,                      /* EqOp  */
  YYSYMBOL_LAndExp = 78,                   /* LAndExp  */
  YYSYMBOL_LOrExp = 79                     /* LOrExp  */
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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   156

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  148

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


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
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    36,    36,    38,    43,    45,    50,    52,    57,    62,
      64,    69,    71,    76,    82,    83,    88,    90,    95,    97,
     102,   107,   109,   114,   116,   121,   123,   128,   130,   135,
     137,   142,   147,   149,   154,   160,   161,   166,   168,   173,
     175,   177,   179,   181,   183,   185,   187,   189,   194,   199,
     204,   209,   211,   213,   218,   220,   225,   227,   229,   231,
     236,   238,   240,   245,   247,   252,   254,   259,   261,   263,
     268,   270,   275,   277,   282,   284,   289,   291,   293,   295,
     300,   302,   307,   309,   314,   316,   321,   323
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
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "COMMA",
  "EQUAL", "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", "LPARE", "RPARE",
  "OPE_NOT", "OPE_ADD", "OPE_SUB", "OPE_MUL", "OPE_DIV", "OPE_MOD",
  "OPE_AND", "OPE_OR", "OPE_EQU", "OPE_NEQ", "OPE_LEQ", "OPE_GEQ",
  "OPE_LSS", "OPE_GTR", "INT_CONST", "FLOAT_CONST", "IDENTIFIER",
  "KEYWORD_CONST", "KEYWORD_INT", "KEYWORD_FLOAT", "KEYWORD_VOID",
  "KEYWORD_IF", "KEYWORD_ELSE", "KEYWORD_WHILE", "KEYWORD_CONTINUE",
  "KEYWORD_BREAK", "KEYWORD_RETURN", "$accept", "CompUnit", "CompUnitDef",
  "Decl", "ConstDecl", "BType", "ConstDefList", "ConstDef",
  "ArrayIndexList", "InitVal", "InitValList", "VarDecl", "VarDefList",
  "VarDef", "FuncDef", "FuncType", "FuncFParams", "FuncFParam",
  "FuncFParamArrayIndexList", "Block", "BlockItemList", "BlockItem",
  "Stmt", "Exp", "Cond", "LVal", "PrimaryExp", "Number", "UnaryExp",
  "UnaryOp", "FuncRPAREms", "MulExp", "MulOp", "AddExp", "AddOp", "RelExp",
  "RelOp", "EqExp", "EqOp", "LAndExp", "LOrExp", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
#endif

#define YYPACT_NINF (-117)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      24,    27,  -117,  -117,  -117,     7,  -117,  -117,  -117,   -10,
    -117,  -117,    -8,    -5,  -117,  -117,  -117,    65,  -117,    37,
    -117,    81,  -117,   104,  -117,   -10,    -3,   106,  -117,    -5,
      94,   118,  -117,    51,    36,     8,  -117,    94,  -117,    94,
     118,  -117,  -117,  -117,  -117,  -117,    60,  -117,  -117,  -117,
    -117,  -117,  -117,   118,    34,    48,    67,  -117,  -117,    66,
      27,    51,  -117,  -117,     6,    71,   113,    70,  -117,  -117,
    -117,  -117,   118,  -117,  -117,   118,  -117,    58,    85,    92,
    -117,  -117,    94,  -117,  -117,  -117,  -117,    10,  -117,    34,
    -117,  -117,    93,    95,   115,   116,    87,  -117,   -10,  -117,
    -117,  -117,   124,  -117,   118,  -117,   118,  -117,   118,   118,
    -117,  -117,  -117,   130,   118,   127,  -117,   125,    48,    56,
      96,   117,   119,   126,  -117,   139,  -117,    -4,  -117,  -117,
    -117,  -117,   118,  -117,  -117,   118,   118,   118,    -4,  -117,
     109,    48,    56,    96,   117,  -117,    -4,  -117
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     9,    10,    27,     0,     2,     4,     6,     0,
       7,     5,     0,     0,     1,     3,    14,     0,    21,     0,
      14,     0,    11,    23,    20,     0,     0,     0,     8,     0,
       0,     0,    22,     0,     0,     0,    29,     0,    12,     0,
       0,    62,    60,    61,    54,    55,    14,    24,    16,    52,
      56,    53,    65,     0,    70,    48,     0,    35,    25,     0,
       0,     0,    13,    18,     0,     0,     0,    50,    59,    67,
      68,    69,     0,    72,    73,     0,    15,     0,     0,    31,
      30,    26,     0,    17,    51,    57,    63,     0,    66,    71,
      34,    14,     0,     0,     0,     0,     0,    37,     0,    40,
      36,    38,     0,    32,     0,    19,     0,    58,     0,     0,
      45,    44,    46,     0,     0,     0,    64,     0,    74,    80,
      84,    86,    49,     0,    47,     0,    33,     0,    77,    79,
      76,    78,     0,    82,    83,     0,     0,     0,     0,    39,
      41,    75,    81,    85,    87,    43,     0,    42
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -117,  -117,   142,    72,  -117,     0,  -117,   121,    26,   -34,
    -117,  -117,  -117,   123,  -117,  -117,  -117,    91,  -117,   -20,
    -117,  -117,  -116,   -31,    43,   -75,  -117,  -117,   -47,  -117,
    -117,    78,  -117,   -92,  -117,    19,  -117,    20,  -117,    18,
    -117
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,     8,     9,    21,    22,    67,    47,
      64,    10,    17,    18,    11,    12,    35,    36,    79,    99,
      77,   100,   101,    48,   117,    49,    50,    51,    52,    53,
      87,    54,    72,    55,    75,   119,   132,   120,   135,   121,
     122
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      56,    13,   102,    62,    57,    63,    68,    14,    33,    65,
      82,   140,    60,    58,   106,    83,   118,   118,    16,    61,
      19,   107,   145,    20,    91,    88,    34,     2,     3,    92,
     147,    93,    94,    95,    96,    86,     1,     2,     3,     4,
     141,    81,    23,   118,   118,   118,    27,    26,   105,    69,
      70,    71,   102,     1,     2,     3,     4,     2,     3,    57,
      34,    73,    74,   102,    59,   113,    57,    90,    24,    25,
      66,   102,    78,   115,    76,   116,    31,    98,   128,   129,
     130,   131,    84,   125,    28,    29,    91,     1,     2,     3,
     112,    92,   103,    93,    94,    95,    96,    40,   104,    41,
      42,    43,    39,   108,    40,   109,    41,    42,    43,    30,
      31,    37,    31,    44,    45,    46,   133,   134,   110,   111,
      44,    45,    46,    40,    85,    41,    42,    43,    40,   114,
      41,    42,    43,   124,   126,   136,   127,   138,   137,    44,
      45,    46,   139,   146,    44,    45,    46,    15,    32,    97,
      38,    80,   123,    89,   142,   144,   143
};

static const yytype_uint8 yycheck[] =
{
      31,     1,    77,    37,     8,    39,    53,     0,    11,    40,
       4,   127,     4,    33,     4,     9,   108,   109,    28,    11,
      28,    11,   138,    28,    28,    72,    26,    30,    31,    33,
     146,    35,    36,    37,    38,    66,    29,    30,    31,    32,
     132,    61,    16,   135,   136,   137,    20,    10,    82,    15,
      16,    17,   127,    29,    30,    31,    32,    30,    31,     8,
      60,    13,    14,   138,    28,    96,     8,     9,     3,     4,
      10,   146,     6,   104,     7,   106,     6,    77,    22,    23,
      24,    25,    11,   114,     3,     4,    28,    29,    30,    31,
       3,    33,     7,    35,    36,    37,    38,    10,     6,    12,
      13,    14,     8,    10,    10,    10,    12,    13,    14,     5,
       6,     5,     6,    26,    27,    28,    20,    21,     3,     3,
      26,    27,    28,    10,    11,    12,    13,    14,    10,     5,
      12,    13,    14,     3,     7,    18,    11,    11,    19,    26,
      27,    28,     3,    34,    26,    27,    28,     5,    25,    77,
      29,    60,   109,    75,   135,   137,   136
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    29,    30,    31,    32,    40,    41,    42,    43,    44,
      50,    53,    54,    44,     0,    41,    28,    51,    52,    28,
      28,    45,    46,    47,     3,     4,    10,    47,     3,     4,
       5,     6,    52,    11,    44,    55,    56,     5,    46,     8,
      10,    12,    13,    14,    26,    27,    28,    48,    62,    64,
      65,    66,    67,    68,    70,    72,    62,     8,    58,    28,
       4,    11,    48,    48,    49,    62,    10,    47,    67,    15,
      16,    17,    71,    13,    14,    73,     7,    59,     6,    57,
      56,    58,     4,     9,    11,    11,    62,    69,    67,    70,
       9,    28,    33,    35,    36,    37,    38,    42,    44,    58,
      60,    61,    64,     7,     6,    48,     4,    11,    10,    10,
       3,     3,     3,    62,     5,    62,    62,    63,    72,    74,
      76,    78,    79,    63,     3,    62,     7,    11,    22,    23,
      24,    25,    75,    20,    21,    77,    18,    19,    11,     3,
      61,    72,    74,    76,    78,    61,    34,    61
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    40,    41,    41,    42,    42,    43,    44,
      44,    45,    45,    46,    47,    47,    48,    48,    49,    49,
      50,    51,    51,    52,    52,    53,    53,    54,    54,    55,
      55,    56,    57,    57,    58,    59,    59,    60,    60,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    62,    63,
      64,    65,    65,    65,    66,    66,    67,    67,    67,    67,
      68,    68,    68,    69,    69,    70,    70,    71,    71,    71,
      72,    72,    73,    73,    74,    74,    75,    75,    75,    75,
      76,    76,    77,    77,    78,    78,    79,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     4,     1,
       1,     1,     3,     4,     0,     4,     1,     3,     1,     3,
       3,     1,     3,     2,     4,     5,     6,     1,     1,     1,
       3,     3,     2,     4,     3,     0,     2,     1,     1,     4,
       1,     5,     7,     5,     2,     2,     2,     3,     1,     1,
       2,     3,     1,     1,     1,     1,     1,     3,     4,     2,
       1,     1,     1,     1,     3,     1,     3,     1,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     3
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
  case 2: /* CompUnit: CompUnitDef  */
#line 37 "example.y"
        { yyval = ++ nid; printf("%10d CompUnit @format CompUnitDef  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1395 "y.tab.c"
    break;

  case 3: /* CompUnit: CompUnit CompUnitDef  */
#line 39 "example.y"
        { yyval = ++ nid; printf("%10d CompUnit @format CompUnit CompUnitDef  :  %d  %d  ; \n", nid, yyvsp[-1], yyvsp[0] ); }
#line 1401 "y.tab.c"
    break;

  case 4: /* CompUnitDef: Decl  */
#line 44 "example.y"
        { yyval = ++ nid; printf("%10d CompUnitDef @format Decl  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1407 "y.tab.c"
    break;

  case 5: /* CompUnitDef: FuncDef  */
#line 46 "example.y"
        { yyval = ++ nid; printf("%10d CompUnitDef @format FuncDef  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1413 "y.tab.c"
    break;

  case 6: /* Decl: ConstDecl  */
#line 51 "example.y"
        { yyval = ++ nid; printf("%10d Decl @format ConstDecl  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1419 "y.tab.c"
    break;

  case 7: /* Decl: VarDecl  */
#line 53 "example.y"
        { yyval = ++ nid; printf("%10d Decl @format VarDecl  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1425 "y.tab.c"
    break;

  case 8: /* ConstDecl: KEYWORD_CONST BType ConstDefList SEMICOLON  */
#line 58 "example.y"
        { yyval = ++ nid; printf("%10d ConstDecl @format KEYWORD_CONST BType ConstDefList SEMICOLON  :  %d  %d  %d  %d  ; \n", nid, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0] ); }
#line 1431 "y.tab.c"
    break;

  case 9: /* BType: KEYWORD_INT  */
#line 63 "example.y"
        { yyval = ++ nid; printf("%10d BType @format KEYWORD_INT  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1437 "y.tab.c"
    break;

  case 10: /* BType: KEYWORD_FLOAT  */
#line 65 "example.y"
        { yyval = ++ nid; printf("%10d BType @format KEYWORD_FLOAT  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1443 "y.tab.c"
    break;

  case 11: /* ConstDefList: ConstDef  */
#line 70 "example.y"
        { yyval = ++ nid; printf("%10d ConstDefList @format ConstDef  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1449 "y.tab.c"
    break;

  case 12: /* ConstDefList: ConstDefList COMMA ConstDef  */
#line 72 "example.y"
        { yyval = ++ nid; printf("%10d ConstDefList @format ConstDefList COMMA ConstDef  :  %d  %d  %d  ; \n", nid, yyvsp[-2], yyvsp[-1], yyvsp[0] ); }
#line 1455 "y.tab.c"
    break;

  case 13: /* ConstDef: IDENTIFIER ArrayIndexList EQUAL InitVal  */
#line 77 "example.y"
        { yyval = ++ nid; printf("%10d ConstDef @format IDENTIFIER ArrayIndexList EQUAL InitVal  :  %d  %d  %d  %d  ; \n", nid, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0] ); }
#line 1461 "y.tab.c"
    break;

  case 14: /* ArrayIndexList: %empty  */
#line 82 "example.y"
        { yyval = ++ nid; printf("%10d ArrayIndexList @format  :  ; \n", nid ); }
#line 1467 "y.tab.c"
    break;

  case 15: /* ArrayIndexList: ArrayIndexList LBRACKET Exp RBRACKET  */
#line 84 "example.y"
        { yyval = ++ nid; printf("%10d ArrayIndexList @format ArrayIndexList LBRACKET Exp RBRACKET  :  %d  %d  %d  %d  ; \n", nid, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0] ); }
#line 1473 "y.tab.c"
    break;

  case 16: /* InitVal: Exp  */
#line 89 "example.y"
        { yyval = ++ nid; printf("%10d InitVal @format Exp  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1479 "y.tab.c"
    break;

  case 17: /* InitVal: LBRACE InitValList RBRACE  */
#line 91 "example.y"
        { yyval = ++ nid; printf("%10d InitVal @format LBRACE InitValList RBRACE  :  %d  %d  %d  ; \n", nid, yyvsp[-2], yyvsp[-1], yyvsp[0] ); }
#line 1485 "y.tab.c"
    break;

  case 18: /* InitValList: InitVal  */
#line 96 "example.y"
        { yyval = ++ nid; printf("%10d InitValList @format InitVal  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1491 "y.tab.c"
    break;

  case 19: /* InitValList: InitValList COMMA InitVal  */
#line 98 "example.y"
        { yyval = ++ nid; printf("%10d InitValList @format InitValList COMMA InitVal  :  %d  %d  %d  ; \n", nid, yyvsp[-2], yyvsp[-1], yyvsp[0] ); }
#line 1497 "y.tab.c"
    break;

  case 20: /* VarDecl: BType VarDefList SEMICOLON  */
#line 103 "example.y"
        { yyval = ++ nid; printf("%10d VarDecl @format BType VarDefList SEMICOLON  :  %d  %d  %d  ; \n", nid, yyvsp[-2], yyvsp[-1], yyvsp[0] ); }
#line 1503 "y.tab.c"
    break;

  case 21: /* VarDefList: VarDef  */
#line 108 "example.y"
        { yyval = ++ nid; printf("%10d VarDefList @format VarDef  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1509 "y.tab.c"
    break;

  case 22: /* VarDefList: VarDefList COMMA VarDef  */
#line 110 "example.y"
        { yyval = ++ nid; printf("%10d VarDefList @format VarDefList COMMA VarDef  :  %d  %d  %d  ; \n", nid, yyvsp[-2], yyvsp[-1], yyvsp[0] ); }
#line 1515 "y.tab.c"
    break;

  case 23: /* VarDef: IDENTIFIER ArrayIndexList  */
#line 115 "example.y"
        { yyval = ++ nid; printf("%10d VarDef @format IDENTIFIER ArrayIndexList  :  %d  %d  ; \n", nid, yyvsp[-1], yyvsp[0] ); }
#line 1521 "y.tab.c"
    break;

  case 24: /* VarDef: IDENTIFIER ArrayIndexList EQUAL InitVal  */
#line 117 "example.y"
        { yyval = ++ nid; printf("%10d VarDef @format IDENTIFIER ArrayIndexList EQUAL InitVal  :  %d  %d  %d  %d  ; \n", nid, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0] ); }
#line 1527 "y.tab.c"
    break;

  case 25: /* FuncDef: FuncType IDENTIFIER LPARE RPARE Block  */
#line 122 "example.y"
        { yyval = ++ nid; printf("%10d FuncDef @format FuncType IDENTIFIER LPARE RPARE Block  :  %d  %d  %d  %d  %d  ; \n", nid, yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0] ); }
#line 1533 "y.tab.c"
    break;

  case 26: /* FuncDef: FuncType IDENTIFIER LPARE FuncFParams RPARE Block  */
#line 124 "example.y"
        { yyval = ++ nid; printf("%10d FuncDef @format FuncType IDENTIFIER LPARE FuncFParams RPARE Block  :  %d  %d  %d  %d  %d  %d  ; \n", nid, yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0] ); }
#line 1539 "y.tab.c"
    break;

  case 27: /* FuncType: KEYWORD_VOID  */
#line 129 "example.y"
        { yyval = ++ nid; printf("%10d FuncType @format KEYWORD_VOID  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1545 "y.tab.c"
    break;

  case 28: /* FuncType: BType  */
#line 131 "example.y"
        { yyval = ++ nid; printf("%10d FuncType @format BType  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1551 "y.tab.c"
    break;

  case 29: /* FuncFParams: FuncFParam  */
#line 136 "example.y"
        { yyval = ++ nid; printf("%10d FuncFParams @format FuncFParam  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1557 "y.tab.c"
    break;

  case 30: /* FuncFParams: FuncFParams COMMA FuncFParam  */
#line 138 "example.y"
        { yyval = ++ nid; printf("%10d FuncFParams @format FuncFParams COMMA FuncFParam  :  %d  %d  %d  ; \n", nid, yyvsp[-2], yyvsp[-1], yyvsp[0] ); }
#line 1563 "y.tab.c"
    break;

  case 31: /* FuncFParam: BType IDENTIFIER FuncFParamArrayIndexList  */
#line 143 "example.y"
        { yyval = ++ nid; printf("%10d FuncFParam @format BType IDENTIFIER FuncFParamArrayIndexList  :  %d  %d  %d  ; \n", nid, yyvsp[-2], yyvsp[-1], yyvsp[0] ); }
#line 1569 "y.tab.c"
    break;

  case 32: /* FuncFParamArrayIndexList: LBRACKET RBRACKET  */
#line 148 "example.y"
        { yyval = ++ nid; printf("%10d FuncFParamArrayIndexList @format LBRACKET RBRACKET  :  %d  %d  ; \n", nid, yyvsp[-1], yyvsp[0] ); }
#line 1575 "y.tab.c"
    break;

  case 33: /* FuncFParamArrayIndexList: FuncFParamArrayIndexList LBRACKET Exp RBRACKET  */
#line 150 "example.y"
        { yyval = ++ nid; printf("%10d FuncFParamArrayIndexList @format FuncFParamArrayIndexList LBRACKET Exp RBRACKET  :  %d  %d  %d  %d  ; \n", nid, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0] ); }
#line 1581 "y.tab.c"
    break;

  case 34: /* Block: LBRACE BlockItemList RBRACE  */
#line 155 "example.y"
        { yyval = ++ nid; printf("%10d Block @format LBRACE BlockItemList RBRACE  :  %d  %d  %d  ; \n", nid, yyvsp[-2], yyvsp[-1], yyvsp[0] ); }
#line 1587 "y.tab.c"
    break;

  case 35: /* BlockItemList: %empty  */
#line 160 "example.y"
        { yyval = ++ nid; printf("%10d BlockItemList @format  :  ; \n", nid ); }
#line 1593 "y.tab.c"
    break;

  case 36: /* BlockItemList: BlockItemList BlockItem  */
#line 162 "example.y"
        { yyval = ++ nid; printf("%10d BlockItemList @format BlockItemList BlockItem  :  %d  %d  ; \n", nid, yyvsp[-1], yyvsp[0] ); }
#line 1599 "y.tab.c"
    break;

  case 37: /* BlockItem: Decl  */
#line 167 "example.y"
        { yyval = ++ nid; printf("%10d BlockItem @format Decl  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1605 "y.tab.c"
    break;

  case 38: /* BlockItem: Stmt  */
#line 169 "example.y"
        { yyval = ++ nid; printf("%10d BlockItem @format Stmt  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1611 "y.tab.c"
    break;

  case 39: /* Stmt: LVal EQUAL Exp SEMICOLON  */
#line 174 "example.y"
        { yyval = ++ nid; printf("%10d Stmt @format LVal EQUAL Exp SEMICOLON  :  %d  %d  %d  %d  ; \n", nid, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0] ); }
#line 1617 "y.tab.c"
    break;

  case 40: /* Stmt: Block  */
#line 176 "example.y"
        { yyval = ++ nid; printf("%10d Stmt @format Block  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1623 "y.tab.c"
    break;

  case 41: /* Stmt: KEYWORD_IF LPARE Cond RPARE Stmt  */
#line 178 "example.y"
        { yyval = ++ nid; printf("%10d Stmt @format KEYWORD_IF LPARE Cond RPARE Stmt  :  %d  %d  %d  %d  %d  ; \n", nid, yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0] ); }
#line 1629 "y.tab.c"
    break;

  case 42: /* Stmt: KEYWORD_IF LPARE Cond RPARE Stmt KEYWORD_ELSE Stmt  */
#line 180 "example.y"
        { yyval = ++ nid; printf("%10d Stmt @format KEYWORD_IF LPARE Cond RPARE Stmt KEYWORD_ELSE Stmt  :  %d  %d  %d  %d  %d  %d  %d  ; \n", nid, yyvsp[-6], yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0] ); }
#line 1635 "y.tab.c"
    break;

  case 43: /* Stmt: KEYWORD_WHILE LPARE Cond RPARE Stmt  */
#line 182 "example.y"
        { yyval = ++ nid; printf("%10d Stmt @format KEYWORD_WHILE LPARE Cond RPARE Stmt  :  %d  %d  %d  %d  %d  ; \n", nid, yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0] ); }
#line 1641 "y.tab.c"
    break;

  case 44: /* Stmt: KEYWORD_BREAK SEMICOLON  */
#line 184 "example.y"
        { yyval = ++ nid; printf("%10d Stmt @format KEYWORD_BREAK SEMICOLON  :  %d  %d  ; \n", nid, yyvsp[-1], yyvsp[0] ); }
#line 1647 "y.tab.c"
    break;

  case 45: /* Stmt: KEYWORD_CONTINUE SEMICOLON  */
#line 186 "example.y"
        { yyval = ++ nid; printf("%10d Stmt @format KEYWORD_CONTINUE SEMICOLON  :  %d  %d  ; \n", nid, yyvsp[-1], yyvsp[0] ); }
#line 1653 "y.tab.c"
    break;

  case 46: /* Stmt: KEYWORD_RETURN SEMICOLON  */
#line 188 "example.y"
        { yyval = ++ nid; printf("%10d Stmt @format KEYWORD_RETURN SEMICOLON  :  %d  %d  ; \n", nid, yyvsp[-1], yyvsp[0] ); }
#line 1659 "y.tab.c"
    break;

  case 47: /* Stmt: KEYWORD_RETURN Exp SEMICOLON  */
#line 190 "example.y"
        { yyval = ++ nid; printf("%10d Stmt @format KEYWORD_RETURN Exp SEMICOLON  :  %d  %d  %d  ; \n", nid, yyvsp[-2], yyvsp[-1], yyvsp[0] ); }
#line 1665 "y.tab.c"
    break;

  case 48: /* Exp: AddExp  */
#line 195 "example.y"
        { yyval = ++ nid; printf("%10d Exp @format AddExp  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1671 "y.tab.c"
    break;

  case 49: /* Cond: LOrExp  */
#line 200 "example.y"
        { yyval = ++ nid; printf("%10d Cond @format LOrExp  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1677 "y.tab.c"
    break;

  case 50: /* LVal: IDENTIFIER ArrayIndexList  */
#line 205 "example.y"
        { yyval = ++ nid; printf("%10d LVal @format IDENTIFIER ArrayIndexList  :  %d  %d  ; \n", nid, yyvsp[-1], yyvsp[0] ); }
#line 1683 "y.tab.c"
    break;

  case 51: /* PrimaryExp: LPARE Exp RPARE  */
#line 210 "example.y"
        { yyval = ++ nid; printf("%10d PrimaryExp @format LPARE Exp RPARE  :  %d  %d  %d  ; \n", nid, yyvsp[-2], yyvsp[-1], yyvsp[0] ); }
#line 1689 "y.tab.c"
    break;

  case 52: /* PrimaryExp: LVal  */
#line 212 "example.y"
        { yyval = ++ nid; printf("%10d PrimaryExp @format LVal  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1695 "y.tab.c"
    break;

  case 53: /* PrimaryExp: Number  */
#line 214 "example.y"
        { yyval = ++ nid; printf("%10d PrimaryExp @format Number  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1701 "y.tab.c"
    break;

  case 54: /* Number: INT_CONST  */
#line 219 "example.y"
        { yyval = ++ nid; printf("%10d Number @format INT_CONST  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1707 "y.tab.c"
    break;

  case 55: /* Number: FLOAT_CONST  */
#line 221 "example.y"
        { yyval = ++ nid; printf("%10d Number @format FLOAT_CONST  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1713 "y.tab.c"
    break;

  case 56: /* UnaryExp: PrimaryExp  */
#line 226 "example.y"
        { yyval = ++ nid; printf("%10d UnaryExp @format PrimaryExp  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1719 "y.tab.c"
    break;

  case 57: /* UnaryExp: IDENTIFIER LPARE RPARE  */
#line 228 "example.y"
        { yyval = ++ nid; printf("%10d UnaryExp @format IDENTIFIER LPARE RPARE  :  %d  %d  %d  ; \n", nid, yyvsp[-2], yyvsp[-1], yyvsp[0] ); }
#line 1725 "y.tab.c"
    break;

  case 58: /* UnaryExp: IDENTIFIER LPARE FuncRPAREms RPARE  */
#line 230 "example.y"
        { yyval = ++ nid; printf("%10d UnaryExp @format IDENTIFIER LPARE FuncRPAREms RPARE  :  %d  %d  %d  %d  ; \n", nid, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0] ); }
#line 1731 "y.tab.c"
    break;

  case 59: /* UnaryExp: UnaryOp UnaryExp  */
#line 232 "example.y"
        { yyval = ++ nid; printf("%10d UnaryExp @format UnaryOp UnaryExp  :  %d  %d  ; \n", nid, yyvsp[-1], yyvsp[0] ); }
#line 1737 "y.tab.c"
    break;

  case 60: /* UnaryOp: OPE_ADD  */
#line 237 "example.y"
        { yyval = ++ nid; printf("%10d UnaryOp @format OPE_ADD  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1743 "y.tab.c"
    break;

  case 61: /* UnaryOp: OPE_SUB  */
#line 239 "example.y"
        { yyval = ++ nid; printf("%10d UnaryOp @format OPE_SUB  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1749 "y.tab.c"
    break;

  case 62: /* UnaryOp: OPE_NOT  */
#line 241 "example.y"
        { yyval = ++ nid; printf("%10d UnaryOp @format OPE_NOT  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1755 "y.tab.c"
    break;

  case 63: /* FuncRPAREms: Exp  */
#line 246 "example.y"
        { yyval = ++ nid; printf("%10d FuncRPAREms @format Exp  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1761 "y.tab.c"
    break;

  case 64: /* FuncRPAREms: FuncRPAREms COMMA Exp  */
#line 248 "example.y"
        { yyval = ++ nid; printf("%10d FuncRPAREms @format FuncRPAREms COMMA Exp  :  %d  %d  %d  ; \n", nid, yyvsp[-2], yyvsp[-1], yyvsp[0] ); }
#line 1767 "y.tab.c"
    break;

  case 65: /* MulExp: UnaryExp  */
#line 253 "example.y"
        { yyval = ++ nid; printf("%10d MulExp @format UnaryExp  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1773 "y.tab.c"
    break;

  case 66: /* MulExp: MulExp MulOp UnaryExp  */
#line 255 "example.y"
        { yyval = ++ nid; printf("%10d MulExp @format MulExp MulOp UnaryExp  :  %d  %d  %d  ; \n", nid, yyvsp[-2], yyvsp[-1], yyvsp[0] ); }
#line 1779 "y.tab.c"
    break;

  case 67: /* MulOp: OPE_MUL  */
#line 260 "example.y"
        { yyval = ++ nid; printf("%10d MulOp @format OPE_MUL  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1785 "y.tab.c"
    break;

  case 68: /* MulOp: OPE_DIV  */
#line 262 "example.y"
        { yyval = ++ nid; printf("%10d MulOp @format OPE_DIV  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1791 "y.tab.c"
    break;

  case 69: /* MulOp: OPE_MOD  */
#line 264 "example.y"
        { yyval = ++ nid; printf("%10d MulOp @format OPE_MOD  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1797 "y.tab.c"
    break;

  case 70: /* AddExp: MulExp  */
#line 269 "example.y"
        { yyval = ++ nid; printf("%10d AddExp @format MulExp  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1803 "y.tab.c"
    break;

  case 71: /* AddExp: AddExp AddOp MulExp  */
#line 271 "example.y"
        { yyval = ++ nid; printf("%10d AddExp @format AddExp AddOp MulExp  :  %d  %d  %d  ; \n", nid, yyvsp[-2], yyvsp[-1], yyvsp[0] ); }
#line 1809 "y.tab.c"
    break;

  case 72: /* AddOp: OPE_ADD  */
#line 276 "example.y"
        { yyval = ++ nid; printf("%10d AddOp @format OPE_ADD  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1815 "y.tab.c"
    break;

  case 73: /* AddOp: OPE_SUB  */
#line 278 "example.y"
        { yyval = ++ nid; printf("%10d AddOp @format OPE_SUB  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1821 "y.tab.c"
    break;

  case 74: /* RelExp: AddExp  */
#line 283 "example.y"
        { yyval = ++ nid; printf("%10d RelExp @format AddExp  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1827 "y.tab.c"
    break;

  case 75: /* RelExp: RelExp RelOp AddExp  */
#line 285 "example.y"
        { yyval = ++ nid; printf("%10d RelExp @format RelExp RelOp AddExp  :  %d  %d  %d  ; \n", nid, yyvsp[-2], yyvsp[-1], yyvsp[0] ); }
#line 1833 "y.tab.c"
    break;

  case 76: /* RelOp: OPE_LSS  */
#line 290 "example.y"
        { yyval = ++ nid; printf("%10d RelOp @format OPE_LSS  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1839 "y.tab.c"
    break;

  case 77: /* RelOp: OPE_LEQ  */
#line 292 "example.y"
        { yyval = ++ nid; printf("%10d RelOp @format OPE_LEQ  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1845 "y.tab.c"
    break;

  case 78: /* RelOp: OPE_GTR  */
#line 294 "example.y"
        { yyval = ++ nid; printf("%10d RelOp @format OPE_GTR  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1851 "y.tab.c"
    break;

  case 79: /* RelOp: OPE_GEQ  */
#line 296 "example.y"
        { yyval = ++ nid; printf("%10d RelOp @format OPE_GEQ  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1857 "y.tab.c"
    break;

  case 80: /* EqExp: RelExp  */
#line 301 "example.y"
        { yyval = ++ nid; printf("%10d EqExp @format RelExp  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1863 "y.tab.c"
    break;

  case 81: /* EqExp: EqExp EqOp RelExp  */
#line 303 "example.y"
        { yyval = ++ nid; printf("%10d EqExp @format EqExp EqOp RelExp  :  %d  %d  %d  ; \n", nid, yyvsp[-2], yyvsp[-1], yyvsp[0] ); }
#line 1869 "y.tab.c"
    break;

  case 82: /* EqOp: OPE_EQU  */
#line 308 "example.y"
        { yyval = ++ nid; printf("%10d EqOp @format OPE_EQU  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1875 "y.tab.c"
    break;

  case 83: /* EqOp: OPE_NEQ  */
#line 310 "example.y"
        { yyval = ++ nid; printf("%10d EqOp @format OPE_NEQ  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1881 "y.tab.c"
    break;

  case 84: /* LAndExp: EqExp  */
#line 315 "example.y"
        { yyval = ++ nid; printf("%10d LAndExp @format EqExp  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1887 "y.tab.c"
    break;

  case 85: /* LAndExp: LAndExp OPE_AND EqExp  */
#line 317 "example.y"
        { yyval = ++ nid; printf("%10d LAndExp @format LAndExp OPE_AND EqExp  :  %d  %d  %d  ; \n", nid, yyvsp[-2], yyvsp[-1], yyvsp[0] ); }
#line 1893 "y.tab.c"
    break;

  case 86: /* LOrExp: LAndExp  */
#line 322 "example.y"
        { yyval = ++ nid; printf("%10d LOrExp @format LAndExp  :  %d  ; \n", nid, yyvsp[0] ); }
#line 1899 "y.tab.c"
    break;

  case 87: /* LOrExp: LOrExp OPE_OR LAndExp  */
#line 324 "example.y"
        { yyval = ++ nid; printf("%10d LOrExp @format LOrExp OPE_OR LAndExp  :  %d  %d  %d  ; \n", nid, yyvsp[-2], yyvsp[-1], yyvsp[0] ); }
#line 1905 "y.tab.c"
    break;


#line 1909 "y.tab.c"

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


#if !defined yyoverflow
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

  return yyresult;
}

#line 328 "example.y"

