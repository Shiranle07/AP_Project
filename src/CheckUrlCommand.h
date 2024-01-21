#ifndef CHECK_URL_COMMAND_H
#define CHECK_URL_COMMAND_H

#include <iostream>
#include <string>
#include <vector>
#include "BloomFilter.h"
#include "ICommand.h"

class CheckUrlCommand : public ICommand {
public:
    // Constructor
    CheckUrlCommand();

    // Execute function to check the existence of the URL in the Bloom filter array
    void execute(std::string url, std::vector<std::string>& urlList, BloomFilter& checkBloom) override;
};

#endif // CHECK_URL_COMMAND_H
