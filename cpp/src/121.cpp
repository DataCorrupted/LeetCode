class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int minPrice = 0x7fffffff;
		int result = 0;
		for (int i: prices){
			if (i < minPrice){ minPrice = i; }
			if (i - minPrice > result) { result = i - minPrice; }
		}
		return result;
	}
};

#ifdef DEBUG
REGISTER_TEST(example1){
	vector<int> prices({7,1,5,3,6,4});
	int groundTruth = 5;
	return Solution().maxProfit(prices) == groundTruth;
}
REGISTER_TEST(example2){
	vector<int> prices({7,6,4,3,1});
	int groundTruth = 0;
	return Solution().maxProfit(prices) == groundTruth;
}
#endif