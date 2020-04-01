class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();

    if (n == 0) {
      return 0;
    }
    vector<int> maxSell(n + 1, 0);
    vector<int> maxCool(n + 1, 0);
    int tmpMax = -prices[0];
    for (int i = 1; i <= n; i++) {
      if (i != 1) {
        tmpMax = std::max(tmpMax, maxCool[i - 2] - prices[i - 2]);
      }
      maxCool[i] = std::max(maxCool[i - 1], maxSell[i - 1]);
      maxSell[i] = std::max(maxSell[i], tmpMax + prices[i - 1]);
    }
    return std::max(maxSell[n], maxCool[n]);
  }
};

#ifdef DEBUG

REGISTER_TEST(example1) {
  vector<int> prices({1, 2, 3, 0, 2});
  int groundTruth(3);

  return Solution().maxProfit(prices) == groundTruth;
}

#endif