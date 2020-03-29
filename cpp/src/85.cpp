class Solution {
 public:
  void insertMap(map<pair<int, int>, int> &map, pair<int, int> &pair, int val) {
    if (map.find(pair) == map.end()) {
      map[pair] = val;
    } else {
      map[pair] = min(map[pair], val);
    }
  }
  int maximalRectangle(vector<vector<char>> &matrix) {
    if (matrix.size() == 0) {
      return 0;
    }
    map<pair<int, int>, int> rangeMap;

    int n = matrix.size();
    int m = matrix.back().size();

    int maxRec = 0;

    for (int j = 0; j < m; j++) {
      map<pair<int, int>, int> newRangeMap;

      int startPtr = -1, endPtr;
      for (int i = 0; i < n; i++) {
        if (matrix[i][j] == '1') {
          if (startPtr == -1) {
            startPtr = i;
            endPtr = i;
          } else {
            endPtr++;
          }
        }
        if ((matrix[i][j] == '0' || (matrix[i][j] == '1' && i == n - 1)) &&
            startPtr != -1) {
          newRangeMap[pair<int, int>(startPtr, endPtr)] = j;
          startPtr = -1;
        }
      }

      for (auto rSPair : rangeMap) {
        pair<int, int> range = rSPair.first;
        int startPtr = rSPair.second;
        maxRec = max(maxRec, (j - startPtr) * (range.second - range.first + 1));
        for (auto newRangePair : newRangeMap) {
          auto oldP = range;
          auto newP = newRangePair.first;
          if (newP.first == oldP.first && newP.second == oldP.second) {
            // Two range are the same
            // 000
            // 011
            // 011
            //   ^
            insertMap(newRangeMap, oldP, startPtr);

          } else if (newP.first <= oldP.first && newP.second >= oldP.second) {
            // New Range larger
            // 001
            // 011
            // 011
            //   ^
            insertMap(newRangeMap, oldP, startPtr);
            insertMap(newRangeMap, newP, j);

          } else if (newP.first >= oldP.first && newP.second <= oldP.second) {
            // New range smaller
            // 000
            // 011
            // 010
            //   ^
            maxRec = std::max(maxRec,
                              (j - startPtr) * (oldP.second - oldP.first + 1));
            insertMap(newRangeMap, newP, startPtr);

          } else if ((newP.first < oldP.first && newP.second <= oldP.second &&
                      newP.second >= oldP.first) ||
                     (newP.first >= oldP.first && newP.first <= oldP.second &&
                      newP.second > oldP.second)) {
            // Two ranges misalign
            // 001  |  010
            // 011  |  011
            // 010  |  001
            //   ^       ^
            maxRec = std::max(maxRec,
                              (j - startPtr) * (oldP.second - oldP.first + 1));
            pair<int, int> commenRange(max(newP.first, oldP.first),
                                       min(newP.second, oldP.second));
            insertMap(newRangeMap, commenRange, startPtr);
          }
        }
      }
      swap(newRangeMap, rangeMap);
    }
    for (auto p : rangeMap) {
      pair<int, int> range = p.first;
      int startPtr = p.second;
      maxRec = max(maxRec, (m - startPtr) * (range.second - range.first + 1));
    }
    return maxRec;
  }
};

#ifdef DEBUG
REGISTER_TEST(example1) {
  vector<vector<char>> matrix({
      {'1', '0', '1', '0', '0'},
      {'1', '0', '1', '1', '1'},
      {'1', '1', '1', '1', '1'},
      {'1', '0', '0', '1', '0'},
  });
  int groundTruth = 6;
  return Solution().maximalRectangle(matrix) == groundTruth;
}
REGISTER_TEST(example2) {
  vector<vector<char>> matrix({
      {'0', '1'},
  });
  int groundTruth = 1;
  return Solution().maximalRectangle(matrix) == groundTruth;
}
REGISTER_TEST(example3) {
  vector<vector<char>> matrix({
      {'0', '0', '0', '1', '0', '1', '1', '1'},
      {'0', '1', '1', '0', '0', '1', '0', '1'},
      {'1', '0', '1', '1', '1', '1', '0', '1'},
      {'0', '0', '0', '1', '0', '0', '0', '0'},
      {'0', '0', '1', '0', '0', '0', '1', '0'},
      {'1', '1', '1', '0', '0', '1', '1', '1'},
      {'1', '0', '0', '1', '1', '0', '0', '1'},
      {'0', '1', '0', '0', '1', '1', '0', '0'},
      {'1', '0', '0', '1', '0', '0', '0', '0'},
  });
  int groundTruth = 4;
  return Solution().maximalRectangle(matrix) == groundTruth;
}
#endif
