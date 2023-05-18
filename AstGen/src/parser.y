%{
#include <stdio.h>
#include <string.h>

#define YYSTYPE  int
#define NEW_NODE $$ = ++ yyNodeCnt;
extern YYSTYPE yylval;

int yyDebug   = 1; // debug
int yyNodeCnt = 0;
int $$ = 0;

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

%token KEYWORD_CONST KEYWORD_INT KEYWORD_FLOAT COMMA EQUAL LBRACKET RBRACKET LBRACE RBRACE SEMICOLON IDENTIFIER

%%
Decl: ConstDecl { NEW_NODE; printf("%10d Decl ConstDecl : @ConstDecl %d ;\n", $$, $1); }
    | VarDecl   { NEW_NODE; printf("%10d Decl VarDecl   : @VarDecl   %d ;\n", $$, $1); }
;

ConstDecl: KEYWORD_CONST BType ConstDefList SEMICOLON { NEW_NODE;\
	 printf("%10d ConstDecl : @BType %d @ConstDefList %d ;\n", $$, $2, $3); }

BType: KEYWORD_INT   { NEW_NODE; printf("%10d BType int   : ;\n", $$); }
     | KEYWORD_FLOAT { NEW_NODE; printf("%10d BType float : ;\n", $$); }
;

ConstDefList: ConstDef                    { NEW_NODE; \
	        printf("%10d ConstDefList : @chain -1 @ConstDef %d ;\n", $$, $1); }
	    | ConstDefList COMMA ConstDef { NEW_NODE; \
                printf("%10d ConstDefList : @chain %d @ConstDef %d ;\n", $$, $1, $3); }

ConstDef: IDENTIFIER ArrayIndexList EQUAL InitVal
	{ NEW_NODE; printf("%10d ConstDef : @IDENTIFIER %d @ArrayIndexList %d @InitVal %d ;\n", $$, $1, $2, $4); }
;

InitVal: Exp                       { NEW_NODE; printf("%10d InitVal exp : @Exp %d\n", $$, $1); }
       | LBRACE InitValList RBRACE { NEW_NODE; printf("%10d InitVal brace : @InitValList %d\n",\
                                         $$, $2); }
;

InitValList: InitVal                   { NEW_NODE; printf("%10d InitValList single : @InitVal %d ; \n", $$, $1); }
	   | InitValList COMMA InitVal { NEW_NODE; printf("%10d InitValList multi : @InitValList %d @InitVal %d ;\n", $$, $1, $3); }

ArrayIndexList: { NEW_NODE; printf("%10d ArrayIndexList empty : ; \n"); }
	      | ArrayIndexList LBRACKET Exp RBRACKET { NEW_NODE; \
                  printf("%10d ArrayIndexList non-empty : @ArrayIndexList %d @Exp %d ;\n",\
                  $$, $1, $3); }
;

Exp: IDENTIFIER { NEW_NODE; printf("%10d Exp : #Exp ; \n", $$); }
;

VarDecl: BType ConstDefList SEMICOLON { NEW_NODE; \
       printf("%10d VarDecl : @BType %d @ConstDefList %d ;\n", $$, $1, $2);}
;
%%

