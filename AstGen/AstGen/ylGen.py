from ylReader import ylReader
from random import randint
import os

# lex 文件前缀
LEX_PREFIX = """
%{
#include <stdio.h>

#define YYSTYPE int
extern int nid;
extern YYSTYPE yylval; // put it before "y.tab.h"

#include "y.tab.h"
%}
"""

# yacc 文件前缀
YACC_PREFIX = """
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
"""

# makefile 文件内容
MAKEFILE = """
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
"""

# 检查符号名称是否合法，符号名称只能由大写字母和下划线构成
def __tokenNameCheck(name: str):
    if name == "": return False # 名字不能为空
    for c in name:
        if c != '_' and not (ord('A') <= ord(c) and ord(c) <= ord('Z')):
            return False
    return True

# 测试
def __test__tokenNameCheck():
    assert __tokenNameCheck("CONST")  == True
    assert __tokenNameCheck("_____")  == True
    assert __tokenNameCheck("H_WORL") == True
    assert __tokenNameCheck("")       == False
    assert __tokenNameCheck("a")      == False
    assert __tokenNameCheck("$")      == False
    assert __tokenNameCheck("aH%")    == False

# 向词法集合中加入一个新的词法
def __addLexical(lexData, line):
    name = line[1]
    if not __tokenNameCheck(name): # 不允许出现非法的词法名字
        return "Token Name Unavailable"
    
    if lexData.get(name) is not None: # 不允许出现重复的词法名字
        return "Token Name Duplicated"
    
    lexData[name] = line[2]
    return "" # No Error

# 检查一个名字是否是合法的非终结符名字
def __syntaxNameCheck(name):
    if name == "": return False # 名字不能为空
    if __tokenNameCheck(name): return False # 名字不能是合法的终结符名字
    for c in name:
        if (c != "_" 
            and not (ord('A') <= ord(c) and ord(c) <= ord('Z'))
            and not (ord('a') <= ord(c) and ord(c) <= ord('z'))
        ):
            return False
    return True

# 测试
def __test__syntaxNameCheck():
    assert __syntaxNameCheck("Add_Exp")  == True
    assert __syntaxNameCheck("ADD_EXP")  == False
    assert __syntaxNameCheck("aH%")      == False

# 向语法集合中加入一个新的语法
def __addSyntax(yaccData, line):
    name = line[1]
    if not __syntaxNameCheck(name): # 不允许出现非法的非终结符名字
        return "Syntax Name Unavailable"
    
    if yaccData.get(name) is None: # 一个非终结符可以有多个定义
        yaccData[name] = []

    yaccData[name].append(line[3:])
    return ""

# 将字符串不足一定的长度
def __fill(s: str, l: int):
    absLen = abs(l)
    if absLen > len(s):
        patch = " " * (absLen - len(s))
    if l > 0: return patch + s
    else:     return s + patch

RND_POOL  = []
RND_POOL += list(map(chr, range(ord('a'), ord('z') + 1)))
RND_POOL += list(map(chr, range(ord('A'), ord('Z') + 1)))
RND_POOL += list(map(chr, range(ord('0'), ord('9') + 1)))
RND_POOL += ["_"]

# 生成随机字符串
def __getRandStr(l: int):
    arr = []
    while len(arr) < l:
        rid = randint(0, len(RND_POOL) - 1)
        arr.append(RND_POOL[rid])
    return "".join(arr)

RND_FLAG_1 = __getRandStr(32) + "_1"
RND_FLAG_2 = __getRandStr(32) + "_2"
RND_FLAG_3 = __getRandStr(32) + "_3"
RND_FLAG_4 = __getRandStr(32) + "_4"

KEYWORD_MATCH_PREFIX_LEN = 8
IDENTIFIER               = "IDENTIFIER"
IDENTIFIER_PATTERN       = "[_a-zA-Z][_a-zA-Z0-9]*"

