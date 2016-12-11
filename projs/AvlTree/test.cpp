#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>

#include "AvlTreeNode.h"
#include "AvlTree.h"

using namespace std;

int main() {
    AvlTree *a = new AvlTree();
    vector<int> data(10);

    srand((unsigned)time(nullptr));
    for (int &d : data) d = rand() % 784;

    auto display = [](AvlTreeNode *p) {
        cout << setw(10) << p->key
             << setw(10) << ((p->left == nullptr)? "n/a" : to_string(p->left->key))
             << setw(10) << ((p->right == nullptr)? "n/a" : to_string(p->right->key))
             << setw(10) << get_height(p->left)
             << setw(10) << get_height(p->right)
             << setw(10) << get_balance(p) << endl;
    };

    // test inserting
    cout << "Insert 10 random numbers" << endl;
    for (int d : data)
        a->insert(d);
    cout << setw(10) << "key" << setw(10) << "key-l" << setw(10) << "key-r"
         << setw(10) << "height-l" << setw(10) << "height-r" << setw(10) << "balance" << endl;
    a->traverse(display);

    // test removing
    cout << "Remove " + to_string(data[3]) + " and " + to_string(data[5]) << endl;
    a->remove(data[3]);
    a->remove(data[5]);
    cout << setw(10) << "key" << setw(10) << "key-l" << setw(10) << "key-r"
         << setw(10) << "height-l" << setw(10) << "height-r" << setw(10) << "balance" << endl;
    a->traverse(display);

    delete a;
    return 0;
}
