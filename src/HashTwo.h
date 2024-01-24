#ifndef HASH_TWO_H
#define HASH_TWO_H

#include <iostream>
#include <string>
#include "IHash.h"
using namespace std;

// class for hash function implementation 
class HashTwo : public IHash {
public:
    HashTwo();

long runFunc(string url) override;
};

#endif // HASH_TWO_H
