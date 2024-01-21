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
void CheckUrlCommand::execute(string url, BloomFilter* checkBloom){
    bool result = checkBloom->check(url);
    cout << boolalpha << result << endl;

    if(result){
        bool blackListed = false;
        for (const string& strUrl : checkBloom->getUrlList()) {
            if (strUrl == url) {
                blackListed = true;
                break;
            }
        }
        cout << boolalpha << blackListed << endl;

    }
    
}

