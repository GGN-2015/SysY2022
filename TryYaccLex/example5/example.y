%{
#include <stdio.h>
#include <string.h>

// this is defined in "lex.yy.c"
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

%token NUMBER TOKHEAT STATE TOKTARGET TOKTEMPERATURE

%%
commands: /* empty */
	| commands command ;

command: heat_switch
       | target_set ;

heat_switch: TOKHEAT STATE
{
	printf("\tHeat turned %s\n", ($2 ? "ON" : "OFF"));
};

target_set: TOKTARGET TOKTEMPERATURE NUMBER
{
	printf("\tTemperature set to %d\n", $3);
};
%%

