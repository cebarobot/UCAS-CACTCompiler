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

IRParamW::IRParamW(IROperand * new_arg1)
: IRCode(PARAM_W, nullptr, new_arg1, nullptr) { }

IRParamF::IRParamF(IROperand * new_arg1)
: IRCode(PARAM_F, nullptr, new_arg1, nullptr) { }

IRParamD::IRParamD(IROperand * new_arg1)
: IRCode(PARAM_D, nullptr, new_arg1, nullptr) { }

IRGetParamW::IRGetParamW(IROperand * new_result)
: IRCode(GET_PARAM_W, new_result, nullptr, nullptr) { }

IRGetParamF::IRGetParamF(IROperand * new_result)
: IRCode(GET_PARAM_F, new_result, nullptr, nullptr) { }

IRGetParamD::IRGetParamD(IROperand * new_result)
: IRCode(GET_PARAM_D, new_result, nullptr, nullptr) { }

IRCall::IRCall(IROperand * new_arg1)
: IRCode(CALL, nullptr, new_arg1, nullptr) { }

IRReturnW::IRReturnW(IROperand * new_arg1)
: IRCode(RETURN_W, nullptr, new_arg1, nullptr) { }

IRReturnF::IRReturnF(IROperand * new_arg1)
: IRCode(RETURN_F, nullptr, new_arg1, nullptr) { }

IRReturnD::IRReturnD(IROperand * new_arg1)
: IRCode(RETURN_D, nullptr, new_arg1, nullptr) { }

IRGetReturnW::IRGetReturnW(IROperand * new_result)
: IRCode(GET_RETURN_W, new_result, nullptr, nullptr) { }

IRGetReturnF::IRGetReturnF(IROperand * new_result)
: IRCode(GET_RETURN_F, new_result, nullptr, nullptr) { }

IRGetReturnD::IRGetReturnD(IROperand * new_result)
: IRCode(GET_RETURN_D, new_result, nullptr, nullptr) { }

IRCopyW::IRCopyW(IROperand * new_result, IROperand * new_arg1)
: IRCode(COPY_W, new_result, new_arg1, nullptr) { }

IRCopyF::IRCopyF(IROperand * new_result, IROperand * new_arg1)
: IRCode(COPY_F, new_result, new_arg1, nullptr) { }

IRCopyD::IRCopyD(IROperand * new_result, IROperand * new_arg1)
: IRCode(COPY_D, new_result, new_arg1, nullptr) { }

