from ylReader import ylReader
from random import randint

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

# 获取词法定义字符串
def __getLexText(lexData):
    maxNameLen = max([len(name) for name in lexData]) + 1
    maxRELen   = max([len(lexData[name]) for name in lexData]) + 1
    text = ""
    for name in lexData:
        newLine = RND_FLAG_1 + r' { yylval = ++ nid; printf("%10d ' + RND_FLAG_2 + ' %s : ; \\n", nid, yytext); return ' + RND_FLAG_2 + ' ; }'
        newLine = newLine.replace(RND_FLAG_1, __fill(lexData[name], -maxRELen))
        newLine = newLine.replace(RND_FLAG_2, __fill(name,        -maxNameLen))
        text   += newLine + "\n"
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
def __getYaccText(lexData, yaccData):
    tokenList = "\n%token "
    for name in lexData: tokenList += name + " "

    syntaxText = ""
    for name in yaccData:
        syntaxText += __genSingleSyntaxText(name, yaccData[name]) + "\n"
    
    return tokenList + "\n%%\n" + syntaxText + "\n%%\n"

# 检查文法符号是否出现过
def __checkYaccToken(lexData, yaccData):
    for name in yaccData:
        for interp in yaccData[name]:
            for token in interp:
                if yaccData.get(token) is not None or lexData.get(token) is not None:
                    pass
                else:
                    return "Syntax Uses Undefined Token"
    return ""

# 生成词法定义字符串和，语法定义字符串
def ylGen(text):
    lis, flag = ylReader(text)
    if flag != "": return ("", ""), flag # ylReader Error

    lexData  = {}
    yaccData = {}
    for line in lis:

        if line[0] == r"%token":
            flag = __addLexical(lexData, line)

        elif line[0] == r"%syntax":
            flag = __addSyntax(yaccData, line)

        else:
            flag = "Line Type Error"

        if flag != "": return ("", ""), flag # Error Report

    flag = __checkYaccToken(lexData, yaccData)
    if flag != "": return ("", ""), flag

    return (__getLexText(lexData), 
            __getYaccText(lexData, yaccData)), "" # No Error

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

# 自动化测试
def __test():
    __test__tokenNameCheck()
    __test__syntaxNameCheck()
    __test__ylGen()

    print(__file__, "[PASSED]")

if __name__ == "__main__":
    __test()