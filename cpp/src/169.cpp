class Solution {
 public:
  int majorityElement(vector<int> &nums) {
    std::map<int, int> occMap;
    for (int n : nums) {
      occMap[n] = occMap[n] + 1;
    }
    std::pair<int, int> max;
    for (auto p : occMap) {
      if (max.second < p.second) {
        max = p;
      }
    }
    return max.first;
  }
};

#ifdef DEBUG
#include "DebugUtil.h"
REGISTER_TEST(example_1) {
  vector<int> nums = {3, 2, 3};
  int groundTruth = 3;
  return Solution().majorityElement(nums) == groundTruth;
}
REGISTER_TEST(example_2) {
  vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
  int groundTruth = 2;
  return Solution().majorityElement(nums) == groundTruth;
}
#endif