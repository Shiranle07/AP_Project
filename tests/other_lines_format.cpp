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

// Test case for checking if the string starts with digit 1 or 2
TEST(FormatTest, CheckOtherLines) {
    
    ICommand* check = new CheckUrlCommand();
    ICommand* insert = new InsertUrlCommand();
    map<int, ICommand*> commands;
    commands[1] = insert;
    commands[2] = check;
    IHash* hash1 = new HashOne();
    IHash* hash2 = new HashTwo();
    map<int, IHash*> hashesMap;
    hashesMap[1] = hash1;
    hashesMap[2] = hash2;
    map<int, bool> hashToRunMap;
    BloomFilter* bloomFilter = new BloomFilter(hashToRunMap, hashesMap);
    InputValidation* inputValidation = new InputValidation(commands, hashToRunMap, bloomFilter);
    
    vector<string> input_vector{"2", "@a"};
    // Good input: string starting with 2
    EXPECT_TRUE(inputValidation->checkOtherLines(input_vector));
    input_vector = {"2ww"};
    // Bad input: no space between digit and string
    EXPECT_FALSE(inputValidation->checkOtherLines(input_vector));
    input_vector = {"1"};
    // Bad input: missing url
    EXPECT_FALSE(inputValidation->checkOtherLines(input_vector));
    input_vector = {"3", "a-b"};
    // Bad input: string starting with a digit other than 1 or 2
    EXPECT_FALSE(inputValidation->checkOtherLines(input_vector));
    input_vector = {"www.example.com0"};
    // Bad input: string containing no numbers
    EXPECT_FALSE(inputValidation->checkOtherLines(input_vector));
    input_vector = {""};
    // Bad input: empty string
    EXPECT_FALSE(inputValidation->checkOtherLines(input_vector));
    input_vector = {"!", "www.example.com0"};
    // Bad input: string starting with a digit other than 1 or 2
    EXPECT_FALSE(inputValidation->checkOtherLines(input_vector));

    delete insert;
    delete check;
    delete hash1;
    delete hash2;
    delete bloomFilter;
    delete inputValidation;
}