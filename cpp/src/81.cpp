class Solution {
public:
	bool search(vector<int>& nums, int target) {
		for (int i: nums){
			if (i == target){ return true; }
		}
		return false;
	}
};

#ifdef DEBUG
#include "DebugUtil.h"

REGISTER_TEST(example1){
	vector<int> nums = {2,5,6,0,0,1,2};
	int target = 0;
	bool groundTruth = true;
	return Solution().search(nums, target) == groundTruth;
}
REGISTER_TEST(example2){
	vector<int> nums = {2,5,6,0,0,1,2};
	int target = 3;
	bool groundTruth = false;
	return Solution().search(nums, target) == groundTruth;
}

#endif