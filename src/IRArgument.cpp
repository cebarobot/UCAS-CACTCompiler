#include <IR.h>

IRArgument::IRArgument(std::string newValue)
: value(newValue) {}

std::string IRArgument::getValue() {
    return value;
}

IRConst::IRConst(std::string newValue)
: IRArgument(newValue) { }

IRIntConst::IRIntConst(std::string newValue)
: IRConst(newValue) { }