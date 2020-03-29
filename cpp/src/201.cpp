/* Explaination:
 *
 */
class Solution {
 public:
  int64_t getPow(int p) {
    int64_t pow = 1;
    while (p >= pow) {
      pow *= 2;
    }
    return pow;
  }
  int rangeBitwiseAnd(int m, int n) {
    int ans = 0;
    int64_t maxPow = getPow(max(m, n));
    while (maxPow && (m / maxPow == n / maxPow)) {
      ans += maxPow * (m / maxPow);
      m = m % maxPow;
      n = n % maxPow;
      maxPow = maxPow >> 1;
    }
    return ans;
  }
};

#ifdef DEBUG
#include "DebugUtil.h"

REGISTER_TEST(example1) {
  int m = 5, n = 7;
  int groundTruth = 4;
  return Solution().rangeBitwiseAnd(m, n) == groundTruth;
}
REGISTER_TEST(example2) {
  int m = 0, n = 1;
  int groundTruth = 0;
  return Solution().rangeBitwiseAnd(m, n) == groundTruth;
}
REGISTER_TEST(example3) {
  int m = 10, n = 10;
  int groundTruth = 10;
  return Solution().rangeBitwiseAnd(m, n) == groundTruth;
}
REGISTER_TEST(example4) {
  int m = 0, n = 2147483647;
  int groundTruth = 0;
  return Solution().rangeBitwiseAnd(m, n) == groundTruth;
}
#endif