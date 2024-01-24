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

/*
this test checks the execute method of the object CheckUrlCommand.
the test checks if before the URL adding, the vector is empty and after the adding the vector size equal to 1.
*/
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
    string expectedOutputBefore = "false\n";

    stringstream capturedOutputBefore;
    streambuf* coutBufferBefore = cout.rdbuf();
    cout.rdbuf(capturedOutputBefore.rdbuf());

    check->execute(url, bloomFilter);
    cout.rdbuf(coutBufferBefore);
    EXPECT_EQ(capturedOutputBefore.str(), expectedOutputBefore);

    string expectedOutput = "true true\n";

    stringstream capturedOutputAfter;
    streambuf* coutBufferAfter = cout.rdbuf();   
    cout.rdbuf(capturedOutputAfter.rdbuf());

    BloomFilter->add(url);
    check->execute(url, bloomFilter);
    cout.rdbuf(coutBufferAfter);
    EXPECT_EQ(capturedOutputAfter.str(), expectedOutputBefore);


    delete bloomFilter;
    delete check;
    delete hash1;
    delete hash2;
    delete coutBufferBefore;
    delete coutBufferAfter;
}