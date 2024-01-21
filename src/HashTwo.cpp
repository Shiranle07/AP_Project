#include <iostream>
#include <cmath>
#include <string>
#include "IHash.h"
#include "HashTwo.h"
using namespace std;

HashTwo::HashTwo() {}

long HashTwo::runFunc(string url){
        hash<string> hasher2;
        string temp_value = to_string(hasher2(url));
        return abs(static_cast<long>(hasher2(temp_value)));
    }