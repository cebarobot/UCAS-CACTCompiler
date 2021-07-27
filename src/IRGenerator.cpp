#include "IRGenerator.h"

IRGenerator::IRGenerator(IRProgram * newIR)
:ir(newIR), currentIRFunc(nullptr) {
    valueCount = 1;
}

void IRGenerator::enterFunc(std::string name) {
    currentIRFunc = new IRFunction(name);
    ir->functions.push_back(currentIRFunc);

    tempCount = 1;
}

void IRGenerator::exitFunc() {
    currentIRFunc = nullptr;
}

IRValue * IRGenerator::newValue(DataType dataType) {
    std::string name = std::string("value") + std::to_string(valueCount);
    valueCount += 1;

    IRValue * val = new IRValue(name, dataType);

    ir->globalValues.push_back(val);

    return val;
}

IRValue * IRGenerator::newValue(DataType dataType, std::string value) {
    std::string name = std::string("value") + std::to_string(valueCount);
    valueCount += 1;

    IRValue * val = new IRValue(name, dataType);
    val->addValue(value);

    ir->globalValues.push_back(val);

    return val;
}

IRVariable * IRGenerator::newVar(std::string name, DataType dataType) {
    IRVariable * var = new IRVariable(name, SizeOfDataType(dataType));

    if (currentIRFunc) {
        currentIRFunc->localVariables.push_back(var);
    } else {
        throw std::runtime_error("are you sure you want to add new var globally???");
    }

    return var;
}

IRVariable * IRGenerator::newVar(std::string name, DataType dataType, size_t len) {
    IRVariable * var = new IRVariable(name, SizeOfDataType(dataType) * len);

    if (currentIRFunc) {
        currentIRFunc->localVariables.push_back(var);
    } else {
        throw std::runtime_error("are you sure you want to add new var globally???");
    }

    return var;
}

IRLabel * IRGenerator::newLabel(std::string name) {
    IRLabel * label = new IRLabel(name);
    ir->labels.push_back(label);
    return label;
}

IRValue * IRGenerator::newInt(int intVal) {
    return new IRValue(intVal);
}

IRVariable * IRGenerator::newTemp(int size) {
    std::string name = std::string("temp") + std::to_string(tempCount);
    tempCount += 1;

    IRVariable * temp = new IRVariable(name, size);
    return temp;
}

IRVariable * IRGenerator::newIntTemp() {
    return newTemp(SizeOfDataType(INT));
}

void IRGenerator::startArrOp(DataType datatype, size_t len) {
    int cellSize = SizeOfDataType(datatype);
    IROperand * ir_cs = newInt(cellSize);
    IROperand * ir_len = newInt(len);
    arrRepeatVar = newIntTemp();
    arrRepeatLabel = newLabel();
    addCode(new IRMulInt(arrRepeatVar, ir_cs, ir_len));
    addCode(new IRLabelHere(arrRepeatLabel));
    addCode(new IRSubInt(arrRepeatVar, arrRepeatVar, ir_cs));
}

void IRGenerator::endArrOp() {
    addCode(new IRIfGreaterThanZeroGoto(arrRepeatLabel, arrRepeatVar));

    arrRepeatLabel = nullptr;
    arrRepeatVar = nullptr;
}

IROperand * IRGenerator::getArrRepeatVar() {
    return arrRepeatVar;
}

void IRGenerator::addCode(IRCode * newCode) {
    if (!currentIRFunc) {
        throw std::runtime_error("not in any function, cannot add code");
    }
    currentIRFunc->codes.push_back(newCode);
}

void IRGenerator::assignBasic(DataType datatype, IROperand * d, IROperand * s) {
    if (datatype == INT) {
        addCode(new IRCopyW(d, s));
    }
}

void IRGenerator::assignArray(DataType datatype, size_t len, IROperand * d, IROperand * s) {
    startArrOp(datatype, len);

    IROperand * ppp = getArrRepeatVar();
    IROperand * temp = newTemp(SizeOfDataType(datatype));

    if (datatype == INT) {
        addCode(new IRCopyFromIndexedW(temp, s, ppp));
        addCode(new IRCopyToIndexedW(d, temp, ppp));
    }

    endArrOp();
}