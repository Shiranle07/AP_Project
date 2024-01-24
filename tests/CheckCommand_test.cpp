#include <gtest/gtest.h>
#include "../src/CheckUrlCommand.cpp"
#include "../src/HashOne.cpp"
#include "../src/HashTwo.cpp"
#include "../src/BloomFilter.cpp"
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

TEST(CheckCommandTest, Execute){
    IHash* hash1 = new HashOne();
    IHash* hash2 = new HashTwo();
    map<int, IHash*> hashesMap;
    hashesMap[1] = hash1;
    hashesMap[2] = hash2;
    ICommand* check = new CheckUrlCommand();
    map<int, bool> hashToRunMap;
    hashToRunMap[1] = true;

    BloomFilter* bloomFilter = new BloomFilter(hashToRunMap, hashesMap);
    bloomFilter->initialize(8);
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