IRCopyFromIndexedW::IRCopyFromIndexedW(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(COPY_FROM_INDEXED_W, new_result, new_arg1, new_arg2) { }

IRCopyFromIndexedF::IRCopyFromIndexedF(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(COPY_FROM_INDEXED_F, new_result, new_arg1, new_arg2) { }

IRCopyFromIndexedD::IRCopyFromIndexedD(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(COPY_FROM_INDEXED_D, new_result, new_arg1, new_arg2) { }

IRCopyToIndexedW::IRCopyToIndexedW(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(COPY_TO_INDEXED_W, new_result, new_arg1, new_arg2) { }

IRCopyToIndexedF::IRCopyToIndexedF(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(COPY_TO_INDEXED_F, new_result, new_arg1, new_arg2) { }

IRCopyToIndexedD::IRCopyToIndexedD(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(COPY_TO_INDEXED_D, new_result, new_arg1, new_arg2) { }

IRAddInt::IRAddInt(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(ADD_INT, new_result, new_arg1, new_arg2) { }

IRAddFloat::IRAddFloat(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(ADD_FLOAT, new_result, new_arg1, new_arg2) { }

IRAddDouble::IRAddDouble(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(ADD_DOUBEL, new_result, new_arg1, new_arg2) { }

IRSubInt::IRSubInt(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(SUB_INT, new_result, new_arg1, new_arg2) { }

IRSubFloat::IRSubFloat(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(SUB_FLOAT, new_result, new_arg1, new_arg2) { }

IRSubDouble::IRSubDouble(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(SUB_DOUBEL, new_result, new_arg1, new_arg2) { }

IRNegInt::IRNegInt(IROperand * new_result, IROperand * new_arg1)
: IRCode(NEG_INT, new_result, new_arg1, nullptr) { }

IRNegFloat::IRNegFloat(IROperand * new_result, IROperand * new_arg1)
: IRCode(NEG_FLOAT, new_result, new_arg1, nullptr) { }

IRNegDouble::IRNegDouble(IROperand * new_result, IROperand * new_arg1)
: IRCode(NEG_DOUBLE, new_result, new_arg1, nullptr) { }

IRMulInt::IRMulInt(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(MUL_INT, new_result, new_arg1, new_arg2) { }

IRMulFloat::IRMulFloat(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(MUL_FLOAT, new_result, new_arg1, new_arg2) { }

IRMulDouble::IRMulDouble(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(MUL_DOUBLE, new_result, new_arg1, new_arg2) { }

IRDivInt::IRDivInt(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(DIV_INT, new_result, new_arg1, new_arg2) { }

IRDivFloat::IRDivFloat(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(DIV_FLOAT, new_result, new_arg1, new_arg2) { }

IRDivDouble::IRDivDouble(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(DIV_DOUBLE, new_result, new_arg1, new_arg2) { }

IRModInt::IRModInt(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(DIV_INT, new_result, new_arg1, new_arg2) { }

IRNotBool::IRNotBool(IROperand * new_result, IROperand * new_arg1)
: IRCode(DIV_INT, new_result, new_arg1, nullptr) { }

IRIfGreaterThanZeroGoto::IRIfGreaterThanZeroGoto(IROperand * new_result, IROperand * new_arg1)
: IRCode(IF_GREATER_THAN_ZERO_GOTO, new_result, new_arg1, nullptr) { }

IRIfEqualGotoW::IRIfEqualGotoW(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(IF_EQUAL_GOTO_W, new_result, new_arg1, new_arg2) { }

IRIfEqualGotoF::IRIfEqualGotoF(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(IF_EQUAL_GOTO_F, new_result, new_arg1, new_arg2) { }

IRIfEqualGotoD::IRIfEqualGotoD(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(IF_EQUAL_GOTO_D, new_result, new_arg1, new_arg2) { }

IRIfGreaterThanGotoW::IRIfGreaterThanGotoW(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(IF_GREATER_THAN_GOTO_W, new_result, new_arg1, new_arg2) { }

IRIfGreaterThanGotoF::IRIfGreaterThanGotoF(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(IF_GREATER_THAN_GOTO_F, new_result, new_arg1, new_arg2) { }

IRIfGreaterThanGotoD::IRIfGreaterThanGotoD(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(IF_GREATER_THAN_GOTO_D, new_result, new_arg1, new_arg2) { }

IRIfGreaterEqualThanGotoW::IRIfGreaterEqualThanGotoW(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(IF_GREATER_EQUAL_THAN_GOTO_W, new_result, new_arg1, new_arg2) { }

IRIfGreaterEqualThanGotoF::IRIfGreaterEqualThanGotoF(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(IF_GREATER_EQUAL_THAN_GOTO_F, new_result, new_arg1, new_arg2) { }

IRIfGreaterEqualThanGotoD::IRIfGreaterEqualThanGotoD(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(IF_GREATER_EQUAL_THAN_GOTO_D, new_result, new_arg1, new_arg2) { }

IRIfLessThanGotoW::IRIfLessThanGotoW(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(IF_LESS_THAN_GOTO_W, new_result, new_arg1, new_arg2) { }

IRIfLessThanGotoF::IRIfLessThanGotoF(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(IF_LESS_THAN_GOTO_F, new_result, new_arg1, new_arg2) { }

IRIfLessThanGotoD::IRIfLessThanGotoD(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(IF_LESS_THAN_GOTO_D, new_result, new_arg1, new_arg2) { }

IRIfLessEqualThanGotoW::IRIfLessEqualThanGotoW(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(IF_LESS_EQUAL_THAN_GOTO_W, new_result, new_arg1, new_arg2) { }

IRIfLessEqualThanGotoF::IRIfLessEqualThanGotoF(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(IF_LESS_EQUAL_THAN_GOTO_F, new_result, new_arg1, new_arg2) { }

IRIfLessEqualThanGotoD::IRIfLessEqualThanGotoD(IROperand * new_result, IROperand * new_arg1, IROperand * new_arg2)
: IRCode(IF_LESS_EQUAL_THAN_GOTO_D, new_result, new_arg1, new_arg2) { }

IRGoto::IRGoto(IROperand * new_result)
: IRCode(GOTO, new_result, nullptr, nullptr) { }

void IRLabelHere::print() {
    std::cout << getArg1()->getName() << ":" << std::endl;
}

void IRParamW::print() {
    std::cout << "param " << getArg1()->getName() << ";" << std::endl;
}

void IRParamF::print() {
    std::cout << "param " << getArg1()->getName() << ";" << std::endl;
}

void IRParamD::print() {
    std::cout << "param " << getArg1()->getName() << ";" << std::endl;
}

void IRGetParamW::print() {
    std::cout << getResult()->getName() << " = " << " param "
              << ";" << std::endl;
}

void IRGetParamF::print() {
    std::cout << getResult()->getName() << " = " << " param "
              << ";" << std::endl;
}

void IRGetParamD::print() {
    std::cout << getResult()->getName() << " = " << " param "
              << ";" << std::endl;
}

void IRCall::print() {
    std::cout << "call " 
              << getArg1()->getName() << "; " << std::endl;
    
}

void IRReturnW::print() {
    std::cout << "return " << getArg1()->getName() << ";" << std::endl;
}

void IRReturnF::print() {
    std::cout << "return " << getArg1()->getName() << ";" << std::endl;
}

void IRReturnD::print() {
    std::cout << "return " << getArg1()->getName() << ";" << std::endl;
}

void IRGetReturnW::print() {
    std::cout <<  getResult()->getName() << " = " << " return "
              << ";" << std::endl;
}

void IRGetReturnF::print() {
    std::cout <<  getResult()->getName() << " = " << " return "
              << ";" << std::endl;
}

void IRGetReturnD::print() {
    std::cout <<  getResult()->getName() << " = " << " return "
              << ";" << std::endl;
}

void IRCopyW::print() {
    std::cout << getResult()->getName() << " := "
              << getArg1()->getName() << ";" << std::endl;
}

void IRCopyF::print() {
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

void IRCopyFromIndexedF::print() {
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

void IRCopyToIndexedF::print() {
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

void IRAddFloat::print() {
    std::cout << getResult()->getName() << " := "
              << getArg1()->getName() << " + "
              << getArg2()->getName() << ";" << std::endl;
}

void IRAddDouble::print() {
    std::cout << getResult()->getName() << " := "
              << getArg1()->getName() << " + "
              << getArg2()->getName() << ";" << std::endl;
}

void IRSubInt::print() {
    std::cout << getResult()->getName() << " := "
              << getArg1()->getName() << " - "
              << getArg2()->getName() << ";" << std::endl;
}

void IRSubFloat::print() {
    std::cout << getResult()->getName() << " := "
              << getArg1()->getName() << " - "
              << getArg2()->getName() << ";" << std::endl;
}

void IRSubDouble::print() {
    std::cout << getResult()->getName() << " := "
              << getArg1()->getName() << " - "
              << getArg2()->getName() << ";" << std::endl;
}

void IRNegInt::print() {
    std::cout << getResult()->getName() << " := "
              << " - "
              << getArg1()->getName() << ";" << std::endl;
}

void IRNegFloat::print() {
    std::cout << getResult()->getName() << " := "
              << " - "
              << getArg1()->getName() << ";" << std::endl;
}

void IRNegDouble::print() {
    std::cout << getResult()->getName() << " := "
              << " - "
              << getArg1()->getName() << ";" << std::endl;
}

void IRMulInt::print() {
    std::cout << getResult()->getName() << " := "
              << getArg1()->getName() << " * "
              << getArg2()->getName() << ";" << std::endl;
}

void IRMulFloat::print() {
    std::cout << getResult()->getName() << " := "
              << getArg1()->getName() << " * "
              << getArg2()->getName() << ";" << std::endl;
}

void IRMulDouble::print() {
    std::cout << getResult()->getName() << " := "
              << getArg1()->getName() << " * "
              << getArg2()->getName() << ";" << std::endl;
}

void IRDivInt::print() {
    std::cout << getResult()->getName() << " := "
              << getArg1()->getName() << " / "
              << getArg2()->getName() << ";" << std::endl;
}

void IRDivFloat::print() {
    std::cout << getResult()->getName() << " := "
              << getArg1()->getName() << " / "
              << getArg2()->getName() << ";" << std::endl;
}

void IRDivDouble::print() {
    std::cout << getResult()->getName() << " := "
              << getArg1()->getName() << " / "
              << getArg2()->getName() << ";" << std::endl;
}

void IRModInt::print() {
    std::cout << getResult()->getName() << " := "
              << getArg1()->getName() << " % "
              << getArg2()->getName() << ";" << std::endl;
}

void IRNotBool::print() {
    std::cout << getResult()->getName() << " := not"
              << getArg1()->getName() << ";" << std::endl;
}

void IRIfGreaterThanZeroGoto::print() {
    std::cout << "If "
              << getArg1()->getName() << " >= 0 "
              << " Goto " << getResult()->getName() << ";" << std::endl;
}

void IRIfEqualGotoW::print() {
    std::cout << "If "
              << getArg1()->getName() << " == "
              << getArg2()->getName() 
              << " Goto " << getResult()->getName() << ";" << std::endl;
}

void IRIfEqualGotoF::print() {
    std::cout << "If "
              << getArg1()->getName() << " == "
              << getArg2()->getName() 
              << " Goto " << getResult()->getName() << ";" << std::endl;
}

void IRIfEqualGotoD::print() {
    std::cout << "If "
              << getArg1()->getName() << " == "
              << getArg2()->getName() 
              << " Goto " << getResult()->getName() << ";" << std::endl;
}

void IRIfGreaterThanGotoW::print() {
    std::cout << "if "
              << getArg1()->getName() << " > "
              << getArg2()->getName() 
              << " Goto " << getResult()->getName() << ";" << std::endl;
}

void IRIfGreaterThanGotoF::print() {
    std::cout << "if "
              << getArg1()->getName() << " > "
              << getArg2()->getName() 
              << " Goto " << getResult()->getName() << ";" << std::endl;
}

void IRIfGreaterThanGotoD::print() {
    std::cout << "if "
              << getArg1()->getName() << " > "
              << getArg2()->getName() 
              << " Goto " << getResult()->getName() << ";" << std::endl;
}

void IRIfGreaterEqualThanGotoW::print() {
    std::cout << "if "
              << getArg1()->getName() << " >= "
              << getArg2()->getName() 
              << " Goto " << getResult()->getName() << ";" << std::endl;
}

void IRIfGreaterEqualThanGotoF::print() {
    std::cout << "if "
              << getArg1()->getName() << " >= "
              << getArg2()->getName() 
              << " Goto " << getResult()->getName() << ";" << std::endl;
}

void IRIfGreaterEqualThanGotoD::print() {
    std::cout << "if "
              << getArg1()->getName() << " >= "
              << getArg2()->getName() 
              << " Goto " << getResult()->getName() << ";" << std::endl;
}

void IRIfLessThanGotoW::print() {
    std::cout << "if "
              << getArg1()->getName() << " < "
              << getArg2()->getName() 
              << " Goto " << getResult()->getName() << ";" << std::endl;
}

void IRIfLessThanGotoF::print() {
    std::cout << "if "
              << getArg1()->getName() << " < "
              << getArg2()->getName() 
              << " Goto " << getResult()->getName() << ";" << std::endl;
}

void IRIfLessThanGotoD::print() {
    std::cout << "if "
              << getArg1()->getName() << " < "
              << getArg2()->getName() 
              << " Goto " << getResult()->getName() << ";" << std::endl;
}

void IRIfLessEqualThanGotoW::print() {
    std::cout << "if "
              << getArg1()->getName() << " <= "
              << getArg2()->getName() 
              << " Goto " << getResult()->getName() << ";" << std::endl;
}

void IRIfLessEqualThanGotoF::print() {
    std::cout << "if "
              << getArg1()->getName() << " <= "
              << getArg2()->getName() 
              << " Goto " << getResult()->getName() << ";" << std::endl;
}

void IRIfLessEqualThanGotoD::print() {
    std::cout << "if "
              << getArg1()->getName() << " <= "
              << getArg2()->getName() 
              << " Goto " << getResult()->getName() << ";" << std::endl;
}

void IRGoto::print() {
    std::cout << "Goto " << getResult()->getName() << ";" << std::endl;
}

void IRLabelHere::genTargetCode(TargetCodeList * t) {
    t->add(getArg1()->getImme() + std::string(":"));
}

void IRParamW::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, t->getRegParamX());
}

void IRParamF::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, t->getRegParamF());
}

void IRParamD::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, t->getRegParamF());
}

void IRGetParamW::genTargetCode(TargetCodeList * t) {
    getResult()->storeFrom(t, t->getRegGetParamX());
}

void IRGetParamF::genTargetCode(TargetCodeList * t) {
    getResult()->storeFrom(t, t->getRegGetParamF());
}

void IRGetParamD::genTargetCode(TargetCodeList * t) {
    getResult()->storeFrom(t, t->getRegGetParamF());
}

void IRCall::genTargetCode(TargetCodeList * t) {
    t->resetRegParam();
    t->add(std::string("\tcall\t") + getArg1()->getImme());
}

void IRReturnW::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "a0");
}

void IRReturnF::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "fa0");
}

void IRReturnD::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "fa0");
}

void IRGetReturnW::genTargetCode(TargetCodeList * t) {
    getResult()->storeFrom(t, "a0");
}

void IRGetReturnF::genTargetCode(TargetCodeList * t) {
    getResult()->storeFrom(t, "fa0");
}

void IRGetReturnD::genTargetCode(TargetCodeList * t) {
    getResult()->storeFrom(t, "fa0");
}

void IRCopyW::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "t4");
    getResult()->storeFrom(t, "t4");
}

void IRCopyF::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "ft4");
    getResult()->storeFrom(t, "ft4");
}

void IRCopyD::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "ft4");
    getResult()->storeFrom(t, "ft4");
}

void IRCopyFromIndexedW::genTargetCode(TargetCodeList * t) {
    getArg1()->loadAddrTo(t, "t5");
    getArg2()->loadTo(t, "t6");
    t->add(std::string("\tadd\tt5, t5, t6"));
    t->add(std::string("\tlw\tt4, 0(t5)"));
    getResult()->storeFrom(t, "t4");
}

void IRCopyFromIndexedF::genTargetCode(TargetCodeList * t) {
    getArg1()->loadAddrTo(t, "t5");
    getArg2()->loadTo(t, "t6");
    t->add(std::string("\tadd\tt5, t5, t6"));
    t->add(std::string("\tflw\tft4, 0(t5)"));
    getResult()->storeFrom(t, "ft4");
}

void IRCopyFromIndexedD::genTargetCode(TargetCodeList * t) {
    getArg1()->loadAddrTo(t, "t5");
    getArg2()->loadTo(t, "t6");
    t->add(std::string("\tadd\tt5, t5, t6"));
    t->add(std::string("\tfld\tft4, 0(t5)"));
    getResult()->storeFrom(t, "ft4");
}

void IRCopyToIndexedW::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "t4");
    getResult()->loadAddrTo(t, "t5");
    getArg2()->loadTo(t, "t6");
    t->add(std::string("\tadd\tt5, t5, t6"));
    t->add(std::string("\tsw\tt4, 0(t5)"));
}

void IRCopyToIndexedF::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "ft4");
    getResult()->loadAddrTo(t, "t5");
    getArg2()->loadTo(t, "t6");
    t->add(std::string("\tadd\tt5, t5, t6"));
    t->add(std::string("\tfsw\tft4, 0(t5)"));
}

void IRCopyToIndexedD::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "ft4");
    getResult()->loadAddrTo(t, "t5");
    getArg2()->loadTo(t, "t6");
    t->add(std::string("\tadd\tt5, t5, t6"));
    t->add(std::string("\tfsd\tft4, 0(t5)"));
}

void IRAddInt::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "t5");
    getArg2()->loadTo(t, "t6");
    t->add(std::string("\tadd\tt4, t5, t6"));
    getResult()->storeFrom(t, "t4");
}

void IRAddFloat::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "ft5");
    getArg2()->loadTo(t, "ft6");
    t->add(std::string("\tfadd.s\tft4, ft5, ft6"));
    getResult()->storeFrom(t, "ft4");
}

void IRAddDouble::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "ft5");
    getArg2()->loadTo(t, "ft6");
    t->add(std::string("\tfadd.d\tft4, ft5, ft6"));
    getResult()->storeFrom(t, "ft4");
}

void IRSubInt::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "t5");
    getArg2()->loadTo(t, "t6");
    t->add(std::string("\tsub\tt4, t5, t6"));
    getResult()->storeFrom(t, "t4");
}

void IRSubFloat::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "ft5");
    getArg2()->loadTo(t, "ft6");
    t->add(std::string("\tfsub.s\tft4, ft5, ft6"));
    getResult()->storeFrom(t, "ft4");
}

void IRSubDouble::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "ft5");
    getArg2()->loadTo(t, "ft6");
    t->add(std::string("\tfsub.d\tft4, ft5, ft6"));
    getResult()->storeFrom(t, "ft4");
}

