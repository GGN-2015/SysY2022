[TOC]

## YACC_Grammar

修订历史

| 版本       | 作者              | 备注             |
| ---------- | ----------------- | ---------------- |
| 2023-05-17 | 东北重工业-郭冠男 | 未经过正确性核验 |

由于我们最终使用 yacc/lex 生成抽象语法树，因此我们需要将语法定义为 YACC 中产生式的形式，但官方手册中给出的语法并不符合 YACC 对产生式的要求。在产生式中，全大写的符号表示终极符，非全大写符号表示非终极符。

### 1. CompUnit 编译单元

每个文件是一个编译单元，非空，包含一个或多个**变量/常量定义** `Decl` 或者**函数定义** `FuncDef`：

```c
// 源文件
// 例如：const int x = 0; int main() { return x; }
CompUnit: CompUnitDef
        | CompUnit CompUnitDef

// 变量常量定义或函数定义
// 例如：int main() { return 0; }
CompUnitDef: Decl
           | FuncDef
```

`Decl` 定义参见 CH-2，`FuncDef` 定义参见 CH-3。

### 2. Decl 变量/常量定义

```c
Decl: ConstDecl
    | VarDecl

// 常量定义语句
// 例如：const float x = 5.0, y = 4.0, z[2][3] = {{1, 2, 3}, {4, 5, 6}};
ConstDecl: KEYWORD_CONST BType ConstDefList SEMICOLON

// 基础数据类型 int/float
BType: KEYWORD_INT
     | KEYWORD_FLOAT

// 常量定义序列（非空）
// 例如：x = 5.0, y = 4.0, z[2] = {1, 2}
ConstDefList: ConstDef
            | ConstDefList COMMA ConstDef

// 常量定义单元
// 例如：z[2][3] = {{1, 2, 3}, {4, 5, 6}}
ConstDef: IDENTIFIER ArrayIndexList EQUAL InitVal

// 数组下标序列（可以为空）
// 例如：[2][3]
ArrayIndexList: /* empty */
              | ArrayIndexList LBRACKET Exp RBRACKET

// 变量初始值
// 例如：{{1, 2, 3}, {4, 5, 6}}
InitVal: Exp
       | LBRACE InitValList RBRACE

// 变量初始值序列（非空）
// 例如：{1, 2, 3}, {4, 5, 6}
InitValList: InitVal
           | InitValList COMMA InitVal

// 变量定义语句
// 例如：int a, b = 1;
VarDecl: BType VarDefList SEMICOLON

// 变量定义序列（非空）
// 例如：a, b = 1
VarDefList: VarDef
          | VarDefList COMMA VarDef

// 变量定义单元
// 例如：b = 1
VarDef: IDENTIFIER ArrayIndexList
      | IDENTIFIER ArrayIndexList EQUAL InitVal
```

`Exp` 定义参见 CH-5。

### 3. FuncDef 函数定义

`LPARA` 和 `RPARA` 分别表示左圆括号和右圆括号。

```c
// 函数定义
// 例如：float f(int x, float y) { return x + y; }
FuncDef: FuncType IDENTIFIER LPARA             RPARA Block
       | FuncType IDENTIFIER LPARA FuncFParams RPARA Block 

// 函数返回值类型：void, int, float
FuncType: KEYWORD_VOID
        | KEYWORD_INT
        | KEYWORD_FLOAT

// 函数形参列表（非空）
// 例如：int x, float y[][2]
FuncFParams: FuncFParam
           | FuncFParams COMMA FuncFParam

// 单个函数形参描述
// 例如：float y[][2]
FuncFParam: BType IDENTIFIER FuncFParamArrayIndexList

// 函数参数中的中括号表达式
// 例如：[][2]
FuncFParamArrayIndexList: LBRACKET RBRACKET
                        | FuncFParamArrayIndexList LBRACKET Exp RBRACKET
```

`Exp` 定义参见 CH-5，`Block` 定义详见 CH-4。

### 4. Block 语句块定义

```c
// 语句块
// 例如：{ int x = 3; return 0; }
Block: LBRACE BlockItemList RBRACE

// 定义或语句序列
// 例如：int x = 3; return 0;
BlockItemList: /* empty */
             | BlockItemList BlockItem

// 定义或语句
// 例如：int x = 3;
BlockItem: Decl
         | Stmt

// 语句
// 例如：return 0;
Stmt: LVal EQUAL Exp SEMICOLON
    | Block
    | KEYWORD_IF           LPARA Cond RPARA Stmt
    | KEYWORD_IF           LPARA Cond RPARA Stmt KEYWORD_ELSE Stmt
    | KEYWORD_WHILE        LPARA Cond RPARA Stmt
    | KEYWORD_BREAK        SEMICOLON
    | KEYWORD_CONTINUE     SEMICOLON
    | KEYWORD_RETURN       SEMICOLON
    | KEYWORD_RETURN   Exp SEMICOLON
```

`Decl` 定义详见 CH-2，`Exp` 定义参见 CH-5，`Cond` 定义详见 CH-5。

### 5. Exp 表达式定义

```c
// 表达式（计算结果为 int 或者 float）
// 例如：x + y
Exp: AddExp

// 条件表达式
// 例如 x != y
Cond: LOrExp

// 左值表达式
// 例如：x[2][3]
LVal: IDENTIFIER ArrayIndexList

// 基本表达式
// 例如：(x + y)
PrimaryExp: LPARA Exp RPARA
          | LVal
          | Number

// 数值
// 例如：3.72
Number: INT_CONST
      | FLOAT_CONST

// 单目运算表达式
// 例如：-x
UnaryExp: PrimaryExp
        | IDENTIFIER LPARA             RPARA
        | IDENTIFIER LPARA FuncRParams RPARA
        | UnaryOp    UnaryExp

// 函数实参列表（非空）
// 例如：x, y[2]
FuncRParams: Exp
           | FuncRParams Exp

// 乘除模表达式
// 例如：x * (y + z) % 5
MulExp: UnaryExp
      | MulExp MulOp UnaryExp

// 乘除模运算符
// 例如：*
MulOp: OPE_MUL
     | OPE_DIV
     | OPE_MOD

// 加减表达式
// 例如：x + y * z
AddExp: MulExp
      | AddExp AddOp MulExp

// 加减运算符
// 例如：+
AddOp: OPE_ADD
     | OPE_SUB

// 比较大小表达式
// 例如：x <= y + 5
RelExp: AddExp
      | RelExp RelOp AddExp

// 比较大小运算符
// 例如：>=
RelOp: OPE_LSS
     | OPE_LEQ
     | OPE_GTR
     | OPE_GEQ

// 判等表达式
// 例如: 1 != x <= y
EqExp: RelExp
     | EqExp EqOp RelExp

// 判等运算符
// 例如：==
EqOp: OPE_EQU
    | OPE_NEQ

// 逻辑与表达式
// 例如 x && y == z
LAndExp: EqExp
       | LAndExp OPE_AND EqExp

// 逻辑或表达式
// 逻辑：x || y && z == 1
LOrExp: LAndExp
      | LOrExp OPE_OR LAndExp
```

