class Solution {
 public:
  void rotate(vector<int> &nums, int k) {
    /*		int n = nums.size();
                    k = k % n;
                    if (k == 0) { return; }
                    int i = k;
                    int bufPtr = 0;
                    int last = nums[(n-k) % n];
                    while (i != k-1 || nums[k-1] == last){
                            std::swap(nums[i], nums[bufPtr]);
                            i = (i + 1) % n;
                            bufPtr = (bufPtr + 1) % k;
                    }*/
    int n = nums.size();
    k %= n;
    if (k == 0) {
      return;
    }
    int currIdx = 0;
    int targIdx = k;
    int origIdx = 0;
    int tempNum = nums[currIdx];
    for (int i = 0; i < n; i++) {
      std::swap(tempNum, nums[targIdx]);
      currIdx = targIdx;

      if (currIdx == origIdx) {
        currIdx++;
        origIdx++;
        tempNum = nums[currIdx];
      }

      targIdx = (currIdx + k) % n;
    }
  }
};

#ifdef DEBUG

REGISTER_TEST(example1) {
  vector<int> nums({1, 2, 3, 4, 5, 6, 7});
  int k = 3;
  vector<int> groundTruth({5, 6, 7, 1, 2, 3, 4});
  Solution().rotate(nums, k);
  return nums == groundTruth;
}
REGISTER_TEST(example2) {
  vector<int> nums({-1, -100, 3, 99});
  int k = 2;
  vector<int> groundTruth({3, 99, -1, -100});
  Solution().rotate(nums, k);
  return nums == groundTruth;
}
REGISTER_TEST(example3) {
  vector<int> nums({1});
  int k = 1;
  vector<int> groundTruth({1});
  Solution().rotate(nums, k);
  return nums == groundTruth;
}
REGISTER_TEST(example4) {
  vector<int> nums({1, 2, 3, 4, 5, 6});
  int k = 4;
  vector<int> groundTruth({3, 4, 5, 6, 1, 2});
  Solution().rotate(nums, k);
  return nums == groundTruth;
}
#endif