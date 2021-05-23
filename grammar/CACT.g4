grammar CACT;

// The language generated
options {
    language = Cpp;
}

@header {
    #include <vector>
    #include <string>
    #include "../src/symbolTable.h"
}

/********** Parser **********/
compUnit
    : (decl | funcDef) (compUnit)* EOF
    ;

decl
    : constDecl
    | varDecl
    ;

constDecl
    : 'const' bType constDef (',' constDef)* ';'
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

constDef
    locals[
        SymbolInfo * thisSymbolInfo
    ]
    : Ident ('[' IntConst ']')? '=' constInitVal
    ;

constInitVal
    locals[
        SymbolInfo * thisSymbolInfo
    ]
    : constExp                                  #constInitValBasic
    | '{' (constExp (',' constExp)*)? '}'       #constInitValArray
    ;

varDecl
    : bType varDef (',' varDef)* ';'
    ;

varDef
    locals[
        SymbolInfo * thisSymbolInfo
    ]
    : Ident ('[' IntConst ']')?
    | Ident ('[' IntConst ']')? '=' constInitVal
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
    : lVal '=' exp ';'
    | (exp)? ';'
    | block
    | 'if' '(' cond ')' stmt ('else' stmt)?
    | 'while' '(' cond ')' stmt
    | 'break' ';' 
    | 'contine' ';'
    | 'return' (exp)? ';'
    ;

exp
    : addExp
    | BoolConst
    ;

cond
    : lOrExp
    ;

lVal
    : Ident ('[' exp ']')?
    ;

primaryExp
    : '(' exp ')' 
    | lVal 
    | number 
    ;

unaryExp
    : primaryExp
    | Ident '(' (funcRParams)? ')'
    | unaryOp unaryExp
    ;

unaryOp
    : '+'
    | '-'
    | '!'
    ;

funcRParams
    : exp (',' exp)*
    ;

mulExp
    : unaryExp 
    | mulExp ('*' | '/' | '%') unaryExp
    ;

addExp
    : mulExp
    | addExp ('+' | '-') mulExp
    ;

relExp
    : addExp
    | relExp ('<' | '>' | '<=' | '>=') addExp
    | BoolConst
    ;

eqExp
    : relExp
    | eqExp ('==' | '!=') relExp
    ;

lAndExp
    : eqExp
    | lAndExp ('&&') eqExp
    ;

lOrExp
    : lAndExp
    | lOrExp ('||') lAndExp
    ;

constExp
    locals[
        DataType dataType,
    ]
    : number            #constExpNumber
    | BoolConst         #constExpBoolConst
    ;

number
    locals[
        DataType dataType,
    ]
    : IntConst          #numberIntConst
    | DoubleConst       #numberDoubleConst
    | FloatConst        #numberFloatConst
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