
%{
#include <stdio.h>

#define YYSTYPE int
extern int nid;
extern int lineId;
extern YYSTYPE yylval; // put it before "y.tab.h"

#include "y.tab.h"
%}

%%
int/[ \t]*[_a-zA-z0-9]+\(    { yylval = ++ nid; printf("%10d KEYWORD_INT_FUNC    %s : ; \n", nid, yytext); return KEYWORD_INT_FUNC    ; }
float/[ \t]*[_a-zA-z0-9]+\(  { yylval = ++ nid; printf("%10d KEYWORD_FLOAT_FUNC  %s : ; \n", nid, yytext); return KEYWORD_FLOAT_FUNC  ; }
\;                           { yylval = ++ nid; printf("%10d SEMICOLON           %s : ; \n", nid, yytext); return SEMICOLON           ; }
\,                           { yylval = ++ nid; printf("%10d COMMA               %s : ; \n", nid, yytext); return COMMA               ; }
\=                           { yylval = ++ nid; printf("%10d EQUAL               %s : ; \n", nid, yytext); return EQUAL               ; }
\[                           { yylval = ++ nid; printf("%10d LBRACKET            %s : ; \n", nid, yytext); return LBRACKET            ; }
\]                           { yylval = ++ nid; printf("%10d RBRACKET            %s : ; \n", nid, yytext); return RBRACKET            ; }
\{                           { yylval = ++ nid; printf("%10d LBRACE              %s : ; \n", nid, yytext); return LBRACE              ; }
\}                           { yylval = ++ nid; printf("%10d RBRACE              %s : ; \n", nid, yytext); return RBRACE              ; }
\(                           { yylval = ++ nid; printf("%10d LPARE               %s : ; \n", nid, yytext); return LPARE               ; }
\)                           { yylval = ++ nid; printf("%10d RPARE               %s : ; \n", nid, yytext); return RPARE               ; }
\!                           { yylval = ++ nid; printf("%10d OPE_NOT             %s : ; \n", nid, yytext); return OPE_NOT             ; }
\+                           { yylval = ++ nid; printf("%10d OPE_ADD             %s : ; \n", nid, yytext); return OPE_ADD             ; }
\-                           { yylval = ++ nid; printf("%10d OPE_SUB             %s : ; \n", nid, yytext); return OPE_SUB             ; }
\*                           { yylval = ++ nid; printf("%10d OPE_MUL             %s : ; \n", nid, yytext); return OPE_MUL             ; }
\/                           { yylval = ++ nid; printf("%10d OPE_DIV             %s : ; \n", nid, yytext); return OPE_DIV             ; }
\%                           { yylval = ++ nid; printf("%10d OPE_MOD             %s : ; \n", nid, yytext); return OPE_MOD             ; }
"&&"                         { yylval = ++ nid; printf("%10d OPE_AND             %s : ; \n", nid, yytext); return OPE_AND             ; }
"||"                         { yylval = ++ nid; printf("%10d OPE_OR              %s : ; \n", nid, yytext); return OPE_OR              ; }
"=="                         { yylval = ++ nid; printf("%10d OPE_EQU             %s : ; \n", nid, yytext); return OPE_EQU             ; }
"!="                         { yylval = ++ nid; printf("%10d OPE_NEQ             %s : ; \n", nid, yytext); return OPE_NEQ             ; }
"<="                         { yylval = ++ nid; printf("%10d OPE_LEQ             %s : ; \n", nid, yytext); return OPE_LEQ             ; }
">="                         { yylval = ++ nid; printf("%10d OPE_GEQ             %s : ; \n", nid, yytext); return OPE_GEQ             ; }
"<"                          { yylval = ++ nid; printf("%10d OPE_LSS             %s : ; \n", nid, yytext); return OPE_LSS             ; }
">"                          { yylval = ++ nid; printf("%10d OPE_GTR             %s : ; \n", nid, yytext); return OPE_GTR             ; }
[1-9][0-9]*                  { yylval = ++ nid; printf("%10d DECIMAL_CONST       %s : ; \n", nid, yytext); return DECIMAL_CONST       ; }
[0][0-7]*                    { yylval = ++ nid; printf("%10d OCTAL_CONST         %s : ; \n", nid, yytext); return OCTAL_CONST         ; }
0[xX][0-9A-F][0-9A-F]*       { yylval = ++ nid; printf("%10d HEXADECIMAL_CONST   %s : ; \n", nid, yytext); return HEXADECIMAL_CONST   ; }
[0-9][0-9]*\.[0-9]*          { yylval = ++ nid; printf("%10d FLOAT_CONST         %s : ; \n", nid, yytext); return FLOAT_CONST         ; }
[_a-zA-Z][_a-zA-Z0-9]*  { yylval = ++ nid; printf("%10d ", nid); 
        int typeId = IDENTIFIER; 
        if(0 == strcmp("const", yytext)) { typeId = KEYWORD_CONST; printf("KEYWORD_CONST"); }
        if(0 == strcmp("int", yytext)) { typeId = KEYWORD_INT; printf("KEYWORD_INT"); }
        if(0 == strcmp("float", yytext)) { typeId = KEYWORD_FLOAT; printf("KEYWORD_FLOAT"); }
        if(0 == strcmp("void", yytext)) { typeId = KEYWORD_VOID; printf("KEYWORD_VOID"); }
        if(0 == strcmp("if", yytext)) { typeId = KEYWORD_IF; printf("KEYWORD_IF"); }
        if(0 == strcmp("else", yytext)) { typeId = KEYWORD_ELSE; printf("KEYWORD_ELSE"); }
        if(0 == strcmp("while", yytext)) { typeId = KEYWORD_WHILE; printf("KEYWORD_WHILE"); }
        if(0 == strcmp("continue", yytext)) { typeId = KEYWORD_CONTINUE; printf("KEYWORD_CONTINUE"); }
        if(0 == strcmp("break", yytext)) { typeId = KEYWORD_BREAK; printf("KEYWORD_BREAK"); }
        if(0 == strcmp("return", yytext)) { typeId = KEYWORD_RETURN; printf("KEYWORD_RETURN"); }

        if(typeId == IDENTIFIER) printf("IDENTIFIER");
        printf(" %s : ; \n", yytext);
        return typeId; }
[ \t]+
\n { lineId += 1; } /* new line */ 
%%
