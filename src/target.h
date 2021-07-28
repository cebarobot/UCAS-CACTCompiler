#pragma once

#include <vector>
#include <string>
#include <iostream>

class TargetCodeList {
private:
    std::vector<std::string> list;

    int countParamX = 0;
    int countParamF = 0;
    int countGetParamX = 0;
    int countGetParamF = 0;

public:
    void add(std::string code);

    friend std::ostream& operator<<(std::ostream& os, const TargetCodeList& obj);

    std::string getRegParamX();
    std::string getRegParamF();
    void resetRegParam();

    std::string getRegGetParamX();
    std::string getRegGetParamF();
};

std::ostream& operator<<(std::ostream& os, const TargetCodeList& obj);