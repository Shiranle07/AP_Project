#include <map>
#include <string>
using namespace std;
#include "ICommand.h"
#include "InputValidation.h"
#include <vector>

InputValidation::InputValidation(map<string, ICommand*>& commands, map<int, bool>& hashToRunMap)
    : commands(commands), hashToRunMap(hashToRunMap) {}

bool InputValidation::checkFirstLine(vector<string> firstLine){
    try{
        int arrSize = stoi(firstLine[0]);
        for (auto vec = firstLine.begin() + 1; vec != firstLine.end(); ++vec){ // changing the hashes bool values
            hashToRunMap[stoi(*vec)] = true;
        }
    }
    catch(invalid_argunemt e){
        return(false);
    }
    return(true);
}

bool InputValidation::checkOtherLines(vector<string> otherLine){
    if(otherLine.size == 2){ // only command and url
        try{
            this->commands[stoi(otherLine[0])]->execute(otherLine[1], this->bloomFilter) // valid command
        }
        catch(invalid_argunemt e){
            return(false);
        }
    }
    else{
        return(false);
    }
    return(true);
}
