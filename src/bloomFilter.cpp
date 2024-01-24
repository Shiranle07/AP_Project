#include <iostream>
using namespace std;
#include <string>
#include <map>
#include <vector>
#include "BloomFilter.h"
#include "IHash.h"

//constructor implement
BloomFilter::BloomFilter(map<int, bool>& hashToRunMap, map<int, IHash*>& hashesMap)
        : arrSize(0), bloomArr(nullptr), hashToRunMap(hashToRunMap), hashesMap(hashesMap), urlList(){}

// destructor implement
BloomFilter::~BloomFilter() {
    delete[] bloomArr;
}

// initialize the bloom filter array by the giving array size
void BloomFilter::initialize(int size) {
    this->arrSize = size;
    this->bloomArr = new int[arrSize];
}

// getter for the url list
vector<string>& BloomFilter::getUrlList(){
    return(this->urlList);
}

// runs all the required hash functions on the url and changes the array according to the hashes results
void BloomFilter::add(string url){
    for(auto& pair : this->hashToRunMap){
        if (pair.second){
            long bit = (this->hashesMap[pair.first]->runFunc(url))%this->arrSize;
            this->bloomArr[bit] = 1;
        }
    }
}

/* runs all the required hash functions on the url and checks if the bits are equal to 1 for all the hashes results
if one of the checks returns false, the iteration stops and returns false
if all checks return true, the method returns that the url exists(can be false positive). 
*/
bool BloomFilter::check(string url){
    for(const auto& pair : this->hashToRunMap){
        if (pair.second){
            long bit = (this->hashesMap[pair.first]->runFunc(url))%this->arrSize;
            if(this->bloomArr[bit] == 1){
                continue;
            }
            else return(false);
        }
    }
    return(true);
}


