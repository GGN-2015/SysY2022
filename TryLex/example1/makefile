OUTPUT_FILE=example
INPUT_FILE=example.l

example1: lex.yy.c
	cc lex.yy.c -o ${OUTPUT_FILE} -ll
lex.yy.c: ${INPUT_FILE}
	lex ${INPUT_FILE}
run: ${OUTPUT_FILE}
	./${OUTPUT_FILE}
clean:
	rm ${OUTPUT_FILE} lex.yy.c
.PHONY: run clean
