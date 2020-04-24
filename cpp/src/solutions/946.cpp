class Solution {
 public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    std::stack<int> s;
    size_t pop_idx = 0;
    for (size_t push_idx = 0; push_idx < pushed.size(); push_idx++) {
      s.push(pushed[push_idx]);
      while (!s.empty() && s.top() == popped[pop_idx]) {
        s.pop();
        pop_idx++;
      }
    }
    while (!s.empty()) {
      if (s.top() == popped[pop_idx]) {
        pop_idx++;
        s.pop();
      } else {
        return false;
      }
    }
    return true;
  }
};

#ifdef DEBUG

REGISTER_TEST(example1) {
  vector<int> pushed({1, 2, 3, 4, 5});
  vector<int> poped({4, 5, 3, 2, 1});
  bool groundTruth = true;

  return Solution().validateStackSequences(pushed, poped) == groundTruth;
}
REGISTER_TEST(example2) {
  vector<int> pushed({1, 2, 3, 4, 5});
  vector<int> poped({4, 3, 5, 1, 2});
  bool groundTruth = false;

  return Solution().validateStackSequences(pushed, poped) == groundTruth;
}

#endif