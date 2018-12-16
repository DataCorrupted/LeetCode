class Solution {
public:
	int n;
	vector<int> curr;
	map<int, int> occMap;	
	vector<vector<int>> result;

	void DFSPermutation(int dep){
		if (dep == n) {
			result.push_back(curr);
			return;
		}
		for (auto p: occMap){
			if (!p.second){ continue; }
			curr[dep] = p.first; 	occMap[p.first] --;
			DFSPermutation(dep + 1);
			curr[dep] = -1;			occMap[p.first] ++;
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		n = nums.size();
		for (int i: nums){ 
			occMap[i] = occMap[i] + 1;
			curr.push_back(-1); 
		}
		DFSPermutation(0);
		return result;
	}
	vector<vector<int>> permuteUnique(vector<int>& nums){
		return permute(nums);
	}
};

#ifdef DEBUG
#include "DebugUtil.h"

REGISTER_TEST(do_repeat){
	vector<int> nums = {1, 1, 2};
	vector<vector<int>> groundTruth = {
		{1,1,2},
		{1,2,1},
		{2,1,1},
	};
	return Solution().permute(nums) == groundTruth;
}
REGISTER_TEST(no_repeat){
	vector<int> nums = {1, 2, 3};
	vector<vector<int>> groundTruth = {
		{1,2,3},
		{1,3,2},
		{2,1,3},
		{2,3,1},
		{3,1,2},
		{3,2,1},
	};
	return Solution().permute(nums) == groundTruth;
}
#endif