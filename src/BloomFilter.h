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
        map<int, bool>& hashToRunMap;
        map<int, IHash*>& hashesMap;
        vector <string> urlList;

//constructor
    public:
        BloomFilter(map<int, bool>& hashToRunMap, map<int, IHash*>& hashesMap);

// intilaize bloom filter array after input insertion
    void initialize(int arrSize);

// getter for the URL list
    vector<string>& getUrlList();

// adds URL to the bloom filter array
    void add(string url);

// checks if an URL exists in the bloom filter array
    bool check(string url);
};

#endif