#ifndef __XOR_LINKED_LIST__
#define __XOR_LINKED_LIST__

typedef struct XorLinkedListNode {
    int key;
    XorLinkedListNode *npx;
} XorLinkedListNode;

typedef void (*visit)(XorLinkedListNode *);

class XorLinkedList {
public:
    XorLinkedList(void);
    void push_back(int key);
    void traverse(visit v, bool reverse = false);
private:
    XorLinkedListNode *head;
    XorLinkedListNode *tail;
};

#endif
