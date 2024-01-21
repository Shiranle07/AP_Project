#include <map>
#include <string>
using namespace std;
#include "ICommand.h"

class InputValidation{
    private:
        map<string, ICommand*> commands;
        map<int, bool>& hashToRunMap;

    public:
        InputValidation(map<string, ICommand*>& commands, map<int, bool>& hashToRunMap) : commands(commands), hashToRunMap(hashToRunMap){}

    bool checkFirstLine(vector firstLine){
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

    bool checkOtherLines(vector otherLine){
        if(otherLine.size == 2){ // only command and url
            try{
                this->commands[stoi(otherLine[0])]->execute(otherLine[1]) // valid command
                // TODO: EXECUTE SHOULD GET THE URL *******************
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
}