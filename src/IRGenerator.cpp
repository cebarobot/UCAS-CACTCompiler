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

IRVariable * IRGenerator::newArray(std::string name, DataType dataType, size_t arraySize) {
    if (currentIRFunc) {
        new IRVariable(name, SizeOfDataType(dataType) * arraySize);
        currentIRVal = new IRValue(name, dataType, false);
    } else {
        currentIRVal = new IRValue(name, dataType, true);
    }
}



void IRGenerator::endNewArray() {

}


IRLabel * IRGenerator::newLabel(std::string name) {
    IRLabel * label = new IRLabel(name);
    ir->labels.push_back(label);
    return label;
}