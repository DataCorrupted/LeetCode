// http://www.cnblogs.com/lichen782/p/leetcode_Jump_Game_II.html
class Solution {
 public:
  int jump(vector<int> &nums) {
    int n = nums.size();
    int step_cnt = 0;
    int curr_max = 0;
    int max_reach = 0;
    for (int i = 0; i < n; i++) {
      if (i > curr_max) {
        step_cnt++;
        curr_max = max_reach;
      }
      if (i + nums[i] > max_reach) {
        max_reach = i + nums[i];
      }
    }
    return step_cnt;
  }
};