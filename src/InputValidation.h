#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H

#include <map>
#include <string>
#include <vector>
#include "ICommand.h"
#include "BloomFilter.h"
using namespace std;

class InputValidation {
private:
    map<int, ICommand*>& commands;
    map<int, bool>& hashToRunMap;
    BloomFilter *bloomFilter;

public:
    InputValidation(map<int, ICommand*>& commands, map<int, bool>& hashToRunMap, BloomFilter* bloomFilter);

    bool checkFirstLine(vector<string>& firstLine);

    bool checkOtherLines(vector<string>& otherLine);
};

#endif // INPUTVALIDATION_H
