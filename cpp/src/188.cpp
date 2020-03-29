class Solution {
 private:
 public:
  int maxProfit(vector<int> &prices) {
    int result = 0;
    if (prices.size() == 0) {
      return 0;
    }
    for (unsigned i = 0; i < prices.size() - 1; i++) {
      if (prices[i] < prices[i + 1]) {
        result += (prices[i + 1] - prices[i]);
      }
    }
    return result;
  }
  int maxProfit(int k, vector<int> &prices) {
    int n = prices.size();
    if (k == 0 || n == 0) {
      return 0;
    }
    if (k > n / 2) {
      return maxProfit(prices);
    }

    vector<int> prev(n, 0);
    vector<int> curr(n, 0);

    for (int i = 1; i < k + 1; i++) {
      std::swap(prev, curr);
      int maxDiff = -prices[0];
      for (int j = 1; j < n; j++) {
        curr[j] = std::max(curr[j - 1], prices[j] + maxDiff);
        maxDiff = std::max(maxDiff, prev[j - 1] - prices[j]);
      }
    }
    return curr[n - 1];
  }
};

#ifdef DEBUG
REGISTER_TEST(example1) {
  vector<int> prices({3, 3, 5, 0, 0, 3, 1, 4});
  int k = 2;
  int groundTruth = 6;
  return Solution().maxProfit(k, prices) == groundTruth;
}
REGISTER_TEST(example2) {
  vector<int> prices({1, 2, 3, 4, 5});
  int k = 2;
  int groundTruth = 4;
  return Solution().maxProfit(k, prices) == groundTruth;
}
REGISTER_TEST(example3) {
  vector<int> prices({2, 1, 2, 0, 1});
  int k = 2;
  int groundTruth = 2;
  return Solution().maxProfit(k, prices) == groundTruth;
}
REGISTER_TEST(example4) {
  vector<int> prices({2, 4, 1});
  int k = 2;
  int groundTruth = 2;
  return Solution().maxProfit(k, prices) == groundTruth;
}
REGISTER_TEST(example5) {
  vector<int> prices({3, 2, 6, 5, 0, 3});
  int k = 2;
  int groundTruth = 7;
  return Solution().maxProfit(k, prices) == groundTruth;
}
#endif
