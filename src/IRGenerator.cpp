#include "IRGenerator.h"

IRGenerator::IRGenerator(IRProgram * newIR)
:ir(newIR), currentIRFunc(nullptr) {}

void IRGenerator::enterFunc(std::string name) {
    currentIRFunc = new IRFunction(name);
    ir->functions.push_back(currentIRFunc);
}

void IRGenerator::exitFunc() {
    currentIRFunc = nullptr;
}