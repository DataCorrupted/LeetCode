class Solution {
 private:
  unsigned ary;

 public:
  Solution() : ary(26){};
  string convertToTitle(int n) {
    string s;
    while (n) {
      s += ((n % ary) == 0) ? 'Z' : ((n % ary) - 1 + 'A');
      n = n / ary - (n % ary == 0);
    }
    std::reverse(s.begin(), s.end());
    return s;
  }
  int titleToNumber(string s) {
    int num = 0;
    unsigned pow = 1;
    std::reverse(s.begin(), s.end());

    for (char c : s) {
      num += (c - 'A' + 1) * pow;
      pow *= ary;
    }
    return num;
  }
};

#ifdef DEBUG
#include "DebugUtil.h"

REGISTER_TEST(2Title_1) {
  int n = 1;
  string groundTruth = "A";
  return Solution().convertToTitle(n) == groundTruth;
}
REGISTER_TEST(2Title_2) {
  int n = 28;
  string groundTruth = "AB";
  return Solution().convertToTitle(n) == groundTruth;
}
REGISTER_TEST(2Title_3) {
  int n = 701;
  string groundTruth = "ZY";
  return Solution().convertToTitle(n) == groundTruth;
}
REGISTER_TEST(2Title_4) {
  int n = 52;
  string groundTruth = "AZ";
  return Solution().convertToTitle(n) == groundTruth;
}
REGISTER_TEST(2Num_1) {
  string s = "A";
  int groundTruth = 1;
  return Solution().titleToNumber(s) == groundTruth;
}
REGISTER_TEST(2Num_2) {
  string s = "AB";
  int groundTruth = 28;
  return Solution().titleToNumber(s) == groundTruth;
}
REGISTER_TEST(2Num_3) {
  string s = "ZY";
  int groundTruth = 701;
  return Solution().titleToNumber(s) == groundTruth;
}
#endif