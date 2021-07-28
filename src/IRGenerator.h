#pragma once

#include "CACT.h"
#include "IR.h"
#include "symbolTable.h"

class IRGenerator {
private:
    IRProgram * ir;
    IRFunction * currentIRFunc;

    IRValue * currentIRVal;

    int tempCount;
    int labelCount;
    int valueCount;

    IRLabel * funcEndLabel;

    IRLabel * arrRepeatLabel;
    IROperand * arrRepeatVar;
public:
    IRGenerator(IRProgram * newIR);

    void enterFunc(std::string name);
    void exitFunc();

    void startConstArr();
    void endConstArr();

    IRValue * newValue(DataType dataType);
    IRValue * newValue(DataType dataType, std::string value);
    void removeValues(int cnt);

    IRVariable * newVar(std::string name, DataType dataType);
    IRVariable * newVar(std::string name, DataType dataType, int len);

    IRLabel * newLabel(std::string name);
    IRLabel * newLabel();

    IRValue * newInt(int intVal);

    IRVariable * newTemp(DataType dataType);

    void startArrOp(DataType datatype, int len);
    void endArrOp();
    IROperand * getArrRepeatVar();

    void addCode(IRCode * newCode);

    void addReturn();

    void assignBasic(DataType datatype, IROperand * d, IROperand * s);
    void assignArray(DataType datatype, int len, IROperand * d, IROperand * s);
};