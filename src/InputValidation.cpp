#include <map>
#include <string>
using namespace std;
#include "ICommand.h"
#include "InputValidation.h"
#include <vector>
#include "BloomFilter.h"

InputValidation::InputValidation(map<int, ICommand*>& commands, map<int, bool>& hashToRunMap, BloomFilter* bloomFilter)
    : commands(commands), hashToRunMap(hashToRunMap), bloomFilter(bloomFilter) {}

bool InputValidation::checkFirstLine(vector<string>& firstLine){
    try{
        int arrSize = stoi(firstLine[0]);
        for (auto vec = firstLine.begin() + 1; vec != firstLine.end(); ++vec){ // changing the hashes bool values
            if(hashToRunMap.find(stoi(*vec)) != hashToRunMap.end()){
            hashToRunMap[stoi(*vec)] = true;
            }
            else{
                    // ******* check *********
    cout << "check first line: FALSE" << endl;
                return(false);
            }
        }
    }
    catch(invalid_argument& e){
    // ******* check *********
    cout << "check first line: FALSE" << endl;
        return(false);
    }
    // ******* check *********
    cout << "check first line: TRUE" << endl;
    return(true);
}

bool InputValidation::checkOtherLines(vector<string>& otherLine){
    if(otherLine.size() == 2){ // only command and url
        try{
            if(commands.find(stoi(otherLine[0])) != commands.end()){
                this->commands[stoi(otherLine[0])]->execute(otherLine[1], this->bloomFilter); // valid command
            }
            else{
                    // ******* check *********
    cout << "check other line: FALSE" << endl;
                return(false);
            }
        }
        catch(exception& e){
                // ******* check *********
    cout << "check other line: FALSE" << endl;
            return(false);
        }
    }
    else{
            // ******* check *********
    cout << "check other line: FALSE" << endl;
        return(false);
    }
    // ******* check *********
    cout << "check other line: TRUE" << endl;
    return(true);
}
