#include "IRGenerator.h"

IRGenerator::IRGenerator(IRProgram * newIR)
:ir(newIR), currentIRFunc(nullptr) {
    labelCount = 1;
    valueCount = 1;
}

void IRGenerator::enterFunc(std::string name) {
    currentIRFunc = new IRFunction(name);
    funcEndLabel = newLabel(std::string("__end_") + name);
    ir->functions.push_back(currentIRFunc);

    tempCount = 1;
}

void IRGenerator::exitFunc() {
    addCode(new IRLabelHere(funcEndLabel));
    currentIRFunc = nullptr;
    funcEndLabel = nullptr;
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

void IRGenerator::removeValues(int cnt) {
    for (int i = 0; i < cnt; i++) {
        ir->globalValues.pop_back();
    }
}

IRVariable * IRGenerator::newVar(std::string name, DataType dataType) {
    IRVariable * var = new IRVariable(name, dataType);

    if (currentIRFunc) {
        currentIRFunc->localVariables.push_back(var);
    } else {
        throw std::runtime_error("are you sure you want to add new var globally???");
    }

    return var;
}

IRVariable * IRGenerator::newVar(std::string name, DataType dataType, int len) {
    IRVariable * var = new IRVariable(name, dataType, len);

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

IRLabel * IRGenerator::newLabel() {
    std::string name = std::string("label") + std::to_string(labelCount);
    labelCount += 1;

    IRLabel * label = new IRLabel(name);
    ir->labels.push_back(label);
    return label;
}

IRValue * IRGenerator::newInt(int intVal) {
    return new IRValue(intVal);
}

IRVariable * IRGenerator::newTemp(DataType dataType) {
    std::string name = std::string("temp") + std::to_string(tempCount);
    tempCount += 1;

    IRVariable * temp = new IRVariable(name, dataType);
    return temp;
}

void IRGenerator::startArrOp(DataType datatype, int len) {
    int cellSize = SizeOfDataType(datatype);
    IROperand * ir_cs = newInt(cellSize);
    IROperand * ir_len = newInt(len);
    arrRepeatVar = newTemp(INT);
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
    if (!arrRepeatVar) {
        throw std::runtime_error("no repeat var");
    }
    return arrRepeatVar;
}

void IRGenerator::addCode(IRCode * newCode) {
    if (!currentIRFunc) {
        throw std::runtime_error("not in any function, cannot add code");
    }
    currentIRFunc->codes.push_back(newCode);
}

void IRGenerator::addReturn() {
    addCode(new IRGoto(funcEndLabel));
}

void IRGenerator::assignBasic(DataType datatype, IROperand * d, IROperand * s) {
    if (datatype == INT || datatype == BOOL) {
        addCode(new IRCopyW(d, s));
    } else if (datatype == FLOAT) {
        addCode(new IRCopyF(d, s));
    } else if (datatype == DOUBLE) {
        addCode(new IRCopyD(d, s));
    }
}

void IRGenerator::assignArray(DataType datatype, int len, IROperand * d, IROperand * s) {
    startArrOp(datatype, len);

    IROperand * ppp = getArrRepeatVar();
    IROperand * temp = newTemp(datatype);

    if (datatype == INT) {
        addCode(new IRCopyFromIndexedW(temp, s, ppp));
        addCode(new IRCopyToIndexedW(d, temp, ppp));
    } else if (datatype == FLOAT) {
        addCode(new IRCopyFromIndexedF(temp, s, ppp));
        addCode(new IRCopyToIndexedF(d, temp, ppp));
    } else if (datatype == DOUBLE) {
        addCode(new IRCopyFromIndexedD(temp, s, ppp));
        addCode(new IRCopyToIndexedD(d, temp, ppp));
    }

    endArrOp();
}