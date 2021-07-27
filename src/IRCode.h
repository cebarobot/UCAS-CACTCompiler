#pragma once

#include <string>
#include <vector>
#include <map>

#include "CACT.h"
#include "IROperand.h"

enum IROperation {
    PARAM,
    LABEL_HERE,
    CALL,
    RETURN,
    COPY_W,
    COPY_D,
    COPY_FROM_INDEXED_W,
    COPY_FROM_INDEXED_D,
    COPY_TO_INDEXED_W,
    COPY_TO_INDEXED_D,
    ADD_INT,
    SUB_INT,
    MUL_INT,
    DIV_INT,
    MOD_INT,
    IF_GREATER_THAN_ZERO_GOTO,
    IF_GREATER_THAN_GOTO,
    IF_GREATER_EQUAL_THAN_GOTO,
    IF_LESS_THAN_GOTO,
    IF_LESS_EQUAL_THAN_GOTO,
};

class IRCode {
private:
    IROperation operation;
    IROperand * arg1;
    IROperand * arg2;
    IROperand * result;

public:
    IRCode(IROperation new_op, IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    IROperation getOperation();
    IROperand * getArg1();
    IROperand * getArg2();
    IROperand * getResult();

    virtual void print() = 0;
    // virtual void genTargetCode() = 0;
};

class IRLabelHere : public IRCode {
public:
    IRLabelHere(IROperand * new_arg1);

    virtual void print();
};

class IRParam : public IRCode {
public:
    IRParam(IROperand * new_arg1);

    virtual void print();
};

class IRCall : public IRCode {
public:
    IRCall(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);
    IRCall(IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
};

class IRReturn : public IRCode {
public:
    IRReturn(IROperand * new_arg1);

    virtual void print();
};

// class IRAddInt : public IRCode {

// };

class IRCopyW : public IRCode {
public:
    IRCopyW(IROperand * new_result, IROperand * new_arg1);

    virtual void print();
};

class IRCopyD : public IRCode {
public:
    IRCopyD(IROperand * new_result, IROperand * new_arg1);

    virtual void print();
};

class IRCopyFromIndexedW : public IRCode {
public:
    IRCopyFromIndexedW(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
};

class IRCopyFromIndexedD : public IRCode {
public:
    IRCopyFromIndexedD(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
};

class IRCopyToIndexedW : public IRCode {
public:
    IRCopyToIndexedW(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
};

class IRCopyToIndexedD : public IRCode {
public:
    IRCopyToIndexedD(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
};

class IRAddInt : public IRCode {
public:
    IRAddInt(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
};

class IRSubInt : public IRCode {
public:
    IRSubInt(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
};

class IRMulInt : public IRCode {
public:
    IRMulInt(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
};

class IRDivInt : public IRCode {
public:
    IRDivInt(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
};

class IRModInt : public IRCode {
public:
    IRModInt(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
};

class IRIfGreaterThanZeroGoto : public IRCode {
public:
    IRIfGreaterThanZeroGoto(IROperand * new_result, IROperand * new_arg1);

    virtual void print();
};

class IRIfGreaterThanGoto : public IRCode {
public:
    IRIfGreaterThanGoto(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
};

class IRIfGreaterEqualThanGoto : public IRCode {
public:
    IRIfGreaterEqualThanGoto(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
};

class IRIfLessThanGoto : public IRCode {
public:
    IRIfLessThanGoto(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
};

class IRIfLessEqualThanGoto : public IRCode {
public:
    IRIfLessEqualThanGoto(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
};

