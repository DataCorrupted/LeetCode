#include <algorithm>

class Solution {
 private:
  int binarySearch(vector<int> &nums, int l, int r, int target) {
    int m = (l + r) / 2;
    while (l + 1 < r) {
      if (nums[m] > target) {
        l = m;
      } else {
        r = m;
      }
      m = (l + r) / 2;
    }
    return (nums[r] > target) ? r : l;
  }

  int findChangePoint(vector<int> &nums) {
    int pt = nums.size() - 2;
    int prev = nums[nums.size() - 1];
    while (pt != -1 && prev <= nums[pt]) {
      prev = nums[pt];
      pt--;
    }
    return pt;
  }

 public:
  void nextPermutation(vector<int> &nums) {
    int changePt = findChangePoint(nums);
    // This is in decending order, reverse them to the initial state would
    // suffice.
    if (changePt == -1) {
      std::reverse(nums.begin(), nums.end());
      return;
    }
    // Find the smallest candidate.
    int minCandPos =
        binarySearch(nums, changePt + 1, nums.size() - 1, nums[changePt]);

    // Switch the smallest candidate to current position.
    std::swap(nums[changePt], nums[minCandPos]);

    // The rest will be sorted.
    std::sort(nums.begin() + changePt + 1, nums.end());
  }
};

#ifdef DEBUG
#include "DebugUtil.h"

REGISTER_TEST(0) {
  vector<int> nums = {1, 2, 3};
  vector<int> groundTruth = {1, 3, 2};
  Solution().nextPermutation(nums);
  return nums == groundTruth;
}
REGISTER_TEST(1) {
  vector<int> nums = {3, 2, 1};
  vector<int> groundTruth = {1, 2, 3};
  Solution().nextPermutation(nums);
  return nums == groundTruth;
}
REGISTER_TEST(2) {
  vector<int> nums = {1, 1, 5};
  vector<int> groundTruth = {1, 5, 1};
  Solution().nextPermutation(nums);
  return nums == groundTruth;
}
REGISTER_TEST(3) {
  vector<int> nums = {4, 5, 3, 2, 1};
  vector<int> groundTruth = {5, 1, 2, 3, 4};
  Solution().nextPermutation(nums);
  return nums == groundTruth;
}
REGISTER_TEST(4) {
  vector<int> nums = {1, 2, 3, 5, 4};
  vector<int> groundTruth = {1, 2, 4, 3, 5};
  Solution().nextPermutation(nums);
  return nums == groundTruth;
}
REGISTER_TEST(5) {
  vector<int> nums = {1, 1, 4, 4, 0, 0, 4};
  vector<int> groundTruth = {1, 1, 4, 4, 0, 4, 0};
  Solution().nextPermutation(nums);
  return nums == groundTruth;
}
#endif