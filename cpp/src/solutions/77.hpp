class Solution {
  vector<vector<int>> comb;

 public:
  void dfs(vector<bool> &usage, vector<int> &combine, int k) {
    if (combine.back() != 0) {
      comb.push_back(combine);
      return;
    }
    int start = 0;
    if (k != 0) {
      start = combine[k - 1];
    }
    for (unsigned i = start; i < usage.size(); i++) {
      if (usage[i]) {
        usage[i] = false;
        combine[k] = i + 1;
        dfs(usage, combine, k + 1);
        combine[k] = 0;
        usage[i] = true;
      }
    }
  }
  vector<vector<int>> combine(int n, int k) {
    vector<int> combine(k, 0);
    vector<bool> usage(n, 0);
    for (int i = 0; i < n; i++) {
      usage[i] = true;
    }

    dfs(usage, combine, 0);
    return comb;
  }
};

#ifdef DEBUG
REGISTER_TEST(example1) {
  int n = 4, k = 2;
  vector<vector<int>> groundTruth(
      {{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}});
  return Solution().combine(n, k) == groundTruth;
}
#endif