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

// constructor
App::App(map<int, ICommand*> commands, map<int, IHash*> hashesMap, map<int, bool>& hashToRunMap, BloomFilter* bloomFilter) 
        : commands(commands), hashesMap(hashesMap), hashToRunMap(hashToRunMap), bloomFilter(bloomFilter) {}

// run methode that loops forever and runs the whole program
void App::run() {
    int l = 0;
    InputValidation* checker = new InputValidation(this->commands, this->hashToRunMap, this->bloomFilter);
    while (true) {
        string input;
        getline(cin, input);
        // converting the string input to a vector
        istringstream iss(input); 
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
            if(!checker->checkFirstLine(line)){ // if first line is invalid, starts new iteration
                continue;
            }
            ++l; // got valit first line
            // initilaze bloom filter according to the array size
            this->bloomFilter->initialize(stoi(line[0]));
        }
        else{ // reading other lines
            if(!checker->checkOtherLines(line)){
                continue; // if the line is invalid, starts new iteration
            }
        }

    }

    delete checker; 
}

