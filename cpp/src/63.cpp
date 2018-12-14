class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		unsigned n = obstacleGrid.size();
		unsigned m = obstacleGrid[0].size();

		std::vector<int> curr = vector<int>();
		std::vector<int> prev = vector<int>();
		int cnt = 1;
		for (unsigned j=0; j<m; j++){
			if (obstacleGrid[0][j]) { cnt = 0; }
			prev.push_back(0);
			curr.push_back(cnt);
		}
		for (unsigned i=1; i<n; i++){
			// Swap is more efficient than prev = curr, 
			// which would require a linear time copy.
			prev.swap(curr);
			curr[0] = obstacleGrid[i][0]? 0: prev[0];
			for (unsigned j=1; j<m; j++){
				curr[j] = obstacleGrid[i][j]? 0: (prev[j] + curr[j-1]);
			}
		}
		return curr[m-1];
	}
};

#ifdef DEBUG
#include "debugUtil.h"

REGISTER_TEST(2x3){
	vector<vector<int>> obstacleGrid = {
			{0, 0, 0},
			{0, 0, 0}
	};
	int groundTruth = 3;
	return Solution().uniquePathsWithObstacles(obstacleGrid) == groundTruth;
}
REGISTER_TEST(ObstacleGrid){
	vector<vector<int>> obstacleGrid = {
			{0, 0, 0},
			{0, 1, 0},
			{0, 0, 0},
	};
	int groundTruth = 2;
	return Solution().uniquePathsWithObstacles(obstacleGrid) == groundTruth;
}
REGISTER_TEST(ObstacleInFirstLine){
	vector<vector<int>> obstacleGrid = {
			{0, 1, 0},
			{0, 1, 1},
			{0, 0, 0},
	};
	int groundTruth = 1;
	return Solution().uniquePathsWithObstacles(obstacleGrid) == groundTruth;
}
REGISTER_TEST(1x1){
	vector<vector<int>> obstacleGrid = {
			{1},
	};
	int groundTruth = 0;
	return Solution().uniquePathsWithObstacles(obstacleGrid) == groundTruth;
}
REGISTER_TEST(2x1_0){
	vector<vector<int>> obstacleGrid = {
			{1},
			{0}
	};
	int groundTruth = 0;
	return Solution().uniquePathsWithObstacles(obstacleGrid) == groundTruth;
}
REGISTER_TEST(1x2){
	vector<vector<int>> obstacleGrid = {
			{1, 0},
	};
	int groundTruth = 0;
	return Solution().uniquePathsWithObstacles(obstacleGrid) == groundTruth;
}
REGISTER_TEST(2x1_1){
	vector<vector<int>> obstacleGrid = {
			{0},
			{1}
	};
	int groundTruth = 0;
	return Solution().uniquePathsWithObstacles(obstacleGrid) == groundTruth;
}
#endif