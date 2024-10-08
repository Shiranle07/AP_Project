#ifndef INSERT_URL_COMMAND_H
#define INSERT_URL_COMMAND_H

#include <iostream>
#include <string>
#include <vector>
#include "BloomFilter.h"
#include "ICommand.h"

class InsertUrlCommand : public ICommand {
public:
    // Constructor
    InsertUrlCommand();

    // Execute function to add the URL to the vector and Bloom filter array
    bool execute(string url, BloomFilter* insertBloom);
};

#endif // INSERT_URL_COMMAND_H
