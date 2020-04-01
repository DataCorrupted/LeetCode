class Solution {
 public:
  string getHint(string secret, string guess) {
    int n = secret.size();
    int bull = 0, cow = 0;
    vector<int> guessCnt(10, 0);
    vector<int> secretCnt(10, 0);
    for (int i = 0; i < n; i++) {
      if (secret[i] == guess[i]) {
        bull++;
      } else {
        secretCnt[secret[i] - 48]++;
        guessCnt[guess[i] - 48]++;
      }
    }
    for (int i = 0; i < 10; i++) {
      cow += std::min(secretCnt[i], guessCnt[i]);
    }
    return to_string(bull) + "A" + to_string(cow) + "B";
  }
};

#ifdef DEBUG

REGISTER_TEST(example1) {
  string secret("1807");
  string guess("7810");
  string groundTruth("1A3B");
  return Solution().getHint(secret, guess) == groundTruth;
}
REGISTER_TEST(example2) {
  string secret("1123");
  string guess("0111");
  string groundTruth("1A1B");
  return Solution().getHint(secret, guess) == groundTruth;
}
REGISTER_TEST(example3) {
  string secret("1122");
  string guess("2211");
  string groundTruth("0A4B");
  return Solution().getHint(secret, guess) == groundTruth;
}

#endif