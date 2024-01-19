#ifndef INSERTURLCOMMAND_H
#define INSERTURLCOMMAND_H

#include <string>
#include <vector>
#include "BloomFilter.h"
#include "ICommand.h"
using namespace std;

class InsertURLCommand : public ICommand {
private:
    string url;
    vector<string>& urlList;
    BloomFilter& insertBloom;

public:
    // Constructor
    InsertURLCommand(string url, vector<string>& urlList, BloomFilter& insertBloom);

    // Execute method that runs the command
    void execute();
};

#endif 
