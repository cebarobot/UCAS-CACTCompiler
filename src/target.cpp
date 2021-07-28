
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