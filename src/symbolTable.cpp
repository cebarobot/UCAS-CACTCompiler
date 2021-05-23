#include "symbolTable.h"

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

VarSymbolInfo::VarSymbolInfo(const std::string & name, DataType dataType)
: SymbolInfo(name), dataType(dataType) { }

ConstArraySymbolInfo::ConstArraySymbolInfo(const std::string & name, DataType dataType, size_t arraySize)
: SymbolInfo(name), dataType(dataType), arraySize(arraySize) { }

VarArraySymbolInfo::VarArraySymbolInfo(const std::string & name, DataType dataType, size_t arraySize)
: SymbolInfo(name), dataType(dataType), arraySize(arraySize) { }

FuncSymbolInfo::FuncSymbolInfo(const std::string & name, DataType returnType)
: SymbolInfo(name), returnType(returnType) { }

SymbolInfo * BlockInfo::lookUpSymbol(std::string symbolName) {
    if (symbolTable.count(symbolName) == 1) {
        return symbolTable[symbolName];
    } else if (parentBlock != nullptr) {
        parentBlock->lookUpSymbol(symbolName);
    }
    return nullptr;
}
    
ConstSymbolInfo * BlockInfo::addNewConst(const std::string & name, DataType dataType) {
    if (symbolTable.count(name) > 0) {
        return nullptr;
    }
    ConstSymbolInfo * newSymbol = new ConstSymbolInfo(name, dataType);
    symbolTable[name] = newSymbol;
    return newSymbol;
}

VarSymbolInfo * BlockInfo::addNewVar(const std::string & name, DataType dataType) {
    if (symbolTable.count(name) > 0) {
        return nullptr;
    }
    VarSymbolInfo * newSymbol = new VarSymbolInfo(name, dataType);
    symbolTable[name] = newSymbol;
    return newSymbol;
}

ConstArraySymbolInfo * BlockInfo::addNewConstArray(const std::string & name, DataType dataType, size_t arraySize) {
    if (symbolTable.count(name) > 0) {
        return nullptr;
    }
    ConstArraySymbolInfo * newSymbol = new ConstArraySymbolInfo(name, dataType, arraySize);
    symbolTable[name] = newSymbol;
    return newSymbol;
}

VarArraySymbolInfo * BlockInfo::addNewVarArray(const std::string & name, DataType dataType, size_t arraySize) {
    if (symbolTable.count(name) > 0) {
        // TODO: throw exception
        return nullptr;
    }
    VarArraySymbolInfo * newSymbol = new VarArraySymbolInfo(name, dataType, arraySize);
    symbolTable[name] = newSymbol;
    return newSymbol;
}

FuncSymbolInfo * BlockInfo::addNewFunc(const std::string & name, DataType returnType) {
    if (parentBlock != nullptr || belongTo != nullptr) {
        // TODO: throw exception
        return nullptr;
    } else if (symbolTable.count(name) > 0) {
        // TODO: throw exception
        return nullptr;
    }
    FuncSymbolInfo * newFunc = new FuncSymbolInfo(name, returnType);
    symbolTable[name] = newFunc;
    return newFunc;
}

BlockInfo * BlockInfo::addNewBlock(FuncSymbolInfo * belongTo, std::vector < SymbolInfo * > paramList) {
    BlockInfo * newBlock = new BlockInfo(this, belongTo, paramList);
    blockTable.push_back(newBlock);
    return newBlock;
}
BlockInfo * BlockInfo::addNewBlock() {
    BlockInfo * newBlock = new BlockInfo(this);
    blockTable.push_back(newBlock);
    return newBlock;
}

BlockInfo::BlockInfo(BlockInfo * parentBlock): parentBlock(parentBlock) { }
BlockInfo::BlockInfo(BlockInfo * parentBlock, FuncSymbolInfo * belongTo, const std::vector < SymbolInfo * > & paramList)
: parentBlock(parentBlock), belongTo(belongTo) {
    for (SymbolInfo * one_param : paramList) {
        symbolTable[one_param->getName()] = one_param;
    }
}