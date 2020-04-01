class Solution {
 public:
  string minWindow(string s, string t) {
    if (s.size() == 0 || t.size() == 0) {
      return "";
    }

    map<char, int> tMap;
    map<char, int> foundMap;
    for (unsigned i = 0; i < t.size(); i++) {
      tMap[t[i]] = tMap[t[i]] + 1;
    }
    unsigned minWin = 0xffffffff;
    unsigned minLeft = 0;
    unsigned matchedLetters = 0;

    for (unsigned left = 0, right = 0; right < s.size(); right++) {
      char c = s[right];
      if (tMap.find(c) != tMap.end()) {
        foundMap[c] = foundMap[c] + 1;
        if (foundMap[c] <= tMap[c]) {
          matchedLetters++;
        }
      }
      while (matchedLetters == t.size()) {
        if (tMap.find(s[left]) != tMap.end()) {
          foundMap[s[left]]--;
          if (foundMap[s[left]] < tMap[s[left]]) {
            matchedLetters--;
            if (minWin > right - left + 1) {
              minWin = right - left + 1;
              minLeft = left;
            }
          }
        }
        left++;
      }
    }
    if (minWin == 0xffffffff) {
      return "";
    } else {
      return s.substr(minLeft, minWin);
    }
  }
};

#ifdef DEBUG

REGISTER_TEST(example1) {
  string s("ADOBECODEBANC"), t("ABC");
  string groundTruth("BANC");
  return Solution().minWindow(s, t) == groundTruth;
}
REGISTER_TEST(example2) {
  string s("a"), t("aa");
  string groundTruth("");
  return Solution().minWindow(s, t) == groundTruth;
}

#endif