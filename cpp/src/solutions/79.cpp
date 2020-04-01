class Solution {
 private:
  int n;
  int m;

  vector<vector<char>> *m_board;
  string *m_word;

  char getCharNextLoc(int x_, int y_) {
    if (x_ < 0 || x_ >= n || y_ < 0 || y_ >= m) {
      return 0;
    } else {
      return (*m_board)[x_][y_];
    }
  }
  bool existAtLoc(int x, int y, int idx) {
    if ((unsigned)idx == m_word->size()) {
      return true;
    }

    const int dx[] = {1, -1, 0, 0};
    const int dy[] = {0, 0, 1, -1};
    for (int i = 0; i < 4; i++) {
      int x_ = x + dx[i];
      int y_ = y + dy[i];
      if (getCharNextLoc(x_, y_) == (*m_word)[idx]) {
        char tmp = (*m_board)[x_][y_];
        (*m_board)[x_][y_] = 0;
        if (existAtLoc(x_, y_, idx + 1)) {
          return true;
        }
        (*m_board)[x_][y_] = tmp;
      }
    }
    return false;
  }

 public:
  bool exist(vector<vector<char>> &board, string word) {
    if (board.empty() || board.back().empty()) {
      return false;
    }

    n = board.size();
    m = board.back().size();
    m_board = &board;
    m_word = &word;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] == word[0]) {
          char tmp = board[i][j];
          board[i][j] = 0;
          if (existAtLoc(i, j, 1)) {
            return true;
          }
          board[i][j] = tmp;
        }
      }
    }
    return false;
  }
};

#ifdef DEBUG
#include "DebugUtil.h"

REGISTER_TEST(example1) {
  vector<vector<char>> board = {
      {'A', 'B', 'C', 'E'},
      {'S', 'F', 'C', 'S'},
      {'A', 'D', 'E', 'E'},
  };
  string word = "ABCCED";
  bool groundTruth = true;
  return Solution().exist(board, word) == groundTruth;
}
REGISTER_TEST(example2) {
  vector<vector<char>> board = {
      {'A', 'B', 'C', 'E'},
      {'S', 'F', 'C', 'S'},
      {'A', 'D', 'E', 'E'},
  };
  string word = "SEE";
  bool groundTruth = true;
  return Solution().exist(board, word) == groundTruth;
}
REGISTER_TEST(example3) {
  vector<vector<char>> board = {
      {'A', 'B', 'C', 'E'},
      {'S', 'F', 'C', 'S'},
      {'A', 'D', 'E', 'E'},
  };
  string word = "ABCB";
  bool groundTruth = false;
  return Solution().exist(board, word) == groundTruth;
}
REGISTER_TEST(example4) {
  vector<vector<char>> board = {
      {'A', 'B', 'C', 'E'},
      {'S', 'F', 'C', 'S'},
      {'A', 'D', 'E', 'E'},
  };
  string word = "EEE";
  bool groundTruth = false;
  return Solution().exist(board, word) == groundTruth;
}
#endif
