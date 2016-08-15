#include <iostream>
#include <cstdlib>

#include "UnionFindSet.h"

using namespace std;

int main() {
    UnionFindSet *u = new UnionFindSet(8);

    cout << "Original" << endl;
    u->Display();

    u->Union(0, 1);
    u->Union(1, 2);
    u->Union(3, 4);
    u->Union(4, 5);
    u->Union(0, 4);
    u->Union(6, 7);

    cout << endl;
    cout << "After Union" << endl;
    u->Display();

    delete u;
}
