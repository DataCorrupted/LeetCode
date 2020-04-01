class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    int result = 0;
    for (int i = 0; i < 32; i++) {
      result = (result << 1) + (n & 0x1);
      n = n >> 1;
    }
    return result;
  }
};

#ifdef DEBUG

REGISTER_TEST(example1) {
  uint32_t n(43261596);
  uint32_t groundTruth(964176192);
  return Solution().reverseBits(n) == groundTruth;
}
REGISTER_TEST(example2) {
  uint32_t n(4294967293);
  uint32_t groundTruth(3221225471);
  return Solution().reverseBits(n) == groundTruth;
}
#endif