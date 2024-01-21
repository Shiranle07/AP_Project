#include <iostream>
#include <string>
#include <vector>
#include "BloomFilter.h"
#include "ICommand.h"
using namespace std;

class InsertUrlCommand : public ICommand {

// Constructor 
    public:
        InsertUrlCommand() {}

// add the url to the url vector and add the url to the bloom filter arrary according to the hash result
    void execute(string url, vector<string>& urlList, BloomFilter& insertBloom) override {
        urlList.push_back(url);
        insertBloom.add(url);
    }
};