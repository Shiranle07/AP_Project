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
    IHash* hash1 = new HashOne();
    IHash* hash2 = new HashTwo();
    map<int, IHash*> hashesMap;
    hashesMap[1] = hash1;
    hashesMap[2] = hash2;
    ICommand* insert = new InsertUrlCommand();
    map<int, bool> hashToRunMap;

    BloomFilter* bloomFilter = new BloomFilter(hashToRunMap, hashesMap);
    string url = "https://www.example.com";

    EXPECT_EQ(bloomFilter->getUrlList().size(), 0);
    insert->execute(url, bloomFilter);
    EXPECT_NE(bloomFilter->getUrlList().size(), 0);
    EXPECT_EQ(bloomFilter->getUrlList().size(), 1);

    delete bloomFilter;
    delete insert;
    delete hash1;
    delete hash2;
}