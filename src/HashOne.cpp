#include <iostream>
#include <cmath>
#include <string>
#include "IHash.h"
using namespace std;

class HashOne : public IHash{
    public:
        HashOne(){}

    long runFunc(string url) override {
        hash<string> hasher1;
        return abs(static_cast<long>(hasher1(url)));
    }
};