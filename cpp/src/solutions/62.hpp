class Solution {
 public:
  int uniquePaths(unsigned m, unsigned n) {
    std::vector<int> curr = vector<int>();
    std::vector<int> prev = vector<int>();
    for (unsigned i = 0; i < m; i++) {
      prev.push_back(0);
      curr.push_back(1);
    }
    for (unsigned i = 1; i < n; i++) {
      // Swap is more efficient than prev = curr,
      // which would require a linear time copy.
      prev.swap(curr);
      curr[0] = 1;
      for (unsigned j = 1; j < m; j++) {
        curr[j] = prev[j] + curr[j - 1];
      }
    }
    return curr[m - 1];
  }
};

#ifdef DEBUG
#include "DebugUtil.h"

REGISTER_TEST(2x3) {
  int m = 3, n = 2;
  int groundTruth = 3;
  return Solution().uniquePaths(n, m) == groundTruth;
}
REGISTER_TEST(3x7) {
  int m = 7, n = 3;
  int groundTruth = 28;
  return Solution().uniquePaths(n, m) == groundTruth;
}
#endif