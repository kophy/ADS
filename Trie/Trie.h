#ifndef __TRIE_H__
#define __TRIE_H__

#include <string>
#include <map>
#include <queue>

typedef struct TrieNode {
    bool completed;
    std::map<char, TrieNode *> children;
    TrieNode() : completed(false) {};
} TrieNode;

class Trie {
    public:
        Trie(void);
        ~Trie(void);
        void insert(std::string word);
        bool search(std::string word);
    private:
        TrieNode *root;
};

#endif
