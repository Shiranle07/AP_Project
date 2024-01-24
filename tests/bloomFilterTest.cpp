#include <gtest/gtest.h>
#include <map>
#include <vector>
#include "../src/InputValidation.cpp"  // Include the correct header file



// Test case for checking if the string starts with digit 1 or 2
TEST(FormatTest, BloomFilterTest) {
    
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