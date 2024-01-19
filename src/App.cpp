#include "ICommand.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "IHash"

class App {
    private:
    map<string, ICommand*> commands;
    map<int, IHash*> hashesMap;
    map<int, bool> hashToRunMap;

    public:
    App(map<string, ICommand*> commands, map<int, IHash*> hashesMap, map<int, bool> hashToRunMap) 
        : commands(commands), hashesMap(hashesMap), hashToRunMap(hashToRunMap) {};

    void run() {
        int l = 0;
        while (true) {
            string input;
            cin >> input;
            istringstream iss(input); // converting the string input to a vector
            vector<string> line;
            while(iss >> word){
                line.pushback(word);
            }
            if(l == 0){ // reading first line
                try{
                    int arrSize = stoi(line[0]);
                    for (auto vec = line.begin() + 1; vec != line.end(); ++vec){ // changing the hashes bool values
                        hashToRunMap[stoi(*vec)] = true;
                    }
                    ++l; // got valid first line
                }
                catch(invalid_argunemt e){
                    continue;
                }
            }
            else{ // reading other lines
                if(line.size == 2){ // only command and url
                    try{
                        commands[stoi(line[0])]->execute(line[1]) // valid command
                        // TODO: EXECUTE SHOULD GET THE URL *******************
                    }
                    catch(invalid_argunemt e){
                        continue;
                    }
                }
            }

        }
    }


int main(){
    string firstLine;
    cin >> firstLine;

}

}
