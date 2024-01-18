#include <iostream>
using namespace std;
#include <string>
#include <map>

// the bloom filter implemention
class BloomFilter{
    private:
        int arrSize;
        int* bloomArr;
        map<int, bool> hashToRunMap;
        map<int, Ihash> hashesMap;

//constructor
    public:
        BloomFilter(int arrSize, std::map<int, bool> hashToRunMap, map<int, Ihash> hashesMap)
            : arrSize(arrSize), bloomArr(new int[arrSize]), hashToRunMap(hashToRunMap), hashesMap(hashesMap)  {}

// runs all the required hash functions on the url and changes the array according to the hashes results
    void add(string url){
        for(const auto& pair : this->hashToRunMap){
            if (pair.second){
                long bit = (this->hashesMap[pair.first].runFunc(url))%this->arrSize;
                this->bloomArr[bit] = 1;
            }
        }
    }

/* runs all the required hash functions on the url and checks if the bits are equal to 1 for all the hashes results
if one of the checks returns false, the iteration stops and returns false
if all checks return true, the method returns that the url exists(can be false positive). 
*/
    bool check(){
        for(const auto& pair : this->hashToRunMap){
            if (pair.second){
                long bit = (this->hashesMap[pair.first].runFunc(url))%this->arrSize;
                if(this->bloomArr[bit] == 1){
                    continue;
                }
                else return(false);
            }
        }
        return(true);
    }
}