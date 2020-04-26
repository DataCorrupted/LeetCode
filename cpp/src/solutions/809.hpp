class Solution {
 private:
  typedef std::pair<char, int> Pair;
  typedef std::vector<Pair> PairVec;

 public:
  bool is_stretchy(const PairVec& s, const PairVec& w) const {
    if (s.size() != w.size()) {
      return false;
    }
    for (size_t i = 0; i < s.size(); i++) {
      if (s[i].first != w[i].first) {
        return false;
      } else {
        if (s[i].second == w[i].second) {
          continue;
        }
        if (s[i].second < 3 || s[i].second < w[i].second) {
          return false;
        }
      }
    }
    return true;
  }
  const PairVec profile_word(const string& s) const {
    PairVec ret;
    for (const char& c : s) {
      size_t size = ret.size() - 1;
      if (ret.empty() || ret[size].first != c) {
        ret.push_back(Pair(c, 1));
      } else {
        ret[size].second++;
      }
    }
    return ret;
  }
  int expressiveWords(string S, vector<string>& words) {
    int ret = 0;
    const PairVec profile = this->profile_word(S);
    for (string& w : words) {
      ret += is_stretchy(profile, this->profile_word(w));
    }
    return ret;
  }
};

#ifdef DEBUG
REGISTER_TEST(example1) {
  vector<string> words({"hello", "hi", "helo"});
  string S = "heeellooo";
  int groundTruth = 1;
  return Solution().expressiveWords(S, words) == groundTruth;
}
#endif