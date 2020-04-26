class Solution {
 public:
  int numDecodings(string s) {
    if (s[0] == '0') {
      return 0;
    }
    std::vector<int> opt;
    opt.push_back(1);
    opt.push_back(1);
    for (size_t i = 1; i < s.size(); i++) {
      if (s[i] == '0') {
        if (s[i - 1] == '0' || s[i - 1] >= '3') {
          return 0;
        } else {
          opt.push_back(opt[i - 1]);
        }
      } else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
        opt.push_back(opt[i] + opt[i - 1]);
      } else {
        opt.push_back(opt[i]);
      }
    }
    return opt[s.size()];
  }
};

#ifdef DEBUG
REGISTER_TEST(sample1) {
  string s = "12";
  int groundTruth(2);
  return Solution().numDecodings(s) == groundTruth;
}
REGISTER_TEST(sample2) {
  string s = "226";
  int groundTruth(3);
  return Solution().numDecodings(s) == groundTruth;
}
REGISTER_TEST(sample3) {
  string s = "0";
  int groundTruth(0);
  return Solution().numDecodings(s) == groundTruth;
}
REGISTER_TEST(sample4) {
  string s = "1000";
  int groundTruth(0);
  return Solution().numDecodings(s) == groundTruth;
}
REGISTER_TEST(sample5) {
  string s = "101020";
  int groundTruth(1);
  return Solution().numDecodings(s) == groundTruth;
}
REGISTER_TEST(sample6) {
  string s = "103020";
  int groundTruth(0);
  return Solution().numDecodings(s) == groundTruth;
}
REGISTER_TEST(sample7) {
  string s = "27";
  int groundTruth(1);
  return Solution().numDecodings(s) == groundTruth;
}
#endif