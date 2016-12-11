#ifndef __AVL_TREE__
#define __AVL_TREE__

#include "AvlTreeNode.h"

typedef void (*visit)(AvlTreeNode *p);

class AvlTree {
public:
    AvlTree(void);
    ~AvlTree(void);
    bool search(int key);
    bool insert(int key);
    bool remove(int key);
    void traverse(visit v);
private:
    bool search(AvlTreeNode *p, int key);
    AvlTreeNode *insert(AvlTreeNode *p, int key);
    AvlTreeNode *remove(AvlTreeNode *p, int key);
    void traverse(AvlTreeNode *p, visit v);

    AvlTreeNode *root;
};

#endif
