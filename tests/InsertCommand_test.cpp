#include <gtest/gtest.h>
#include "../src/ICommand.h"
#include "../src/IHash.h"
#include "../src/BloomFilter.h"
#include "../src/InsertUrlCommand.h"
#include "../src/BloomFilter.cpp"
#include "../src/InsertUrlCommand.cpp"
#include "../src/CheckUrlCommand.h"
#include "../src/CheckUrlCommand.cpp"
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include "../src/HashOne.h"
#include "../src/HashTwo.h"
#include "../src/HashOne.cpp"
#include "../src/HashTwo.cpp"
#include <string>
using namespace std;

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

TEST(CheckCommandTest, Execute){
    IHash* hash1 = new HashOne();
    IHash* hash2 = new HashTwo();
    map<int, IHash*> hashesMap;
    hashesMap[1] = hash1;
    hashesMap[2] = hash2;
    ICommand* check = new CheckUrlCommand();
    map<int, bool> hashToRunMap;

    BloomFilter* bloomFilter = new BloomFilter(hashToRunMap, hashesMap);
    string url = "https://www.example.com0";
    string expectedOutput = "false\n";
    stringstream capturedOutput;
    streambuf* coutBuffer = cout.rdbuf();
    cout.rdbuf(capturedOutput.rdbuf());
    check->execute(url, bloomFilter);
    cout.rdbuf(coutBuffer);
    EXPECT_EQ(capturedOutput.str(), expectedOutput);

    delete bloomFilter;
    delete check;
    delete hash1;
    delete hash2;
}