#include <queue>

class Solution {
private:
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	typedef std::pair<unsigned, unsigned> PosPair;
	void clearPosIJ(vector<vector<char>>& grid, unsigned i, unsigned j){
		queue<PosPair> clearQ;
		clearQ.push(PosPair(i, j));
		while (!clearQ.empty()) {
			PosPair pos = clearQ.front();
			clearQ.pop();

			for (int k = 0; k<4; k++){
				int x_ = pos.first + dx[k];
				int y_ = pos.second + dy[k];

				if (x_ >= 0 && x_ < int(grid.size())
				 && y_ >= 0 && y_ < int(grid.back().size())
				 && grid[x_][y_] == '1'){
				 	grid[x_][y_] = '0';
					clearQ.push(PosPair(x_, y_));
				}
			}

		}
	}

public:
	int numIslands(vector<vector<char>>& grid) {
		int islandsCnt = 0;
		for (unsigned i=0; i<grid.size(); i++){
			for (unsigned j=0; j<grid.back().size(); j++){
				if (grid[i][j] == '1') { 
					islandsCnt ++;
					grid[i][j] = '0';
					clearPosIJ(grid, i, j);
				}
			}
		}
		return islandsCnt;
	}
};

#ifdef DEBUG
#include "DebugUtil.h"

REGISTER_TEST(empty){
	vector< vector<char> > grid;
	int groundTruth = 0;
	return Solution().numIslands(grid) == groundTruth;
}
REGISTER_TEST(example1){
	vector< vector<char> > grid = {
		{'0', '1', '0'},
		{'0', '1', '0'},
		{'0', '1', '0'},
	};
	int groundTruth = 1;
	return Solution().numIslands(grid) == groundTruth;
}
REGISTER_TEST(example2){
	vector< vector<char> > grid = {
		{'1', '1', '1', '1', '0'},
		{'1', '1', '0', '1', '0'},
		{'1', '1', '0', '0', '0'},
		{'0', '0', '0', '0', '0'},
	};
	int groundTruth = 1;
	return Solution().numIslands(grid) == groundTruth;
}
REGISTER_TEST(example3){
	vector< vector<char> > grid = {
		{'1', '1', '0', '0', '0'},
		{'1', '1', '0', '0', '0'},
		{'0', '0', '1', '0', '0'},
		{'0', '0', '0', '1', '1'},
	};
	int groundTruth = 3;
	return Solution().numIslands(grid) == groundTruth;
}
#endif