class Solution {
  map<int, vector<int>> graph;

 public:
  vector<int> bfs_find_longest_path(int start) {
    vector<int> max_path;
    queue<std::pair<int, vector<int>>> Q;
    vector<bool> visited(this->graph.size(), false);

    Q.push(std::pair<int, vector<int>>(start, {start}));
    visited[start] = true;
    while (!Q.empty()) {
      auto pair = Q.front();
      Q.pop();
      int curr = pair.first;
      vector<int> path = pair.second;

      for (int next : this->graph[curr]) {
        if (visited[next]) {
          continue;
        }
        path.push_back(next);
        Q.push(std::pair<int, vector<int>>(next, path));
        path.pop_back();
        visited[next] = true;
      }
      if (max_path.size() < path.size()) {
        max_path = path;
      }
    }
    return max_path;
  }
  void dfs_find_longest_path(vector<int>& path, vector<bool>& visited,
                             vector<int>& longest) {
    if (this->graph.size() == 1) {
      longest = {0};
      return;
    }
    for (int next : this->graph[path[path.size() - 1]]) {
      if (visited[next]) {
        continue;
      } else {
        visited[next] = true;
        path.push_back(next);
        if (path.size() > longest.size()) {
          longest = path;
        }
        dfs_find_longest_path(path, visited, longest);
        path.pop_back();
      }
    }
  }

  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    for (int i = 0; i < n; i++) {
      this->graph[i] = vector<int>();
    }
    for (vector<int>& vec : edges) {
      this->graph[vec[0]].push_back(vec[1]);
      this->graph[vec[1]].push_back(vec[0]);
    }

    /*
        vector<int> first_path = this->bfs_find_longest_path(0);
        vector<int> diameter =
            this->bfs_find_longest_path(first_path[first_path.size() - 1]);
    */

    vector<int> first_path, diameter;

    vector<int> path = {0};
    vector<bool> visited(n, false);
    visited[0] = true;
    this->dfs_find_longest_path(path, visited, first_path);

    path = {first_path[first_path.size() - 1]};
    visited = vector<bool>(n, false);
    visited[path[0]] = true;
    this->dfs_find_longest_path(path, visited, diameter);
    size_t size = diameter.size();
    vector<int> ret({diameter[size / 2]});
    if ((size & 1) == 0) {
      ret.push_back(diameter[size / 2 - 1]);
    }
    return ret;
  }
};

#ifdef DEBUG

REGISTER_TEST(example1) {
  int n = 4;
  vector<vector<int>> edges = {{1, 0}, {1, 2}, {1, 3}};
  vector<int> groundTruth = {1};
  return Solution().findMinHeightTrees(n, edges) == groundTruth;
}

REGISTER_TEST(example2) {
  int n = 4;
  vector<vector<int>> edges = {{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}};
  vector<int> groundTruth = {3, 4};
  return Solution().findMinHeightTrees(n, edges) == groundTruth;
}
REGISTER_TEST(example3) {
  int n = 1;
  vector<vector<int>> edges = {};
  vector<int> groundTruth = {0};
  return Solution().findMinHeightTrees(n, edges) == groundTruth;
}
REGISTER_TEST(example4) {
  int n = 2;
  vector<vector<int>> edges = {{0, 1}};
  vector<int> groundTruth = {0, 1};
  return Solution().findMinHeightTrees(n, edges) == groundTruth;
}
#endif