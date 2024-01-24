#include <map>
#include <string>
using namespace std;
#include "ICommand.h"
#include "InputValidation.h"
#include <vector>
#include <algorithm>
#include <cctype>
#include "BloomFilter.h"

InputValidation::InputValidation(map<int, ICommand*>& commands, map<int, bool>& hashToRunMap, BloomFilter* bloomFilter)
    : commands(commands), hashToRunMap(hashToRunMap), bloomFilter(bloomFilter) {}

bool InputValidation::checkFirstLine(vector<string>& firstLine){
    if(firstLine.size()<2){
         return false;
    }
    try{
        // array size is digit and must be positive number
        if(!(all_of(firstLine[0].begin(), firstLine[0].end(), ::isdigit)) or (stoi(firstLine[0])<=0)){
            return(false);
        }
        for (auto vec = firstLine.begin() + 1; vec != firstLine.end(); ++vec){ // changing the hashes bool values
            if(!(all_of((*vec).begin(), (*vec).end(), ::isdigit))){
                return false;
            }

            if(hashToRunMap.find(stoi(*vec)) != hashToRunMap.end()){
            hashToRunMap[stoi(*vec)] = true;
            }
            else{
                return(false);
            }
        }
    }
    catch(invalid_argument& e){
        return(false);
    }
    return(true);
}

bool InputValidation::checkOtherLines(vector<string>& otherLine){
    if(otherLine.size() == 2){ // only command and url
        try{
            if(!(all_of(otherLine[0].begin(), otherLine[0].end(), ::isdigit))){
                return(false);
            }
            if(commands.find(stoi(otherLine[0])) != commands.end()){
                this->commands[stoi(otherLine[0])]->execute(otherLine[1], this->bloomFilter); // valid command
            }
            else{
                return(false);
            }
        }
        catch(exception& e){
            return(false);
        }
    }
    else{
        return(false);
    }
    return(true);
}
