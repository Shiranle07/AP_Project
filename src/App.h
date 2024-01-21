#ifndef APP_H
#define APP_H

#include <map>
#include "ICommand.h"
#include "IHash.h"
#include "BloomFilter.h"
#include "InputValidation.h"
using namespace std;

class App {
private:
    map<int, ICommand*> commands;
    map<int, IHash*> hashesMap;
    map<int, bool>& hashToRunMap;
    BloomFilter *bloomFilter;

public:
    App(map<int, ICommand*> commands, map<int, IHash*> hashesMap, map<int, bool>& hashToRunMap, BloomFilter* bloomFilter);
    void run();
};

#endif // APP_H
