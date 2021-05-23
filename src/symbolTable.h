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

    SymbolInfo(const std::string & name);
};

class ConstSymbolInfo : public SymbolInfo {
private:
    DataType dataType;

    union {
        bool valueBool;
        int valueInt;
        float valueFloat;
        double valueDouble;
    };

public:
    DataType getDataType();
    virtual SymbolType getSymbolType();

    ConstSymbolInfo(const std::string & name, DataType dataType, const std::string & value);
};

class VarSymbolInfo : public SymbolInfo {
    DataType dataType;

    union {
        bool valueBool;
        int valueInt;
        float valueFloat;
        double valueDouble;
    };

public:
    DataType getDataType();
    virtual SymbolType getSymbolType();

    VarSymbolInfo(const std::string & name, DataType dataType, const std::string & value);
    VarSymbolInfo(const std::string & name, DataType dataType);
};

class ConstArraySymbolInfo : public SymbolInfo {
    DataType dataType;

    union {
        std::vector <bool> valueBoolArray;
        std::vector <int> valueIntArray;
        std::vector <float> valueFloatArray;
        std::vector <double> valueDoubleArray;
    };

    size_t arraySize;

public:
    DataType getDataType();
    virtual SymbolType getSymbolType();

    ConstArraySymbolInfo(const std::string & name, DataType dataType, size_t arraySize, const std::vector <std::string> & value);
};

class VarArraySymbolInfo : public SymbolInfo {
    DataType dataType;

    union {
        std::vector <bool> valueBoolArray;
        std::vector <int> valueIntArray;
        std::vector <float> valueFloatArray;
        std::vector <double> valueDoubleArray;
    };

    size_t arraySize;

public:
    DataType getDataType();
    virtual SymbolType getSymbolType();

    VarArraySymbolInfo(const std::string & name, DataType dataType, size_t arraySize, const std::vector <std::string> & value);
    VarArraySymbolInfo(const std::string & name, DataType dataType, size_t arraySize);
};

class BlockInfo;

class FuncSymbolInfo : public SymbolInfo {
    DataType returnType;
    size_t paramNum;
    std::vector < SymbolInfo * > paramList;
    BlockInfo * blockInfo;

public:
    virtual SymbolType getSymbolType();
    FuncSymbolInfo(const std::string & name, DataType returnType, size_t paramNum, const std::vector <SymbolInfo *> paramList);
};

class BlockInfo {
    FuncSymbolInfo * belongTo;
    std::map < std::string, SymbolInfo * > symbolTable;
    std::vector < BlockInfo * > blockTable;
};