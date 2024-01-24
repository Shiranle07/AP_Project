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

/*
this is the main function to the program
*/
int main(){
    // all needed objects creation
    IHash* hash1 = new HashOne();
    IHash* hash2 = new HashTwo();
    map<int, IHash*> hashesMap;
    // initilizing hashes map with the supporting hash function on the program
    hashesMap[1] = hash1;
    hashesMap[2] = hash2;

    // initilizing commands map with the supporting commands on the program
    ICommand* check = new CheckUrlCommand();
    ICommand* insert = new InsertUrlCommand();
    map<int, ICommand*> commands;
    commands[1] = insert;
    commands[2] = check;

    // creating an empty map to the hash function the user will ask to use with
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