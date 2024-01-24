using namespace std;
#include <iostream>
#include <gtest/gtest.h>
#include <map>
#include <vector>
#include <string>
#include "../src/InputValidation.cpp"
#include "../src/HashOne.cpp"
#include "../src/HashTwo.cpp"
#include "../src/BloomFilter.cpp"
#include "../src/CheckUrlCommand.cpp"
#include "../src/InsertUrlCommand.cpp"


TEST(BloomFilterTest, AddAndCheckURL) {
    // Create Bloom filter with specific size
    IHash* hash1 = new HashOne();
    IHash* hash2 = new HashTwo();
    map<int, IHash*> hashesMap;
    hashesMap[1] = hash1;
    hashesMap[2] = hash2;
    map<int, bool> hashToRunMap;
    hashToRunMap[1] = true;
    BloomFilter* bloomFilter = new BloomFilter(hashToRunMap, hashesMap);

    //initialize the bloom-filter array
    bloomFilter->initialize(128);

    // Check a URL that hasn't been added
    EXPECT_FALSE(bloomFilter->check("www.nonexistent"));

    // Add a URL to the Bloom filter
    bloomFilter->add("www.example1");

    // Check if the Bloom filter recognizes the added URL
    EXPECT_TRUE(bloomFilter->check("www.example1"));


    delete hash1;
    delete hash2;
    delete bloomFilter;
}