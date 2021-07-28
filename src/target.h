#pragma once

#include <vector>
#include <string>
#include <iostream>

class TargetCodeList {
private:
    std::vector<std::string> list;
public:
    void add(std::string code);

    friend std::ostream& operator<<(std::ostream& os, const TargetCodeList& obj);
};