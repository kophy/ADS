#ifndef __UNION_FIND_SET__
#define __UNION_FIND_SET__

#include <vector>

class UnionFindSet {
    public:
        UnionFindSet(int n);
        int Find(int x);
        void Union(int x, int y);
        void Display(void);
    private:
        std::vector<int> parent;
        std::vector<int> height;
};

#endif // __UNION_FIND_SET__
