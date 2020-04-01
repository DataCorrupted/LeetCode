class Solution {
 public:
  map<int, int> num_left;

  const vector<vector<int>> recursiveCombSum(const int target) {
    vector<vector<int>> v;
    if (target == 0) {
      v.push_back(vector<int>());
      return v;
    }
    for (auto iter = num_left.begin(); iter != num_left.end(); ++iter) {
      int candidate = iter->first;
      if (iter->second && target - candidate >= 0) {
        iter->second--;
        auto temp = recursiveCombSum(target - candidate);
        iter->second++;
        for (int j = 0; j < temp.size(); j++) {
          auto vec = temp[j];
          if (vec.size() == 0 || candidate <= vec[0]) {
            vec.insert(vec.begin(), candidate);
            v.push_back(vec);
          }
        }
      }
    }
    return v;
  }

  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    for (int i = 0; i < candidates.size(); i++) {
      num_left[candidates[i]] += 1;
    }
    return recursiveCombSum(target);
  }
};