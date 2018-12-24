class Solution {
public:
	void sortColors(vector<int>& nums) {
		int cnt[3] = {0, 0, 0};
		for (int i: nums){
			cnt[i] ++;
		}
		int col = 0;
		for (unsigned i=0; i<nums.size(); i++){
			while (!cnt[col]) { col ++; }
			nums[i] = col;
			cnt[col] --;
		}
	}
};

#ifdef DEBUG
#include "DebugUtil.h"

REGISTER_TEST(example1){
	vector<int> nums = {2,0,2,1,1,0};
	vector<int> groundTruth = {0,0,1,1,2,2};

	Solution().sortColors(nums);
	return nums == groundTruth;
}
REGISTER_TEST(example2){
	vector<int> nums = {1};
	vector<int> groundTruth = {1};

	Solution().sortColors(nums);
	return nums == groundTruth;
}
#endif