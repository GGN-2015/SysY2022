%{
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