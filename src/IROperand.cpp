#include <IR.h>

IRLabel::IRLabel(std::string newName)
: name(newName) { }

bool IRLabel::isVariable() {
    return true;
}

void IRValue::setName(std::string newName) {
    name = newName;
}

std::string IRLabel::getName() {
    return name;
}

std::string IRLabel::getTarget() {
    // TODO:
}


IRVariable::IRVariable(std::string newName, int newSize)
: name(newName), size(newSize) { }

bool IRVariable::isVariable() {
    return true;
}

void IRValue::setName(std::string newName) {
    name = newName;
}

std::string IRVariable::getName() {
    return name;
}

std::string IRVariable::getTarget() {
    // TODO:
}


IRValue::IRValue(std::string newName, DataType newDataType) 
: name(newName), dataType(newDataType), isVar(true) { }


IRValue::IRValue(int newVal)
: name(std::to_string(newVal)), dataType(INT), isVar(true) {
    values.push_back(std::to_string(newVal));
}

bool IRValue::isVariable() {
    return isVar;
}

void IRValue::setName(std::string newName) {
    name = newName;
}

std::string IRValue::getName() {
    return name;
}

std::string IRValue::getTarget() {
    // TODO:
}

void IRValue::addValue(std::string newValue) {
    values.push_back(newValue);
}

std::string IRValue::getValue(int x) {
    if (x >= values.size()) {
        throw std::runtime_error("irGen: wrong index");
    }
    return values[x];
}

std::vector<std::string> IRValue::getValue() {
    return values;
}

void IRValue::fillValue(int len) {
    while (values.size() < len) {
        values.push_back("0");
    }
}