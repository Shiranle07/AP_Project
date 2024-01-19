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
        while (true) {
            int task; //reading input
        try {
            commands[task]->execute();
        }
        catch(...){
        //...
        }
        }
    }
};