void IRNegInt::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "t5");
    t->add(std::string("\tneg\tt4, t5"));
    getResult()->storeFrom(t, "t4");
}

void IRNegFloat::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "ft5");
    t->add(std::string("\tfneg.s\tft4, ft5"));
    getResult()->storeFrom(t, "ft4");
}

void IRNegDouble::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "ft5");
    t->add(std::string("\tfneg.d\tft4, ft5"));
    getResult()->storeFrom(t, "ft4");
}

void IRMulInt::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "t5");
    getArg2()->loadTo(t, "t6");
    t->add(std::string("\tmul\tt4, t5, t6"));
    getResult()->storeFrom(t, "t4");
}

void IRMulFloat::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "ft5");
    getArg2()->loadTo(t, "ft6");
    t->add(std::string("\tfmul.s\tft4, ft5, ft6"));
    getResult()->storeFrom(t, "ft4");
}

void IRMulDouble::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "ft5");
    getArg2()->loadTo(t, "ft6");
    t->add(std::string("\tfmul.d\tft4, ft5, ft6"));
    getResult()->storeFrom(t, "ft4");
}

void IRDivInt::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "t5");
    getArg2()->loadTo(t, "t6");
    t->add(std::string("\tdiv\tt4, t5, t6"));
    getResult()->storeFrom(t, "t4");
}

