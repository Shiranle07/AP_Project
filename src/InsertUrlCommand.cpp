#include <iostream>
#include <string>
#include <vector>
#include "BloomFilter.h"
#include "ICommand.h"
#include "InsertUrlCommand.h"
using namespace std;

// Constructor implementation
InsertUrlCommand::InsertUrlCommand() {}

// add the url to the url vector and add the url to the bloom filter arrary according to the hash result
void InsertUrlCommand::execute(string url, BloomFilter& insertBloom){
    insertBloom->getUrlList().push_back(url);
    insertBloom.add(url);
}
