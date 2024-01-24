#include <iostream>
#include <cmath>
#include <string>
#include "IHash.h"
#include "HashOne.h"
using namespace std;

// Constructor
HashOne::HashOne() {}

// running hash 1 by using the built-in function std::hash
long HashOne::runFunc(string url){
    hash<string> hasher1;
    return abs(static_cast<long>(hasher1(url)));
}