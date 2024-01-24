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



// Checks that the first number in the input (array size) contain only digits.
TEST(InputValidationTest1, CheckFirstLine) {

    /**Create an instance of InputValidation with necessary maps and BloomFilter***************
    need the parameters to send???***************
    */ 
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
    hashToRunMap[1] = false;
    hashToRunMap[2] = false;
    BloomFilter* bloomFilter = new BloomFilter(hashToRunMap, hashesMap);
    InputValidation* inputValidation = new InputValidation(commands, hashToRunMap, bloomFilter);

    vector<string> input_vector{"256", "1", "2"};
    // Test with a normal array size
    EXPECT_TRUE(inputValidation->checkFirstLine(input_vector));
    input_vector = {"-8", "2", "2"};
    // Test with a negative array size
    EXPECT_FALSE(inputValidation->checkFirstLine(input_vector));
    input_vector = {"0", "2", "1"};
    // Test that array size = 0
    EXPECT_FALSE(inputValidation->checkFirstLine(input_vector));
    input_vector = {"128a", "1", "2"};
    // Test with a string containing also letter in array size
    EXPECT_FALSE(inputValidation->checkFirstLine(input_vector));
    input_vector = {"a", "1", "1"};
    // Test with a string containing no numbers in array size
    EXPECT_FALSE(inputValidation->checkFirstLine(input_vector));
    input_vector = {""};
    // Test with an empty string
    EXPECT_FALSE(inputValidation->checkFirstLine(input_vector));

    delete insert;
    delete check;
    delete hash1;
    delete hash2;
    delete bloomFilter;
    delete inputValidation;

}

// Checks that the hash number is 1 or 2 only.
TEST(InputValidationTest2, CheckFirstLine) {

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
    vector<string> input_vector{"8", "3", "2"};

    // Test with a big hash number
    EXPECT_FALSE(inputValidation->checkFirstLine(input_vector));
    input_vector = {"8", "3", "0"};

    // Test with a small hash number
    EXPECT_FALSE(inputValidation->checkFirstLine(input_vector));
    input_vector = {"8", "3", "-2"};

    // Test with a negative hash number
    EXPECT_FALSE(inputValidation->checkFirstLine(input_vector));
    input_vector = {"8", "1", "a6"};

    // Test with a string containing also letter in hash number
    EXPECT_FALSE(inputValidation->checkFirstLine(input_vector));
    input_vector = {"8"};

    // Test with no hash number
    EXPECT_FALSE(inputValidation->checkFirstLine(input_vector));

    delete insert;
    delete check;
    delete hash1;
    delete hash2;
    delete bloomFilter;
    delete inputValidation;
}

// Checks that the first input has more than one digit.
TEST(InputValidationTest3, CheckFirstLine) {
    
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
    vector<string> input_vector{"256"};
    // Test with a string containing only one number
    EXPECT_FALSE(inputValidation->checkFirstLine(input_vector));
    input_vector = {"a8b2c1"};

    // Test with a string containing no numbers
    EXPECT_FALSE(inputValidation->checkFirstLine(input_vector));
    
    delete insert;
    delete check;
    delete hash1;
    delete hash2;
    delete bloomFilter;
    delete inputValidation;
}