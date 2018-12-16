class Solution {
public:
	const vector<int> pow = {0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

	string getPermutation(int n, int k) {
		std::vector<int> selectionPool;
		std::string result = std::string();
		for (int i=0; i<n; i++){ selectionPool.push_back(i+1); }
		for (int i=0; i<n; i++){
			int cnt = pow[n-i-1];
			int idx = (cnt == 0)? 0: (k-1) / cnt;
			result += (char)(selectionPool[idx] + 48);
			selectionPool.erase(selectionPool.begin() + idx);
			k -= idx * pow[n-i-1];
		}
		return result;
	}
};

#ifdef DEBUG
#include "DebugUtil.h"
REGISTER_TEST(example_1){
	int n=3, k=3;
	string groundTruth = "213";
	return Solution().getPermutation(n, k) == groundTruth;
}
REGISTER_TEST(example_2){
	int n=4, k=9;
	string groundTruth = "2314";
	return Solution().getPermutation(n, k) == groundTruth;
}
REGISTER_TEST(example_3){
	int n=5, k=120;
	string groundTruth = "54321";
	cout <<Solution().getPermutation(n, k); 
	return Solution().getPermutation(n, k) == groundTruth;
}
#endif