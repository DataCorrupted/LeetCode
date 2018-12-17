class Solution {
public:
	bool canJump(vector<int>& nums) {
		vector<bool> reachVec = {true};
		for (unsigned dest=1; dest<nums.size(); dest++){
			bool curReachable = false;
			for (unsigned src=0; src<dest; src++){
				// distance less eq than the jump ability;
				// The start point also have to reachable
				curReachable = curReachable || (reachVec[src] && int(dest - src) <= nums[src]);
			}
			reachVec.push_back(curReachable);
		}
		return reachVec.back();
	}
};

#ifdef DEBUG
#include "DebugUtil.h"
REGISTER_TEST(example_1){
	vector<int> nums = {2,3,1,1,4};
	bool groundTruth = true;
	return Solution().canJump(nums) == groundTruth;
}
REGISTER_TEST(example_2){
	vector<int> nums = {3,2,1,0,4};
	bool groundTruth = false;
	return Solution().canJump(nums) == groundTruth;
}
#endif