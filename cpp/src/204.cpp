class Solution {
 public:
  int countPrimes(int n) {
    if (!n) {
      return 0;
    }
    int cnt = 0;
    bool isPrime[n];
    for (int i = 0; i < n; i++) {
      isPrime[i] = true;
    }
    for (int64_t i = 2; i < n; i++) {
      if (isPrime[i]) {
        cnt++;
      }
      int64_t k = i * i;
      while (k < n) {
        isPrime[k] = false;
        k += i;
      }
    }
    return cnt;
  }
};

#ifdef DEBUG
#include "DebugUtil.h"

REGISTER_TEST(example0) {
  int n = 10;
  int groundTruth = 4;
  return Solution().countPrimes(n) == groundTruth;
}
REGISTER_TEST(example1) {
  int n = 10000;
  int groundTruth = 1229;
  return Solution().countPrimes(n) == groundTruth;
}
REGISTER_TEST(example2) {
  int n = 2;
  int groundTruth = 0;
  return Solution().countPrimes(n) == groundTruth;
}
REGISTER_TEST(example3) {
  int n = 1;
  int groundTruth = 0;
  return Solution().countPrimes(n) == groundTruth;
}
#endif