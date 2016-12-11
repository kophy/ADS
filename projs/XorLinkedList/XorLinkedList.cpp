#include <iostream>
#include <cstdlib>
#include <cstdint>

#include "XorLinkedList.h"

using namespace std;

// interesting part... casting pointer to unsigned int is forbidden
static XorLinkedListNode *XOR(XorLinkedListNode *p, XorLinkedListNode *q) {
    unsigned int temp = reinterpret_cast<uintptr_t>(p) ^ reinterpret_cast<uintptr_t>(q);
    return reinterpret_cast<XorLinkedListNode *>(temp);
}

XorLinkedList::XorLinkedList(void) {
    head = NULL;
    tail = NULL;
}

void XorLinkedList::push_back(int key) {
    XorLinkedListNode *curr = new XorLinkedListNode();
    curr->key = key;
    if (head == NULL) {
        curr->npx = XOR(NULL, NULL);
        head = curr;
    }
    else {
        curr->npx = XOR(tail, NULL);
        tail->npx = XOR(XOR(tail->npx, NULL), curr);
    }
    tail = curr;
}

void XorLinkedList::traverse(visit v, bool reverse) {
    if (!reverse) {
        XorLinkedListNode *prev = NULL;
        XorLinkedListNode *curr = head;
        while (curr != NULL) {
            v(curr);
            XorLinkedListNode *next = XOR(curr->npx, prev);
            prev = curr;
            curr = next;
        }
    } else {
        XorLinkedListNode *next = NULL;
        XorLinkedListNode *curr = tail;
        while (curr != NULL) {
            v(curr);
            XorLinkedListNode *prev = XOR(curr->npx, next);
            next = curr;
            curr = prev;
        }
    }
}
