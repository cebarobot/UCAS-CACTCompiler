#include "symbolTable.h"
#include <iostream>

std::string ToString(DataType x) {
    if (x == VOID) {
        return "void";
    } else if (x == BOOL) {
        return "bool";
    } else if (x == INT) {
        return "int";
    } else if (x == FLOAT) {
        return "float";
    } else if (x == DOUBLE) {
        return "double";
    }
    return "unknown";
}

size_t SizeOfDataType(DataType x) {
    if (x == BOOL) {
        return 4;
    } else if (x == INT) {
        return 4;
    } else if (x == FLOAT) {
        return 4;
    } else if (x == DOUBLE) {
        return 8;
    }
    return 0;
}

SymbolInfo::SymbolInfo(const std::string & name, IROperand * op)
: name(name), operand(op) { }

ConstSymbolInfo::ConstSymbolInfo(const std::string & name, IROperand * op, DataType dataType)
: SymbolInfo(name, op), dataType(dataType) { }


VarSymbolInfo::VarSymbolInfo(const std::string & name, IROperand * op, DataType dataType)
: SymbolInfo(name, op), dataType(dataType) { }


ConstArraySymbolInfo::ConstArraySymbolInfo(const std::string & name, IROperand * op, DataType dataType, size_t arraySize)
: SymbolInfo(name, op), dataType(dataType), arraySize(arraySize) { }


VarArraySymbolInfo::VarArraySymbolInfo(const std::string & name, IROperand * op, DataType dataType, size_t arraySize)
: SymbolInfo(name, op), dataType(dataType), arraySize(arraySize) { }


FuncSymbolInfo::FuncSymbolInfo(const std::string & name, IROperand * op, DataType returnType)
: SymbolInfo(name, op), returnType(returnType), blockInfo(nullptr) { }

SymbolInfo * FuncSymbolInfo::addParamVar(const std::string & name, IROperand * op, DataType dataType) {
    VarSymbolInfo * newParam = new VarSymbolInfo(name, op, dataType);
    paramList.push_back(newParam);
    return newParam;
}

SymbolInfo * FuncSymbolInfo::addParamVar(const std::string & name, DataType dataType) {
    VarSymbolInfo * newParam = new VarSymbolInfo(name, nullptr, dataType);
    paramList.push_back(newParam);
    return newParam;
}

SymbolInfo * FuncSymbolInfo::addParamArray(const std::string & name, DataType dataType) {
    VarArraySymbolInfo * newParam = new VarArraySymbolInfo(name, nullptr, dataType, 0);
    paramList.push_back(newParam);
    return newParam;
}

size_t FuncSymbolInfo::calcParamNum() {
    paramNum = paramList.size();
    return paramNum;
}

SymbolInfo * BlockInfo::lookUpSymbol(std::string symbolName) {
    if (symbolTable.count(symbolName) == 1) {
        return symbolTable[symbolName];
    } else if (parentBlock != nullptr) {
        return parentBlock->lookUpSymbol(symbolName);
    }
    return nullptr;
}

FuncSymbolInfo * BlockInfo::lookUpFunc(std::string symbolName) {
    if (parentBlock != nullptr || belongTo != nullptr) {
        throw std::runtime_error("cannot find func here");
        return nullptr;
    } else if (funcTable.count(symbolName) == 1) {
        if (funcTable[symbolName]->getSymbolType() == SymbolType::FUNC) {
            return funcTable[symbolName];
        } else {
            throw std::runtime_error("this is not a func");
            return nullptr;
        }
    }
    return nullptr;
}
    
ConstSymbolInfo * BlockInfo::addNewConst(const std::string & name, IROperand * op, DataType dataType) {
    if (symbolTable.count(name) > 0) {
        throw std::runtime_error("duplicate name of symbol");
        return nullptr;
    }
    ConstSymbolInfo * newSymbol = new ConstSymbolInfo(name, op, dataType);
    symbolTable[name] = newSymbol;
    return newSymbol;
}

VarSymbolInfo * BlockInfo::addNewVar(const std::string & name, IROperand * op, DataType dataType) {
    if (symbolTable.count(name) > 0) {
        throw std::runtime_error("duplicate name of symbol");
        return nullptr;
    }
    VarSymbolInfo * newSymbol = new VarSymbolInfo(name, op, dataType);
    symbolTable[name] = newSymbol;
    return newSymbol;
}

ConstArraySymbolInfo * BlockInfo::addNewConstArray(const std::string & name, IROperand * op, DataType dataType, size_t arraySize) {
    if (symbolTable.count(name) > 0) {
        throw std::runtime_error("duplicate name of symbol");
        return nullptr;
    }
    ConstArraySymbolInfo * newSymbol = new ConstArraySymbolInfo(name, op, dataType, arraySize);
    symbolTable[name] = newSymbol;
    return newSymbol;
}

VarArraySymbolInfo * BlockInfo::addNewVarArray(const std::string & name, IROperand * op, DataType dataType, size_t arraySize) {
    if (symbolTable.count(name) > 0) {
        throw std::runtime_error("duplicate name of symbol");
        return nullptr;
    }
    VarArraySymbolInfo * newSymbol = new VarArraySymbolInfo(name, op, dataType, arraySize);
    symbolTable[name] = newSymbol;
    return newSymbol;
}

FuncSymbolInfo * BlockInfo::addNewFunc(const std::string & name, IROperand * op, DataType returnType) {
    if (parentBlock != nullptr || belongTo != nullptr) {
        throw std::runtime_error("cannot declare a function in other function or block");
        return nullptr;
    } else if (funcTable.count(name) > 0) {
        throw std::runtime_error("duplicate name of function");
        return nullptr;
    }
    FuncSymbolInfo * newFunc = new FuncSymbolInfo(name, op, returnType);
    funcTable[name] = newFunc;
    return newFunc;
}

BlockInfo * BlockInfo::addNewBlock(FuncSymbolInfo * belongTo) {
    BlockInfo * newBlock = new BlockInfo(this, belongTo, belongTo->getparamList());
    blockTable.push_back(newBlock);
    return newBlock;
}
BlockInfo * BlockInfo::addNewBlock() {
    BlockInfo * newBlock = new BlockInfo(this);
    blockTable.push_back(newBlock);
    return newBlock;
}

BlockInfo::BlockInfo(BlockInfo * parentBlock): parentBlock(parentBlock), belongTo(nullptr) { }
BlockInfo::BlockInfo(BlockInfo * parentBlock, FuncSymbolInfo * belongTo, const std::vector < SymbolInfo * > & paramList)
: parentBlock(parentBlock), belongTo(belongTo) {
    for (SymbolInfo * one_param : paramList) {
        if (symbolTable.count(one_param->getName()) > 0) {
            throw std::runtime_error("dupliacte name of parameters");
            return;
        }
        symbolTable[one_param->getName()] = one_param;
    }
}