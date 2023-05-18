OUT_FILE=parser
LEX_FILE=parser.l
YACC_FILE=parser.y

${OUT_FILE}: lex.yy.c y.tab.c
	cc lex.yy.c y.tab.c -o ${OUT_FILE} -ll

y.tab.c: ${YACC_FILE}
	yacc -d ${YACC_FILE}

lex.yy.c: ${INPUT_FILE}
	lex ${LEX_FILE}

run: ${OUTPUT_FILE}
	./${OUT_FILE}

clean:
	rm ${OUT_FILE} lex.yy.c y.tab.c y.tab.h

.PHONY: run clean
