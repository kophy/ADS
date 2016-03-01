#ifndef __BLOOM_FILTER_H__
#define __BLOOM_FILTER_H__

#include <vector>
#include <string>

class BloomFilter {
    public:
        BloomFilter(unsigned int m, unsigned int k);
        void insertElement(std::string s);
        bool existsElement(std::string s);
    private:
        unsigned int BKDR_Hash(std::string s, unsigned int i);
        unsigned int getSeed(unsigned int hash_index);
        std::vector<bool> table;
        unsigned int _m;
        unsigned int _k;
};

#endif // __BLOOM_FILTER_H__
