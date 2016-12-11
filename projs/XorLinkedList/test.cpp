#include <iostream>
#include <cstdlib>

#include "XorLinkedList.h"

using namespace std;

int main() {
    XorLinkedList *xl = new XorLinkedList();
    for (int i = 0; i < 10; ++i)
        xl->push_back(i);

    auto print = [](XorLinkedListNode *node) {
        cout << node->key << " ";
    };

    cout << "traverse in order: " << endl;
    xl->traverse(print);
    cout << endl;

    cout << "traverse in reverse order: " << endl;
    xl->traverse(print, true);
    cout << endl;

    return 0;
}
