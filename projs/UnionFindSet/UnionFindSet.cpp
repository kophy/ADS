#include <iostream>
#include <cstdlib>
#include <iomanip>

#include "UnionFindSet.h"

using namespace std;

UnionFindSet::UnionFindSet(int n) {
    parent.resize(n);
    height.resize(n);

    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        height[i] = 0;
    }
}

int UnionFindSet::Find(int x) {
    if (parent[x] == x)
        return x;
    else {
        int result = Find(parent[x]), f;
        parent[x] = result;
        return result;
    }
}

void UnionFindSet::Union(int x, int y) {
    int root_x = Find(x);
    int root_y = Find(y);

    if (root_x == root_y)
        return;

    if (height[root_x] > height[root_y]) {
        parent[root_y] = root_x;
    } else if (height[root_x] < height[root_y]) {
        parent[root_x] = root_y;
    } else {
        parent[root_y] = root_x;
        ++height[root_x];
    }
}

void UnionFindSet::Display(void) {
    cout << "Index | Parent | Root | height" << endl;
    for (int i = 0; i < parent.size(); ++i) {
        cout << " " << setw(4) << i;
        cout << "     " << setw(4) << parent[i];
        cout << "   " << setw(4) << Find(i);
        cout << "   " << setw(4) << height[i] << endl;
    }
}
