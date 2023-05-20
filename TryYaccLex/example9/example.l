%{
#include <stdio.h>

#define YYSTYPE int
extern int nid;
extern YYSTYPE yylval; // put it before "y.tab.h"

#include "y.tab.h"
%}

%token EQUAL IDENTIFIER KEYWORD_INT KEYWORD_FLOAT
%%
VarDefine
    : BType IDENTIFIER EQUAL IDENTIFIER
        { $$ = ++ nid; printf("%10d VarDefine @format BType IDENTIFIER EQUAL IDENTIFIER  :  %d  %d  %d  %d  ; \n", nid, $1, $2, $3, $4 ); }   
;

BType
    : KEYWORD_INT
        { $$ = ++ nid; printf("%10d BType @format KEYWORD_INT  :  %d  ; \n", nid, $1 ); }
    | KEYWORD_FLOAT
        { $$ = ++ nid; printf("%10d BType @format KEYWORD_FLOAT  :  %d  ; \n", nid, $1 ); }
;


%%