class NumMatrix {
  vector<vector<int>> partialSum;

 public:
  NumMatrix(vector<vector<int>> matrix) {
    if (matrix.size() == 0) {
      return;
    }
    int n = matrix.size();
    int m = matrix[0].size();
    partialSum = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        partialSum[i][j] = partialSum[i - 1][j] + partialSum[i][j - 1] -
                           partialSum[i - 1][j - 1] + matrix[i - 1][j - 1];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    if (partialSum.size() == 0) {
      return 0;
    }
    return partialSum[row2 + 1][col2 + 1] - partialSum[row2 + 1][col1] -
           partialSum[row1][col2 + 1] + partialSum[row1][col1];
  }
};

#ifdef DEBUG
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */

static NumMatrix example1({
    {3, 0, 1, 4, 2},
    {5, 6, 3, 2, 1},
    {1, 2, 0, 1, 5},
    {4, 1, 0, 1, 7},
    {1, 0, 3, 0, 5},
});
REGISTER_TEST(example1) {
  vector<int> result({
      example1.sumRegion(2, 1, 4, 3),
      example1.sumRegion(1, 1, 2, 2),
      example1.sumRegion(1, 2, 2, 4),
  });
  vector<int> groundTruth({8, 11, 12});
  return result == groundTruth;
}

#endif