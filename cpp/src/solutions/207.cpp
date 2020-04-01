class Solution {
 private:
#define BLACK 0
#define GREY 1
#define WHITE 2

  vector<int> m_visited;
  vector<int> m_color;

 public:
  bool dfs(int node, vector<pair<int, int>> &prerequisites) {
    for (auto pair : prerequisites) {
      if (pair.first == node) {
        if (m_color[pair.second] == GREY) {
          return true;
        } else if (m_color[pair.second] == WHITE) {
          m_visited.push_back(pair.second);
          m_color[pair.second] = GREY;

          if (dfs(pair.second, prerequisites)) {
            return true;
          }
          m_color[pair.second] = WHITE;
        }
      }
    }
    return false;
  }
  bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
    for (int i = 0; i < numCourses; i++) {
      m_color.push_back(WHITE);
    }

    for (int i = 0; i < numCourses; i++) {
      if (m_color[i] == WHITE) {
        m_visited.push_back(i);
        m_color[i] = GREY;

        if (dfs(i, prerequisites)) {
          return false;
        } else {
          for (unsigned j = 0; j < m_visited.size(); j++) {
            m_color[m_visited[j]] = BLACK;
          }
          m_visited = vector<int>();
        }
      }
    }
    return true;
  }
};

#ifdef DEBUG
REGISTER_TEST(example0) {
  int numCourses = 2;
  vector<pair<int, int>> prerequisites = {pair<int, int>(1, 0)};
  return Solution().canFinish(numCourses, prerequisites) == true;
}
REGISTER_TEST(example1) {
  int numCourses = 2;
  vector<pair<int, int>> prerequisites = {pair<int, int>(1, 0),
                                          pair<int, int>(0, 1)};
  return Solution().canFinish(numCourses, prerequisites) == false;
}
REGISTER_TEST(example2) {
  int numCourses = 4;
  vector<pair<int, int>> prerequisites = {
      pair<int, int>(0, 1), pair<int, int>(1, 2), pair<int, int>(0, 3),
      pair<int, int>(3, 0)};
  return Solution().canFinish(numCourses, prerequisites) == false;
}
REGISTER_TEST(example3) {
  int numCourses = 3;
  vector<pair<int, int>> prerequisites = {
      pair<int, int>(0, 1), pair<int, int>(0, 2), pair<int, int>(1, 2)};
  return Solution().canFinish(numCourses, prerequisites) == true;
}
#endif