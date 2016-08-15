#include <iostream>
#include <cstdlib>

#include "Trie.h"

using namespace std;

Trie::Trie(void) {
    root = new TrieNode();
}

Trie::~Trie(void) {
    queue<TrieNode *> data;
    data.push(root);
    // BFS: release all TrieNodes.
    while (!data.empty()) {
        TrieNode *curr = data.front();
        data.pop();
        for (auto iter = curr->children.begin(); 
                iter != curr->children.end(); ++iter) {
            data.push(iter->second);
        }
        delete curr;
    }
}

void Trie::insert(string word) {
    TrieNode *curr = root;
    for (int i = 0; i < word.size(); ++i) {
        if (curr->children.find(word[i]) == curr->children.end())
            curr->children[word[i]] = new TrieNode();
        curr = curr->children[word[i]];
    }
    curr->completed = true;
}

bool Trie::search(string word) {
    TrieNode *curr = root;
    for (int i = 0; i < word.size(); ++i) {
        if (curr->children.find(word[i]) == curr->children.end())
            return false;
        curr = curr->children[word[i]];
    }
    return curr->completed;
}
