
OUT_FILE=example
LEX_FILE=example.l
YACC_FILE=example.y

${OUT_FILE}: lex.yy.c y.tab.c
	cc lex.yy.c y.tab.c -o ${OUT_FILE} -ll

y.tab.c: ${YACC_FILE}
	yacc -d ${YACC_FILE}

lex.yy.c: ${LEX_FILE}
	lex ${LEX_FILE}

run: ${OUT_FILE}
	./${OUT_FILE}

clean:
	rm ${OUT_FILE} lex.yy.c y.tab.c y.tab.h

.PHONY: run clean
