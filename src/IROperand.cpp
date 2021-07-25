#include <IR.h>

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
    return name;
}

IRValue::IRValue(std::string newValue) 
: value(newValue) { }

bool IRValue::isVariable() {
    return false;
}

std::string IRValue::getName() {
    return value;
}

std::string IRValue::getTarget() {
    // TODO:
    return value;
}