class Solution {
  vector<vector<int>> *m;

  bool le(int a, int b) { return a <= b; }
  int nums(int idx) {
    return (*m)[idx / m->back().size()][idx % m->back().size()];
  }
  // The cmpFunc guarantees that the array can be converted to the form of
  // TTT...TTFF...FFF. This function will find the idx of the last T or return
  // l-1.
  int binarySearch(int target, int l, int r,
                   bool (Solution::*cmpFunc)(int, int)) {
    // However, there can be cases where only T or only F are present.
    // Test if the first is F, if so, return not found.
    if (!(this->*cmpFunc)(nums(l), target)) {
      return l - 1;
    }
    // Test if the last is T, if so, return the last one.
    if ((this->*cmpFunc)(nums(r), target)) {
      return r;
    }

    int mid = 0;
    while (l + 1 < r) {
      mid = (l + r) / 2;
      if ((this->*cmpFunc)(nums(mid), target)) {
        l = mid;
      } else {
        r = mid;
      }
    }
    // arr[l] = T, arr[r] = F.
    return l;
  }

 public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    if (matrix.size() == 0 || matrix.back().size() == 0) {
      return false;
    }
    m = &matrix;
    int idx = binarySearch(target, 0, m->size() * m->back().size() - 1,
                           &Solution::le);
    if (idx == -1) {
      return false;
    }
    return nums(idx) == target;
  }
};

#ifdef DEBUG
#include "DebugUtil.h"

REGISTER_TEST(example1) {
  vector<vector<int>> matrix = {
      {1, 3, 5, 7},
      {10, 11, 16, 20},
      {23, 30, 34, 50},
  };
  int target = 3;
  bool groundTruth = true;
  return Solution().searchMatrix(matrix, target) == groundTruth;
}
REGISTER_TEST(example2) {
  vector<vector<int>> matrix = {
      {1, 3, 5, 7},
      {10, 11, 16, 20},
      {23, 30, 34, 50},
  };
  int target = 0;
  bool groundTruth = false;
  return Solution().searchMatrix(matrix, target) == groundTruth;
}
REGISTER_TEST(example3) {
  vector<vector<int>> matrix = {{}};
  int target = 1;
  bool groundTruth = false;
  return Solution().searchMatrix(matrix, target) == groundTruth;
}
#endif