class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int result = 0;
		if (prices.size() == 0) { return 0; }
		for (unsigned i=0; i<prices.size()-1; i++){
			if (prices[i] < prices[i+1]){
				result += (prices[i+1] - prices[i]);
			}
		}
		return result;
	}
};

#ifdef DEBUG
REGISTER_TEST(example1){
	vector<int> prices({7,1,5,3,6,4});
	int groundTruth = 7;
	return Solution().maxProfit(prices) == groundTruth;
}
REGISTER_TEST(example2){
	vector<int> prices({1,2,3,4,5});
	int groundTruth = 4;
	return Solution().maxProfit(prices) == groundTruth;
}
REGISTER_TEST(example3){
	vector<int> prices({7,6,4,3,1});
	int groundTruth = 0;
	return Solution().maxProfit(prices) == groundTruth;
}
REGISTER_TEST(example4){
	vector<int> prices;
	int groundTruth = 0;
	return Solution().maxProfit(prices) == groundTruth;
}
#endif