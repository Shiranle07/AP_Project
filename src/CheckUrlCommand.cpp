#include <iostream>
#include <string>
#include <vector>
#include "BloomFilter.h"
#include "ICommand.h"
using namespace std;


// constructor implement
class CheckUrlCommand : public ICommand{

// constructor
    public:
        CheckUrlCommand(){}

/* checks if the url exist in the bloom filter array.
if true, checks false positive case
if false, prints "false"
*/ 
    void execute(string url, vector<string>& urlList, BloomFilter& checkBloom) override {
        bool result = checkBloom.check(url);
        cout<<result<<endl;

        if(result){
            // false positive check******************8
        }
        
    }
};
