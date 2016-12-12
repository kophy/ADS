#include <iostream>
#include <cstdlib>
#include <vector>
#include "TernarySearchTree.h"

using namespace std;

int main() {
    TernarySearchTree *tst = new TernarySearchTree();

    cout << "test inserting:" << endl;
    vector<string> dict = {"vector", "map", "queue", "stack", "set", " wierd"};
    for (string word : dict)
        tst->insert(word);
    tst->traverse();
    cout << endl;

    cout << "testing searching:" << endl;
    cout << "contain \"vector\": " << tst->search("vector") << endl;
    cout << "contain \"deque\": " << tst->search("deque") << endl;
    cout << endl;

    cout << "test removing:" << endl;
    tst->remove("vector");
    tst->traverse();

    delete tst;
    return 0;
}
