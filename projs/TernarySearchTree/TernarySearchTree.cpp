#include <iostream>
#include <cstdlib>
#include <cassert>
#include <queue>

#include "TernarySearchTree.h"

using namespace std;

TernarySearchTree::TernarySearchTree(void) {
    root = new TernarySearchTreeNode(128);
}

void TernarySearchTree::insert(string word) {
    assert(!word.empty());
    TernarySearchTreeNode *curr = root;
    int pos = 0;
    while (pos < word.size()) {
        if (word[pos] < curr->key) {
            if (curr->left == nullptr)
                curr->left = new TernarySearchTreeNode(word[pos]);
            curr = curr->left;
        } else if (word[pos] > curr->key) {
            if (curr->right == nullptr)
                curr->right = new TernarySearchTreeNode(word[pos]);
            curr = curr->right;
        } else {
            if (pos + 1 < word.size()) {
                if (curr->equal == nullptr)
                    curr->equal = new TernarySearchTreeNode(word[pos + 1]);
                curr = curr->equal;
            }
            ++pos;
        }
    }
    curr->completed = true;
}

void TernarySearchTree::remove(string word) {
    assert(!word.empty());
    TernarySearchTreeNode *curr = root;
    int pos = 0;
    while (pos < word.size()) {
        if (word[pos] < curr->key) {
            if (curr->left == nullptr)
                return;
            curr = curr->left;
        } else if (word[pos] > curr->key) {
            if (curr->right == nullptr)
                return;
            curr = curr->right;
        } else {
            if (pos + 1 < word.size()) {
                if (curr->equal == nullptr)
                    return;
                curr = curr->equal;
            }
            ++pos;
        }
    }
    curr->completed = false;
}

bool TernarySearchTree::search(string word) {
    assert(!word.empty());
    TernarySearchTreeNode *curr = root;
    int pos = 0;
    while (pos < word.size()) {
        if (word[pos] < curr->key) {
            if (curr->left == nullptr)
                return false;
            curr = curr->left;
        } else if (word[pos] > curr->key) {
            if (curr->right == nullptr)
                return false;
            curr = curr->right;
        } else {
            if (pos + 1 < word.size()) {
                if (curr->equal == nullptr)
                    return false;
                curr = curr->equal;
            }
            ++pos;
        }
    }
    return curr->completed;
}

void TernarySearchTree::traverse(void) {
    vector<string> result;
    traverseUtil(result, root, "");
    for (string s: result)
        cout << s << " ";
    cout << endl;
}

void TernarySearchTree::traverseUtil(vector<string> &result, TernarySearchTreeNode *curr, string path) {
    if (curr == nullptr)
        return;
    traverseUtil(result, curr->left, path);
    traverseUtil(result, curr->right, path);

    // only "equal" suggests the node is in the path
    path += curr->key;
    if (curr->completed)
        result.push_back(path);
    traverseUtil(result, curr->equal, path);
}
