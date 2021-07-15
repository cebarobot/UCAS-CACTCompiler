#pragma once

#include <string>
#include <vector>
#include <map>

#include "IRArgument.h"

enum IROperation {
    PARAM,
    CALL,
    RETURN,
    ASSIGN_INT,
};

class IRCode {
private:
    IROperation operation;
    IRArgument * arg1;
    IRArgument * arg2;
    IRArgument * result;

public:
    IRCode(IROperation new_op, IRArgument * new_arg1, IRArgument * new_arg2, IRArgument * new_result);

    IROperation getOperation();
    IRArgument * getArg1();
    IRArgument * getArg2();
    IRArgument * getResult();

    virtual void print() = 0;
    // virtual void genTargetCode() = 0;
};

class IRParam : public IRCode {
public:
    IRParam(IRArgument * new_arg1);

    virtual void print();
};

class IRCall : public IRCode {
public:
    IRCall(IRArgument * new_arg1, IRArgument * new_arg2, IRArgument * new_result);
    IRCall(IRArgument * new_arg1, IRArgument * new_arg2);

    virtual void print();
};

class IRReturn : public IRCode {
public:
    IRReturn(IRArgument * new_arg1);

    virtual void print();
};

// class IRAddInt : public IRCode {

// };

class IRAssignInt : public IRCode {
public:
    IRAssignInt(IRArgument * new_arg1, IRArgument * new_result);

    virtual void print();
};