class Solution {
 public:
  bool rows[9][10];
  bool cols[9][10];
  bool boxs[9][10];
  const bool dfs(int i, int j, vector<vector<char>> &board) {
    while (board[i][j] != '.') {
      i++;
      if (i == 9) {
        i = 0;
        j++;
      }
      if (i == 8 && j == 9) {
        return true;
      }
    }
    for (int k = 1; k < 10; k++) {
      if (!rows[i][k] && !cols[j][k] && !boxs[(i / 3) * 3 + j / 3][k]) {
        board[i][j] = ('0' + k);
        rows[i][k] = cols[j][k] = boxs[(i / 3) * 3 + j / 3][k] = true;
        bool result = dfs(i, j, board);
        if (result) {
          return result;
        }
        rows[i][k] = cols[j][k] = boxs[(i / 3) * 3 + j / 3][k] = false;
        board[i][j] = '.';
      }
    }
    return false;
  }

  void init(const vector<vector<char>> &board) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 10; j++) {
        rows[i][j] = false;
        cols[i][j] = false;
        boxs[i][j] = false;
      }
    }

    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        char c = board[i][j];
        int a = (c - '0');
        if (c != '.') {
          rows[i][a] = true;
          cols[j][a] = true;
          boxs[(i / 3) * 3 + j / 3][a] = true;
        }
      }
    }
  }

  void solveSudoku(vector<vector<char>> &board) {
    init(board);
    dfs(0, 0, board);
  }
};