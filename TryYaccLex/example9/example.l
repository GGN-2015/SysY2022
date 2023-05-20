%{
#include <stdio.h>

#define YYSTYPE int
extern int nid;
extern YYSTYPE yylval; // put it before "y.tab.h"

#include "y.tab.h"
%}

%%
\=                      { yylval = ++ nid; printf("%10d EQUAL          %s : ; \n", nid, yytext); return EQUAL          ; }
[_a-zA-Z][_a-zA-Z0-9]*  { yylval = ++ nid;
        if(0 == strcmp("int", yytext)) return KEYWORD_INT;
        if(0 == strcmp("float", yytext)) return KEYWORD_FLOAT;
        return IDENTIFIER; }
%%