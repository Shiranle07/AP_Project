#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

#include <iostream>
using namespace std;
#include <string>
#include <map>
#include "IHash.h"

// the bloom filter class
class BloomFilter{
    private:
        int arrSize;
        int* bloomArr;
        map<int, bool> hashToRunMap;
        map<int, IHash*> hashesMap;

//constructor
    public:
        BloomFilter(int arrSize, map<int, bool> hashToRunMap, map<int, IHash*> hashesMap);

// adds URL to the bloom filter array
    void add(string url);

// checks if an URL exists in the bloom filter array
    bool check();
};

#endif