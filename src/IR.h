#pragma once

#include <string>
#include <vector>
#include <map>

#include "CACT.h"
#include "IRCode.h"
#include "IROperand.h"
#include "target.h"

class IRFunction {
public:
    std::string functionName;
    std::vector<IRVariable *> localVariables;
    std::vector<IRCode *> codes;

    IRFunction(std::string newFunctionName);

    void print();
    void targetGen(TargetCodeList * t);
};

class IRProgram {
public:
    std::string filename;
    std::vector<IRValue *> globalValues;
    std::vector<IRFunction *> functions;

    std::vector<IRLabel *> labels;

    IRProgram(std::string newFilename);

    void print();
    void targetGen(TargetCodeList * t);
};
