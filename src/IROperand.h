#pragma once

#include <string>
#include <vector>
#include <map>

#include "IRCode.h"

enum MemBase {
    STACK,
    DATA,
};

class IROperand {
public:
    virtual ~IROperand() {}

    virtual bool isVariable() = 0;
    virtual std::string getName() = 0;
    virtual std::string getTarget() = 0;
};

class IRVariable : public IROperand {
private:
    std::string name;
    int size;
    // TODO: MemCell mem;

public:
    IRVariable(std::string newName, int newSize);
    bool isVariable();
    std::string getName();
    std::string getTarget();
};

class IRValue : public IROperand {
private:
    std::string value;

public:
    IRValue(std::string newValue);
    bool isVariable();
    std::string getName();
    std::string getTarget();
};




// enum IRArgType {
//     CONST,
//     VARIABLE,
//     ARRAY,
// };


// class IRArgument {
// protected:
//     std::string value;      // name for var; value for const
// public:
//     IRArgument(std::string newValue);
//     std::string getValue();
// };

// class IRConst : public IRArgument {
// public:
//     IRConst::IRConst(std::string newValue);
// };

// class IRVariable : public IRArgument {
// protected:
//     int regID;
//     bool regValid;
//     int memAddr;
//     MemBase memBase;
// };

// class IRArray : public IRArgument {
// protected:
//     int length;
// public:
//     int getLength();
//     virtual int getCellSize() = 0;
// };

// class IRIntConst : public IRConst {
// protected:
//     int intValue;
// public:
//     IRIntConst(std::string newValue);
// };

// class IRFloatConst: public IRConst {
// protected:
//     float floatValue;
// public:
//     IRFloatConst(std::string newValue);
// };

// class IRDoubleConst : public IRConst {
// protected:
//     double doubleValue;
// public:
//     IRDoubleConst(std::string newValue);
// };

// class IRBoolConst : public IRConst {
// protected:
//     bool boolValue;
// public:
//     IRBoolConst(std::string newValue);
// };

// class IRIntVariable : public IRVariable {
// public:
//     IRIntVariable(std::string name);
// };

// class IRFloatVariable: public IRVariable {
// public:
//     IRFloatVariable(std::string name);
// };

// class IRDoubleVariable : public IRVariable {
// public:
//     IRDoubleVariable(std::string name);
// };

// class IRBoolVariable : public IRVariable {
// public:
//     IRBoolVariable(std::string name);
// };

// class IRIntArray : public IRArray {
// public:
//     IRIntArray(std::string name, int length);
// };

// class IRFloatArray: public IRArray {
// public:
//     IRFloatArray(std::string name, int length);
// };

// // class IRDoubleArray : public IRArray {
    
// // };

// // class IRBoolArray : public IRArray {

// // };