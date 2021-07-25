#pragma once

#include <string>
#include <vector>
#include <map>

#include "IROperand.h"

enum IROperation {
    PARAM,
    CALL,
    RETURN,
    ASSIGN_INT,
};

class IRCode {
private:
    IROperation operation;
    IROperand * arg1;
    IROperand * arg2;
    IROperand * result;

public:
    IRCode(IROperation new_op, IROperand * new_arg1, IROperand * new_arg2, IROperand * new_result);

    IROperation getOperation();
    IROperand * getArg1();
    IROperand * getArg2();
    IROperand * getResult();

    virtual void print() = 0;
    // virtual void genTargetCode() = 0;
};

class IRParam : public IRCode {
public:
    IRParam(IROperand * new_arg1);

    virtual void print();
};

class IRCall : public IRCode {
public:
    IRCall(IROperand * new_arg1, IROperand * new_arg2, IROperand * new_result);
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

class IRAssignInt : public IRCode {
public:
    IRAssignInt(IROperand * new_arg1, IROperand * new_result);

    virtual void print();
};