void IRDivFloat::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "ft5");
    getArg2()->loadTo(t, "ft6");
    t->add(std::string("\tfdiv.s\tft4, ft5, ft6"));
    getResult()->storeFrom(t, "ft4");
}

void IRDivDouble::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "ft5");
    getArg2()->loadTo(t, "ft6");
    t->add(std::string("\tfdiv.d\tft4, ft5, ft6"));
    getResult()->storeFrom(t, "ft4");
}

void IRModInt::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "t5");
    getArg2()->loadTo(t, "t6");
    t->add(std::string("\trem\tt4, t5, t6"));
    getResult()->storeFrom(t, "t4");
}

void IRNotBool::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "t5");
    t->add(std::string("\tnot\tt4, t5"));
    getResult()->storeFrom(t, "t4");
}

void IRIfGreaterThanZeroGoto::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "t5");
    t->add(std::string("\tbgtz\tt5, ") + getResult()->getImme());
}

void IRIfEqualGotoW::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "t5");
    getArg2()->loadTo(t, "t6");
    t->add(std::string("\tbeq\tt5, t6, ") + getResult()->getImme());
}

void IRIfEqualGotoF::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "ft5");
    getArg2()->loadTo(t, "ft6");
    t->add(std::string("\tfeq.s\tt4, ft5, ft6") + getResult()->getImme());
    t->add(std::string("\tbnez\tt4, ") + getResult()->getImme());
}

