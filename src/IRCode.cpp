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

IRLabelHere::IRLabelHere(IROperand * new_arg1)
: IRCode(LABEL_HERE, nullptr, new_arg1, nullptr) { }

IRParam::IRParam(IROperand * new_arg1)
: IRCode(PARAM, nullptr, new_arg1, nullptr) { }

IRCall::IRCall(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(CALL, new_result, new_arg1, new_arg2) { }

IRCall::IRCall(IROperand * new_arg1, IROperand * new_arg2)
: IRCode(CALL, new_arg1, new_arg2, nullptr) { }

IRReturn::IRReturn(IROperand * new_arg1)
: IRCode(RETURN, nullptr, new_arg1, nullptr) { }

IRCopyW::IRCopyW(IROperand * new_result, IROperand * new_arg1)
: IRCode(COPY_W, new_result, new_arg1, nullptr) { }

IRCopyD::IRCopyD(IROperand * new_result, IROperand * new_arg1)
: IRCode(COPY_D, new_result, new_arg1, nullptr) { }

IRAddInt::IRAddInt(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(ADD_INT, new_result, new_arg1, new_arg2) { }

IRSubInt::IRSubInt(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(SUB_INT, new_result, new_arg1, new_arg2) { }

IRMulInt::IRMulInt(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(MUL_INT, new_result, new_arg1, new_arg2) { }

IRDivInt::IRDivInt(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(DIV_INT, new_result, new_arg1, new_arg2) { }

IRModInt::IRModInt(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(DIV_INT, new_result, new_arg1, new_arg2) { }

IRIfGreaterThanZeroGoto::IRIfGreaterThanZeroGoto(IROperand * new_result, IROperand * new_arg1)
: IRCode(DIV_INT, new_result, new_arg1, nullptr) { }

void IRLabelHere::print() {
    std::cout << getArg1()->getName() << ":" << std::endl;
}

void IRParam::print() {
    std::cout << "param " << getArg1()->getName() << ";" << std::endl;
}

void IRCall::print() {
    if (getResult()) {
        std::cout << getResult()->getName() << " := call " 
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

void IRAddInt::print() {
    std::cout << getResult()->getName() << " := "
              << getArg1()->getName() << " + "
              << getArg2()->getName() << ";" << std::endl;
}

void IRSubInt::print() {
    std::cout << getResult()->getName() << " := "
              << getArg1()->getName() << " - "
              << getArg2()->getName() << ";" << std::endl;
}

void IRMulInt::print() {
    std::cout << getResult()->getName() << " := "
              << getArg1()->getName() << " * "
              << getArg2()->getName() << ";" << std::endl;
}

void IRDivInt::print() {
    std::cout << getResult()->getName() << " := "
              << getArg1()->getName() << " / "
              << getArg2()->getName() << ";" << std::endl;
}

void IRModInt::print() {
    std::cout << getResult()->getName() << " := "
              << getArg1()->getName() << " % "
              << getArg2()->getName() << ";" << std::endl;
}

void IRIfGreaterThanZeroGoto::print() {
    std::cout << "If "
              << getArg1()->getName() << " >= 0 "
              << "Goto " << getResult()->getName() << ";" << std::endl;
}