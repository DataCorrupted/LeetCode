class Solution {
 public:
  string getDecimal(uint64_t numerator, uint64_t denominator) {
    if (!numerator) {
      return "";
    }
    string decimal = ".";
    vector<std::pair<uint64_t, uint64_t>> digRemPairVec;
    while (numerator) {
      uint64_t digit = numerator / denominator;
      uint64_t reman = numerator % denominator;
      std::pair<uint64_t, uint64_t> digRemPair =
          std::pair<uint64_t, uint64_t>(digit, reman);
      for (unsigned i = 0; i < digRemPairVec.size(); i++) {
        if (digRemPairVec[i] == digRemPair) {
          decimal.insert(i + 1, "(");
          decimal += ")";
          return decimal;
        }
      }
      digRemPairVec.push_back(digRemPair);

      decimal += std::to_string(digit);
      numerator = reman * 10;
    }
    return decimal;
  }
  string fractionToDecimal(int numerator, int denominator) {
    string sign = ((numerator > 0 && denominator < 0) ||
                   (numerator < 0 && denominator > 0))
                      ? "-"
                      : "";
    uint64_t nu = abs(int64_t(numerator));
    uint64_t de = abs(int64_t(denominator));
    return sign + std::to_string(nu / de) + getDecimal((nu % de) * 10, de);
  }
};

#ifdef DEBUG
#include "DebugUtil.h"

REGISTER_TEST(1_div_2) {
  int numerator = 1, denominator = 2;
  string groundTruth = "0.5";
  return Solution().fractionToDecimal(numerator, denominator) == groundTruth;
}
REGISTER_TEST(2_div_1) {
  int numerator = 2, denominator = 1;
  string groundTruth = "2";
  return Solution().fractionToDecimal(numerator, denominator) == groundTruth;
}
REGISTER_TEST(2_div_3) {
  int numerator = 2, denominator = 3;
  string groundTruth = "0.(6)";
  return Solution().fractionToDecimal(numerator, denominator) == groundTruth;
}
REGISTER_TEST(100_div_25) {
  int numerator = 100, denominator = 25;
  string groundTruth = "4";
  return Solution().fractionToDecimal(numerator, denominator) == groundTruth;
}
REGISTER_TEST(30_div_7) {
  int numerator = 30, denominator = 7;
  string groundTruth = "4.(285714)";
  return Solution().fractionToDecimal(numerator, denominator) == groundTruth;
}
REGISTER_TEST(500000000_div_73) {
  int numerator = 500000000, denominator = 73;
  string groundTruth = "6849315.(06849315)";
  return Solution().fractionToDecimal(numerator, denominator) == groundTruth;
}
REGISTER_TEST(n2147483648_div_n1) {
  int numerator = -2147483648, denominator = -1;
  string groundTruth = "2147483648";
  return Solution().fractionToDecimal(numerator, denominator) == groundTruth;
}
REGISTER_TEST(7_div_n12) {
  int numerator = 7, denominator = -12;
  string groundTruth = "-0.58(3)";
  return Solution().fractionToDecimal(numerator, denominator) == groundTruth;
}
REGISTER_TEST(n1_div_n2147483648) {
  int numerator = -1, denominator = -2147483648;
  string groundTruth = "0.0000000004656612873077392578125";
  return Solution().fractionToDecimal(numerator, denominator) == groundTruth;
}
#endif