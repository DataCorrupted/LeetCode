class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        bool used[256];
        for (int i=0; i<s.size() - max; i++){
            for (int j = 0; j<256; j++){
                used[j] = false;
            }
            int j = 0;
            for (j=0; j<s.size() - i; j++){
                if (!used[s[j+i]]){
                    used[s[j+i]] = true;
                } else {
                    break;
                }
            }
            max = (j > max) ? j: max;
        }
        return max;
    }
};