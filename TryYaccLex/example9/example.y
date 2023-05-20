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

%token NUM LPARE RPARE ADD SUB MUL DIV 
%%
Exp
    : AddExp 
        { $$ = ++ nid; printf("%10d Exp @format AddExp  :  %d  ; \n", nid, $1 ); }
;

AddExp
    : MulExp 
        { $$ = ++ nid; printf("%10d AddExp @format MulExp  :  %d  ; \n", nid, $1 ); }
    | AddExp ADD MulExp
        { $$ = ++ nid; printf("%10d AddExp @format AddExp ADD MulExp  :  %d  %d  %d  ; \n", nid, $1, $2, $3 ); }
    | AddExp SUB MulExp
        { $$ = ++ nid; printf("%10d AddExp @format AddExp SUB MulExp  :  %d  %d  %d  ; \n", nid, $1, $2, $3 ); }
;

MulExp
    : PrExp
        { $$ = ++ nid; printf("%10d MulExp @format PrExp  :  %d  ; \n", nid, $1 ); }
    | MulExp MUL PrExp
        { $$ = ++ nid; printf("%10d MulExp @format MulExp MUL PrExp  :  %d  %d  %d  ; \n", nid, $1, $2, $3 ); }
    | MulExp DIV PrExp
        { $$ = ++ nid; printf("%10d MulExp @format MulExp DIV PrExp  :  %d  %d  %d  ; \n", nid, $1, $2, $3 ); }
;

PrExp
    : NUM
        { $$ = ++ nid; printf("%10d PrExp @format NUM  :  %d  ; \n", nid, $1 ); }
    | LPARE AddExp RPARE
        { $$ = ++ nid; printf("%10d PrExp @format LPARE AddExp RPARE  :  %d  %d  %d  ; \n", nid, $1, $2, $3 ); }
;


%%