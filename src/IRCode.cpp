#include <iostream>

#include "IRCode.h"


IRCode::IRCode(IROperation new_op, IROperand * new_arg1, IROperand * new_arg2, IROperand * new_result)
: operation(new_op), arg1(new_arg1), arg2(new_arg2), result(new_result) { }

IROperation IRCode::getOperation() {
    return operation;
}

IROperand * IRCode::getArg1() {
    return arg1;
}

IROperand * IRCode::getArg2() {
    return arg2;
}

IROperand * IRCode::getResult() {
    return result;
}

IRParam::IRParam(IROperand * new_arg1)
: IRCode(PARAM, new_arg1, nullptr, nullptr) { }

IRCall::IRCall(IROperand * new_arg1, IROperand * new_arg2, IROperand * new_result)
: IRCode(CALL, new_arg1, new_arg2, new_result) { }

IRCall::IRCall(IROperand * new_arg1, IROperand * new_arg2)
: IRCode(CALL, new_arg1, new_arg2, nullptr) { }

IRReturn::IRReturn(IROperand * new_arg1)
: IRCode(RETURN, new_arg1, nullptr, nullptr) { }

IRAssignInt::IRAssignInt(IROperand * new_arg1, IROperand * new_result)
: IRCode(ASSIGN_INT, new_arg1, nullptr, new_result) { }

void IRParam::print() {
    std::cout << "param " << getArg1()->getName() << ";" << std::endl;
}

void IRCall::print() {
    if (getResult()) {
        std::cout << getResult()->getName() << " = call " 
                  << getArg1()->getName() << ", " 
                  << getArg2()->getName() << "; " << std::endl;
    } else {
        std::cout << "call " 
                  << getArg1()->getName() << ", " 
                  << getArg2()->getName() << "; " << std::endl;
    }
}

void IRReturn::print() {
    std::cout << "return " << getArg1()->getName() << ";" << std::endl;
}

void IRAssignInt::print() {
    std::cout << getResult()->getName() << " = " << getArg1()->getName() << ";" << std::endl;
}