# 获取词法定义字符串
def __getLexText(lexData, keywordData, ignore_space=True):
    maxNameLen = max(
        [len(name) for name in lexData] + 
        [len(keyword) for keyword in keywordData] + 
        [len(IDENTIFIER)]) + 1
    maxRELen   = max(
        [len(lexData[name]) for name in lexData] + 
        [len(IDENTIFIER_PATTERN)]) + 1

    text = ""
    for name in lexData:
        newLine = (RND_FLAG_1 
            + r' { yylval = ++ nid; printf("%10d ' 
            + RND_FLAG_2 
            + ' %s : ; \\n", nid, yytext); return ' 
            + RND_FLAG_2 
            + ' ; }')
        newLine = newLine.replace(RND_FLAG_1, __fill(lexData[name], -maxRELen))
        newLine = newLine.replace(RND_FLAG_2, __fill(name,        -maxNameLen))
        text   += newLine + "\n"

    # 处理关键字匹配
    if keywordData != {}:
        newLine  = (IDENTIFIER_PATTERN + r"  { yylval = ++ nid; "
                    + 'printf("%10d ", nid); \n' 
                    + (' ' * KEYWORD_MATCH_PREFIX_LEN)
                    + "int typeId = IDENTIFIER; " # 默认类型为标识符
                    + "\n")

        for keyword in keywordData:
            value   = keywordData[keyword]
            lineTmp = ((' ' * KEYWORD_MATCH_PREFIX_LEN) + 'if(0 == strcmp("' 
                + RND_FLAG_1 
                + '", yytext)) { typeId = ' 
                + RND_FLAG_2 + '; printf("' + RND_FLAG_2 + '"); }\n')
            lineTmp = lineTmp.replace(RND_FLAG_1, value).replace(RND_FLAG_2, keyword)
            newLine += lineTmp
        
        newLine += ("\n" + (' ' * KEYWORD_MATCH_PREFIX_LEN) 
                    + 'if(typeId == IDENTIFIER) printf("IDENTIFIER");\n')
        newLine += ((' ' * KEYWORD_MATCH_PREFIX_LEN) 
                    + 'printf(" %s : ; \\n", yytext);\n')
        newLine += (' ' * KEYWORD_MATCH_PREFIX_LEN) + "return typeId; }" 
        text    += newLine + "\n"

    # 忽略空白字符
    if ignore_space:
        text += "[ \\t]+\n"

    return "%%\n" + text + "%%\n"

# 为某一个非终极符生成文法规则
def __genSingleSyntaxText(name, ruleList):
    text = name + "\n"

    for i in range(len(ruleList)):
        lineNow = "    "
        if i == 0: lineNow += ": "
        else:      lineNow += "| "
        ruleNow = ruleList[i]

        lineTmp = ""
        for token in ruleNow:
            lineTmp += token + " "

        lineNow += lineTmp

        # 为文法输出节点信息
        lineCmd  = ('\n        { $$ = ++ nid; printf("%10d ' 
                    + RND_FLAG_1 
                    + ' @format ' 
                    + RND_FLAG_2 +  ' : ' 
                    + RND_FLAG_3 + ' ; \\n", nid' + RND_FLAG_4 +  ' ); }\n')
        lineNow += (lineCmd
                    .replace(RND_FLAG_1, name)
                    .replace(RND_FLAG_2, lineTmp)
                    .replace(RND_FLAG_3, " %d " * len(ruleNow))
                    .replace(RND_FLAG_4, "" if len(ruleNow) == 0 else (
                        ", " + ", ".join([ "$" + str(x) for x in range(1, len(ruleNow) + 1) ])
                    )))

        text += lineNow
    text += ";\n"
    return text

# 获取语法定义字符串
def __getYaccText(lexData, keywordData, yaccData):
    tokenList = "\n%token "
    for name in lexData: tokenList += name + " "

    # 处理关键字匹配
    if keywordData != {}:
        tokenList += "IDENTIFIER "
        for keyword in keywordData: tokenList += keyword + " "

    syntaxText = ""
    for name in yaccData:
        syntaxText += __genSingleSyntaxText(name, yaccData[name]) + "\n"
    
    return tokenList + "\n%%\n" + syntaxText + "\n%%\n"

# 检查文法符号是否出现过
def __checkYaccToken(lexData, keywordData, yaccData):
    for name in yaccData:
        for interp in yaccData[name]:
            for token in interp:
                if (yaccData.get(token) is not None 
                    or lexData.get(token) is not None
                    or (keywordData != {} and token == IDENTIFIER)
                    or (keywordData.get(token) is not None)
                ):
                    pass
                else:
                    return "Syntax Uses Undefined Token"

    return ""

# 检查是否是字母数字下划线
def __checkIdentifierChar(c: str):
    return c == "_" or c.isdigit() or c.isalpha()

# 检查 Keyword 值的合法性
def __keywordValueCheck(value):
    if value == "":
        return False

    # 检查是否存在非法字符
    for c in value:
        if not __checkIdentifierChar(c):
            return False

    # 检查第一个字符是否合法
    if value[0].isdigit():
        return False

    return True

# 增加新的关键字
def __addKeyword(keywordData, line):
    name  = line[1]
    value = line[2]

    if not __tokenNameCheck(name):
        return "Keyword Name Unavailable"

    if keywordData.get(name) is not None:
        return "Keyword Name Duplicated"

    if not __keywordValueCheck(value):
        return "Keyword Value Unavailable"

    keywordData[name] = value
    return ""

