#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H

#include <map>
#include <string>
#include <vector>
#include "ICommand.h"
#include "BloomFilter.h"
using namespace std;

/*
this class checks all inputs in the program 
*/
class InputValidation {
private:
    map<int, ICommand*>& commands;
    map<int, bool>& hashToRunMap;
    BloomFilter *bloomFilter;

// Constructor
public:
    InputValidation(map<int, ICommand*>& commands, map<int, bool>& hashToRunMap, BloomFilter* bloomFilter);
    
// first line must include array size and hash functions numbers
    bool checkFirstLine(vector<string>& firstLine);

// all other lines must include valid command and url address
    bool checkOtherLines(vector<string>& otherLine);
};

#endif // INPUTVALIDATION_H
