class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.size() == 0) { return 0; }
		vector<int> length;
		length.push_back(1);
		for (unsigned i=1; i < nums.size(); i++){
			int maxLen = 1;
			for (unsigned j=0; j<i; j++){
				if (nums[j] < nums[i] && length[j]+1 > maxLen){
					maxLen = length[j] + 1;
				}
			}
			length.push_back(maxLen);
		}
		int result = 0;
		for (int len: length){
			if (len > result){ result = len; }
		}
		return result;
	}
};

#ifdef DEBUG
REGISTER_TEST(example0){
	vector<int> nums;
	int groundTruth = 0;
	return Solution().lengthOfLIS(nums) == groundTruth;
}
REGISTER_TEST(example1){
	vector<int> nums({10,9,2,5,3,7,101,18});
	int groundTruth = 4;
	return Solution().lengthOfLIS(nums) == groundTruth;
}
REGISTER_TEST(example2){
	vector<int> nums({2, 2});
	int groundTruth = 1;
	return Solution().lengthOfLIS(nums) == groundTruth;
}
#endif