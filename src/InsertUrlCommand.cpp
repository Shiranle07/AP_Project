#include <string>
using namespace std;
#include <vector>
#include "BloomFilter.h" 

// the class includes objects that adds an url to the structure.
class InsertURLCommand : public ICommand{
    private:
        string url;
        vector<string>& urlList;
        BloomFilter& insertBloom;

// constructor
    public:
        InsertURLCommand(std::string url, std::vector<std::string>& urlList, BloomFilter& insertBloom)
            : url(url), urlList(urlList), insertBloom(insertBloom) {}

// add the url to the url vector and add the url to the bloom filter arrary according to the hash result
    void execute(){
        this->urlList->push_back(this->url);
        this->insertBloom->add(this->url);
    }
};