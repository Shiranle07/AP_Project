#ifndef APP_H
#define APP_H

#include <map>
#include "ICommand.h"
#include "IHash.h"
#include "BloomFilter.h"
#include "InputValidation.h"

class App {
private:
    std::map<std::string, ICommand*> commands;
    std::map<int, IHash*> hashesMap;
    std::map<int, bool>& hashToRunMap;
    BloomFilter bloomFilter;

public:
    App(std::map<std::string, ICommand*> commands, std::map<int, IHash*> hashesMap, std::map<int, bool>& hashToRunMap, BloomFilter bloomFilter);
    void run();
};

#endif // APP_H
