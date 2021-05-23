#include "symbolTable.h"
#include <iostream>

/* we decided not to assign value when constructing symbols
ConstSymbolInfo::ConstSymbolInfo(const std::string & name, DataType dataType, const std::string & value)
: SymbolInfo(name), dataType(dataType), valueText(value) {
    if (dataType == DataType::FLOAT) {
        valueText = valueText.substr(0, valueText.length() - 1);
    }
}

VarSymbolInfo::VarSymbolInfo(const std::string & name, DataType dataType, const std::string & value)
: SymbolInfo(name), dataType(dataType), valueText(value) {
    if (dataType == DataType::FLOAT) {
        valueText = valueText.substr(0, valueText.length() - 1);
    }
}

VarSymbolInfo::VarSymbolInfo(const std::string & name, DataType dataType)
: SymbolInfo(name), dataType(dataType) {
    if (dataType == DataType::BOOL) {
        valueText = "false";
    } else {
        valueText = "0";
    }
}

ConstArraySymbolInfo::ConstArraySymbolInfo(const std::string & name, DataType dataType, size_t arraySize, const std::vector <std::string> & value)
: SymbolInfo(name), dataType(dataType), arraySize(arraySize), valueTextArray(value) {
    if (arraySize != value.size()) {
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC\n");
    }
    if (dataType == DataType::FLOAT) {
        for (auto & valueText : valueTextArray) {
            valueText = valueText.substr(0, valueText.length() - 1);
        }
    }
}

VarArraySymbolInfo::VarArraySymbolInfo(const std::string & name, DataType dataType, size_t arraySize, const std::vector <std::string> & value)
: SymbolInfo(name), dataType(dataType), arraySize(arraySize), valueTextArray(value) {
    if (arraySize != value.size()) {
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC\n");
    }
    if (dataType == DataType::FLOAT) {
        for (auto & valueText : valueTextArray) {
            valueText = valueText.substr(0, valueText.length() - 1);
        }
    }
}

VarArraySymbolInfo::VarArraySymbolInfo(const std::string & name, DataType dataType, size_t arraySize)
: SymbolInfo(name), dataType(dataType), arraySize(arraySize), valueTextArray(arraySize, "0") {
    if (dataType == DataType::BOOL) {
        for (auto & valueText : valueTextArray) {
            valueText = "false";
        }
    }
}

FuncSymbolInfo::FuncSymbolInfo(const std::string & name, DataType returnType, size_t paramNum)
: SymbolInfo(name), returnType(returnType), paramNum(paramNum) { }
*/

ConstSymbolInfo::ConstSymbolInfo(const std::string & name, DataType dataType)
: SymbolInfo(name), dataType(dataType) { }

void ConstSymbolInfo::addValue(DataType valueDataType, const std::string & value) {
    if (valueDataType != dataType) {
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC\n");
        return;
    } else if (!valueText.empty()) {
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC\n");
        return;
    }
    valueText = value;
    isInitialized = true;
}
void ConstSymbolInfo::checkValue() {
    if (!isInitialized) {
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC\n");
    }
}

VarSymbolInfo::VarSymbolInfo(const std::string & name, DataType dataType)
: SymbolInfo(name), dataType(dataType), isInitialized(false) { }

void VarSymbolInfo::addValue(DataType valueDataType, const std::string & value) {
    if (valueDataType != dataType) {
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC\n");
        return;
    } else if (isInitialized || !valueText.empty()) {
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC\n");
        return;
    }
    valueText = value;
    isInitialized = true;
}
void VarSymbolInfo::checkValue() {
    // nothing to check
}

ConstArraySymbolInfo::ConstArraySymbolInfo(const std::string & name, DataType dataType, size_t arraySize)
: SymbolInfo(name), dataType(dataType), arraySize(arraySize) { }

void ConstArraySymbolInfo::addValue(DataType valueDataType, const std::string & value) {
    if (valueDataType != dataType) {
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC\n");
        return;
    } else if (valueTextArray.size() >= arraySize) {
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC\n");
        return;
    }
    valueTextArray.push_back(value);
    isInitialized = true;
}
void ConstArraySymbolInfo::checkValue() {
    if (!isInitialized) {
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC\n");
    } else if (valueTextArray.size() != arraySize) {
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC\n");
    }
}

