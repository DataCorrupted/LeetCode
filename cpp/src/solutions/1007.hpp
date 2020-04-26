class Solution {
 public:
  int minDominoRotations(vector<int>& A, vector<int>& B) {
    std::vector<size_t> count_a(6, 0);
    std::vector<size_t> count_b(6, 0);

    for (size_t i = 0; i < A.size(); i++) {
      count_a[A[i] - 1]++;
      count_b[B[i] - 1]++;
    }
    int dominate = -1;
    for (int i = 0; i < 6; i++) {
      if (count_a[i] + count_b[i] >= A.size()) {
        dominate = i;
        break;
      }
    }
    if (dominate == -1) {
      return -1;
    }
    for (size_t i = 0; i < A.size(); i++) {
      if (A[i] - 1 != dominate && B[i] - 1 != dominate) {
        return -1;
      }
    }
    return std::min(A.size() - count_a[dominate], B.size() - count_b[dominate]);
  }
};
#ifdef DEBUG

REGISTER_TEST(example1) {
  vector<int> A({2, 1, 2, 4, 2, 2});
  vector<int> B({5, 2, 6, 2, 3, 2});
  int groundTruth = 2;

  return Solution().minDominoRotations(A, B) == groundTruth;
}
REGISTER_TEST(example2) {
  vector<int> A({3, 5, 1, 2, 3});
  vector<int> B({3, 6, 3, 3, 4});
  int groundTruth = -1;

  return Solution().minDominoRotations(A, B) == groundTruth;
}

REGISTER_TEST(example3) {
  vector<int> A({1});
  vector<int> B({1});
  int groundTruth = 0;

  return Solution().minDominoRotations(A, B) == groundTruth;
}

#endif