
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


%token SEMICOLON COMMA EQUAL LBRACKET RBRACKET LBRACE RBRACE LPARE RPARE OPE_NOT OPE_ADD OPE_SUB OPE_MUL OPE_DIV OPE_MOD OPE_AND OPE_OR OPE_EQU OPE_NEQ OPE_LEQ OPE_GEQ OPE_LSS OPE_GTR INT_CONST FLOAT_CONST IDENTIFIER KEYWORD_CONST KEYWORD_INT KEYWORD_FLOAT KEYWORD_VOID KEYWORD_IF KEYWORD_ELSE KEYWORD_WHILE KEYWORD_CONTINUE KEYWORD_BREAK KEYWORD_RETURN 

%left KEYWORD_ELSE
%left KEYWORD_IF
%%
CompUnit
    : CompUnitDef 
        { $$ = ++ nid; printf("%10d CompUnit @format CompUnitDef  :  %d  ; \n", nid, $1 ); }
    | CompUnit CompUnitDef 
        { $$ = ++ nid; printf("%10d CompUnit @format CompUnit CompUnitDef  :  %d  %d  ; \n", nid, $1, $2 ); }
;

CompUnitDef
    : Decl 
        { $$ = ++ nid; printf("%10d CompUnitDef @format Decl  :  %d  ; \n", nid, $1 ); }
    | FuncDef 
        { $$ = ++ nid; printf("%10d CompUnitDef @format FuncDef  :  %d  ; \n", nid, $1 ); }
;

Decl
    : ConstDecl 
        { $$ = ++ nid; printf("%10d Decl @format ConstDecl  :  %d  ; \n", nid, $1 ); }
    | VarDecl 
        { $$ = ++ nid; printf("%10d Decl @format VarDecl  :  %d  ; \n", nid, $1 ); }
;

ConstDecl
    : KEYWORD_CONST BType ConstDefList SEMICOLON 
        { $$ = ++ nid; printf("%10d ConstDecl @format KEYWORD_CONST BType ConstDefList SEMICOLON  :  %d  %d  %d  %d  ; \n", nid, $1, $2, $3, $4 ); }
;

BType
    : KEYWORD_INT 
        { $$ = ++ nid; printf("%10d BType @format KEYWORD_INT  :  %d  ; \n", nid, $1 ); }
    | KEYWORD_FLOAT 
        { $$ = ++ nid; printf("%10d BType @format KEYWORD_FLOAT  :  %d  ; \n", nid, $1 ); }
;

ConstDefList
    : ConstDef 
        { $$ = ++ nid; printf("%10d ConstDefList @format ConstDef  :  %d  ; \n", nid, $1 ); }
    | ConstDefList COMMA ConstDef 
        { $$ = ++ nid; printf("%10d ConstDefList @format ConstDefList COMMA ConstDef  :  %d  %d  %d  ; \n", nid, $1, $2, $3 ); }
;

ConstDef
    : IDENTIFIER ArrayIndexList EQUAL InitVal 
        { $$ = ++ nid; printf("%10d ConstDef @format IDENTIFIER ArrayIndexList EQUAL InitVal  :  %d  %d  %d  %d  ; \n", nid, $1, $2, $3, $4 ); }
;

ArrayIndexList
    : 
        { $$ = ++ nid; printf("%10d ArrayIndexList @format  :  ; \n", nid ); }
    | ArrayIndexList LBRACKET Exp RBRACKET 
        { $$ = ++ nid; printf("%10d ArrayIndexList @format ArrayIndexList LBRACKET Exp RBRACKET  :  %d  %d  %d  %d  ; \n", nid, $1, $2, $3, $4 ); }
;

InitVal
    : Exp 
        { $$ = ++ nid; printf("%10d InitVal @format Exp  :  %d  ; \n", nid, $1 ); }
    | LBRACE InitValList RBRACE 
        { $$ = ++ nid; printf("%10d InitVal @format LBRACE InitValList RBRACE  :  %d  %d  %d  ; \n", nid, $1, $2, $3 ); }
;

InitValList
    : InitVal 
        { $$ = ++ nid; printf("%10d InitValList @format InitVal  :  %d  ; \n", nid, $1 ); }
    | InitValList COMMA InitVal 
        { $$ = ++ nid; printf("%10d InitValList @format InitValList COMMA InitVal  :  %d  %d  %d  ; \n", nid, $1, $2, $3 ); }
;

VarDecl
    : BType VarDefList SEMICOLON 
        { $$ = ++ nid; printf("%10d VarDecl @format BType VarDefList SEMICOLON  :  %d  %d  %d  ; \n", nid, $1, $2, $3 ); }
