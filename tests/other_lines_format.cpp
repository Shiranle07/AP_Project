#include <gtest/gtest.h>
#include <map>
#include <vector>
#include "../src/InputValidation.cpp"  // Include the correct header file



// Test case for checking if the string starts with digit 1 or 2
TEST(FormatTest, StartsWithDigitOneOrTwo) {
    
    IHash* hash1 = new HashOne();
    IHash* hash2 = new HashTwo();
    map<int, IHash*> hashesMap;
    hashesMap[1] = hash1;
    hashesMap[2] = hash2;
    map<int, bool> hashToRunMap;
    BloomFilter* bloomFilter = new BloomFilter(hashToRunMap, hashesMap);
    InputValidation* inputValidation = new InputValidation(commands, hashToRunMap, bloomFilter);

    // Good input: string starting with 2
    EXPECT_TRUE(startsWithDigitOneOrTwo({2, @a}));

    // Bad input: no space between digit and string
    EXPECT_FALSE(startsWithDigitOneOrTwo({2www}));

    // Bad input: missing url
    EXPECT_FALSE(startsWithDigitOneOrTwo({1}));

    // Bad input: string starting with a digit other than 1 or 2
    EXPECT_FALSE(startsWithDigitOneOrTwo({3, a-b}));

    // Bad input: string containing no numbers
    EXPECT_FALSE(startsWithDigitOneOrTwo({www.example.com0}));

    // Bad input: empty string
    EXPECT_FALSE(startsWithDigitOneOrTwo({}));

    // Bad input: string starting with a digit other than 1 or 2
    EXPECT_FALSE(startsWithDigitOneOrTwo({!, www.example.com0}));

    delete hash1;
    delete hash2;
    delete bloomFilter;
    delete inputValidation;
}