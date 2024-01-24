#include "ICommand.h"
#include "IHash.h"
#include "InputValidation.h"
#include "BloomFilter.h"
#include "CheckUrlCommand.h"
#include "InsertUrlCommand.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include "App.h"
#include "HashOne.h"
#include "HashTwo.h"
#include <string>
using namespace std;

int main(){
    IHash* hash1 = new HashOne();
    IHash* hash2 = new HashTwo();
    map<int, IHash*> hashesMap;
    hashesMap[1] = hash1;
    hashesMap[2] = hash2;
    ICommand* check = new CheckUrlCommand();
    ICommand* insert = new InsertUrlCommand();
    map<int, ICommand*> commands;
    commands[1] = insert;
    commands[2] = check;
    map<int, bool> hashToRunMap;

    BloomFilter* bloomFilter = new BloomFilter(hashToRunMap, hashesMap);
    App app(commands, hashesMap, hashToRunMap, bloomFilter);
    app.run();

    delete hash1;
    delete hash2;
    delete check;
    delete insert;
    delete bloomFilter;

}