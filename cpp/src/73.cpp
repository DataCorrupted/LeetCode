class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {

		if (matrix.size() == 0){ return; }
		int n = matrix.size(), m = matrix.back().size();

		bool rm1StLn = false, rm1StCo = false;
		for (int i=0; i<n; i++){
			if (!matrix[i][0]) {
				rm1StCo = true; break;
			}
		}
		for (int j=0; j<m; j++){
			if (!matrix[0][j]){
				rm1StLn = true; break;
			}
		}
		for (int i=1; i<n; i++){
			for (int j=1; j<m; j++){
				if (!matrix[i][j]){
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}

		for (int i=1; i<n; i++){
			for (int j=1; j<m; j++){
				if (!matrix[i][0] || !matrix[0][j]){
					matrix[i][j] = 0;
				}
			}
		}
		if (rm1StLn){
			for (int j=0; j<m; j++){
				matrix[0][j] = 0;
			}	
		}
		if (rm1StCo){
			for (int i=0; i<n; i++){
				matrix[i][0] = 0;
			}	
		}
	}
};

#ifdef DEBUG
#include "DebugUtil.h"

REGISTER_TEST(example1){
	vector<vector<int>> matrix = {
		{1,1,1},
		{1,0,1},
		{1,1,1},
	};
	vector<vector<int>> groundTruth = {
		{1,0,1},
		{0,0,0},
		{1,0,1},
	};
	Solution().setZeroes(matrix);
	return matrix == groundTruth;
}
REGISTER_TEST(example2){
	vector<vector<int>> matrix = {
		{0,1,2,0},
		{3,4,5,2},
		{1,3,1,5},
	};
	vector<vector<int>> groundTruth = {
		{0,0,0,0},
		{0,4,5,0},
		{0,3,1,0},
	};
	Solution().setZeroes(matrix);
	return matrix == groundTruth;
}
#endif