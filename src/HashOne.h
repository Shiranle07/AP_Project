#ifndef HASH_ONE_H
#define HASH_ONE_H

#include <iostream>
#include <string>
#include "IHash.h"

class HashOne : public IHash {
public:
    HashOne();

    long runFunc(std::string url) override;
};

#endif // HASH_ONE_H
