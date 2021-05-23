#pragma once

#include <map>
#include <vector>
#include <string>

enum class SymbolType {
    CONST,
    VAR,
    CONST_ARRAY,
    VAR_ARRAY,
    FUNC,
};

enum class DataType {
    VOID,
    BOOL,
    INT,
    FLOAT,
    DOUBLE,
};

class SymbolInfo {
private:
    std::string name;

public:
    std::string getName();
    virtual SymbolType getSymbolType() = 0;

    SymbolInfo(const std::string & name): name(name) { }
};

class ConstSymbolInfo : public SymbolInfo {
private:
    DataType dataType;

    std::string valueText;
    union {
        bool valueBool;
        int valueInt;
        float valueFloat;
        double valueDouble;
    };

public:
    DataType getDataType() { return dataType; }
    virtual SymbolType getSymbolType() { return SymbolType::CONST; }

    // ConstSymbolInfo(const std::string & name, DataType dataType, const std::string & value);
    ConstSymbolInfo(const std::string & name, DataType dataType);
};

class VarSymbolInfo : public SymbolInfo {
    DataType dataType;

    std::string valueText;
    union {
        bool valueBool;
        int valueInt;
        float valueFloat;
        double valueDouble;
    };

public:
    DataType getDataType() { return dataType; }
    virtual SymbolType getSymbolType() { return SymbolType::VAR; }

    // VarSymbolInfo(const std::string & name, DataType dataType, const std::string & value);
    VarSymbolInfo(const std::string & name, DataType dataType);
};

class ConstArraySymbolInfo : public SymbolInfo {
private:
    DataType dataType;

    std::vector <std::string> valueTextArray;
    union {
        std::vector <bool> valueBoolArray;
        std::vector <int> valueIntArray;
        std::vector <float> valueFloatArray;
        std::vector <double> valueDoubleArray;
    };

    size_t arraySize;

public:
    DataType getDataType() { return dataType; }
    virtual SymbolType getSymbolType() { return SymbolType::CONST_ARRAY; }

    // ConstArraySymbolInfo(const std::string & name, DataType dataType, size_t arraySize, const std::vector <std::string> & value);
    ConstArraySymbolInfo(const std::string & name, DataType dataType, size_t arraySize);
};

class VarArraySymbolInfo : public SymbolInfo {
private:
    DataType dataType;

    std::vector <std::string> valueTextArray;
    union {
        std::vector <bool> valueBoolArray;
        std::vector <int> valueIntArray;
        std::vector <float> valueFloatArray;
        std::vector <double> valueDoubleArray;
    };

    size_t arraySize;

public:
    DataType getDataType() { return dataType; }
    virtual SymbolType getSymbolType() { return SymbolType::VAR_ARRAY; }

    // VarArraySymbolInfo(const std::string & name, DataType dataType, size_t arraySize, const std::vector <std::string> & value);
    VarArraySymbolInfo(const std::string & name, DataType dataType, size_t arraySize);
};

class BlockInfo;

class FuncSymbolInfo : public SymbolInfo {
private:
    DataType returnType;
    size_t paramNum;
    std::vector < SymbolInfo * > paramList;
    BlockInfo * blockInfo;

public:
    virtual SymbolType getSymbolType()  { return SymbolType::FUNC; }
    // FuncSymbolInfo(const std::string & name, DataType returnType, size_t paramNum);
    FuncSymbolInfo(const std::string & name, DataType returnType);
};

class BlockInfo {
private:
    BlockInfo * parentBlock;
    FuncSymbolInfo * belongTo;
    std::map < std::string, SymbolInfo * > symbolTable;
    std::vector < BlockInfo * > blockTable;

public:
    SymbolInfo * lookUpSymbol(std::string);
    
    ConstSymbolInfo * addNewConst(const std::string & name, DataType dataType);
    VarSymbolInfo * addNewVar(const std::string & name, DataType dataType);
    ConstArraySymbolInfo * addNewConstArray(const std::string & name, DataType dataType, size_t arraySize);
    VarArraySymbolInfo * addNewVarArray(const std::string & name, DataType dataType, size_t arraySize);
    FuncSymbolInfo * addNewFunc(const std::string & name, DataType returnType);

    BlockInfo * addNewBlock(FuncSymbolInfo * belongTo, std::vector < SymbolInfo * > paramList);
    BlockInfo * addNewBlock();

    BlockInfo(BlockInfo * parentBlock);
    BlockInfo(BlockInfo * parentBlock, FuncSymbolInfo * belongTo, const std::vector < SymbolInfo * > & paramList);
};