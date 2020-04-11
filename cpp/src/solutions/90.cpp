class Solution {

    vector<std::pair<int, int> > num_pairs;
    vector<vector<int> > power_set;
    vector<int> curr_subset;

private:

    void dfs(size_t curr) {
        if (curr == num_pairs.size()) {
            this->power_set.push_back(curr_subset);
            return;
        }

        std::pair<int, int> p = this->num_pairs[curr];
        int num = p.first;
        int occ = p.second;

        for (int i=0; i<=occ; i++) {
            dfs(curr + 1);
            this->curr_subset.push_back(num);
        }
        for (int i=0; i<=occ; i++) {
            this->curr_subset.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (int n: nums) {
            size_t len = num_pairs.size();
            if (len != 0 && this->num_pairs[len-1].first == n) {
                this->num_pairs[len-1].second += 1;
            } else  {
                this->num_pairs.push_back(std::pair<int, int>(n, 1));
            }
        }
        this->curr_subset = vector<int>();
        dfs(0);
        return this->power_set;
    }
};

#ifdef DEBUG
REGISTER_TEST(sample) {
  vector<int> nums = {1, 2, 2};
  vector<vector<int> > groundTruth {
    {},
    {2},
    {2, 2},
    {1},
    {1, 2},
    {1, 2, 2}
  };
  return Solution().subsetsWithDup(nums) == groundTruth;
}
REGISTER_TEST(empty) {
  vector<int> nums = {};
  vector<vector<int> > groundTruth {
    {},
  };
  return Solution().subsetsWithDup(nums) == groundTruth;
}
REGISTER_TEST(non_order) {
  vector<int> nums = {4,4,4,1,4};
  vector<vector<int> > groundTruth {
    {},
    {4},
    {4, 4},
    {4, 4, 4},
    {4, 4, 4, 4},
    {1},
    {1, 4},
    {1, 4, 4},
    {1, 4, 4, 4},
    {1, 4, 4, 4, 4},
  };
  return Solution().subsetsWithDup(nums) == groundTruth;
}
#endif