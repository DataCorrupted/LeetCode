class Solution {
 public:
  vector<int> pick(vector<int> nums, int k) {
    if (nums.size() == 0) {
      return vector<int>();
    }

    int mask = 1 << (nums.size() - 1);
    vector<int> picked;
    for (int i = 0; i < nums.size(); i++) {
      if (k & mask) {
        picked.push_back(nums[i]);
      }
      mask = mask >> 1;
    }
    return picked;
  }
  vector<vector<int>> subsets(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    for (int i = 0; i < pow(2, n); i++) {
      ans.push_back(pick(nums, i));
    }
    return ans;
  }
};