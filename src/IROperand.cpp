#include <IR.h>

IRLabel::IRLabel(std::string newName)
: name(newName) { }

bool IRLabel::isVariable() {
    return true;
}

void IRLabel::setName(std::string newName) {
    name = newName;
}

std::string IRLabel::getName() {
    return name;
}

std::string IRLabel::getImme() {
    return name;
}

void IRLabel::alloc(TargetCodeList * t) {
    // nothing to do
}

void IRLabel::loadTo(TargetCodeList * t, std::string reg) {
    throw std::runtime_error("target gen: label is not allow to loatTo");
}

void IRLabel::storeFrom(TargetCodeList * t, std::string reg) {
    throw std::runtime_error("target gen: label is not allow to storeFrom");
}

void IRLabel::loadAddrTo(TargetCodeList * t, std::string reg) {
    throw std::runtime_error("target gen: label is not allow to loadAddrTo");
}


IRVariable::IRVariable(std::string newName, DataType dt, int len)
: name(newName), dataType(dt), length(len) { }
IRVariable::IRVariable(std::string newName, DataType dt)
: name(newName), dataType(dt), length(1) { }

bool IRVariable::isVariable() {
    return true;
}

void IRVariable::setName(std::string newName) {
    name = newName;
}

std::string IRVariable::getName() {
    return name;
}

int IRVariable::getSize() {
    return SizeOfDataType(dataType) * length;
}

std::string IRVariable::getImme() {
    return name;
}

void IRVariable::alloc(TargetCodeList * t) {
    // nothing to do
}

void IRVariable::loadTo(TargetCodeList * t, std::string reg) {
    if (dataType == INT || dataType == BOOL) {
        t->add(std::string("\tlw\t") + reg + std::string(", ") + std::to_string(getMemOff()) + std::string("(s0)"));
    } else if (dataType == FLOAT) {
        t->add(std::string("\tflw\t") + reg + std::string(", ") + std::to_string(getMemOff()) + std::string("(s0)"));
    } else if (dataType == DOUBLE) {
        t->add(std::string("\tfld\t") + reg + std::string(", ") + std::to_string(getMemOff()) + std::string("(s0)"));
    }
}

void IRVariable::storeFrom(TargetCodeList * t, std::string reg) {
    if (dataType == INT || dataType == BOOL) {
        t->add(std::string("\tsw\t") + reg + std::string(", ") + std::to_string(getMemOff()) + std::string("(s0)"));
    } else if (dataType == FLOAT) {
        t->add(std::string("\tfsw\t") + reg + std::string(", ") + std::to_string(getMemOff()) + std::string("(s0)"));
    } else if (dataType == DOUBLE) {
        t->add(std::string("\tfsd\t") + reg + std::string(", ") + std::to_string(getMemOff()) + std::string("(s0)"));
    }
}

void IRVariable::loadAddrTo(TargetCodeList * t, std::string reg) {
    t->add(std::string("\tli\t") + reg + std::string(", ") + std::to_string(getMemOff()));
    t->add(std::string("\taddi\t") + reg + std::string(", ") + reg + std::string(", s0"));
}

void IRVariable::setMemOff(int off) {
    memOffset = off;
}

int IRVariable::getMemOff() {
    return memOffset;
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

int IRValue::getSize() {
    return SizeOfDataType(dataType) * values.size();
}

std::string IRValue::getImme() {
    if ((dataType == INT || dataType == BOOL) && values.size() == 1 && !isVar) {
        return values[0];
    }
    throw std::runtime_error("cannot get imme");
}

void IRValue::alloc(TargetCodeList * t) {
    if ((dataType == INT || dataType == BOOL) && values.size() == 1 && !isVar) {
        // no need to alloc;
    } else {
        int size = getSize();

        t->add(std::string("\t.text"));
        t->add(std::string("\t.globl\t") + name);
        if (isVar) {
            t->add(std::string("\t.data"));
        } else {
            t->add(std::string("\t.rodata"));
        }
        t->add(std::string("\t.align\t3"));
        t->add(std::string("\t.type\t") + name + std::string(", @object"));
        t->add(std::string("\t.size\t") + name + std::string(", ") + std::to_string(size));
        t->add(name + std::string(":"));
        
        std::string type;
        if (dataType == BOOL || dataType == INT) {
            type = ".word";
        } else if (dataType == FLOAT) {
            type = ".float";
        } else if (dataType == DOUBLE) {
            type = ".double";
        }

        for (std::string v : values) {
            if (v == "") {
                t->add(std::string("\t.zero\t") + std::to_string(size));
                break;
            }

            t->add(std::string("\t") + type + std::string("\t") + v);
            size -= SizeOfDataType(dataType);
        }
    }
}

void IRValue::loadTo(TargetCodeList * t, std::string reg) {
    if (values.size() != 1) {
        throw std::runtime_error("only size 1 IRValue can load to reg");
    }
    if (dataType == INT || dataType == BOOL) {
        if (isVar) {
            t->add(std::string("\tlui\tt1, %%hi(") + name + std::string(")"));
            t->add(std::string("\tlw\t") + reg + std::string(", %%lo(") + name + std::string(")(t1)"));
        } else {
            t->add(std::string("\tli\t") + reg + std::string(", ") + values[0]);
        }
    } else if (dataType == FLOAT) {
        t->add(std::string("\tlui\tt1, %%hi(") + name + std::string(")"));
        t->add(std::string("\tflw\t") + reg + std::string(", %%lo(") + name + std::string(")(t1)"));
    } else if (dataType == DOUBLE) {
        t->add(std::string("\tlui\tt1, %%hi(") + name + std::string(")"));
        t->add(std::string("\tfld\t") + reg + std::string(", %%lo(") + name + std::string(")(t1)"));
    }
}

void IRValue::storeFrom(TargetCodeList * t, std::string reg) {
    if (values.size() != 1) {
        throw std::runtime_error("only size 1 IRValue can store from reg");
    }
    if (!isVar) {
        throw std::runtime_error("cannot store to const");
    }

    if (dataType == INT || dataType == BOOL) {
        t->add(std::string("\tlui\tt1, %%hi(") + name + std::string(")"));
        t->add(std::string("\tsw\t") + reg + std::string(", %%lo(") + name + std::string(")(t1)"));
    } else if (dataType == FLOAT) {
        t->add(std::string("\tlui\tt1, %%hi(") + name + std::string(")"));
        t->add(std::string("\tfsw\t") + reg + std::string(", %%lo(") + name + std::string(")(t1)"));
    } else if (dataType == DOUBLE) {
        t->add(std::string("\tlui\tt1, %%hi(") + name + std::string(")"));
        t->add(std::string("\tfsd\t") + reg + std::string(", %%lo(") + name + std::string(")(t1)"));
    }
}

void IRValue::loadAddrTo(TargetCodeList * t, std::string reg) {
    t->add(std::string("\tlui\t") + reg + std::string(", %%hi(") + name + std::string(")"));
    t->add(std::string("\taddi\t") + reg + std::string(", ") + reg + std::string(", %%lo(") + name + std::string(")"));
}

void IRValue::addValue(std::string newValue) {
    values.push_back(newValue);
}

std::string IRValue::getValue(int x) {
    if (x >= (int) values.size()) {
        throw std::runtime_error("irGen: wrong index");
    }
    return values[x];
}

std::vector<std::string> IRValue::getValue() {
    return values;
}

void IRValue::fillValue(int len) {
    while ((int) values.size() < len) {
        values.push_back("");
    }
}