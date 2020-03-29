class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int result = 0;
    for (int i = 0; i < 32; i++) {
      result += (n & 0x1);
      n = n >> 1;
    }
    return result;
  }
};

#ifdef DEBUG
REGISTER_TEST(example1) {
  uint32_t n(4);
  int groundTruth(1);
  return Solution().reverseBits(n) == groundTruth;
}
REGISTER_TEST(example2) {
  uint32_t n(32767);
  int groundTruth(15);
  return Solution().reverseBits(n) == groundTruth;
}
#endif