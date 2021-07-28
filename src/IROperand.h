#pragma once

#include <string>
#include <vector>
#include <map>

#include "CACT.h"
#include "symbolTable.h"
#include "target.h"

enum MemBase {
    STACK,
    DATA,
    RODATA
};

class IROperand {
public:
    virtual ~IROperand() {}

    virtual bool isVariable() = 0;
    virtual void setName(std::string) = 0;
    virtual std::string getName() = 0;
    virtual int getSize() = 0;

    virtual std::string getImme() = 0;
    virtual void alloc(TargetCodeList * t) = 0;
    virtual void loadTo(TargetCodeList * t, std::string reg) = 0;
    virtual void storeFrom(TargetCodeList * t, std::string reg) = 0;
    virtual void loadAddrTo(TargetCodeList * t, std::string reg) = 0;
};

class IRLabel : public IROperand {
private:
    std::string name;
public:
    IRLabel(std::string newName);

    virtual bool isVariable();
    virtual void setName(std::string);
    virtual std::string getName();
    virtual int getSize();

    virtual std::string getImme();
    virtual void alloc(TargetCodeList * t);
    virtual void loadTo(TargetCodeList * t, std::string reg);
    virtual void storeFrom(TargetCodeList * t, std::string reg);
    virtual void loadAddrTo(TargetCodeList * t, std::string reg);
};

class IRVariable : public IROperand {
private:
    std::string name;
    DataType dataType;
    int length;

    int memOffset;

public:
    IRVariable(std::string newName, DataType dt);
    IRVariable(std::string newName, DataType dt, int len);

    virtual bool isVariable();
    virtual void setName(std::string);
    virtual std::string getName();
    virtual int getSize();

    virtual std::string getImme();
    virtual void alloc(TargetCodeList * t);
    virtual void loadTo(TargetCodeList * t, std::string reg);
    virtual void storeFrom(TargetCodeList * t, std::string reg);
    virtual void loadAddrTo(TargetCodeList * t, std::string reg);

    int getAlign();
    void setMemOff(int off);
    int getMemOff();
};

class IRValue : public IROperand {
private:
    std::string name;
    DataType dataType;
    bool isVar = false;
    std::vector<std::string> values;

public:
    IRValue(std::string newName, DataType newDataType);
    IRValue(int newVal);

    void setVariable(bool newIsVar);
    virtual bool isVariable();
    virtual std::string getName();
    virtual void setName(std::string);
    virtual int getSize();

    virtual std::string getImme();
    virtual void alloc(TargetCodeList * t);
    virtual void loadTo(TargetCodeList * t, std::string reg);
    virtual void storeFrom(TargetCodeList * t, std::string reg);
    virtual void loadAddrTo(TargetCodeList * t, std::string reg);

    void addValue(std::string newValue);
    std::string getValue(int x);
    std::vector<std::string> getValue();
    void fillValue(int len);
};

