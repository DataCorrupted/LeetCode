class Solution {
 public:
  int minimumTotal(vector<vector<int>> &triangle) {
    // The first line is not accounted for.
    for (unsigned i = 1; i < triangle.size(); i++) {
      // The first and the last column is not accounted for.
      triangle[i][0] += triangle[i - 1][0];
      triangle[i].back() += triangle[i - 1].back();
      for (unsigned j = 1; j < triangle[i].size() - 1; j++) {
        triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
      }
    }
    int min = 2147483647;
    for (unsigned i = 0; i < triangle.back().size(); i++) {
      if (triangle.back()[i] < min) {
        min = triangle.back()[i];
      }
    }
    return min;
  }
};

#ifdef DEBUG
#include "DebugUtil.h"

REGISTER_TEST(example_0) {
  vector<vector<int>> triangle = {
      {2},
      {3, 4},
      {6, 5, 7},
      {4, 1, 8, 3},
  };
  int groundTruth = 11;
  return Solution().minimumTotal(triangle) == groundTruth;
}
#endif