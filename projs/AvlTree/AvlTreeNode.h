#ifndef __AVL_TREE_NODE__
#define __AVL_TREE_NODE__

// rotation direction
enum direction {LEFT, RIGHT};

// defintion of AVL tree node
typedef struct AvlTreeNode {
    int key;
    unsigned int height;
    AvlTreeNode *left;
    AvlTreeNode *right;

    AvlTreeNode(int k) {
        key = k;
        left = nullptr;
        right = nullptr;
        height = 1;
    }

} AvlTreeNode;

extern unsigned int get_height(AvlTreeNode *p);     // get height
extern void fix_height(AvlTreeNode *p);             // update height

extern int get_balance(AvlTreeNode *p);             // get balance
extern AvlTreeNode *fix_balance(AvlTreeNode *p);    // fix balance through rotation

extern AvlTreeNode *rotate(AvlTreeNode *p, direction d);

#endif
