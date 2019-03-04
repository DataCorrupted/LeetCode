class NumArray {
	vector<int> partialSum;
public:
	NumArray(vector<int> nums) {
		partialSum.push_back(0);
		int total = 0;
		for (int num: nums){
			total += num;
			partialSum.push_back(total);
		}
	}
	
	int sumRange(int i, int j) {
		return partialSum[j+1] - partialSum[i];
	}
};

#ifdef DEBUG
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */

static NumArray obj(vector<int>({-2, 0, 3, -5, 2, -1}));

REGISTER_TEST(example1){
	vector<int> result({
		obj.sumRange(0, 2),
		obj.sumRange(2, 5),
		obj.sumRange(0, 5),
	});
	vector<int> groundTruth({1, -1, -3});
	return result == groundTruth;
}

#endif