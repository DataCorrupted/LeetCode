class Solution {
 public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 0) {
      return "";
    }
    int n = strs[0].size();
    for (int i = 0; i < strs.size(); i++) {
      n = (strs[i].size() < n) ? strs[i].size() : n;
    }
    string ans = "";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < strs.size(); j++) {
        if (strs[j][i] != strs[0][i]) {
          return ans;
        }
      }
      ans += strs[0][i];
    }
    return ans;
  }
};