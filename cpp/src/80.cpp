class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		unsigned wrPtr = 0, rdPtr = 0;
		int appCnt = 0, curr = -1;
		while (rdPtr < nums.size()){
			if (nums[rdPtr] != curr){
				curr = nums[rdPtr];
				appCnt = 1;
			}
			if (appCnt <= 2){
				nums[wrPtr] = nums[rdPtr];
				wrPtr ++; rdPtr ++;
				appCnt ++;
			} else {
				// Exaust all the sduplicates.
				while (rdPtr < nums.size() && nums[rdPtr] == curr) { rdPtr ++; }
			}
		}
		return wrPtr;
	}
};

#ifdef DEBUG
#include "DebugUtil.h"

REGISTER_TEST(example1){
	vector<int> nums = {1,1,1,2,2,3};
	vector<int> groundTruthVec = {1, 1, 2, 2, 3};
	int groundTruthInt = 5;
	int len = Solution().removeDuplicates(nums);
	return groundTruthInt == len && groundTruthVec == vector<int>(nums.begin(), nums.begin() + len);
}
REGISTER_TEST(example2){
	vector<int> nums = {0,0,1,1,1,1,2,3,3};
	vector<int> groundTruthVec = {0, 0, 1, 1, 2, 3, 3};
	int groundTruthInt = 7;
	int len = Solution().removeDuplicates(nums);
	return groundTruthInt == len && groundTruthVec == vector<int>(nums.begin(), nums.begin() + len);
}
#endif