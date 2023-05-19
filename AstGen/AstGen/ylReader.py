import os
DIRNAME = os.path.dirname(__file__)

TOKEN_DEFINE_LEN      = 3
SYNTAX_DEFINE_MIN_LEN = 3

def __matchPre(s: str, template: str):
    if len(s) < len(template): return False
    return s[:len(template)] == template

def __parseToken(line):
    lis = [x.strip() for x in line.split(" ", TOKEN_DEFINE_LEN) if x.strip() != ""]
    return lis

def __parseSyntax(line):
    lis = [x.strip() for x in line.split() if x.strip() != ""]
    return lis

# ans, flag = ylReader(text)
def ylReader(text):
    ans = []
    for line in text.split('\n'):
        line = line.strip()
        if line == "": continue # jump empty line

        if __matchPre(line, r"%token "):
            lis = __parseToken(line)
            ans.append(lis)
            if len(lis) != TOKEN_DEFINE_LEN:
                return [], "Token Define Len Error"

        elif __matchPre(line, r"%syntax "):
            lis = __parseSyntax(line)
            ans.append(lis)
            if len(lis) < SYNTAX_DEFINE_MIN_LEN:
                return [], "Syntax Define Len Error"
            if lis[2] != ":=":
                return [], "Syntax Define Symbol Error"
            
        else:
            return [], "Line Type Error"
    return ans, ""

def __test():
    # empty string
    ans, flag = ylReader("")
    assert ans == [] and flag == ""

    # normal token
    ans, flag = ylReader(r"%token NUM [0-9]+")
    assert ans == [[r"%token", "NUM", "[0-9]+"]] and flag == ""

    # normal syntax
    ans, flag = ylReader(r"%syntax  AddExp  :=  MulExp  ADD  AddExp")
    assert ans == [[
        r"%syntax", "AddExp", ":=", "MulExp", "ADD", "AddExp"
    ]] and flag == ""

    # empty syntax
    ans, flag = ylReader(r"%syntax  AddExp  :=  ")
    assert ans == [[
        r"%syntax", "AddExp", ":="
    ]] and flag == ""

    # error short token
    ans, flag = ylReader(r"%token  NUM  ")
    assert ans == [] and flag == "Token Define Len Error"

    # error short syntax
    ans, flag = ylReader(r"%syntax  AddExp  ")
    assert ans == [] and flag == "Syntax Define Len Error"

    # error syntax symbol
    ans, flag = ylReader(r"%syntax  AddExp  =")
    assert ans == [] and flag == "Syntax Define Symbol Error"

    print(__file__, "[PASSED]")

if __name__ == "__main__":
    __test()