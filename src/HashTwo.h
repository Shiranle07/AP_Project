#ifndef HASH_TWO_H
#define HASH_TWO_H

#include <iostream>
#include <string>
#include "IHash.h"

class HashTwo : public IHash {
public:
    HashTwo();

    long runFunc(std::string url) override;
};

#endif // HASH_TWO_H
