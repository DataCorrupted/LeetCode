class Solution {
 public:
  vector<int> strToVec(string &s) {
    s += ".";
    int num = 0;
    vector<int> v;
    for (char c : s) {
      if (c == '.') {
        v.push_back(num);
        num = 0;
        continue;
      }
      num = num * 10 + (c - '0');
    }
    return v;
  }
  int compareVersion(string version1, string version2) {
    vector<int> v1 = strToVec(version1);
    vector<int> v2 = strToVec(version2);

    // Align vectors
    vector<int> &refV = (v1.size() < v2.size()) ? v1 : v2;
    while (v1.size() != v2.size()) {
      refV.push_back(0);
    }

    for (unsigned i = 0; i < v1.size(); i++) {
      if (v1[i] != v2[i]) {
        return (v1[i] > v2[i]) ? 1 : -1;
      }
    }
    return 0;
  }
};

#ifdef DEBUG
#include "DebugUtil.h"
REGISTER_TEST(example_1) {
  string version1("0.1"), version2("1.1");
  int groundTruth = -1;
  return Solution().compareVersion(version1, version2) == groundTruth;
}
REGISTER_TEST(example_2) {
  string version1("1.0.1"), version2("1");
  int groundTruth = 1;
  return Solution().compareVersion(version1, version2) == groundTruth;
}
REGISTER_TEST(example_3) {
  string version1("7.5.2.4"), version2("7.5.3");
  int groundTruth = -1;
  return Solution().compareVersion(version1, version2) == groundTruth;
}
REGISTER_TEST(example_4) {
  string version1("01"), version2("1");
  int groundTruth = 0;
  return Solution().compareVersion(version1, version2) == groundTruth;
}
#endif