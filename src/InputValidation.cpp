#include <map>
#include <string>
using namespace std;
#include "ICommand.h"
#include "InputValidation.h"
#include <vector>
#include <algorithm>
#include <cctype>
#include "BloomFilter.h"

// Constructor
InputValidation::InputValidation(map<int, ICommand*>& commands, map<int, bool>& hashToRunMap, BloomFilter* bloomFilter)
    : commands(commands), hashToRunMap(hashToRunMap), bloomFilter(bloomFilter) {}

// this method checks the validation of the first line of the input
bool InputValidation::checkFirstLine(vector<string>& firstLine){
    if(firstLine.size()<2){ // must be at least 2 arguments - array size and hash function
         return false;
    }
    try{
        // array size is digit and must be positive number
        if(!(all_of(firstLine[0].begin(), firstLine[0].end(), ::isdigit)) or (stoi(firstLine[0])<=0)){
            return(false);
        }
        for (auto vec = firstLine.begin() + 1; vec != firstLine.end(); ++vec){ // changing the hashes bool values
            if(!(all_of((*vec).begin(), (*vec).end(), ::isdigit))){ // hash function must be digit
                return false;
            }

            if(hashToRunMap.find(stoi(*vec)) != hashToRunMap.end()){ // checks hash function number's validation
            hashToRunMap[stoi(*vec)] = true; // if valid, changing to true
            }
            else{
                return(false); // case the user gave invalid hash function
            }
        }
    }
    catch(invalid_argument& e){
        return(false);
    }
    return(true); // all checks passed
}

// this method checks the validation of the other lines of the input
bool InputValidation::checkOtherLines(vector<string>& otherLine){
    if(otherLine.size() == 2){ // only command and url
        try{
            if(!(all_of(otherLine[0].begin(), otherLine[0].end(), ::isdigit))){ // command must be a digit
                return(false);
            }
            if(commands.find(stoi(otherLine[0])) != commands.end()){
                return this->commands[stoi(otherLine[0])]->execute(otherLine[1], this->bloomFilter); // valid command
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
