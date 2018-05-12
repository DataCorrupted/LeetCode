class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        while (l < r - 1){
            int mid = (l + r) / 2;
            if (nums[mid] > target){
                r = mid;
            } else if (nums[mid] < target){
                l = mid;
            } else {
                return mid;
            }
        }
        if (nums[l] >= target) { return l; }
        if (nums[r] < target) { return r+1; }
        return r;
    }
};