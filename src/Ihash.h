#ifndef IHASH_H
#define IHASH_H

#include <string>
using namespace std;
#include <vector>

class IHash{
    public:
    virtual long runFunc(string url)=0;
};

#endif
