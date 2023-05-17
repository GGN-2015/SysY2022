%{
#include <stdio.h>

#define YYSTYPE char*
extern YYSTYPE yylval; // put it before "y.tab.h"

#include "y.tab.h"
%}

%%
[0-9]+ yylval = atoi(yytext); return NUM;
[ \n]+ /* eat whitespace */
-                             return SUB;
\*                            return MUL;
\+                            return ADD;
\/                            return DIV;
\(                            return OPARA;
\)                            return EPARA;
%%
