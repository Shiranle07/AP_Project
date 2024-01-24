#include <gtest/gtest.h>
#include "../src/InsertUrlCommand.cpp"
#include "../src/HashOne.h"
#include "../src/HashTwo.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

/*
this test checks the execute method of the object InsertUrlCommand.
the test checks if before the URL adding, the vector is empty and after the adding the vector size equal to 1.
*/
TEST(InsertCommandTest, Execute){
    // initializing the requierd objects for the test
    IHash* hash1 = new HashOne();
    IHash* hash2 = new HashTwo();
    map<int, IHash*> hashesMap;
    hashesMap[1] = hash1;
    hashesMap[2] = hash2;
    ICommand* insert = new InsertUrlCommand();
    map<int, bool> hashToRunMap;
    BloomFilter* bloomFilter = new BloomFilter(hashToRunMap, hashesMap);
    
    string url = "https://www.example.com";

    EXPECT_EQ(bloomFilter->getUrlList().size(), 0); // expecting empty vector before adding
    insert->execute(url, bloomFilter); // adding url
    EXPECT_NE(bloomFilter->getUrlList().size(), 0); // expecting unempty vector after adding
    EXPECT_EQ(bloomFilter->getUrlList().size(), 1); // expecting vector's size increased by 1

    // deleting objects
    delete bloomFilter;
    delete insert;
    delete hash1;
    delete hash2;
}