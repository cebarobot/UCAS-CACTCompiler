#include <iostream>

#include "IR.h"

IRFunction::IRFunction(std::string newFunctionName)
: functionName(newFunctionName) { }

void IRFunction::print() {
    std::cout << "function " << functionName << ":" << std::endl;

    for (auto p : codes) {
        p->print();
    }

    std::cout << std::endl;
    std::cout << std::endl;
}

void IRProgram::print() {
    std::cout << "------------------------- IR -------------------------" << std::endl;
    std::cout << "data: " << std::endl;

    for (auto p : globalValues) {
        std::cout << p->getName() << std::endl;
    }

    std::cout << "text: " << std::endl;

    for (auto p : functions) {
        p->print();
    }

    std::cout << "========================= IR =========================" << std::endl;
}
