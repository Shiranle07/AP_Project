#include <string>
using namespace std;
#include <vector>
#include "BloomFilter.h" 

// the class includes objects that checks if an url exist by using bloom filter.
class CheckUrlCommand : public ICommand{

    private:
        string url;
        BloomFilter& checkBloom;

// constructor
    public:
        CheckUrlCommand(std::string url, BloomFilter& checkBloom)
            : url(url), checkBloom(checkBloom) {}

/* checks if the url exist in the bloom filter array.
if true, checks false positive case
if false, prints "false"
*/ 
    void execute(){
        bool result = checkBloom->check(this->url);
        if(!result){
            cout<<result<<endl;
        }
        else{
            // TODO: false positive check
        }
    }
};