# 生成词法定义字符串和，语法定义字符串
def ylGen(text):
    lis, flag = ylReader(text)
    if flag != "": return ("", ""), flag # ylReader Error

    lexData     = {}
    yaccData    = {}
    keywordData = {}
    for line in lis:

        if line[0] == r"%token":
            flag = __addLexical(lexData, line)

        elif line[0] == r"%syntax":
            flag = __addSyntax(yaccData, line)

        elif line[0] == r"%keyword":
            flag = __addKeyword(keywordData, line)

        else:
            flag = "Line Type Error"

        if flag != "": return ("", ""), flag # Error Report

    flag = __checkYaccToken(lexData, keywordData, yaccData)
    if flag != "": return ("", ""), flag

    if keywordData != {} and lexData.get(IDENTIFIER) is not None:
        return ("", ""), "Keyword Mode Should Not Define Token IDENTIFIER"

    return (__getLexText(lexData, keywordData), 
            __getYaccText(lexData, keywordData, yaccData)), "" # No Error

def __test__ylGen():
    correctText = r"""
        %token  NUM   [0-9]+
        %token  LPARE \(
        %token  RPARE \)
        %token  ADD   \+
        %token  SUB   \-
        %token  MUL   \*
        %token  DIV   \/

        %syntax Exp    := AddExp

        %syntax AddExp := MulExp
        %syntax AddExp := AddExp ADD MulExp
        %syntax AddExp := AddExp SUB MulExp

        %syntax MulExp := PrExp
        %syntax MulExp := MulExp MUL PrExp
        %syntax MulExp := MulExp DIV PrExp

        %syntax PrExp  := NUM
        %syntax PrExp  := LPARE AddExp RPARE
    """
    (lex, yacc), flag = ylGen(correctText)
    assert flag == ""
    # print(lex, yacc)

    correctText = r"""
        %token EQUAL \=

        %keyword KEYWORD_INT    int
        %keyword KEYWORD_FLOAT float

        %syntax VarDefine := BType IDENTIFIER EQUAL IDENTIFIER
        %syntax BType     := KEYWORD_INT
        %syntax BType     := KEYWORD_FLOAT
    """
    (lex, yacc), flag = ylGen(correctText)
    assert flag == ""
    # print(lex, yacc)

    (lex, yacc), flag = ylGen(r"%token num [0-9]+")
    assert flag == "Token Name Unavailable"

    (lex, yacc), flag = ylGen("%token NUM [0-9]+ \n %token NUM [0-9]+\.[0-9]*")
    assert flag == "Token Name Duplicated"
    
    (lex, yacc), flag = ylGen(r"%syntax ADD_EXP :=")
    assert flag == "Syntax Name Unavailable"
    
    (lex, yacc), flag = ylGen(r"%syntax $aaADD_EXP :=")
    assert flag == "Syntax Name Unavailable"

    (lex, yacc), flag = ylGen(r"%syntax AddExp := NUM")
    assert flag == "Syntax Uses Undefined Token"

    (lex, yacc), flag = ylGen(r"%keyword abc int")
    assert flag == "Keyword Name Unavailable"

    (lex, yacc), flag = ylGen("%keyword KEY_INT int\n%keyword KEY_INT int")
    assert flag == "Keyword Name Duplicated"

    (lex, yacc), flag = ylGen("%keyword KEY_INT int\n%keyword KEY_FLOAT 3int")
    assert flag == "Keyword Value Unavailable"

    (lex, yacc), flag = ylGen("%keyword KEY_INT int\n%token IDENTIFIER test")
    assert flag == "Keyword Mode Should Not Define Token IDENTIFIER"

# 自动化测试
def __test():
    __test__tokenNameCheck()
    __test__syntaxNameCheck()
    __test__ylGen()

    print(__file__, "[PASSED]")

DIR_NOW   = os.path.dirname(__file__)
DIR_OUT   = os.path.join(DIR_NOW, "output")

# 根据输入 yl 文件的要求生成输出文件
def createOutput(infile):
    lex_file  = os.path.join(DIR_OUT, "example.l")
    yacc_file = os.path.join(DIR_OUT, "example.y")
    makefile  = os.path.join(DIR_OUT, "makefile")

    (lex, yacc), flag = ylGen(open(infile).read())
    if flag != "":
        print("[ERROR] " + flag)
    else:
        # 生成 LEX 文件
        with open(lex_file, "w") as f:
            f.write(LEX_PREFIX + "\n" + lex)

        # 生成 YACC 文件
        with open(yacc_file, "w") as f:
            f.write(YACC_PREFIX + "\n" + yacc)

        # 生成 MAKEFILE
        with open(makefile, "w") as f:
            f.write(MAKEFILE)

if __name__ == "__main__":
    __test()

    testFile = os.path.join(DIR_NOW, "TryGenYL.yl")
    createOutput(testFile)