class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1) {
      return s;
    }
    string ans = "";
    int letter_per_zig = numRows * 2 - 2;
    int zig_cnt = s.size() / letter_per_zig + 1;
    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < zig_cnt; j++) {
        const int first_in_zig = j * letter_per_zig + i;
        if (first_in_zig < s.size()) {
          ans += s[first_in_zig];
        }
        if (i != 0 && i != numRows - 1) {
          const int second_in_zig =
              j * letter_per_zig + numRows - 1 + numRows - 1 - i;
          if (second_in_zig < s.size()) {
            ans += s[second_in_zig];
          }
        }
      }
    }
    return ans;
  }
};