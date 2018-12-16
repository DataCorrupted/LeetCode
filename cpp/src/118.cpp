class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> result;
		if (numRows == 0) { return result; }
		result.push_back(vector<int>({1}));
		for (int i=1; i<numRows; i++){
			result.push_back(vector<int>());
			for (int j=0; j<= i; j++){
				int val = 
					((j-1 <  0)? 0: result[i-1][j-1]) + 
					((j   >= i)? 0: result[i-1][j]);
				result[i].push_back((val == 0)? 1: val);
			}
		}
		return result;
	}
};

#ifdef DEBUG
#include "DebugUtil.h"
REGISTER_TEST(5){
	int numRows = 5;
	vector<vector<int>> groundTruth = {
		{1},
		{1, 1},
		{1, 2, 1},
		{1, 3, 3, 1},
		{1, 4, 6, 4, 1},
	};
	return Solution().generate(numRows) == groundTruth;
}
REGISTER_TEST(0){
	int numRows = 0;
	vector<vector<int>> groundTruth = {};
	return Solution().generate(numRows) == groundTruth;
}
#endif