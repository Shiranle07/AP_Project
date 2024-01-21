#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H

#include <map>
#include <string>
#include <vector>
#include "ICommand.h"
#include "BloomFilter.h"

class InputValidation {
private:
    std::map<std::string, ICommand*>& commands;
    std::map<int, bool>& hashToRunMap;
    BloomFilter bloomFilter;

public:
    InputValidation(std::map<std::string, ICommand*>& commands, std::map<int, bool>& hashToRunMap);

    bool checkFirstLine(const std::vector<std::string>& firstLine);

    bool checkOtherLines(const std::vector<std::string>& otherLine);
};

#endif // INPUTVALIDATION_H
