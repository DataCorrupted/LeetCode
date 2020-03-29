class Solution {
 public:
  int minDistance(string word1, string word2) {
    if (word1.size() < word2.size()) {
      std::swap(word1, word2);
    }
    if (word2.size() == 0) {
      return word1.size();
    }

    std::vector<int> curr, prev;

    bool hadSame = false;
    // the distance of word1[0:i] and word2[0:0]
    for (unsigned i = 0; i < word1.size(); i++) {
      curr.push_back(((i == 0) ? 0 : curr.back()) + 1);
      prev.push_back(0);
      if (!hadSame && word1[i] == word2[0]) {
        curr.back()--;
        hadSame = true;
      }
    }

    hadSame = false;
    for (unsigned i = 1; i < word2.size(); i++) {
      std::swap(curr, prev);
      curr[0] = prev[0] + 1;
      if (!hadSame && word2[i] == word1[0]) {
        curr[0]--;
        hadSame = true;
      }
      for (unsigned j = 1; j < word1.size(); j++) {
        if (word2[i] == word1[j]) {
          curr[j] = prev[j - 1];
        } else {
          curr[j] = 1 + min(min(curr[j - 1], prev[j]), prev[j - 1]);
        }
      }
    }
    return curr.back();
  }
};

#ifdef DEBUG
#include "DebugUtil.h"

REGISTER_TEST(example1) {
  string word1("horse"), word2("ros");
  int groundTruth = 3;
  return Solution().minDistance(word1, word2) == groundTruth;
}
REGISTER_TEST(example2) {
  string word1("intention"), word2("execution");
  int groundTruth = 5;
  return Solution().minDistance(word1, word2) == groundTruth;
}
REGISTER_TEST(example3) {
  string word1("a"), word2("ab");
  int groundTruth = 1;
  return Solution().minDistance(word1, word2) == groundTruth;
}

#endif