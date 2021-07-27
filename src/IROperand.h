#pragma once

#include <string>
#include <vector>
#include <map>

#include "symbolTable.h"

enum MemBase {
    STACK,
    DATA,
    RODATA
};

class IROperand {
public:
    virtual ~IROperand() {}

    virtual bool isVariable() = 0;
    virtual std::string getName() = 0;
    virtual std::string getTarget() = 0;
};

class IRLabel : public IROperand {
private:
    std::string name;
public:
    IRLabel(std::string newName);

    virtual bool isVariable();
    virtual std::string getName();
    virtual std::string getTarget();
};

class IRVariable : public IROperand {
private:
    std::string name;
    int size;

public:
    IRVariable(std::string newName, int newSize);

    virtual bool isVariable();
    virtual std::string getName();
    virtual std::string getTarget();
};

class IRValue : public IROperand {
private:
    std::string name;
    bool isVar;
    DataType dataType;
    std::vector<std::string> value;

public:
    IRValue(std::string newName, DataType newDataType, bool newIsVar);

    virtual bool isVariable();
    virtual std::string getName();
    virtual std::string getTarget();

    void addValue(std::string newValue);
};

