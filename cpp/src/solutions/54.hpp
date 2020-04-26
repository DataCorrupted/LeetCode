class SpiralNextPosGenerator {
 private:
  std::vector<std::pair<int, int> (SpiralNextPosGenerator::*)(
      std::pair<int, int>)>
      nextDirFuncVec = {
          &SpiralNextPosGenerator::right,
          &SpiralNextPosGenerator::down,
          &SpiralNextPosGenerator::left,
          &SpiralNextPosGenerator::up,
  };
  int dirFuncIdx;
  std::pair<int, int> currPos;
  int upBnd;
  int downBnd;
  int leftBnd;
  int rightBnd;

 private:
  std::pair<int, int> up(std::pair<int, int> pos) {
    pos.first--;
    return pos;
  }
  std::pair<int, int> down(std::pair<int, int> pos) {
    pos.first++;
    return pos;
  }
  std::pair<int, int> left(std::pair<int, int> pos) {
    pos.second--;
    return pos;
  }
  std::pair<int, int> right(std::pair<int, int> pos) {
    pos.second++;
    return pos;
  }
  bool isValidPos(const std::pair<int, int> &pos) {
    return pos.first >= upBnd && pos.first <= downBnd &&
           pos.second >= leftBnd && pos.second <= rightBnd;
  }
  void tryShrink() {
    // The outside loop is finished, shrink the size.
    // If it is currently goint up and finishing this loop.
    if (dirFuncIdx == 3 && currPos == std::pair<int, int>(upBnd + 1, leftBnd)) {
      upBnd++;
      downBnd--;
      leftBnd++;
      rightBnd--;
    }
  }

 public:
  SpiralNextPosGenerator(int n, int m)
      : dirFuncIdx(0),
        currPos({0, 0}),
        upBnd(0),
        downBnd(n - 1),
        leftBnd(0),
        rightBnd(m - 1){};
  std::pair<int, int> &next() {
    if (!isValidPos((this->*nextDirFuncVec[dirFuncIdx])(currPos))) {
      // Change direction
      dirFuncIdx = (dirFuncIdx + 1) % 4;
    }
    currPos = (this->*nextDirFuncVec[dirFuncIdx])(currPos);
    tryShrink();
    return currPos;
  }
};

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    if (matrix.size() == 0) {
      return vector<int>();
    }
    int n = matrix.size(), m = matrix[0].size();
    SpiralNextPosGenerator posGenerator(n, m);
    vector<int> result;
    std::pair<int, int> currPos;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        // cout << currPos;
        result.push_back(matrix[currPos.first][currPos.second]);
        currPos = posGenerator.next();
      }
    }
    return result;
  }
};

#ifdef DEBUG
#include "DebugUtil.h"

REGISTER_TEST(SpiralNextPosGenerator_0) {
  int n = 3, m = 3;
  SpiralNextPosGenerator posGenerator(n, m);
  std::vector<std::pair<int, int>> path = {{0, 0}};
  for (int i = 0; i < n * m - 1; i++) {
    path.push_back(posGenerator.next());
  }
  std::vector<std::pair<int, int>> groundTruth = {
      {0, 0}, {0, 1}, {0, 2}, {1, 2}, {2, 2}, {2, 1}, {2, 0}, {1, 0}, {1, 1}};
  return path == groundTruth;
}
REGISTER_TEST(SpiralNextPosGenerator_1) {
  int n = 5, m = 6;
  SpiralNextPosGenerator posGenerator(n, m);
  std::vector<std::pair<int, int>> path = {{0, 0}};
  for (int i = 0; i < n * m - 1; i++) {
    path.push_back(posGenerator.next());
  }
  std::vector<std::pair<int, int>> groundTruth = {
      {0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {1, 5}, {2, 5},
      {3, 5}, {4, 5}, {4, 4}, {4, 3}, {4, 2}, {4, 1}, {4, 0}, {3, 0},
      {2, 0}, {1, 0}, {1, 1}, {1, 2}, {1, 3}, {1, 4}, {2, 4}, {3, 4},
      {3, 3}, {3, 2}, {3, 1}, {2, 1}, {2, 2}, {2, 3},
  };
  return path == groundTruth;
}
REGISTER_TEST(example_1) {
  vector<vector<int>> matrix = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9},
  };
  vector<int> groundTruth = {1, 2, 3, 6, 9, 8, 7, 4, 5};
  return Solution().spiralOrder(matrix) == groundTruth;
}
REGISTER_TEST(example_2) {
  vector<vector<int>> matrix = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12},
  };
  vector<int> groundTruth = {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};
  return Solution().spiralOrder(matrix) == groundTruth;
}
REGISTER_TEST(example_3) {
  vector<vector<int>> matrix = {
      {1},
      {5},
  };
  vector<int> groundTruth = {1, 5};
  return Solution().spiralOrder(matrix) == groundTruth;
}
REGISTER_TEST(example_4) {
  vector<vector<int>> matrix = {{7}, {9}, {6}};
  vector<int> groundTruth = {7, 9, 6};
  return Solution().spiralOrder(matrix) == groundTruth;
}
#endif