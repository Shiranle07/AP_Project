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
using namespace std;

App::App(map<string, ICommand*> commands, map<int, IHash*> hashesMap, map<int, bool>& hashToRunMap, BloomFilter bloomFilter) 
        : commands(commands), hashesMap(hashesMap), hashToRunMap(hashToRunMap), bloomFilter(bloomFilter) {}

void App::run() {
    int l = 0;
    InputValidation* checker = new InputValidation(this->commands, this->hashToRunMap);
    while (true) {
        //initilaize the hashToRun map with false
        for(auto& pair : this->hashesMap){
            this->hashToRunMap[pair.first] = false;
        }
        string input;
        cin >> input;
        istringstream iss(input); // converting the string input to a vector
        vector<string> line;
        string word;
        while(iss >> word){
            line.push_back(word);
        }
        if(l == 0){ // reading first line
            if(!checker->checkFirstLine(line)){
                continue;
            }
            l++; 
            // initilaze bloom filter
            this->bloomFilter->initialize(stoi(line[0]));
        }
        else{ // reading other lines
            if(!checker->checkOtherLines(line)){
                continue;
            }
        }

    }

    delete checker; 
}


int main(){
    IHash* hash1 = new HashOne;
    IHash* hash2 = new HashTwo;
    map<int, IHash*> hashesMap;
    hashesMap[1] = hash1;
    hashesMap[2] = hash2;
    ICommand* check = new CheckUrlCommand;
    ICommand* insert = new InsertUrlCommand;
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

