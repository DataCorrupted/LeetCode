class Solution {
public:

	int binarySearch(vector<int>& nums, int target){
		int l = 0, r = nums.size() - 1;

		if (nums.size() == 0) { return -1; }
		if (target <= nums[l]) { return -1; }
		if (nums[r] < target) { return r; }
		
		int m = 0;
		while (l + 1 < r){
			m = (l + r) / 2;
			if (nums[m] < target) {
				l = m;
			} else {
				r = m;
			}
		}
		return l;
	}

	vector<int> searchRange(vector<int>& nums, int target) {
		int l = binarySearch(nums, target);
		int r = binarySearch(nums, target + 1);
		if (l == r) {
			return {-1, -1};
		} else {
			return {l+1, r};
		}
	}
};

#ifdef DEBUG
#include "debugUtil.h"
REGISTER_TEST(0){
	int target = 8;
	std::vector<int> nums = {5, 7, 7, 8, 8, 10};
	std::vector<int> groundTruth = {3, 4};
	return Solution().searchRange(nums, target) == groundTruth;
}
REGISTER_TEST(1){
	int target = 6;
	std::vector<int> nums = {5, 7, 7, 8, 8, 10};
	std::vector<int> groundTruth = {-1, -1};
	return Solution().searchRange(nums, target) == groundTruth;
}
REGISTER_TEST(2){
	int target = 3;
	std::vector<int> nums = {};
	std::vector<int> groundTruth = {-1, -1};
	return Solution().searchRange(nums, target) == groundTruth;
}
REGISTER_TEST(3){
	int target = 1;
	std::vector<int> nums = {1, 1, 1, 1, 1};
	std::vector<int> groundTruth = {0, 4};
	return Solution().searchRange(nums, target) == groundTruth;
}
#endif