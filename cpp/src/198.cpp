class Solution {
 public:
  int rob(vector<int> &nums) {
    int preprev = 0, prev = 0;
    int curr = 0;
    for (int i : nums) {
      curr = max(prev, preprev + i);
      preprev = prev;
      prev = curr;
    }
    return curr;
  }
};

#ifdef DEBUG

REGISTER_TEST(example1) {
  vector<int> nums({1, 2, 3, 1});
  int groundTruth = 4;
  return Solution().rob(nums) == groundTruth;
}
REGISTER_TEST(example2) {
  vector<int> nums({2, 7, 9, 3, 1});
  int groundTruth = 12;
  return Solution().rob(nums) == groundTruth;
}

#endif