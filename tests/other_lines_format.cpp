#include <gtest/gtest.h>
#include <cctype>
#include "../src/calc.cpp" // here we include the code to be tested

// todo : create an object
A a(a,b)

// Test case for checking if the string starts with digit 1 or 2
TEST(FormatTest, StartsWithDigitOneOrTwo) {
    // Good input: string starting with 2
    EXPECT_TRUE(startsWithDigitOneOrTwo("2 @a"));

    // Bad input: no space between digit and string
    EXPECT_FALSE(startsWithDigitOneOrTwo("2www"));

    // Bad input: missing url
    EXPECT_FALSE(startsWithDigitOneOrTwo("1"));

    // Bad input: string starting with a digit other than 1 or 2
    EXPECT_FALSE(startsWithDigitOneOrTwo("3 a-b"));

    // Bad input: string containing no numbers
    EXPECT_FALSE(startsWithDigitOneOrTwo("www.example.com0"));

    // Bad input: empty string
    EXPECT_FALSE(startsWithDigitOneOrTwo(""));

    // Bad input: string starting with a digit other than 1 or 2
    EXPECT_FALSE(startsWithDigitOneOrTwo("! www.example.com0"));
}