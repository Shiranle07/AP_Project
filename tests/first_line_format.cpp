#include <gtest/gtest.h>
#include <cctype>
#include "../src/calc.cpp" // here we include the code to be tested

// todo : create an object
A a(a,b)

// Checks that the first number in the input (array size) contain only digits.
TEST(FormatTest, JustDigits) {
    // Test with a normal array size
    EXPECT_TRUE(justDigits("256 1 2"));

    // Test with a negative array size
    EXPECT_FALSE(justDigits("-8 2 1"));
    
    // Test that array size = 0
    EXPECT_FALSE(justDigits("0 2 1"));

    // Test with a string containing also letter in array size
    EXPECT_FALSE(justDigits("128a 1 2"));

    // Test with a string containing no numbers in array size
    EXPECT_FALSE(justDigits("a 1 1"));

    // Test with an empty string
    EXPECT_FALSE(justDigits(""));
}

// Checks that the hash number is 1 or 2 only.
TEST(FormatTest, HashNumber) {
    // Test with a normal hash numbers
    EXPECT_TRUE(hashNumber("8 1 2"));

    // Test with a big hash number
    EXPECT_FALSE(hashNumber("8 3 2"));

    // Test with a small hash number
    EXPECT_FALSE(hashNumber("8 3 0"));

    // Test with a negative hash number
    EXPECT_FALSE(hashNumber("8 3 -2"));

    // Test with a string containing also letter in hash number
    EXPECT_FALSE(hashNumber("8 1 6"));

    // Test with no hash number
    EXPECT_FALSE(hashNumber("8"));
}

// Checks that the first input has more than one digit.
TEST(FormatTest, HasMoreThanOneNumber) {
    // Test with a string containing more than one number
    EXPECT_TRUE(hasMoreThanOneNumber("8 1 2"));

    // Test with a string containing only one number
    EXPECT_FALSE(hasMoreThanOneNumber("256"));

    // Test with a string containing no numbers
    EXPECT_FALSE(hasMoreThanOneNumber("a8b2c1"));

    // Test with an empty string
    EXPECT_FALSE(hasMoreThanOneNumber(""));
}