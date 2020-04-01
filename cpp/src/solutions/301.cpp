class Solution {
 private:
  vector<string> m_result;

 public:
  bool isValid(string &s) {
    std::stack<char> charStack;
    for (char c : s) {
      if (c != ')' && c != '(') {
        continue;
      } else if (c == '(') {
        charStack.push(c);
      } else if (c == ')') {
        if (!charStack.empty()) {
          charStack.pop();
        } else {
          return false;
        }
      }
    }
    return charStack.empty();
  }

  void dfs(string &s, int start, int left, int right) {
    if (left == 0 && right == 0) {
      if (isValid(s) &&
          std::find(m_result.begin(), m_result.end(), s) == m_result.end()) {
        m_result.push_back(s);
      }
      return;
    }
    char c = 0;
    for (unsigned i = start; i < s.size(); i++) {
      c = s[i];
      if (c == '(' && left) {
        string removedStr = s;
        removedStr.erase(i, 1);
        dfs(removedStr, i, left - 1, right);
      } else if (c == ')' && right) {
        string removedStr = s;
        removedStr.erase(i, 1);
        dfs(removedStr, i, left, right - 1);
      }
    }
  }

  vector<string> removeInvalidParentheses(string s) {
    unsigned i = 0;
    while (i < s.size() && s[i] != '(') {
      if (s[i] == ')') {
        s.erase(i, 1);
      } else {
        i++;
      }
    }

    int j = s.size();
    while (j >= 0 && s[j] != ')') {
      if (s[j] == '(') {
        s.erase(j, 1);
      } else {
        j--;
      }
    }
    std::stack<char> charStack;
    for (char c : s) {
      if (c != ')' && c != '(') {
        continue;
      } else if (c == '(') {
        charStack.push(c);
      } else if (c == ')') {
        if (!charStack.empty() && charStack.top() == '(') {
          charStack.pop();
        } else {
          charStack.push(c);
        }
      }
    }
    int left = 0, right = 0;
    while (!charStack.empty()) {
      char c = charStack.top();
      left += (c == '(');
      right += (c == ')');
      charStack.pop();
    }
    dfs(s, 0, left, right);
    return m_result;
  }
};

#ifdef DEBUG

REGISTER_TEST(isBoolTest1) {
  string s("(())()");
  bool groundTruth = true;
  return Solution().isValid(s) == groundTruth;
}
REGISTER_TEST(isBoolTest2) {
  string s("(()))(");
  bool groundTruth = false;
  return Solution().isValid(s) == groundTruth;
}
REGISTER_TEST(example1) {
  string s("()())()");
  vector<string> groundTruth = {"(())()", "()()()"};
  return Solution().removeInvalidParentheses(s) == groundTruth;
}
REGISTER_TEST(example2) {
  string s("(a)())()");
  vector<string> groundTruth = {"(a())()", "(a)()()"};
  return Solution().removeInvalidParentheses(s) == groundTruth;
}
REGISTER_TEST(example3) {
  string s(")(");
  vector<string> groundTruth = {""};
  return Solution().removeInvalidParentheses(s) == groundTruth;
}
REGISTER_TEST(example4) {
  string s("))())(()(((()t)");
  vector<string> groundTruth = {"()()(()t)", "()(()()t)"};
  return Solution().removeInvalidParentheses(s) == groundTruth;
}
REGISTER_TEST(example5) {
  string s(")()(");
  vector<string> groundTruth = {"()"};
  return Solution().removeInvalidParentheses(s) == groundTruth;
}
REGISTER_TEST(example6) {
  string s("())((((((((((b))(");
  vector<string> groundTruth = {"()((b))"};
  return Solution().removeInvalidParentheses(s) == groundTruth;
}
#endif