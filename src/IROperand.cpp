#include <IR.h>

IRLabel::IRLabel(std::string newName)
: name(newName) { }

bool IRLabel::isVariable() {
    return true;
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

std::string IRVariable::getName() {
    return name;
}

std::string IRVariable::getTarget() {
    // TODO:
}


IRValue::IRValue(std::string newName, DataType newDataType, bool newIsVar) 
: name(newName), dataType(newDataType), isVar(newIsVar) { }

bool IRValue::isVariable() {
    return isVar;
}

std::string IRValue::getName() {
    return name;
}

std::string IRValue::getTarget() {
    // TODO:
}