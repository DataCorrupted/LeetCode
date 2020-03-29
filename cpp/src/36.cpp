class Solution {
 public:
  bool rows[9][10];
  bool cols[9][10];
  bool boxs[9][10];

  bool isValidSudoku(vector<vector<char>> &board) {
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
          if (rows[i][a] || cols[j][a] || boxs[(i / 3) * 3 + j / 3][a]) {
            return false;
          } else {
            rows[i][a] = true;
            cols[j][a] = true;
            boxs[(i / 3) * 3 + j / 3][a] = true;
          }
        }
      }
    }
    return true;
  }
};