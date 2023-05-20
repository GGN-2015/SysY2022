%{
#include <stdio.h>

#define YYSTYPE int
extern int nid;
extern YYSTYPE yylval; // put it before "y.tab.h"

#include "y.tab.h"
%}

%%
\=                      { yylval = ++ nid; printf("%10d EQUAL          %s : ; \n", nid, yytext); return EQUAL          ; }
[_a-zA-Z][_a-zA-Z0-9]*  { yylval = ++ nid; printf("%10d ", nid);
        int typeId = IDENTIFIER;
        if(0 == strcmp("int", yytext)) { typeId = KEYWORD_INT; printf("KEYWORD_INT"); }
        if(0 == strcmp("float", yytext)) { typeId = KEYWORD_FLOAT; printf("KEYWORD_FLOAT"); }

        if(typeId == IDENTIFIER) printf("IDENTIFIER");
        printf(" %s : ; \n", yytext);
        return typeId; }
[ \t]
%%
