class Solution {
public:
    bool isSubVecPossible(vector<int>& nums) {
        if (nums.size() < 3)
        {
            return false;
        }

        unsigned i = 0;
        int last_occ = 0;
        int occ = 0;
        int cur = 0;

        queue<int> q;
        while (i < nums.size()){
            cur = nums[i];
            last_occ = occ;
            occ = 0;
            while (i < nums.size() && cur == nums[i]){
                i++;
                occ++;
            }
            if (occ > last_occ)
            {
                // Start new sub sequences
                for (int k = last_occ; k < occ; k++)
                {
                    q.push(cur);
                }
            }
            else
            {
                // Eliminate early sub sequences
                for (int k = occ; k < last_occ; k++)
                {
                    int front = q.front();
                    if (q.size() != 0)
                    {
                        q.pop();
                    }
                    if (cur - front < 3)
                    {
                        return false;
                    }
                }
            }
        }
        int last_num = nums[nums.size() - 1];
        while (q.size() != 0) {
            if (last_num - q.front() < 2)  {
                return false;
            }
            q.pop();
        }
        return true;
    }
    bool isPossible(vector<int>& nums) {
        if (nums.size() < 3) { return false; }
        if (nums[1] - nums[0] > 1) {
            return false;
        }
        unsigned begin = 0;
        unsigned end = 0;
        for (unsigned i=1; i<nums.size(); i++) {
            if (nums[i] - nums[i-1] > 1)  {
                end = i;
                vector<int> subVec = vector<int>(nums.begin() + begin, nums.begin() + end);
                bool result = isSubVecPossible(subVec);
                if (!result) { return false; }
                begin = end;
            } else {
                end ++;
            }
        }
        // Last sub vec
        vector<int> subVec = vector<int>(nums.begin() + begin, nums.end());
        return isSubVecPossible(subVec);
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
REGISTER_TEST(example3){
    vector<int> nums({1, 2, 3, 3, 4, 4, 5, 5, 9, 10, 11});
    bool groundTruth = true;
    return Solution().isPossible(nums) == groundTruth;
}
REGISTER_TEST(example4){
    vector<int> nums({1, 2, 3, 3, 4, 4, 5, 5, 9, 10, 11, 13, 14});
    bool groundTruth = false;
    return Solution().isPossible(nums) == groundTruth;
}
REGISTER_TEST(example5)
{
    vector<int> nums({1, 2, 3, 4, 4, 5});
    bool groundTruth = false;
    return Solution().isPossible(nums) == groundTruth;
}
REGISTER_TEST(example6)
{
    vector<int> nums({1});
    bool groundTruth = false;
    return Solution().isPossible(nums) == groundTruth;
}
#endif