#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <ctime>

#include "FenwickTree.hpp"

using namespace std;

int main() {
  srand((unsigned)time(NULL));
  vector<int> data;
  for (int i = 0; i < 15; ++i)
    data.push_back(rand() % 137);

  FenwickTree ft(data);

  auto naive_prefix_sum = [&data](int index) {
    return accumulate(data.begin(), data.begin() + index + 1, 0);
  };

  cout << "Naive solution: " << naive_prefix_sum(3) << endl;
  cout << "Fenwick Tree: " << ft.getPrefixSum(3) << endl;
  return 0;
}
