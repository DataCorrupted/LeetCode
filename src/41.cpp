class Solution {
public:
    // Set nums[i] == i. The first one that does not match this pattern is the missing one.
    // Or everyone matches, then we stuck an extra one and he is it.
    int firstMissingPositive(vector<int>& nums) {
        nums.push_back(0);
        for (int i=0; i<nums.size(); i++){
            while (nums[i]>=0 && nums[i] < nums.size()){
                if (nums[i] == nums[nums[i]]){
                    break;
                }
                swap(nums[i], nums[nums[i]]);
            }
        }
        for (int i=1; i<nums.size(); i++){
            if (nums[i] != i){
                return i;
            }
        }
        return nums.size();
        
    }
};