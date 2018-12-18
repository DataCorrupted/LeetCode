class Solution {
public:

	bool le(int a, int b) { return a<=b; }

	// The cmpFunc guarantees that the array can be converted to the form of TTT...TTFF...FFF.
	// This function will find the idx of the last T or return l-1.
	int binarySearch(vector<int>& nums, int target, int l, int r, bool (Solution::*cmpFunc)(int, int)){

		// However, there can be cases where only T or only F are present.
		// Test if the first is F, if so, return not found.
		if (!(this->*cmpFunc)(nums[l], target)) { return l-1; }
		// Test if the last is T, if so, return the last one.
		if ((this->*cmpFunc)(nums[r],target)) { return r; }
		
		int m = 0;
		while (l + 1 < r){
			m = (l + r) / 2;
			if ((this->*cmpFunc)(nums[m],target)) {
				l = m;
			} else {
				r = m;
			}
		}
		// arr[l] = T, arr[r] = F.
		return l;
	}

	vector<int> twoSum(vector<int>& numbers, int target) {
		int idx = 0;
		while (numbers[idx] < target / 2 + 1){
			int otherIdx = 
				binarySearch(numbers, target-numbers[idx], idx, numbers.size() -1, &Solution::le);
			if (numbers[idx] + numbers[otherIdx] == target) {
				return {idx+1, otherIdx+1};
			}
			idx ++;
		}
		// Should not happen.
		return {0, 0};
	}
};	

#ifdef DEBUG
#include "DebugUtil.h"
REGISTER_TEST(example_1){
	vector<int> numbers = {2,7,11,15};
	int target = 9;
	vector<int> groundTruth = {1, 2};
	return Solution().twoSum(numbers, target) == groundTruth;
}
#endif