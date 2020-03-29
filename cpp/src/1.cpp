class Solution {
 public:
  vector<int> twoSum(vector<int> &nums, int target) {
    for (unsigned i = 0; i < nums.size(); i++) {
      for (unsigned j = i + 1; j < nums.size(); j++) {
        if (nums[j] == target - nums[i]) {
          vector<int> temp;
          temp.push_back(i);
          temp.push_back(j);
          return temp;
        }
      }
    }
    return vector<int>();
  }
};

#ifdef DEBUG
#include "DebugUtil.h"

REGISTER_TEST(0) {
  int target = 9;
  vector<int> nums({2, 7, 11, 15});
  vector<int> groundTruth({0, 1});
  return Solution().twoSum(nums, target) == groundTruth;
}

#endif