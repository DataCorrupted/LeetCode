class Solution {
 public:
  bool eq(const char a, const char b) { return (a == b || b == '.'); }
  bool isMatch(string s, string p) {
    if (s.size() == 0) {
      if (p.size() == 0) {
        return true;
      }
      if (p.size() < 2 || p[1] != '*') {
        return false;
      }
      return isMatch(s, p.substr(2));
    }
    if (p.size() == 0) {
      return false;
    }
    if (p.size() == 1 && s.size() == 1) {
      return eq(s[0], p[0]);
    }

    if (p[1] != '*') {
      return eq(s[0], p[0]) && isMatch(s.substr(1), p.substr(1));
    } else if (eq(s[0], p[0])) {
      if (isMatch(s.substr(0), p.substr(2))) {
        return true;
      }
      int rep_cnt = 1;
      while (rep_cnt - 1 < s.size() && eq(s[rep_cnt - 1], p[0])) {
        if (isMatch(s.substr(rep_cnt), p.substr(2))) {
          return true;
        } else {
          rep_cnt++;
        }
      }
      return false;

    } else {
      return isMatch(s, p.substr(2));
    }
  }
};
