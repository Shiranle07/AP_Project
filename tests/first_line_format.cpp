#include <gtest/gtest.h>
#include <map>
#include <vector>
#include "../src/InputValidation.h"  // Include the correct header file

// Checks that the first number in the input (array size) contain only digits.
TEST(InputValidationTest, CheckFirstLine) {

    /**Create an instance of InputValidation with necessary maps and BloomFilter***************
    need the parameters to send???***************
    */ 

    std::map<int, ICommand*> commands;
    std::map<int, bool> hashToRunMap;
    BloomFilter* bloomFilter = new BloomFilter(/* pass constructor arguments */);
    InputValidation inputValidation(commands, hashToRunMap, bloomFilter);

    // Test with a normal array size
    EXPECT_TRUE(inputValidation.checkFirstLine({256, 1, 2}));

    // Test with a negative array size
    EXPECT_FALSE(inputValidation.checkFirstLine({-8, 2, 2}));
    
    // Test that array size = 0
    EXPECT_FALSE(inputValidation.checkFirstLine({0, 2, 1}));

    // Test with a string containing also letter in array size
    EXPECT_FALSE(inputValidation.checkFirstLine({128a, 1, 2}));

    // Test with a string containing no numbers in array size
    EXPECT_FALSE(inputValidation.checkFirstLine({a, 1, 1}));

    // Test with an empty string
    EXPECT_FALSE(inputValidation.checkFirstLine({}));
}

// Checks that the hash number is 1 or 2 only.
TEST(InputValidationTest, CheckFirstLine) {
    // Test with a normal hash numbers
    EXPECT_TRUE(inputValidation.checkFirstLine({8, 1, 2}));

    // Test with a big hash number
    EXPECT_FALSE(inputValidation.checkFirstLine({8, 3, 2}));

    // Test with a small hash number
    EXPECT_FALSE(inputValidation.checkFirstLine({8, 3, 0}));

    // Test with a negative hash number
    EXPECT_FALSE(inputValidation.checkFirstLine({8, 3, -2}));

    // Test with a string containing also letter in hash number
    EXPECT_FALSE(inputValidation.checkFirstLine({8, 1, 6}));

    // Test with no hash number
    EXPECT_FALSE(inputValidation.checkFirstLine({8}));
}

// Checks that the first input has more than one digit.
TEST(InputValidationTest, CheckFirstLine) {
    // Test with a string containing more than one number
    EXPECT_TRUE(inputValidation.checkFirstLine({8, 1, 2}));

    // Test with a string containing only one number
    EXPECT_FALSE(inputValidation.checkFirstLine({256}));

    // Test with a string containing no numbers
    EXPECT_FALSE(inputValidation.checkFirstLine({a8b2c1}));

    // Test with an empty string
    EXPECT_FALSE(inputValidation.checkFirstLine({}));
}