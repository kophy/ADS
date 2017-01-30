#ifndef __FENWICK_TREE__
#define __FENWICK_TREE__

#include <iostream>
#include <cassert>
#include <vector>

class FenwickTree {
  public:
    FenwickTree(std::vector<int> &_nums) {
      N = _nums.size();
      elements.resize(N);
      BITree = std::vector<int>(N + 1, 0);
      for (int i = 0; i < N; ++i)
        updateEle(i, _nums[i]);
    }

    int getPrefixSum(unsigned int index) {
      assert(index >= 0 && index < N);
      int sum = 0;
      index += 1;
      while (index > 0) {
        sum += BITree[index];
        index -= index & (-index);
      }
      return sum;
    }

    void updateEle(unsigned int index, int val) {
      assert(index >= 0 && index < N);
      int diff = val - elements[index];
      index += 1;
      while (index <= N) {
        BITree[index] += diff;
        index += index & (-index);
      }
      elements[index] = val;
    }

  private:
    size_t N;
    std::vector<int> elements;      // to calculate difference
    std::vector<int> BITree;        // binary indexed tree
};

#endif
