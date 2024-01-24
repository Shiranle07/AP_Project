#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <string>
using namespace std;
#include <vector>
#include "BloomFilter.h" 

// interface for command object that has only execute methode
class ICommand{
    public:
        virtual void execute(string url, BloomFilter* bloom) = 0;
};

#endif
