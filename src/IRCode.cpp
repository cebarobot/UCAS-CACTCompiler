#include <iostream>

#include "IRCode.h"


IRCode::IRCode(IROperation new_op, IRArgument * new_arg1, IRArgument * new_arg2, IRArgument * new_result)
: operation(new_op), arg1(new_arg1), arg2(new_arg2), result(new_result) { }

IROperation IRCode::getOperation() {
    return operation;
}

IRArgument * IRCode::getArg1() {
    return arg1;
}

IRArgument * IRCode::getArg2() {
    return arg2;
}

IRArgument * IRCode::getResult() {
    return result;
}

IRParam::IRParam(IRArgument * new_arg1)
: IRCode(PARAM, new_arg1, nullptr, nullptr) { }

IRCall::IRCall(IRArgument * new_arg1, IRArgument * new_arg2, IRArgument * new_result)
: IRCode(CALL, new_arg1, new_arg2, new_result) { }

IRCall::IRCall(IRArgument * new_arg1, IRArgument * new_arg2)
: IRCode(CALL, new_arg1, new_arg2, nullptr) { }

IRReturn::IRReturn(IRArgument * new_arg1)
: IRCode(RETURN, new_arg1, nullptr, nullptr) { }

IRAssignInt::IRAssignInt(IRArgument * new_arg1, IRArgument * new_result)
: IRCode(ASSIGN_INT, new_arg1, nullptr, new_result) { }

void IRParam::print() {
    std::cout << "param " << getArg1()->getValue() << ";" << std::endl;
}

void IRCall::print() {
    if (getResult()) {
        std::cout << getResult()->getValue() << " = call " 
                  << getArg1()->getValue() << ", " 
                  << getArg2()->getValue() << "; " << std::endl;
    } else {
        std::cout << "call " 
                  << getArg1()->getValue() << ", " 
                  << getArg2()->getValue() << "; " << std::endl;
    }
}

void IRReturn::print() {
    std::cout << "return " << getArg1()->getValue() << ";" << std::endl;
}

void IRAssignInt::print() {
    std::cout << getResult()->getValue() << " = " << getArg1()->getValue() << ";" << std::endl;
}