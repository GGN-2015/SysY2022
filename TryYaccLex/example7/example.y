%{
#include <stdio.h>
#include <string.h>

#define YYSTYPE char*
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

%token ADD SUB MUL DIV OPARA EPARA

%%
add_exp: mul_exp             { $$ = $1; }
       | add_exp ADD mul_exp { $$ = $1 + $3; }
       | add_exp SUB mul_exp { $$ = $1 - $3;  }
;
%%

