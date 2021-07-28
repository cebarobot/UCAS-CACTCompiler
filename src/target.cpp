
#include "target.h"

void TargetCodeList::add(std::string code) {
    list.push_back(code);
}

std::ostream& operator<<(std::ostream& os, const TargetCodeList& obj) {
    for (auto code : obj.list) {
        os << code << std::endl;
    }
    return os;
}

std::string TargetCodeList::getRegParamX() {
    std::string name = std::string("a") + std::to_string(countParamX);
    countParamX += 1;
    return name;
}

std::string TargetCodeList::getRegParamF() {
    std::string name = std::string("fa") + std::to_string(countParamF);
    countParamF += 1;
    return name;
}

void TargetCodeList::resetRegParam() {
    countParamX = 0;
    countParamF = 0;
}

std::string TargetCodeList::getRegGetParamX() {
    std::string name = std::string("a") + std::to_string(countGetParamX);
    countGetParamX += 1;
    return name;
}

std::string TargetCodeList::getRegGetParamF() {
    std::string name = std::string("fa") + std::to_string(countGetParamF);
    countGetParamF += 1;
    return name;
}