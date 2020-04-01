class Solution {
 public:
  int maxProfit(vector<int> &prices, int l, int r) {
    int minPrice = 0x7fffffff;
    int result = 0;
    for (int k = l; k < r; k++) {
      int i = prices[k];
      if (i < minPrice) {
        minPrice = i;
      }
      if (i - minPrice > result) {
        result = i - minPrice;
      }
    }
    return result;
  }

  int maxProfit(vector<int> &prices) {
    if (prices.size() == 0) {
      return 0;
    }
    int result = 0;
    for (unsigned i = 1; i < prices.size() - 1; i++) {
      int leftPart = maxProfit(prices, 0, i);
      int rightPart = maxProfit(prices, i, prices.size());
      if (leftPart + rightPart > result) {
        result = leftPart + rightPart;
      }
    }
    int oneTrade = maxProfit(prices, 0, prices.size());
    return (oneTrade > result) ? oneTrade : result;
  }
};

#ifdef DEBUG

REGISTER_TEST(example1) {
  vector<int> prices({3, 3, 5, 0, 0, 3, 1, 4});
  int groundTruth = 6;
  return Solution().maxProfit(prices) == groundTruth;
}
REGISTER_TEST(example2) {
  vector<int> prices({1, 2, 3, 4, 5});
  int groundTruth = 4;
  return Solution().maxProfit(prices) == groundTruth;
}
REGISTER_TEST(example3) {
  vector<int> prices({2, 1, 2, 0, 1});
  int groundTruth = 2;
  return Solution().maxProfit(prices) == groundTruth;
}

#endif