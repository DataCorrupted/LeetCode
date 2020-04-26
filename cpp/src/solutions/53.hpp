#define SMALL_INT -2147483647
class Solution {
 private:
  typedef std::pair<int64_t, int64_t> MaxMinPair;
  vector<int> m_nums;
  vector<int64_t> m_subTotal;

  // returns max sub array value ,
  // max and min sub total in this range
  std::pair<int, MaxMinPair> divAndConquer(int l, int r) {
    if (l == r) {
      // We don't pick anything if this number is negative.
      return std::pair<int, MaxMinPair>(
          m_nums[l], MaxMinPair(m_subTotal[l], m_subTotal[r]));
    };
    std::pair<int, MaxMinPair> leftPart = divAndConquer(l, (l + r) / 2);
    std::pair<int, MaxMinPair> rightPart = divAndConquer((l + r) / 2 + 1, r);
    return std::pair<int, MaxMinPair>(
        // Left max, Right max or the max across the region.
        max(max(leftPart.first, rightPart.first),
            int(rightPart.second.first - leftPart.second.second)),
        // Update the max and min data.
        MaxMinPair(max(leftPart.second.first, rightPart.second.first),
                   min(leftPart.second.second, rightPart.second.second)));
  }

 public:
  int maxSubArray(vector<int> &nums) {
    if (nums.size() == 0) {
      return 0;
    }
    m_nums = nums;
    // Add a dummy head to make sure the first element's sub total is
    // considered.
    m_nums.insert(m_nums.begin(), SMALL_INT);
    m_subTotal.push_back(m_nums[0]);
    for (unsigned i = 1; i < m_nums.size(); i++) {
      m_subTotal.push_back(m_subTotal.back() + m_nums[i]);
    }
    return divAndConquer(0, m_nums.size() - 1).first;
  }
};

#ifdef DEBUG
#include "DebugUtil.h"
REGISTER_TEST(example_1) {
  vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int groundTruth = 6;
  return Solution().maxSubArray(nums) == groundTruth;
}
REGISTER_TEST(example_2) {
  vector<int> nums = {1, 2};
  int groundTruth = 3;
  return Solution().maxSubArray(nums) == groundTruth;
}
REGISTER_TEST(example_3) {
  vector<int> nums = {-1};
  int groundTruth = -1;
  return Solution().maxSubArray(nums) == groundTruth;
}

#endif