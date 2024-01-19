#include <iostream>
#include <cmath>
using namespace std;

class HashOne : public IHash{
    public:
        HashOne(){};

    long runFunc(string url){
        hash<string> hasher1;
        return abs(static_cast<long>(hasher1(url)));
    }
};