;

VarDefList
    : VarDef 
        { $$ = ++ nid; printf("%10d VarDefList @format VarDef  :  %d  ; \n", nid, $1 ); }
    | VarDefList COMMA VarDef 
        { $$ = ++ nid; printf("%10d VarDefList @format VarDefList COMMA VarDef  :  %d  %d  %d  ; \n", nid, $1, $2, $3 ); }
;

VarDef
    : IDENTIFIER ArrayIndexList 
        { $$ = ++ nid; printf("%10d VarDef @format IDENTIFIER ArrayIndexList  :  %d  %d  ; \n", nid, $1, $2 ); }
    | IDENTIFIER ArrayIndexList EQUAL InitVal 
        { $$ = ++ nid; printf("%10d VarDef @format IDENTIFIER ArrayIndexList EQUAL InitVal  :  %d  %d  %d  %d  ; \n", nid, $1, $2, $3, $4 ); }
;

FuncDef
    : FuncType IDENTIFIER LPARE RPARE Block 
        { $$ = ++ nid; printf("%10d FuncDef @format FuncType IDENTIFIER LPARE RPARE Block  :  %d  %d  %d  %d  %d  ; \n", nid, $1, $2, $3, $4, $5 ); }
    | FuncType IDENTIFIER LPARE FuncFParams RPARE Block 
        { $$ = ++ nid; printf("%10d FuncDef @format FuncType IDENTIFIER LPARE FuncFParams RPARE Block  :  %d  %d  %d  %d  %d  %d  ; \n", nid, $1, $2, $3, $4, $5, $6 ); }
;

FuncType
    : KEYWORD_VOID 
        { $$ = ++ nid; printf("%10d FuncType @format KEYWORD_VOID  :  %d  ; \n", nid, $1 ); }
    | BType 
        { $$ = ++ nid; printf("%10d FuncType @format BType  :  %d  ; \n", nid, $1 ); }
;

FuncFParams
    : FuncFParam 
        { $$ = ++ nid; printf("%10d FuncFParams @format FuncFParam  :  %d  ; \n", nid, $1 ); }
    | FuncFParams COMMA FuncFParam 
        { $$ = ++ nid; printf("%10d FuncFParams @format FuncFParams COMMA FuncFParam  :  %d  %d  %d  ; \n", nid, $1, $2, $3 ); }
;

FuncFParam
    : BType IDENTIFIER FuncFParamArrayIndexList 
        { $$ = ++ nid; printf("%10d FuncFParam @format BType IDENTIFIER FuncFParamArrayIndexList  :  %d  %d  %d  ; \n", nid, $1, $2, $3 ); }
;

FuncFParamArrayIndexList
    : LBRACKET RBRACKET 
        { $$ = ++ nid; printf("%10d FuncFParamArrayIndexList @format LBRACKET RBRACKET  :  %d  %d  ; \n", nid, $1, $2 ); }
    | FuncFParamArrayIndexList LBRACKET Exp RBRACKET 
        { $$ = ++ nid; printf("%10d FuncFParamArrayIndexList @format FuncFParamArrayIndexList LBRACKET Exp RBRACKET  :  %d  %d  %d  %d  ; \n", nid, $1, $2, $3, $4 ); }
;

Block
    : LBRACE BlockItemList RBRACE 
        { $$ = ++ nid; printf("%10d Block @format LBRACE BlockItemList RBRACE  :  %d  %d  %d  ; \n", nid, $1, $2, $3 ); }
;

BlockItemList
    : 
        { $$ = ++ nid; printf("%10d BlockItemList @format  :  ; \n", nid ); }
    | BlockItemList BlockItem 
        { $$ = ++ nid; printf("%10d BlockItemList @format BlockItemList BlockItem  :  %d  %d  ; \n", nid, $1, $2 ); }
;

BlockItem
    : Decl 
        { $$ = ++ nid; printf("%10d BlockItem @format Decl  :  %d  ; \n", nid, $1 ); }
    | Stmt 
        { $$ = ++ nid; printf("%10d BlockItem @format Stmt  :  %d  ; \n", nid, $1 ); }
;

