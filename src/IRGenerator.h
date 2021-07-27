#pragma once

#include "IR.h"
#include "symbolTable.h"

class IRGenerator {
private:
    IRProgram * ir;
    IRFunction * currentIRFunc;
public:
    IRGenerator(IRProgram * newIR);

    void enterFunc(std::string name);
    void exitFunc();

    IRVariable * newArray(std::string name, DataType dataType, size_t arraySize);
    IRVariable * newVar(std::string name, DataType dataType);
};