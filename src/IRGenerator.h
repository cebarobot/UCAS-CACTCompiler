#pragma once

#include "IR.h"
#include "symbolTable.h"

class IRGenerator {
private:
    IRProgram * ir;
    IRFunction * currentIRFunc;

    IRValue * currentIRVal;

    int tempCount;
    int valueCount;

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

    IRVariable * newVar(std::string name, DataType dataType);
    IRVariable * newVar(std::string name, DataType dataType, size_t len);

    IRLabel * newLabel(std::string name);
    IRLabel * newLabel();

    IRValue * newInt(int intVal);

    IRVariable * newTemp(int size);
    IRVariable * newIntTemp();

    void startArrOp(DataType datatype, size_t len);
    void endArrOp();
    IROperand * getArrRepeatVar();

    void addCode(IRCode * newCode);

    void assignBasic(DataType datatype, IROperand * d, IROperand * s);
    void assignArray(DataType datatype, size_t len, IROperand * d, IROperand * s);
};