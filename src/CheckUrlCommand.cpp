#include <string>
using namespace std;
#include <vector>
#include "BloomFilter.h" 
#include "ICommand.h"
#include "CheckUrlCommand.h"

// constructor implement
CheckUrlCommand::CheckUrlCommand(string url, BloomFilter& checkBloom)
            : url(url), checkBloom(checkBloom) {};


/* checks if the url exist in the bloom filter array.
if true, checks false positive case
if false, prints "false"
*/ 
void CheckUrlCommand::execute(){
    bool result = checkBloom.check(this->url);
    if(!result){
        cout<<"false"<<endl;
    }
    else{
            // TODO: false positive check
    }
};
