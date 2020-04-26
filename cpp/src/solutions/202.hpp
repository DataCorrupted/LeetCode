class Solution {
 public:
  int getNextN(int n) {
    int nextN = 0;
    while (n != 0) {
      nextN += (n % 10) * (n % 10);
      n = n / 10;
    }
    return nextN;
  }
  bool isHappy(int n) {
    map<int, int> occMap;
    occMap[n] = 1;
    while (n != 1) {
      n = getNextN(n);
      // Repeat!
      if (occMap[n] != 0) {
        return false;
      }
      occMap[n] = occMap[n] + 1;
    }
    return true;
  }
};

#ifdef DEBUG
#include "DebugUtil.h"

REGISTER_TEST(example1) {
  int n = 19;
  bool groundTruth = true;
  return Solution().isHappy(n) == groundTruth;
}

REGISTER_TEST(example2) {
  int n = 24;
  bool groundTruth = false;
  return Solution().isHappy(n) == groundTruth;
}
#endif