class Solution {
public:
	unsigned cntFive(int n){
		if (n < 5) { return 0; }
		return n/5 + cntFive(n/5);
	}
	int trailingZeroes(int n) {
		// Don't cnt two because it's always more than five;
		unsigned five=0; 
		five = cntFive(n);
		return five;
	}
};

#ifdef DEBUG
#include "DebugUtil.h"
REGISTER_TEST(example_1){
	int n = 3;
	int groundTruth = 0;
	return Solution().trailingZeroes(n) == groundTruth;
}
REGISTER_TEST(example_2){
	int n = 5;
	int groundTruth = 1;
	return Solution().trailingZeroes(n) == groundTruth;
}
REGISTER_TEST(example_3){
	int n = 1808548329;
	int groundTruth = 452137076;
	cout << Solution().trailingZeroes(n);
	return Solution().trailingZeroes(n) == groundTruth;
}
#endif