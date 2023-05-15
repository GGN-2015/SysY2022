OUT_FILE=example
IN_FILE=example.l

${OUT_FILE}: lex.yy.c
	cc lex.yy.c -o ${OUT_FILE} -ll
lex.yy.c: ${IN_FILE}
	lex ${IN_FILE}
run: ${OUT_FILE}
	./${OUT_FILE}
clean:
	rm ${OUT_FILE} lex.yy.c
.PHONY: run clean
