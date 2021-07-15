#pragma once

#include <string>
#include <vector>
#include <map>

#include "IRCode.h"

enum IRAddrType {
    CONST,
    VARIABLE,
    ARRAY,
};

enum MemBase {
    STACK,
    DATA,
};

class IRArgument {
private:
    std::string value;
public:
    IRArgument(std::string newValue);
    std::string getValue();
};

class IRConst : public IRArgument {
public:
    IRConst::IRConst(std::string newValue);
};

class IRVariable : public IRArgument {
private:
    int regID;
    bool regValid;
    int memAddr;
    MemBase memBase;
};

// class IRArray : public IRArgument {

// };

class IRIntConst : public IRConst {
private:
    int intValue;
public:
    IRIntConst(std::string newValue);
};

// class IRFloatConst: public IRConst {

// };

// class IRDoubleConst : public IRConst {
    
// };

// class IRBoolConst : public IRBoolConst {

// };

class IRIntVariable : public IRVariable {
private:
    int intValue;
};

// class IRFloatVariable: public IRVariable {

// };

// class IRDoubleVariable : public IRVariable {
    
// };

// class IRBoolVariable : public IRBoolVariable {

// };

// class IRIntArray : public IRArray {
// private:
//     int intValue;
// };

// class IRFloatArray: public IRArray {

// };

// class IRDoubleArray : public IRArray {
    
// };

// class IRBoolArray : public IRBoolArray {

// };