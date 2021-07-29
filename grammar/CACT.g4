grammar CACT;

// The language generated
options {
    language = Cpp;
}

@header {
    #include <vector>
    #include <string>
    #include "../src/CACT.h"
    #include "../src/symbolTable.h"
    #include "../src/IR.h"
}

/********** Parser **********/
compUnit
    : (decl | funcDef)* EOF
    ;

bType
    locals [
        DataType bDataType
    ]
    : 'int'
    | 'bool'
    | 'double'
    | 'float'
    ;

decl
    : constDecl
    | varDecl
    ;

constDecl
    : 'const' bType constDef (',' constDef)* ';'
    ;

constDef
    locals[
        SymbolInfo * thisSymbolInfo
    ]
    : Ident                  '=' constExp           #constDefBasic
    | Ident '[' IntConst ']' '=' constArrExp        #constDefArray
    ;

varDecl
    : bType varDef (',' varDef)* ';'
    ;

varDef
    locals[
        SymbolInfo * thisSymbolInfo
    ]
    : Ident                  ('=' constExp)?        #varDefBasic
    | Ident '[' IntConst ']' ('=' constArrExp)?     #varDefArray
    ;

funcDef
    locals[
        FuncSymbolInfo * thisFuncInfo
    ]
    : funcType Ident '(' (funcFParams)? ')' block
    ;

funcType
    : 'void'
    | 'int'
    | 'float'
    | 'double'
    | 'bool'
    ;

funcFParams
    locals[
        FuncSymbolInfo * thisFuncInfo
    ]
    : funcFParam (',' funcFParam)*
    ;

funcFParam
    locals[
        DataType bDataType
    ]
    : bType Ident (ArraySymbol)?
    ;

block
    locals[
        FuncSymbolInfo * thisFuncInfo
    ]
    : '{' (blockItem)* '}'
    ;

blockItem
    : decl 
    | stmt
    ;

stmt
    locals[
        IRLabel * flowNext = nullptr,
        IRLabel * flowEnd = nullptr,
        std::vector<IRCode *> codeBefore,
    ]
    : lVal '=' exp ';'                          #stmtAssign
    | (exp)? ';'                                #stmtExp
    | block                                     #stmtBlock
    | 'if' '(' cond ')' stmt                    #stmtCtrlIf
    | 'if' '(' cond ')' stmt ('else' stmt)?     #stmtCtrlIfElse
    | 'while' '(' cond ')' stmt                 #stmtCtrlWhile
    | 'break' ';'                               #stmtCtrlBreak
    | 'continue' ';'                            #stmtCtrlContinue
    | 'return' (exp)? ';'                       #stmtReturn
    ;

exp
    locals[
        bool isArray,
        int arraySize,
        DataType dataType,
        IROperand * result
    ]
    : addExp                    #expAddExp
    | boolVal                   #expBoolConst
    ;

cond
    locals[
        IRLabel * flowTrue = nullptr,
        IRLabel * flowFalse = nullptr,
        DataType dataType,
        IROperand * result
    ]
    : lOrExp
    ;

primaryExp
    locals[
        bool isArray,
        int arraySize,
        DataType dataType,
        IROperand * result
    ]
    : '(' exp ')'               #primaryExpExp
    | rVal                      #primaryExpRVal
    | numVal                    #primaryNumVal
    ;

unaryExp
    locals[
        bool isArray,
        int arraySize,
        DataType dataType,
        IROperand * result
    ]
    : primaryExp                #unaryExpPrimaryExp
    | funcVal                   #unaryExpFunc
    | unaryOp unaryExp          #unaryExpUnaryOp
    ;

unaryOp
    : '+'
    | '-'
    | '!'
    ;

mulExp
    locals[
        bool isArray,
        int arraySize,
        DataType dataType,
        IROperand * result
    ]
    : unaryExp                  #mulExpUnaryExp
    | mulExp mulOp unaryExp     #mulExpMulExp
    ;

mulOp
    : '*'
    | '/'
    | '%'
    ;

addExp
    locals[
        bool isArray,
        int arraySize,
        DataType dataType,
        IROperand * result
    ]
    : mulExp                    #addExpMulExp
    | addExp addOp mulExp       #addExpAddExp
    ;

addOp
    : '+'
    | '-'
    ;

relExp
    locals[
        IRLabel * flowTrue = nullptr,
        IRLabel * flowFalse = nullptr,
        bool isArray,
        int arraySize,
        DataType dataType,
        IROperand * result
    ]
    : addExp                    #relExpAddExp
    | relExp relOp addExp       #relExpRelExp
    | boolVal                   #relExpBoolVal
    ;

relOp
    : '<'
    | '>'
    | '<='
    | '>='
    ;

eqExp
    locals[
        std::vector<IRCode *> codeBefore,
        IRLabel * flowTrue = nullptr,
        IRLabel * flowFalse = nullptr,
        bool isArray,
        int arraySize,
        DataType dataType,
        IROperand * result
    ]
    : relExp                    #eqExpRelExp
    | eqExp eqOp relExp         #eqExpEqExp
    ;

