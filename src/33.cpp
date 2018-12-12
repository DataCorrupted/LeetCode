class Solution {
public:

	bool gt(int a, int b) { return a>b; }
	bool lt(int a, int b) { return a<b; }

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

	int search(vector<int>& nums, int target) {
		if (nums.size() == 0) { return -1; }
		if (nums.size() == 1) { return (nums[0] == target)? 0: -1; }
		int mid = nums.size() - 1;
		// Search for the split point.
		// nums[end] is max; nums[begin] is min
		int end = binarySearch(nums, nums[mid], 0, mid, &Solution::gt);
		int begin = end + 1;
		int l;
		if (target == nums[mid]){
			return mid;
		} else if (target < nums[mid]){
			l = binarySearch(nums, target, begin, mid, &Solution::lt);
		} else {
			// Don't worry about end == -1,
			// In that case, the array would be sorted and the control flow will never reach here.
			// Since by then nums[mid] would be the max.
			l = binarySearch(nums, target, 0, end, &Solution::lt);
		}
		return (nums[l+1] != target) ? -1: l+1;
	}

	static bool test0(){
		int target = 0;
		std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
		int groundTruth = 4;
		return Solution().search(nums, target) == groundTruth;
	}
	static bool test1(){
		int target = 3;
		std::vector<int> nums = {1, 3, 5};
		int groundTruth = 1;
		return Solution().search(nums, target) == groundTruth;
	}
	static bool test2(){
		int target = 0;
		std::vector<int> nums = {1};
		int groundTruth = -1;
		return Solution().search(nums, target) == groundTruth;
	}
	static bool test3(){
		int target = 1;
		std::vector<int> nums = {1, 2, 3, 4, 5};
		int groundTruth = 0;
		return Solution().search(nums, target) == groundTruth;
	}
};