class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] == target - nums[i]) {
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    return temp;
                }
            }
        }        
    }
};