VarArraySymbolInfo::VarArraySymbolInfo(const std::string & name, DataType dataType, size_t arraySize)
: SymbolInfo(name), dataType(dataType), arraySize(arraySize), isInitialized(false) { }

void VarArraySymbolInfo::addValue(DataType valueDataType, const std::string & value) {
    if (valueDataType != dataType) {
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC\n");
        return;
    } else if (valueTextArray.size() >= arraySize) {
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC\n");
        return;
    }
    valueTextArray.push_back(value);
    isInitialized = true;
}
void VarArraySymbolInfo::checkValue() {
    if (isInitialized && valueTextArray.size() != arraySize) {
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC\n");
    }
}

FuncSymbolInfo::FuncSymbolInfo(const std::string & name, DataType returnType)
: SymbolInfo(name), returnType(returnType), blockInfo(nullptr) { }

SymbolInfo * FuncSymbolInfo::addParamVar(const std::string & name, DataType dataType) {
    VarSymbolInfo * newParam = new VarSymbolInfo(name, dataType);
    paramList.push_back(newParam);
    return newParam;
}

SymbolInfo * FuncSymbolInfo::addParamArray(const std::string & name, DataType dataType) {
    VarArraySymbolInfo * newParam = new VarArraySymbolInfo(name, dataType, 0);
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
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC\n");
        return nullptr;
    } else if (symbolTable.count(symbolName) == 1) {
        if (symbolTable[symbolName]->getSymbolType() == SymbolType::FUNC) {
            return dynamic_cast<FuncSymbolInfo *>(symbolTable[symbolName]);
        } else {
            // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC\n");
            return nullptr;
        }
    }
    return nullptr;
}
    
ConstSymbolInfo * BlockInfo::addNewConst(const std::string & name, DataType dataType) {
    if (symbolTable.count(name) > 0) {
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC\n");
        return nullptr;
    }
    ConstSymbolInfo * newSymbol = new ConstSymbolInfo(name, dataType);
    symbolTable[name] = newSymbol;
    return newSymbol;
}

VarSymbolInfo * BlockInfo::addNewVar(const std::string & name, DataType dataType) {
    if (symbolTable.count(name) > 0) {
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC\n");
        return nullptr;
    }
    VarSymbolInfo * newSymbol = new VarSymbolInfo(name, dataType);
    symbolTable[name] = newSymbol;
    return newSymbol;
}

ConstArraySymbolInfo * BlockInfo::addNewConstArray(const std::string & name, DataType dataType, size_t arraySize) {
    if (symbolTable.count(name) > 0) {
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC\n");
        return nullptr;
    }
    ConstArraySymbolInfo * newSymbol = new ConstArraySymbolInfo(name, dataType, arraySize);
    symbolTable[name] = newSymbol;
    return newSymbol;
}

VarArraySymbolInfo * BlockInfo::addNewVarArray(const std::string & name, DataType dataType, size_t arraySize) {
    if (symbolTable.count(name) > 0) {
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC\n");
        return nullptr;
    }
    VarArraySymbolInfo * newSymbol = new VarArraySymbolInfo(name, dataType, arraySize);
    symbolTable[name] = newSymbol;
    return newSymbol;
}

FuncSymbolInfo * BlockInfo::addNewFunc(const std::string & name, DataType returnType) {
    if (parentBlock != nullptr || belongTo != nullptr) {
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC\n");
        return nullptr;
    } else if (symbolTable.count(name) > 0) {
        // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC\n");
        return nullptr;
    }
    FuncSymbolInfo * newFunc = new FuncSymbolInfo(name, returnType);
    symbolTable[name] = newFunc;
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
            // TODO: throw exception
throw std::runtime_error("\nWRONG SENMANTIC\n");
            return;
        }
        symbolTable[one_param->getName()] = one_param;
    }
}