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
if false, return "false"
*/ 
bool CheckUrlCommand::execute(string url, BloomFilter* checkBloom) {
    bool result = checkBloom->check(url); // checks the bloom filter array
    if(result){ // if the url exists, checking false positive
        bool blackListed = false;
        for (const string& strUrl : checkBloom->getUrlList()) {
            if (strUrl == url) {
                blackListed = true; // url was found in the vector
                break;
            }
        }
        return blackListed; // returning true if blacklisted, false otherwise
    }
    else{
        return false; // returning false if the url does not exist in the bloom filter
    }
}


