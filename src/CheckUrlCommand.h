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
    bool execute(string url, BloomFilter* checkBloom);
};

#endif // CHECK_URL_COMMAND_H
