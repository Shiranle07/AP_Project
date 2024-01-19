#include <string>
using namespace std;
#include <vector>
#include "BloomFilter.h" 
#include "ICommand.h"
#include "InsertUrlCommand.h"

// constructor implement
InsertURLCommand::InsertURLCommand(string url, vector<string>& urlList, BloomFilter& insertBloom)
            : url(url), urlList(urlList), insertBloom(insertBloom) {}


// add the url to the url vector and add the url to the bloom filter arrary according to the hash result
void InsertURLCommand::execute(){
    this->urlList.push_back(this->url);
    this->insertBloom.add(this->url);
}