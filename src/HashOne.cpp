#include <iostream>
#include <cmath>
#include <string>
#include "IHash.h"
#include "HashOne.h"
using namespace std;

HashOne::HashOne() {}

long HashOne::runFunc(string url){
    hash<string> hasher1;
    return abs(static_cast<long>(hasher1(url)));
}