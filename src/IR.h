#pragma once

#include <string>
#include <vector>
#include <map>

#include "IRCode.h"
#include "IRArgument.h"

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
    std::vector<IRVariable *> globalVariables;
    std::vector<IRFunction *> functions;

    void print();
};
