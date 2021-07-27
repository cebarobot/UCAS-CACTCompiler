#include <iostream>

#include "IRCode.h"


IRCode::IRCode(IROperation new_op, IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: operation(new_op), result(new_result), arg1(new_arg1), arg2(new_arg2) { }

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

IRCall::IRCall(IROperand * new_result, IROperand * new_arg1)
: IRCode(CALL, new_result, new_arg1, nullptr) { }

IRCall::IRCall(IROperand * new_arg1)
: IRCode(CALL, nullptr, new_arg1, nullptr) { }

IRReturn::IRReturn(IROperand * new_arg1)
: IRCode(RETURN, nullptr, new_arg1, nullptr) { }

IRCopyW::IRCopyW(IROperand * new_result, IROperand * new_arg1)
: IRCode(COPY_W, new_result, new_arg1, nullptr) { }

IRCopyD::IRCopyD(IROperand * new_result, IROperand * new_arg1)
: IRCode(COPY_D, new_result, new_arg1, nullptr) { }

IRCopyFromIndexedW::IRCopyFromIndexedW(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(COPY_FROM_INDEXED_W, new_result, new_arg1, new_arg2) { }

IRCopyFromIndexedD::IRCopyFromIndexedD(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(COPY_FROM_INDEXED_D, new_result, new_arg1, new_arg2) { }

IRCopyToIndexedW::IRCopyToIndexedW(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(COPY_TO_INDEXED_W, new_result, new_arg1, new_arg2) { }

IRCopyToIndexedD::IRCopyToIndexedD(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(COPY_TO_INDEXED_D, new_result, new_arg1, new_arg2) { }

IRAddInt::IRAddInt(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(ADD_INT, new_result, new_arg1, new_arg2) { }

IRSubInt::IRSubInt(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(SUB_INT, new_result, new_arg1, new_arg2) { }

IRNegInt::IRNegInt(IROperand * new_result, IROperand * new_arg1)
: IRCode(NEG_INT, new_result, new_arg1, nullptr) { }

IRMulInt::IRMulInt(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(MUL_INT, new_result, new_arg1, new_arg2) { }

IRDivInt::IRDivInt(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(DIV_INT, new_result, new_arg1, new_arg2) { }

IRModInt::IRModInt(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(DIV_INT, new_result, new_arg1, new_arg2) { }

IRIfGreaterThanZeroGoto::IRIfGreaterThanZeroGoto(IROperand * new_result, IROperand * new_arg1)
: IRCode(IF_GREATER_THAN_ZERO_GOTO, new_result, new_arg1, nullptr) { }

IRIfGreaterThanGoto::IRIfGreaterThanGoto(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(IF_GREATER_THAN_GOTO, new_result, new_arg1, new_arg2) { }

IRIfGreaterEqualThanGoto::IRIfGreaterEqualThanGoto(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(IF_GREATER_EQUAL_THAN_GOTO, new_result, new_arg1, new_arg2) { }

IRIfLessThanGoto::IRIfLessThanGoto(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(IF_LESS_THAN_GOTO, new_result, new_arg1, new_arg2) { }

IRIfLessEqualThanGoto::IRIfLessEqualThanGoto(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(IF_LESS_EQUAL_THAN_GOTO, new_result, new_arg1, new_arg2) { }

void IRLabelHere::print() {
    std::cout << getArg1()->getName() << ":" << std::endl;
}

void IRParam::print() {
    std::cout << "param " << getArg1()->getName() << ";" << std::endl;
}

void IRCall::print() {
    if (getResult()) {
        std::cout << getResult()->getName() << " := call " 
                  << getArg1()->getName() << "; " << std::endl;
    } else {
        std::cout << "call " 
                  << getArg1()->getName() << "; " << std::endl;
    }
}

void IRReturn::print() {
    std::cout << "return " << getArg1()->getName() << ";" << std::endl;
}

void IRCopyW::print() {
    std::cout << getResult()->getName() << " := "
              << getArg1()->getName() << ";" << std::endl;
}

void IRCopyD::print() {
    std::cout << getResult()->getName() << " := "
              << getArg1()->getName() << ";" << std::endl;
}

void IRCopyFromIndexedW::print() {
    std::cout << getResult()->getName() << " := "
              << getArg1()->getName() << " [ " 
              << getArg2()->getName() << " ] "
              << ";" << std::endl;
}

void IRCopyFromIndexedD::print() {
    std::cout << getResult()->getName() << " := "
              << getArg1()->getName() << " [ " 
              << getArg2()->getName() << " ] "
              << ";" << std::endl;
}

void IRCopyToIndexedW::print() {
    std::cout << getResult()->getName() << " [ "
              << getArg2()->getName() << " ] " 
              << " := "
              << getArg1()->getName() << ";" << std::endl;
}

void IRCopyToIndexedD::print() {
    std::cout << getResult()->getName() << " [ "
              << getArg2()->getName() << " ] " 
              << " := "
              << getArg1()->getName() << ";" << std::endl;
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

void IRNegInt::print() {
    std::cout << getResult()->getName() << " := "
              << " - "
              << getArg1()->getName() << ";" << std::endl;
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

void IRIfGreaterThanGoto::print() {
    std::cout << "if "
              << getArg1()->getName() << " > "
              << getArg2()->getName() 
              << "Goto " << getResult()->getName() << ";" << std::endl;
}

void IRIfGreaterEqualThanGoto::print() {
    std::cout << "if "
              << getArg1()->getName() << " >= "
              << getArg2()->getName() 
              << "Goto " << getResult()->getName() << ";" << std::endl;
}

void IRIfLessThanGoto::print() {
    std::cout << "if "
              << getArg1()->getName() << " < "
              << getArg2()->getName() 
              << "Goto " << getResult()->getName() << ";" << std::endl;
}

void IRIfLessEqualThanGoto::print() {
    std::cout << "if "
              << getArg1()->getName() << " <= "
              << getArg2()->getName() 
              << "Goto " << getResult()->getName() << ";" << std::endl;
}