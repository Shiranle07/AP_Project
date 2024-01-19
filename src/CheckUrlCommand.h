#ifndef CHECKURLCOMMAND_H
#define CHECKURLCOMMAND_H

#include <string>
#include "BloomFilter.h"
#include "ICommand.h"
using namespace std;

// the class includes objects that checks if an url exist by using bloom filter.
class CheckUrlCommand : public ICommand {
private:
    string url;
    BloomFilter& checkBloom;

public:
    // Constructor
    CheckUrlCommand(string url, BloomFilter& checkBloom);

    // Execute that checks the URL
    void execute();
};

#endif // CHECKURLCOMMAND_H
