class Solution {
 public:
  bool isScramble(string s1, string s2) {
    if (s1.size() == 0) {
      return true;
    }
    if (s1.size() != s2.size()) {
      return false;
    }
    int n = s1.size();
    if (n == 1) {
      return s1[0] == s2[0];
    }
    if (n == 2) {
      return s1 == s2 || (s1[0] == s2[1] && s1[1] == s2[0]);
    }

    map<char, int> s1Cnt;
    map<char, int> s2Cnt;
    for (int i = 0; i < n; i++) {
      s1Cnt[s1[i]] = s1Cnt[s1[i]] + 1;
      s2Cnt[s2[i]] = s2Cnt[s2[i]] + 1;
      if (s1Cnt == s2Cnt && i != n - 1) {
        if (isScramble(s1.substr(0, i + 1), s2.substr(0, i + 1)) &&
            isScramble(s1.substr(i + 1, n - i), s2.substr(i + 1, n - i))) {
          return true;
        }
      }
    }
    s1Cnt = map<char, int>();
    s2Cnt = map<char, int>();
    for (int i = 0; i < n; i++) {
      s1Cnt[s1[i]] = s1Cnt[s1[i]] + 1;
      s2Cnt[s2[n - i - 1]] = s2Cnt[s2[n - i - 1]] + 1;
      if (s1Cnt == s2Cnt && i != n - 1) {
        if (isScramble(s1.substr(0, i + 1), s2.substr(n - i - 1, i + 1)) &&
            isScramble(s1.substr(i + 1, n - i), s2.substr(0, n - i - 1))) {
          return true;
        }
      }
    }
    return false;
  }
};

#ifdef DEBUG
REGISTER_TEST(example1) {
  string s1("great");
  string s2("rgtea");
  bool groundTruth = true;
  return Solution().isScramble(s1, s2) == groundTruth;
}
REGISTER_TEST(example2) {
  string s1("abcde");
  string s2("caebd");
  bool groundTruth = false;
  return Solution().isScramble(s1, s2) == groundTruth;
}
#endif