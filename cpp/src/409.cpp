class Solution {
 public:
  int longestPalindrome(string s) {
    bool is_pair[255];
    int max_len = 0;
    for (int i = 0; i < 255; i++) {
      is_pair[i] = false;
    }
    for (int i = 0; i < s.size(); i++) {
      is_pair[s[i]] = !is_pair[s[i]];

      if (!is_pair[s[i]]) {
        max_len += 2;
      }
    }
    return max_len + (max_len != s.size());
  }
};