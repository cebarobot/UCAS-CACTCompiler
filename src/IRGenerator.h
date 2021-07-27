#pragma once

#include "IR.h"
#include "symbolTable.h"

class IRGenerator {
private:
    IRProgram * ir;
    IRFunction * currentIRFunc;

    IRValue * currentIRVal;
public:
    IRGenerator(IRProgram * newIR);

    void enterFunc(std::string name);
    void exitFunc();

    void startConstArr();
    void endConstArr();

    IRVariable * newArray(std::string name, DataType dataType, size_t arraySize);
    void addArrValue();
    void addArrValue(std::string newValue);
    void endNewArray();

    IRVariable * newVar(std::string name, DataType dataType);

    IRLabel * newLabel(std::string name);
    IRLabel * newLabel();
};