void IRIfEqualGotoD::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "ft5");
    getArg2()->loadTo(t, "ft6");
    t->add(std::string("\tfeq.d\tt4, ft5, ft6") + getResult()->getImme());
    t->add(std::string("\tbnez\tt4, ") + getResult()->getImme());
}

void IRIfGreaterThanGotoW::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "t5");
    getArg2()->loadTo(t, "t6");
    t->add(std::string("\tbgt\tt5, t6, ") + getResult()->getImme());
}

void IRIfGreaterThanGotoF::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "ft5");
    getArg2()->loadTo(t, "ft6");
    t->add(std::string("\tfgt.s\tt4, ft5, ft6") + getResult()->getImme());
    t->add(std::string("\tbnez\tt4, ") + getResult()->getImme());
}

void IRIfGreaterThanGotoD::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "ft5");
    getArg2()->loadTo(t, "ft6");
    t->add(std::string("\tfgt.d\tt4, ft5, ft6") + getResult()->getImme());
    t->add(std::string("\tbnez\tt4, ") + getResult()->getImme());
}

void IRIfGreaterEqualThanGotoW::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "t5");
    getArg2()->loadTo(t, "t6");
    t->add(std::string("\tbge\tt5, t6, ") + getResult()->getImme());
}

void IRIfGreaterEqualThanGotoF::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "ft5");
    getArg2()->loadTo(t, "ft6");
    t->add(std::string("\tfge.s\tt4, ft5, ft6") + getResult()->getImme());
    t->add(std::string("\tbnez\tt4, ") + getResult()->getImme());
}

