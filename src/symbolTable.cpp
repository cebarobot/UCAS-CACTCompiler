#include "symbolTable.h"

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
: SymbolInfo(name), returnType(returnType), paramNum(paramNum) {

}