Stmt
    : LVal EQUAL Exp SEMICOLON 
        { $$ = ++ nid; printf("%10d Stmt @format LVal EQUAL Exp SEMICOLON  :  %d  %d  %d  %d  ; \n", nid, $1, $2, $3, $4 ); }
    | Block 
        { $$ = ++ nid; printf("%10d Stmt @format Block  :  %d  ; \n", nid, $1 ); }
    | KEYWORD_IF LPARE Cond RPARE Stmt 
        { $$ = ++ nid; printf("%10d Stmt @format KEYWORD_IF LPARE Cond RPARE Stmt  :  %d  %d  %d  %d  %d  ; \n", nid, $1, $2, $3, $4, $5 ); }
    | KEYWORD_IF LPARE Cond RPARE Stmt KEYWORD_ELSE Stmt 
        { $$ = ++ nid; printf("%10d Stmt @format KEYWORD_IF LPARE Cond RPARE Stmt KEYWORD_ELSE Stmt  :  %d  %d  %d  %d  %d  %d  %d  ; \n", nid, $1, $2, $3, $4, $5, $6, $7 ); }
    | KEYWORD_WHILE LPARE Cond RPARE Stmt 
        { $$ = ++ nid; printf("%10d Stmt @format KEYWORD_WHILE LPARE Cond RPARE Stmt  :  %d  %d  %d  %d  %d  ; \n", nid, $1, $2, $3, $4, $5 ); }
    | KEYWORD_BREAK SEMICOLON 
        { $$ = ++ nid; printf("%10d Stmt @format KEYWORD_BREAK SEMICOLON  :  %d  %d  ; \n", nid, $1, $2 ); }
    | KEYWORD_CONTINUE SEMICOLON 
        { $$ = ++ nid; printf("%10d Stmt @format KEYWORD_CONTINUE SEMICOLON  :  %d  %d  ; \n", nid, $1, $2 ); }
    | KEYWORD_RETURN SEMICOLON 
        { $$ = ++ nid; printf("%10d Stmt @format KEYWORD_RETURN SEMICOLON  :  %d  %d  ; \n", nid, $1, $2 ); }
    | KEYWORD_RETURN Exp SEMICOLON 
        { $$ = ++ nid; printf("%10d Stmt @format KEYWORD_RETURN Exp SEMICOLON  :  %d  %d  %d  ; \n", nid, $1, $2, $3 ); }
;

Exp
    : AddExp 
        { $$ = ++ nid; printf("%10d Exp @format AddExp  :  %d  ; \n", nid, $1 ); }
;

Cond
    : LOrExp 
        { $$ = ++ nid; printf("%10d Cond @format LOrExp  :  %d  ; \n", nid, $1 ); }
;

LVal
    : IDENTIFIER ArrayIndexList 
        { $$ = ++ nid; printf("%10d LVal @format IDENTIFIER ArrayIndexList  :  %d  %d  ; \n", nid, $1, $2 ); }
;

PrimaryExp
    : LPARE Exp RPARE 
        { $$ = ++ nid; printf("%10d PrimaryExp @format LPARE Exp RPARE  :  %d  %d  %d  ; \n", nid, $1, $2, $3 ); }
    | LVal 
        { $$ = ++ nid; printf("%10d PrimaryExp @format LVal  :  %d  ; \n", nid, $1 ); }
    | Number 
        { $$ = ++ nid; printf("%10d PrimaryExp @format Number  :  %d  ; \n", nid, $1 ); }
;

Number
    : INT_CONST 
        { $$ = ++ nid; printf("%10d Number @format INT_CONST  :  %d  ; \n", nid, $1 ); }
    | FLOAT_CONST 
        { $$ = ++ nid; printf("%10d Number @format FLOAT_CONST  :  %d  ; \n", nid, $1 ); }
;

UnaryExp
    : PrimaryExp 
        { $$ = ++ nid; printf("%10d UnaryExp @format PrimaryExp  :  %d  ; \n", nid, $1 ); }
    | IDENTIFIER LPARE RPARE 
        { $$ = ++ nid; printf("%10d UnaryExp @format IDENTIFIER LPARE RPARE  :  %d  %d  %d  ; \n", nid, $1, $2, $3 ); }
    | IDENTIFIER LPARE FuncRPAREms RPARE 
        { $$ = ++ nid; printf("%10d UnaryExp @format IDENTIFIER LPARE FuncRPAREms RPARE  :  %d  %d  %d  %d  ; \n", nid, $1, $2, $3, $4 ); }
    | UnaryOp UnaryExp 
        { $$ = ++ nid; printf("%10d UnaryExp @format UnaryOp UnaryExp  :  %d  %d  ; \n", nid, $1, $2 ); }
;

UnaryOp
    : OPE_ADD 
        { $$ = ++ nid; printf("%10d UnaryOp @format OPE_ADD  :  %d  ; \n", nid, $1 ); }
    | OPE_SUB 
        { $$ = ++ nid; printf("%10d UnaryOp @format OPE_SUB  :  %d  ; \n", nid, $1 ); }
    | OPE_NOT 
        { $$ = ++ nid; printf("%10d UnaryOp @format OPE_NOT  :  %d  ; \n", nid, $1 ); }
