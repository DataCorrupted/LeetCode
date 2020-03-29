class Solution {
public:
    bool isPossible(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }

        int i = 1;
        int last_occ;
        int occ;
        int cur = nums[0];

        std::queue<int> q;
        while (i != nums.size()) {
            occ = 1;
            while (i < nums.size() && cur == num[i]) {
                i ++;
                occ ++;
            }
            if (occ > last_occ) {
                // Start new sub sequences
                for (int k = last_occ; k < occ; k++) {
                    q.push(cur);
                }
            } else {
                // Eliminate early sub sequences
                for (int k = occ; k < last_occ; k++) {
                    int front = q.front();
                    q.pop();
                    if cur - front < 3 {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};


#ifdef  DEBUG
REGISTER_TEST(example1){
	vector<int> nums({1, 2, 3, 3, 4, 5});
    bool groundTruth = true;
	return Solution().isPossible(nums) == groundTruth;	
}
REGISTER_TEST(example2){
	vector<int> nums({1, 2, 3, 3, 4, 4, 5, 5});
    bool groundTruth = true;
	return Solution().isPossible(nums) == groundTruth;	
}
#endif