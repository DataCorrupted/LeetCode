class Solution {
public:
	int climbStairs(int n) {
		if (n == 1){ return 1; }
		if (n == 2){ return 2; }
		int prev = 2;
		int pprev = 1;
		int curr = 0;
		for (int i = 3; i<=n; i++){
			curr = prev + pprev;
			pprev = prev; 
			prev = curr;
		}
		return curr;
	}
};