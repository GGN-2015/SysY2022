%{
#include <stdio.h>
#include <string.h>

#define YYSTYPE int
extern YYSTYPE yylval; // put it before "y.tab.h"

#include "y.tab.h"
%}

%%
\, { return COMMA;     }
\= { return EQUAL;     }
\[ { return LBRACKET;  }
\] { return RBRACKET;  }
\{ { return LBRACE;    }
\} { return RBRACE;    }
\; { return SEMICOLON; }
[a-zA-Z_][a-zA-Z0-9_]* { 
	if(0 == strcmp(yytext, "int"))   return KEYWORD_INT;
	if(0 == strcmp(yytext, "float")) return KEYWORD_FLOAT;
	if(0 == strcmp(yytext, "const")) return KEYWORD_CONST;
	return IDENTIFIER;
}
%%
