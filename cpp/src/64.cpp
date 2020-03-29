class Solution {
 public:
  int MAXINT = 2147483647;
  int n, m;
  int getCostAtIJ(vector<vector<int>> &grid, int i, int j) {
    if (i < 0 || i > n - 1) {
      return MAXINT;
    }
    if (j < 0 || j > m - 1) {
      return MAXINT;
    }
    return grid[i][j];
  }
  int min(int a, int b) { return (a < b) ? a : b; }
  int minPathSum(vector<vector<int>> &grid) {
    n = grid.size();
    if (n == 0) {
      return 0;
    }
    m = grid[n - 1].size();
    if (m == 0) {
      return 0;
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i == 0 && j == 0) {
          continue;
        }
        grid[i][j] +=
            min(getCostAtIJ(grid, i - 1, j), getCostAtIJ(grid, i, j - 1));
      }
    }
    return grid[n - 1][m - 1];
  }
};

#ifdef DEBUG
#include "DebugUtil.h"

REGISTER_TEST(empty) {
  vector<vector<int>> grid;
  int groundTruth = 0;
  return Solution().minPathSum(grid) == groundTruth;
}

REGISTER_TEST(0) {
  vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  int groundTruth = 7;
  return Solution().minPathSum(grid) == groundTruth;
}
#endif