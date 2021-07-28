#pragma once

#include <string>
#include <vector>
#include <map>

#include "CACT.h"
#include "IROperand.h"

enum IROperation {
    PARAM_W,
    PARAM_F,
    PARAM_D,
    GET_PARAM_W,
    GET_PARAM_F,
    GET_PARAM_D,
    LABEL_HERE,
    CALL,
    RETURN_W,
    RETURN_F,
    RETURN_D,
    COPY_W,
    COPY_F,
    COPY_D,
    COPY_FROM_INDEXED_W,
    COPY_FROM_INDEXED_F,
    COPY_FROM_INDEXED_D,
    COPY_TO_INDEXED_W,
    COPY_TO_INDEXED_F,
    COPY_TO_INDEXED_D,
    ADD_INT,
    ADD_FLOAT,
    ADD_DOUBEL,
    SUB_INT,
    SUB_FLOAT,
    SUB_DOUBEL,
    NEG_INT,
    NEG_FLOAT,
    NEG_DOUBLE,
    MUL_INT,
    MUL_FLOAT,
    MUL_DOUBLE,
    DIV_INT,
    DIV_FLOAT,
    DIV_DOUBLE,
    MOD_INT,

    IF_GREATER_THAN_ZERO_GOTO,
    IF_GREATER_THAN_GOTO_W,
    IF_GREATER_THAN_GOTO_F,
    IF_GREATER_THAN_GOTO_D,
    IF_GREATER_EQUAL_THAN_GOTO_W,
    IF_GREATER_EQUAL_THAN_GOTO_F,
    IF_GREATER_EQUAL_THAN_GOTO_D,
    IF_LESS_THAN_GOTO_W,
    IF_LESS_THAN_GOTO_F,
    IF_LESS_THAN_GOTO_D,
    IF_LESS_EQUAL_THAN_GOTO_W,
    IF_LESS_EQUAL_THAN_GOTO_F,
    IF_LESS_EQUAL_THAN_GOTO_D,
};

class IRCode {
private:
    IROperation operation;
    IROperand * result;
    IROperand * arg1;
    IROperand * arg2;

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

class IRParamW : public IRCode {
public:
    IRParamW(IROperand * new_arg1);

    virtual void print();
};


class IRParamF : public IRCode {
public:
    IRParamF(IROperand * new_arg1);

    virtual void print();
};

class IRParamD : public IRCode {
public:
    IRParamD(IROperand * new_arg1);

    virtual void print();
};

class IRCall : public IRCode {
public:
    IRCall(IROperand * new_result, IROperand * new_arg1);
    IRCall(IROperand * new_arg1);

    virtual void print();
};

class IRReturnW : public IRCode {
public:
    IRReturnW(IROperand * new_arg1);

    virtual void print();
};

class IRReturnF : public IRCode {
public:
    IRReturnF(IROperand * new_arg1);

    virtual void print();
};

class IRReturnD : public IRCode {
public:
    IRReturnD(IROperand * new_arg1);

    virtual void print();
};

// class IRAddInt : public IRCode {

// };

class IRCopyW : public IRCode {
public:
    IRCopyW(IROperand * new_result, IROperand * new_arg1);

    virtual void print();
};

class IRCopyF : public IRCode {
public:
    IRCopyF(IROperand * new_result, IROperand * new_arg1);

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

class IRCopyFromIndexedF : public IRCode {
public:
    IRCopyFromIndexedF(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

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

class IRCopyToIndexedF : public IRCode {
public:
    IRCopyToIndexedF(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

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

class IRAddFloat : public IRCode {
public:
    IRAddFloat(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
};

class IRAddDouble : public IRCode {
public:
    IRAddDouble(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
};
class IRSubInt : public IRCode {
public:
    IRSubInt(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
};

class IRSubFloat : public IRCode {
public:
    IRSubFloat(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
};

class IRSubDouble : public IRCode {
public:
    IRSubDouble(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
};

class IRNegInt : public IRCode {
public:
    IRNegInt(IROperand * new_result, IROperand * new_arg1);

    virtual void print();
};

class IRNegFloat : public IRCode {
public:
    IRNegFloat(IROperand * new_result, IROperand * new_arg1);

    virtual void print();
};

class IRNegDouble : public IRCode {
public:
    IRNegDouble(IROperand * new_result, IROperand * new_arg1);

    virtual void print();
};

class IRMulInt : public IRCode {
public:
    IRMulInt(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
};

class IRMulFloat : public IRCode {
public:
    IRMulFloat(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
};

class IRMulDouble : public IRCode {
public:
    IRMulDouble(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
};

class IRDivInt : public IRCode {
public:
    IRDivInt(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
};

class IRDivFloat : public IRCode {
public:
    IRDivFloat(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
};

class IRDivDouble : public IRCode {
public:
    IRDivDouble(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

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

class IRIfGreaterThanGotoW : public IRCode {
public:
    IRIfGreaterThanGotoW(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
};

class IRIfGreaterThanGotoF : public IRCode {
public:
    IRIfGreaterThanGotoF(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
};

class IRIfGreaterThanGotoD : public IRCode {
public:
    IRIfGreaterThanGotoD(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
};

class IRIfGreaterEqualThanGotoW : public IRCode {
public:
    IRIfGreaterEqualThanGotoW(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
};

class IRIfGreaterEqualThanGotoF : public IRCode {
public:
    IRIfGreaterEqualThanGotoF(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
};

class IRIfGreaterEqualThanGotoD : public IRCode {
public:
    IRIfGreaterEqualThanGotoD(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
};

class IRIfLessThanGotoW : public IRCode {
public:
    IRIfLessThanGotoW(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
};

class IRIfLessThanGotoF : public IRCode {
public:
    IRIfLessThanGotoF(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
};

class IRIfLessThanGotoD : public IRCode {
public:
    IRIfLessThanGotoD(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
};

class IRIfLessEqualThanGotoW : public IRCode {
public:
    IRIfLessEqualThanGotoW(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
};

class IRIfLessEqualThanGotoF : public IRCode {
public:
    IRIfLessEqualThanGotoF(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
};

class IRIfLessEqualThanGotoD : public IRCode {
public:
    IRIfLessEqualThanGotoD(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
};

