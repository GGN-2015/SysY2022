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

%token SEMICOLON ZONETOK OBRACE EBRACE QUOTE FILENAME WORD FILETOK

%%
commands: /* empty */
	| commands command SEMICOLON ;

command: zone_set ;

zone_set: ZONETOK quotedname zonecontent
{
	printf("Complete zone for '%s' found\n", $2);
};

zonecontent: OBRACE zonestatements EBRACE
{
	$$ = $2;
};

quotedname: QUOTE FILENAME QUOTE
{
	$$ = $2;
};

zonestatements: /* empty */
	      | zonestatements zonestatement SEMICOLON;

zonestatement: statements
	     | FILETOK quotedname
{
	printf("A zonefile name '%s' was encountered\n", $2);
};

statements: /* empty */
	  | WORD statement
{
	$$ = $2;
	printf("satements, key: %s, value: %s\n", $1, $2);
};

statement: WORD
	 | quotedname;
%%

