class Solution {
 private:
  string m_str;
  size_t m_size;
  vector<vector<int>> m_f;

 public:
  int dp(size_t i, size_t j) {
    if (i > j) {
      return 0;
    }
    if (m_f[i][j] != -1) {
      return m_f[i][j];
    }
    int ret = dp(i + 1, j) + 1;
    for (size_t k = i + 1; k <= j; k++) {
      if (m_str[i] == m_str[k]) {
        ret = std::min(ret, dp(i, k - 1) + dp(k + 1, j));
      }
    }
    m_f[i][j] = ret;
    return ret;
  }
  int strangePrinter(string s) {
    m_size = s.size();
    if (m_size == 0) {
      return 0;
    }
    m_str = s;
    m_f = vector<vector<int>>(m_size, vector<int>(m_size, -1));

    return dp(0, m_size - 1);
  }
};

#ifdef DEBUG
REGISTER_TEST(example1) {
  string s = "aaabbb";
  int groundTruth = 2;
  return Solution().strangePrinter(s) == groundTruth;
}
REGISTER_TEST(example2) {
  string s = "aba";
  int groundTruth = 2;
  return Solution().strangePrinter(s) == groundTruth;
}
REGISTER_TEST(example3) {
  string s = "";
  int groundTruth = 0;
  return Solution().strangePrinter(s) == groundTruth;
}
#endif