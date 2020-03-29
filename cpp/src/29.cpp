class Solution {
 public:
  int divide(int dividend, int divisor) {
    // The only case that divide causes overflow.
    if (dividend == -2147483648 && divisor == -1) {
      return 2147483647;
    }
    bool is_negative = ((dividend & 0x80000000) ^ (divisor & 0x80000000));
    int ans = 0;
    long dividend_ = dividend;
    long divisor_ = divisor;

    dividend_ = (dividend_ > 0) ? dividend_ : (-1 * dividend_);
    divisor_ = (divisor_ > 0) ? divisor_ : (-1 * divisor_);

    int shift = 31;
    while (dividend_ >= divisor_) {
      if (dividend_ >= (divisor_ << shift)) {
        dividend_ -= divisor_ << shift;
        ans += 1 << shift;
      }
      shift--;
    }
    return ans * ((is_negative) ? -1 : 1);
  }
};