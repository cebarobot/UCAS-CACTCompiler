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
    GET_RETURN_W,
    GET_RETURN_F,
    GET_RETURN_D,
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
    GOTO,
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
    virtual void genTargetCode(TargetCodeList * t) = 0;
};

class IRLabelHere : public IRCode {
public:
    IRLabelHere(IROperand * new_arg1);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRParamW : public IRCode {
public:
    IRParamW(IROperand * new_arg1);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRParamF : public IRCode {
public:
    IRParamF(IROperand * new_arg1);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRParamD : public IRCode {
public:
    IRParamD(IROperand * new_arg1);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRGetParamW : public IRCode {
public:
    IRGetParamW(IROperand * new_result);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRGetParamF : public IRCode {
public:
    IRGetParamF(IROperand * new_result);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRGetParamD : public IRCode {
public:
    IRGetParamD(IROperand * new_result);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRCall : public IRCode {
public:
    IRCall(IROperand * new_arg1);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRReturnW : public IRCode {
public:
    IRReturnW(IROperand * new_arg1);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRReturnF : public IRCode {
public:
    IRReturnF(IROperand * new_arg1);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRReturnD : public IRCode {
public:
    IRReturnD(IROperand * new_arg1);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRGetReturnW : public IRCode {
public:
    IRGetReturnW(IROperand * new_result);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRGetReturnF : public IRCode {
public:
    IRGetReturnF(IROperand * new_result);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRGetReturnD : public IRCode {
public:
    IRGetReturnD(IROperand * new_result);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRCopyW : public IRCode {
public:
    IRCopyW(IROperand * new_result, IROperand * new_arg1);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRCopyF : public IRCode {
public:
    IRCopyF(IROperand * new_result, IROperand * new_arg1);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRCopyD : public IRCode {
public:
    IRCopyD(IROperand * new_result, IROperand * new_arg1);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRCopyFromIndexedW : public IRCode {
public:
    IRCopyFromIndexedW(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRCopyFromIndexedF : public IRCode {
public:
    IRCopyFromIndexedF(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRCopyFromIndexedD : public IRCode {
public:
    IRCopyFromIndexedD(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRCopyToIndexedW : public IRCode {
public:
    IRCopyToIndexedW(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRCopyToIndexedF : public IRCode {
public:
    IRCopyToIndexedF(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRCopyToIndexedD : public IRCode {
public:
    IRCopyToIndexedD(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRAddInt : public IRCode {
public:
    IRAddInt(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRAddFloat : public IRCode {
public:
    IRAddFloat(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRAddDouble : public IRCode {
public:
    IRAddDouble(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};
class IRSubInt : public IRCode {
public:
    IRSubInt(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRSubFloat : public IRCode {
public:
    IRSubFloat(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRSubDouble : public IRCode {
public:
    IRSubDouble(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRNegInt : public IRCode {
public:
    IRNegInt(IROperand * new_result, IROperand * new_arg1);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRNegFloat : public IRCode {
public:
    IRNegFloat(IROperand * new_result, IROperand * new_arg1);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRNegDouble : public IRCode {
public:
    IRNegDouble(IROperand * new_result, IROperand * new_arg1);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRMulInt : public IRCode {
public:
    IRMulInt(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRMulFloat : public IRCode {
public:
    IRMulFloat(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRMulDouble : public IRCode {
public:
    IRMulDouble(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRDivInt : public IRCode {
public:
    IRDivInt(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRDivFloat : public IRCode {
public:
    IRDivFloat(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRDivDouble : public IRCode {
public:
    IRDivDouble(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRModInt : public IRCode {
public:
    IRModInt(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRIfGreaterThanZeroGoto : public IRCode {
public:
    IRIfGreaterThanZeroGoto(IROperand * new_result, IROperand * new_arg1);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRIfGreaterThanGotoW : public IRCode {
public:
    IRIfGreaterThanGotoW(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRIfGreaterThanGotoF : public IRCode {
public:
    IRIfGreaterThanGotoF(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRIfGreaterThanGotoD : public IRCode {
public:
    IRIfGreaterThanGotoD(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRIfGreaterEqualThanGotoW : public IRCode {
public:
    IRIfGreaterEqualThanGotoW(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRIfGreaterEqualThanGotoF : public IRCode {
public:
    IRIfGreaterEqualThanGotoF(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRIfGreaterEqualThanGotoD : public IRCode {
public:
    IRIfGreaterEqualThanGotoD(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRIfLessThanGotoW : public IRCode {
public:
    IRIfLessThanGotoW(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRIfLessThanGotoF : public IRCode {
public:
    IRIfLessThanGotoF(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRIfLessThanGotoD : public IRCode {
public:
    IRIfLessThanGotoD(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRIfLessEqualThanGotoW : public IRCode {
public:
    IRIfLessEqualThanGotoW(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRIfLessEqualThanGotoF : public IRCode {
public:
    IRIfLessEqualThanGotoF(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRIfLessEqualThanGotoD : public IRCode {
public:
    IRIfLessEqualThanGotoD(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

class IRGoto : public IRCode {
public:
    IRGoto(IROperand * new_result);

    virtual void print();
    void genTargetCode(TargetCodeList * t);
};