;

FuncRPAREms
    : Exp 
        { $$ = ++ nid; printf("%10d FuncRPAREms @format Exp  :  %d  ; \n", nid, $1 ); }
    | FuncRPAREms COMMA Exp 
        { $$ = ++ nid; printf("%10d FuncRPAREms @format FuncRPAREms COMMA Exp  :  %d  %d  %d  ; \n", nid, $1, $2, $3 ); }
;

MulExp
    : UnaryExp 
        { $$ = ++ nid; printf("%10d MulExp @format UnaryExp  :  %d  ; \n", nid, $1 ); }
    | MulExp MulOp UnaryExp 
        { $$ = ++ nid; printf("%10d MulExp @format MulExp MulOp UnaryExp  :  %d  %d  %d  ; \n", nid, $1, $2, $3 ); }
;

MulOp
    : OPE_MUL 
        { $$ = ++ nid; printf("%10d MulOp @format OPE_MUL  :  %d  ; \n", nid, $1 ); }
    | OPE_DIV 
        { $$ = ++ nid; printf("%10d MulOp @format OPE_DIV  :  %d  ; \n", nid, $1 ); }
    | OPE_MOD 
        { $$ = ++ nid; printf("%10d MulOp @format OPE_MOD  :  %d  ; \n", nid, $1 ); }
;

AddExp
    : MulExp 
        { $$ = ++ nid; printf("%10d AddExp @format MulExp  :  %d  ; \n", nid, $1 ); }
    | AddExp AddOp MulExp 
        { $$ = ++ nid; printf("%10d AddExp @format AddExp AddOp MulExp  :  %d  %d  %d  ; \n", nid, $1, $2, $3 ); }
;

AddOp
    : OPE_ADD 
        { $$ = ++ nid; printf("%10d AddOp @format OPE_ADD  :  %d  ; \n", nid, $1 ); }
    | OPE_SUB 
        { $$ = ++ nid; printf("%10d AddOp @format OPE_SUB  :  %d  ; \n", nid, $1 ); }
;

RelExp
    : AddExp 
        { $$ = ++ nid; printf("%10d RelExp @format AddExp  :  %d  ; \n", nid, $1 ); }
    | RelExp RelOp AddExp 
        { $$ = ++ nid; printf("%10d RelExp @format RelExp RelOp AddExp  :  %d  %d  %d  ; \n", nid, $1, $2, $3 ); }
;

RelOp
    : OPE_LSS 
        { $$ = ++ nid; printf("%10d RelOp @format OPE_LSS  :  %d  ; \n", nid, $1 ); }
    | OPE_LEQ 
        { $$ = ++ nid; printf("%10d RelOp @format OPE_LEQ  :  %d  ; \n", nid, $1 ); }
    | OPE_GTR 
        { $$ = ++ nid; printf("%10d RelOp @format OPE_GTR  :  %d  ; \n", nid, $1 ); }
    | OPE_GEQ 
        { $$ = ++ nid; printf("%10d RelOp @format OPE_GEQ  :  %d  ; \n", nid, $1 ); }
;

EqExp
    : RelExp 
        { $$ = ++ nid; printf("%10d EqExp @format RelExp  :  %d  ; \n", nid, $1 ); }
    | EqExp EqOp RelExp 
        { $$ = ++ nid; printf("%10d EqExp @format EqExp EqOp RelExp  :  %d  %d  %d  ; \n", nid, $1, $2, $3 ); }
;

EqOp
    : OPE_EQU 
        { $$ = ++ nid; printf("%10d EqOp @format OPE_EQU  :  %d  ; \n", nid, $1 ); }
    | OPE_NEQ 
        { $$ = ++ nid; printf("%10d EqOp @format OPE_NEQ  :  %d  ; \n", nid, $1 ); }
;

LAndExp
    : EqExp 
        { $$ = ++ nid; printf("%10d LAndExp @format EqExp  :  %d  ; \n", nid, $1 ); }
    | LAndExp OPE_AND EqExp 
        { $$ = ++ nid; printf("%10d LAndExp @format LAndExp OPE_AND EqExp  :  %d  %d  %d  ; \n", nid, $1, $2, $3 ); }
;

LOrExp
    : LAndExp 
        { $$ = ++ nid; printf("%10d LOrExp @format LAndExp  :  %d  ; \n", nid, $1 ); }
    | LOrExp OPE_OR LAndExp 
        { $$ = ++ nid; printf("%10d LOrExp @format LOrExp OPE_OR LAndExp  :  %d  %d  %d  ; \n", nid, $1, $2, $3 ); }
;


%%