eqOp
    : '=='
    | '!='
    ;

lAndExp
    locals[
        std::vector<IRCode *> codeBefore,
        IRLabel * label = nullptr;
        IRLabel * flowTrue = nullptr,
        IRLabel * flowFalse = nullptr,
        bool isArray,
        int arraySize,
        DataType dataType,
        IROperand * result
    ]
    : eqExp                     #lAndExpEqExp
    | lAndExp '&&' eqExp        #lAndExpLAndExp
    ;

lOrExp
    locals[
        IRLabel * flowTrue = nullptr,
        IRLabel * flowFalse = nullptr,
        bool isArray,
        int arraySize,
        DataType dataType,
        IROperand * result
    ]
    : lAndExp                   #lOrExpLAndExp
    | lOrExp '||' lAndExp       #lOrExpLOrExp
    ;

constArrExp
    locals[
        bool isArray,
        int arraySize,
        DataType dataType,
        IRValue * result
    ]
    : '{' (constExp (',' constExp)*)? '}'
    ;

constExp
    locals[
        bool isArray,
        int arraySize,
        DataType dataType,
        IRValue * result
    ]
    : numVal                    #constExpNumVal
    | boolVal                   #constExpBoolVal
    ;

numVal
    locals[
        bool isArray,
        int arraySize,
        DataType dataType,
        IRValue * result
    ]
    : IntConst                  #numValIntConst
    | DoubleConst               #numValDoubleConst
    | FloatConst                #numValFloatConst
    ;

boolVal
    locals[
        bool isArray,
        int arraySize,
        DataType dataType,
        IRValue * result
    ]
    : BoolConst
    ;

lVal
    locals[
        bool isArray,
        int arraySize,
        DataType dataType,
        IROperand * result,
        IROperand * index,
        SymbolInfo * thisSymbol
    ]
    : Ident                     #lValBasic
    | Ident '[' exp ']'         #lValIndexed
    ;

rVal
    locals[
        bool isArray,
        int arraySize,
        DataType dataType,
        IROperand * result, 
        SymbolInfo * thisSymbol
    ]
    : Ident                     #rValBasic
    | Ident '[' exp ']'         #rValIndexed
    ;

funcVal
    locals[
        bool isArray,
        int arraySize,
        DataType dataType,
        IROperand * result,
        FuncSymbolInfo * thisFunc,
    ]
    : Ident '(' (funcRParams)? ')'
    ;

funcRParams
    locals[
        FuncSymbolInfo * thisFunc
    ]
    : exp (',' exp)*
    ;

/********** Lexer **********/

// /** keywords */
// BREAK       : 'break';
// CONTINUE    : 'continue';
// IF          : 'if';
// ELSE        : 'else';
// WHILE       : 'while';
// RETURN      : 'return';
// TRUE        : 'true';
// FALSE       : 'false';
// VOID        : 'void';
// BOOL        : 'bool';
// INT         : 'int';
// FLOAT       : 'float';
// DOUBLE      : 'double';
// CONST       : 'const';

BoolConst : 'true' | 'false';

Ident
    : IdentNondigit [a-zA-Z_0-9]*
    ;

fragment
IdentNondigit
    : [a-zA-Z_]
    ;

fragment
Digit
    : [0-9]
    ;

IntConst
    : DecimalConst 
    | OctalConst
    | HexadecimalConst
    ;

fragment
DecimalConst
    : '0'
    | NonzeroDigit Digit*
    ;

fragment
OctalConst
    : '0' OctalDigit+
    ;

fragment
HexadecimalConst
    : HexadecimalPrefix HexadecimalDigit+
    ;

fragment
NonzeroDigit
    : [1-9]
    ;

fragment
OctalDigit
    : [0-7]
    ;

fragment
HexadecimalPrefix
    : '0x'
    | '0X'
    ;

fragment
HexadecimalDigit
    : [0-9a-fA-F]
    ;

FloatConst
    : DoubleConst ('F' | 'f')
    ;

DoubleConst
    : ExpNum
    | NonExpNum
    ;

fragment
ExpNum
    : Base Index
    ;

fragment
Base
    : '.' (Digit)+ 
    | (Digit)+ '.'
    | (Digit)+ '.' (Digit)+
    | (Digit)+
    ;

fragment
Index
    : ('E' | 'e') ('+' | '-')? (Digit)+
    ;

fragment
NonExpNum
    : '.' (Digit)+
    | (Digit)+ '.'
    | (Digit)+ '.' (Digit)+
    ;

ArraySymbol
    : '[' ']'
    ;

NewLine
    : ('\r' '\n'? | '\n') 
      -> skip
    ;

WhiteSpace
    : [ \t]+ 
      -> skip
    ;

BlockComment
    : '/*' .*? '*/'
      -> skip
    ;

LineComment
    : '//' ~[\r\n]*
      -> skip
    ;