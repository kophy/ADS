#ifndef __TERNARY_SEARCH_TREE__
#define __TERNARY_SEARCH_TREE__

#include <string>
#include <vector>

typedef struct TernarySearchTreeNode {
    char key;
    TernarySearchTreeNode *left, *equal, *right;
    bool completed;

    TernarySearchTreeNode(char k) {
        key = k;
        left = nullptr;
        equal = nullptr;
        right = nullptr;
        completed = false;
    }
} TernarySearchTreeNode;

class TernarySearchTree {
public:
    TernarySearchTree(void);
    void insert(std::string word);
    void remove(std::string word);
    bool search(std::string word);
    void traverse(void);
private:
    TernarySearchTreeNode *root;
    void traverseUtil(std::vector<std::string> &result, TernarySearchTreeNode *curr, std::string path);
};

#endif
