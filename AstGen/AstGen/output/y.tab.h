/* A Bison parser, made by GNU Bison 3.7.5.  */

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
