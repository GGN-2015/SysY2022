%{
#include <stdio.h>

#define YYSTYPE int
extern int nid;
extern YYSTYPE yylval; // put it before "y.tab.h"

#include "y.tab.h"
%}

%%
[0-9]+  { yylval = ++ nid; printf("%10d NUM    %s : ; \n", nid, yytext); return NUM    ; }
\(      { yylval = ++ nid; printf("%10d LPARE  %s : ; \n", nid, yytext); return LPARE  ; }
\)      { yylval = ++ nid; printf("%10d RPARE  %s : ; \n", nid, yytext); return RPARE  ; }
\+      { yylval = ++ nid; printf("%10d ADD    %s : ; \n", nid, yytext); return ADD    ; }
\-      { yylval = ++ nid; printf("%10d SUB    %s : ; \n", nid, yytext); return SUB    ; }
\*      { yylval = ++ nid; printf("%10d MUL    %s : ; \n", nid, yytext); return MUL    ; }
\/      { yylval = ++ nid; printf("%10d DIV    %s : ; \n", nid, yytext); return DIV    ; }
%%