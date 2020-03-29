class Solution {
 public:
  int n;
  int trapLeft(vector<int> &height, int &max_pos) {
    if (n == 0) {
      return 0;
    }
    int ans = 0;
    int max_h = height[0];
    int obst_cnt = 0;
    for (int i = 1; i < n; i++) {
      if (height[i] > max_h) {
        ans = ans + (i - max_pos - 1) * max_h - obst_cnt;
        obst_cnt = 0;
        max_pos = i;
        max_h = height[i];
      } else {
        obst_cnt += height[i];
      }
    }
    return ans;
  }
  int trap(vector<int> &height) {
    n = height.size();

    if (n == 0) {
      return 0;
    }
    vector<int> h = height;
    int left_pos = 0, right_pos = 0;

    int left = trapLeft(h, left_pos);
    reverse(h.begin(), h.end());
    int right = trapLeft(h, right_pos);

    left_pos = n - 1 - left_pos;
    int middle = 0;
    if (left_pos != right_pos) {
      int obst_cnt = 0;
      for (int i = right_pos + 1; i < left_pos; i++) {
        obst_cnt += h[i];
      }
      middle = (left_pos - right_pos - 1) * h[left_pos] - obst_cnt;
    }
    return left + right + middle;
  }
};