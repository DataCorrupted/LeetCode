class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		std::stack<std::pair<int,int> > maxHeight;
		unsigned maxSize = 0;
		for (int i=0; i<heights.size(); i++){

			while (maxHeight.size() != 0 && maxHeight.top().first > heights[i]){
				std::pair<int, int> heightPair = maxHeight.top();
				maxHeight.pop();
				int height = heightPair.first;
				int length = i - heightPair.second;
				if (height * length > maxSize){
					maxSize = height * length;
				}
			}

			if (maxHeight.size() != 0 && maxHeight.top().first == heights[i]) {
				continue;
			}

			maxHeight.push(std::pair<int, int>(heights[i], i));
		}
		while (maxHeight.size() != 0){
			std::pair<int, int> heightPair = maxHeight.top();
			maxHeight.pop();
			int height = heightPair.first;
			int length = heights.size() - heightPair.second;
			if (height * length > maxSize){
				maxSize = height * length;
			}			
		}
		return maxSize;
	}

	static bool test0(){
		std::vector<int> v = {2,1,5,6,2,3};
		int groundTruth = 10;
		return Solution().largestRectangleArea(v) == groundTruth;
	}
	static bool test1(){
		std::vector<int> v = {2,2,2,2,2,2};
		int groundTruth = 12;
		return Solution().largestRectangleArea(v) == groundTruth;
	}
	static bool test2(){
		std::vector<int> v = {1, 2, 3, 4, 5, 4, 3, 2, 1};
		int groundTruth = 15;
		return Solution().largestRectangleArea(v) == groundTruth;
	}
	static bool test3(){
		std::vector<int> v = {1, 2, 3, 0, 2, 2, 1, 4, 0, 0, 3, 3, 3, 5, 3, 0};
		int groundTruth = 15;
		return Solution().largestRectangleArea(v) == groundTruth;
	}
};