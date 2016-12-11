#include <iostream>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <stack>

#include "AvlTree.h"

using namespace std;

AvlTree::AvlTree(void) {
    root = nullptr;
}

AvlTree::~AvlTree(void) {
    stack<AvlTreeNode *> data;
    while (root != nullptr) {
        data.push(root);
        root = root->left;
    }
    while (!data.empty()) {
        auto curr = data.top();
        data.pop();
        auto temp = curr->right;
        delete curr;
        while (temp != nullptr) {
            data.push(temp);
            temp = temp->left;
        }
    }
}

// three wrapper functions
bool AvlTree::search(int key) {
    return search(root, key);
}

bool AvlTree::insert(int key) {
    if (search(key))
        return false;
    root = insert(root, key);
    return true;
}

bool AvlTree::remove(int key) {
    if (!search(key))
        return false;
    root = remove(root, key);
    return true;
}

void AvlTree::traverse(visit v) {
    traverse(root, v);
}

bool AvlTree::search(AvlTreeNode *p, int key) {
    if (p == nullptr)
        return false;
    else if (p->key == key)
        return true;
    else
        return (p->key < key)? search(p->right, key) : search(p->left, key);
}

AvlTreeNode *AvlTree::insert(AvlTreeNode *p, int key) {
    if (p == nullptr)
        return new AvlTreeNode(key);
    else if (p->key < key)
        p->right = insert(p->right, key);
    else
        p->left = insert(p->left, key);
    return fix_balance(p);
}

AvlTreeNode *AvlTree::remove(AvlTreeNode *p, int key) {
    if (p == nullptr)
        return nullptr;
    if (p->key < key)
        p->right = remove(p->right, key);
    else if (p->key > key)
        p->left = remove(p->left, key);
    else {
        AvlTreeNode *l = p->left, *r = p->right;
        // case 1: has empty subtree, delete directly
        if (l == nullptr || r == nullptr) {
            delete p;
            return (l != nullptr)? l : r;
        }
        // case 2: no empty subtree, find substitute
        else {
            AvlTreeNode *temp = r;
            while (temp->left)
                temp = temp->left;
            swap(p->key, temp->key);
            p->right = remove(r, key);
        }
    }
    return fix_balance(p);
}

void AvlTree::traverse(AvlTreeNode *p, visit v) {
    if (p == nullptr)
        return;
    traverse(p->left, v);
    v(p);
    traverse(p->right, v);
}
