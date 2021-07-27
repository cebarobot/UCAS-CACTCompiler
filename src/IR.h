#pragma once

#include <string>
#include <vector>
#include <map>

#include "CACT.h"
#include "IRCode.h"
#include "IROperand.h"

class IRFunction {
public:
    std::string functionName;
    std::vector<IRVariable *> localVariables;
    std::vector<IRCode *> codes;

    IRFunction(std::string newFunctionName);

    void print();
};

class IRProgram {
public:
    std::vector<IRValue *> globalValues;
    std::vector<IRFunction *> functions;

    std::vector<IRLabel *> labels;

    void print();
};