void IRIfGreaterEqualThanGotoD::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "ft5");
    getArg2()->loadTo(t, "ft6");
    t->add(std::string("\tfge.d\tt4, ft5, ft6") + getResult()->getImme());
    t->add(std::string("\tbnez\tt4, ") + getResult()->getImme());
}

void IRIfLessThanGotoW::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "t5");
    getArg2()->loadTo(t, "t6");
    t->add(std::string("\tblt\tt5, t6, ") + getResult()->getImme());
}

void IRIfLessThanGotoF::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "ft5");
    getArg2()->loadTo(t, "ft6");
    t->add(std::string("\tflt.s\tt4, ft5, ft6") + getResult()->getImme());
    t->add(std::string("\tbnez\tt4, ") + getResult()->getImme());
}

void IRIfLessThanGotoD::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "ft5");
    getArg2()->loadTo(t, "ft6");
    t->add(std::string("\tflt.d\tt4, ft5, ft6") + getResult()->getImme());
    t->add(std::string("\tbnez\tt4, ") + getResult()->getImme());
}

void IRIfLessEqualThanGotoW::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "t5");
    getArg2()->loadTo(t, "t6");
    t->add(std::string("\tble\tt5, t6, ") + getResult()->getImme());
}

void IRIfLessEqualThanGotoF::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "ft5");
    getArg2()->loadTo(t, "ft6");
    t->add(std::string("\tfle.s\tt4, ft5, ft6") + getResult()->getImme());
    t->add(std::string("\tbnez\tt4, ") + getResult()->getImme());
}

void IRIfLessEqualThanGotoD::genTargetCode(TargetCodeList * t) {
    getArg1()->loadTo(t, "ft5");
    getArg2()->loadTo(t, "ft6");
    t->add(std::string("\tfle.d\tt4, ft5, ft6") + getResult()->getImme());
    t->add(std::string("\tbnez\tt4, ") + getResult()->getImme());
}

void IRGoto::genTargetCode(TargetCodeList * t) {
    t->add(std::string("\tj\t") + getResult()->getImme());
}