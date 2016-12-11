#include <iostream>
#include <cstdlib>
#include <algorithm>

#include "AvlTreeNode.h"

using namespace std;

unsigned int get_height(AvlTreeNode *p) {
    return (p == nullptr)? 0 : p->height;
}

void fix_height(AvlTreeNode *p) {
    if (p == nullptr)
        return;
    p->height = max(get_height(p->left), get_height(p->right)) + 1;
}

int get_balance(AvlTreeNode *p) {
    return get_height(p->right) - get_height(p->left);
}

AvlTreeNode *fix_balance(AvlTreeNode *p) {
    fix_height(p);
    int balance = get_balance(p);
    // case 1: invalid, right too deep
    if (balance == 2) {
        // fix right subtree if left rotation leads to its left subtree too deep
        if (get_balance(p->right) < 0)
            p->right = rotate(p->right, RIGHT);
        return rotate(p, LEFT);
    }
    // case 2: invalid, left too deep
    else if (balance == -2) {
        // fix left subtree if right rotation leads to its right subtree too deep
        if (get_balance(p->left) > 0)
            p->left = rotate(p->left, LEFT);
        return rotate(p, RIGHT);
    }
    // case 3: valid
    else
        return p;
}

AvlTreeNode *rotate(AvlTreeNode *p, direction d) {
    AvlTreeNode *q = nullptr;
    if (d == LEFT) {
        q = p->right;
        p->right = q->left;
        q->left = p;
    }
    else {
        q = p->left;
        p->left = q->right;
        q->right = p;
    }
    fix_height(p);
    fix_height(q);
    return q;
}
