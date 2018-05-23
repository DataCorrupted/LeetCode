class Solution {
public:
	int minVol(int i, int j, vector<int>& v){
		return (j - i) * min(v[i], v[j]);
	}
	int maxArea(vector<int>& height) {
		int i=0, j=height.size() - 1;
		int left = height[i], right = height[j];
		int max_left = height[0], max_right = height[height.size() - 1];
		int max_vol = minVol(i, j, height);
		while (i < j){
			if (height[i] < height[j]){
				i++;
				while (height[i] < max_left || height[i] < left ) { 
					i++; 
					if (i == j){ return max_vol; }
				}
				max_left = height[i];
			} else {
				j--;
				while (height[j] < max_right || height[j] < right) { 
					j--; 
					if (i == j){ return max_vol; }
				}
				max_right = height[j];
			}
			if (minVol(i, j, height) > max_vol){
				max_vol = minVol(i, j, height);
				left = height[i];
				right = height[j];
			}
		}
		return max_vol;
	}
};