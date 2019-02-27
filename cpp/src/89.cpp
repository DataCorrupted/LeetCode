class Solution {
public:
	vector<int> grayCode(int n) {
		uint64_t total = 1 << n;
		vector<int> result;
		result.push_back(0);
		int data = 0;
		for (uint64_t i=1; i<total; i++){
			for (int j=0; j<n; j++){
				int tmp_data = data ^ (1 << j);
				if (std::find(result.begin(), result.end(), tmp_data) == result.end()){
					data = tmp_data;
					result.push_back(data);
					break;
				}
			}
		}
		return result;
	}
};

#ifdef DEBUG

REGISTER_TEST(example1){
	int n = 2;
	vector<int> groundTruth({0, 1, 3, 2});
	return Solution().grayCode(n) == groundTruth;
}
REGISTER_TEST(example2){
	int n = 0;
	vector<int> groundTruth({0});
	return Solution().grayCode(n) == groundTruth;
}
REGISTER_TEST(example3){
	int n = 1;
	vector<int> groundTruth({0, 1});
	return Solution().grayCode(n) == groundTruth;
}
REGISTER_TEST(example4){
	int n = 3;
	vector<int> groundTruth({0, 1, 3, 2, 6, 7, 5, 4});
	return Solution().grayCode(n) == groundTruth;
}

#endif