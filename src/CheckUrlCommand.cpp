#include <iostream>
#include <string>
#include <vector>
#include "BloomFilter.h"
#include "ICommand.h"
#include "CheckUrlCommand.h"
using namespace std;


// Constructor implementation
CheckUrlCommand::CheckUrlCommand() {}

/* checks if the url exist in the bloom filter array.
if true, checks false positive case
if false, prints "false"
*/ 
void CheckUrlCommand::execute(string url, vector<string>& urlList, BloomFilter& checkBloom){
    bool result = checkBloom.check(url);
    cout<<result<<endl;

    if(result){
        // false positive check******************8
    }
    
}

