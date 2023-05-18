%{
#include <stdio.h>
#include <string.h>

#define YYSTYPE int
extern YYSTYPE yylval;
int yydebu = 1; // debug

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

%token NUM ADD SUB MUL DIV OPARE EPARE

%%
exp: add_exp { printf("ans = %d\n", $1); }
;

add_exp: mul_exp             { $$ = $1; }
       | add_exp ADD mul_exp { $$ = $1 + $3; }
       | add_exp SUB mul_exp { $$ = $1 - $3;  }
;

mul_exp: primary_exp             { $$ = $1; }
       | mul_exp MUL primary_exp { $$ = $1 * $3; }
       | mul_exp DIV primary_exp { $$ = $1 / $3; }
;

primary_exp: NUM                 { $$ = $1; }
	   | OPARE add_exp EPARE { $$ = $2; }
;
%%

