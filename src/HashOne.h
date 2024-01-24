#ifndef HASH_ONE_H
#define HASH_ONE_H

#include <iostream>
#include <string>
#include "IHash.h"
using namespace std;

// class for hash function implementation 
class HashOne : public IHash {
public:
    HashOne();

long runFunc(string url) override;
};

#endif // HASH_ONE_H
