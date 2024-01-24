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

App::App(map<int, ICommand*> commands, map<int, IHash*> hashesMap, map<int, bool>& hashToRunMap, BloomFilter* bloomFilter) 
        : commands(commands), hashesMap(hashesMap), hashToRunMap(hashToRunMap), bloomFilter(bloomFilter) {}

void App::run() {
    int l = 0;
    InputValidation* checker = new InputValidation(this->commands, this->hashToRunMap, this->bloomFilter);
    while (true) {
        string input;
        getline(cin, input);
        istringstream iss(input); // converting the string input to a vector
        vector<string> line;
        string word;
        while(iss >> word){
            line.push_back(word);
        }
        if(l == 0){ // reading first line
        //initilaize the hashToRun map with false before getting first line
            for(auto& pair : this->hashesMap){
                this->hashToRunMap[pair.first] = false;
            }
            if(!checker->checkFirstLine(line)){
                continue;
            }
            ++l;
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

