#pragma once

#include <map>
#include <vector>
#include <string>
#include <iostream>

#include "IROperand.h"

enum SymbolType {
    CONST,
    VAR,
    CONST_ARRAY,
    VAR_ARRAY,
    FUNC,
};

enum DataType {
    VOID,
    BOOL,
    INT,
    FLOAT,
    DOUBLE,
};

std::string ToString(DataType x);
size_t SizeOfDataType(DataType x);

class SymbolInfo {
private:
    std::string name;
    IROperand * operand;

public:
    std::string getName();

    void setOp(IROperand * op);
    IROperand * getOp();

    virtual DataType getDataType() = 0;
    virtual size_t getArraySize() = 0;
    virtual SymbolType getSymbolType() = 0;

    SymbolInfo(const std::string & name);
};

class ConstSymbolInfo : public SymbolInfo {
private:
    DataType dataType;

public:
    virtual DataType getDataType() { return dataType; }
    virtual size_t getArraySize() { return -1; };
    virtual SymbolType getSymbolType() { return SymbolType::CONST; }

    ConstSymbolInfo(const std::string & name, DataType dataType);
};

class VarSymbolInfo : public SymbolInfo {
    DataType dataType;

public:
    virtual DataType getDataType() { return dataType; }
    virtual size_t getArraySize() { return -1; };
    virtual SymbolType getSymbolType() { return SymbolType::VAR; }

    VarSymbolInfo(const std::string & name, DataType dataType);
};

class ConstArraySymbolInfo : public SymbolInfo {
private:
    DataType dataType;
    size_t arraySize;

public:
    virtual DataType getDataType() { return dataType; }
    virtual size_t getArraySize() { return arraySize; };
    virtual SymbolType getSymbolType() { return SymbolType::CONST_ARRAY; }

    ConstArraySymbolInfo(const std::string & name, DataType dataType, size_t arraySize);
};

class VarArraySymbolInfo : public SymbolInfo {
private:
    DataType dataType;
    size_t arraySize;

public:
    virtual DataType getDataType() { return dataType; }
    virtual size_t getArraySize() { return arraySize; };
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
    virtual DataType getDataType()  { return returnType; }
    virtual size_t getArraySize() { return paramNum; };
    virtual SymbolType getSymbolType()  { return SymbolType::FUNC; }
    std::vector < SymbolInfo * > getparamList() { return paramList; }
    size_t getparamNum() { return paramNum; }

    SymbolInfo * addParamVar(const std::string & name, DataType dataType);
    SymbolInfo * addParamArray(const std::string & name, DataType dataType);
    size_t calcParamNum();

    // FuncSymbolInfo(const std::string & name, DataType returnType, size_t paramNum);
    FuncSymbolInfo(const std::string & name, DataType returnType);
};

class BlockInfo {
private:
    BlockInfo * parentBlock;
    FuncSymbolInfo * belongTo;
    std::map < std::string, SymbolInfo * > symbolTable;
    std::map < std::string, FuncSymbolInfo * > funcTable;
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