class Solution {
 public:
  bool check(uint64_t st, uint64_t nd, int k, string &num) {
    int n = num.size();
    uint64_t sum = nd;
    nd = st;
    while (true) {
      st = nd;
      nd = sum;
      sum = st + nd;
      std::ostringstream o;
      o << sum;
      string sumStr = o.str();
      for (char c : sumStr) {
        if (k == n) {
          return false;
        }
        if (c == num[k]) {
          k++;
        } else {
          return false;
        }
      }
      if (k == n) {
        return true;
      }
    }
  }
  bool isAdditiveNumber(string num) {
    int n = num.size();

    if (n == 0) {
      return false;
    }
    uint64_t st = 0, nd = 0;
    for (int i = 0; i < n; i++) {
      nd = 0;
      st = st * 10 + (num[i] - 48);
      for (int j = i + 1; j < n - 1; j++) {
        nd = nd * 10 + (num[j] - 48);
        if (check(st, nd, j + 1, num)) {
          return true;
        }
        if (j == i + 1 && num[j] == '0') {
          break;
        }
      }
      if (i == 0 && num[i] == '0') {
        break;
      }
    }
    return false;
  }
};

#ifdef DEBUG

REGISTER_TEST(example1) {
  string num("112358");
  return Solution().isAdditiveNumber(num) == true;
}
REGISTER_TEST(example2) {
  string num("199100199");
  return Solution().isAdditiveNumber(num) == true;
}
REGISTER_TEST(example3) {
  string num("1023");
  return Solution().isAdditiveNumber(num) == false;
}
REGISTER_TEST(example4) {
  string num("0235813");
  return Solution().isAdditiveNumber(num) == false;
}
REGISTER_TEST(example5) {
  string num("000");
  return Solution().isAdditiveNumber(num) == true;
}
#endif
