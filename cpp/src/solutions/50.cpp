class Solution {
 public:
  double myPow(double x, int n) {
    if (n < 0) {
      x = 1 / x;
    }
    unsigned n_ = abs(n);
    double pow = x;
    double ans = 1;

    while (n_) {
      if ((n_ & 1) == 1) {
        ans *= pow;
      }
      n_ >>= 1;
      pow *= pow;
    }
    return ans;
  }
};

#ifdef DEBUG
#include "DebugUtil.h"

REGISTER_TEST(2_10) {
  double x = 2;
  int n = 10;
  double groundTruth = 1024;
  return abs(Solution().myPow(x, n) - groundTruth) < 1e-10;
}
REGISTER_TEST(2p1_3) {
  double x = 2.1;
  int n = 3;
  double groundTruth = 9.261;
  return abs(Solution().myPow(x, n) - groundTruth) < 1e-10;
}
REGISTER_TEST(2_m2) {
  double x = 2;
  int n = -2;
  double groundTruth = .25;
  return abs(Solution().myPow(x, n) - groundTruth) < 1e-10;
}
#endif