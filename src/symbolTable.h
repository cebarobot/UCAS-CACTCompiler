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
    std::string getName() { return name; }
    virtual DataType getDataType() = 0;
    virtual size_t getArraySize() = 0;
    virtual SymbolType getSymbolType() = 0;
    virtual void addValue(DataType DataType, const std::string & value) = 0;
    virtual void checkValue() = 0;

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
    
    bool isInitialized;

public:
    virtual DataType getDataType() { return dataType; }
    virtual size_t getArraySize() { return -1; };
    virtual SymbolType getSymbolType() { return SymbolType::CONST; }
    virtual void addValue(DataType DataType, const std::string & value);
    virtual void checkValue();

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

    bool isInitialized;

public:
    virtual DataType getDataType() { return dataType; }
    virtual size_t getArraySize() { return -1; };
    virtual SymbolType getSymbolType() { return SymbolType::VAR; }
    virtual void addValue(DataType DataType, const std::string & value);
    virtual void checkValue();

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
    bool isInitialized;

public:
    virtual DataType getDataType() { return dataType; }
    virtual size_t getArraySize() { return arraySize; };
    virtual SymbolType getSymbolType() { return SymbolType::CONST_ARRAY; }
    virtual void addValue(DataType DataType, const std::string & value);
    virtual void checkValue();

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
    bool isInitialized;

public:
    virtual DataType getDataType() { return dataType; }
    virtual size_t getArraySize() { return arraySize; };
    virtual SymbolType getSymbolType() { return SymbolType::VAR_ARRAY; }
    virtual void addValue(DataType DataType, const std::string & value);
    virtual void checkValue();

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
    virtual DataType getDataType()  { return returnType; }
    virtual size_t getArraySize() { return paramNum; };
    virtual SymbolType getSymbolType()  { return SymbolType::FUNC; }
    std::vector < SymbolInfo * > getparamList() { return paramList; }
    size_t getparamNum() { return paramNum; }

    SymbolInfo * addParamVar(const std::string & name, DataType dataType);
    SymbolInfo * addParamArray(const std::string & name, DataType dataType);
    size_t calcParamNum();

    virtual void addValue(DataType DataType, const std::string & value) { }
    virtual void checkValue() { }

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
    BlockInfo * getParentBlock() { return parentBlock; }
    SymbolInfo * lookUpSymbol(std::string symbolName);
    FuncSymbolInfo * lookUpFunc(std::string symbolName);
    
    ConstSymbolInfo * addNewConst(const std::string & name, DataType dataType);
    VarSymbolInfo * addNewVar(const std::string & name, DataType dataType);
    ConstArraySymbolInfo * addNewConstArray(const std::string & name, DataType dataType, size_t arraySize);
    VarArraySymbolInfo * addNewVarArray(const std::string & name, DataType dataType, size_t arraySize);
    FuncSymbolInfo * addNewFunc(const std::string & name, DataType returnType);

    BlockInfo * addNewBlock();
    BlockInfo * addNewBlock(FuncSymbolInfo * belongTo);

    BlockInfo(BlockInfo * parentBlock);
    BlockInfo(BlockInfo * parentBlock, FuncSymbolInfo * belongTo, const std::vector < SymbolInfo * > & paramList);
};