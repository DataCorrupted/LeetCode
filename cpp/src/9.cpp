class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) { return false; }
        int tmp = x;
        long par_x = 0;
        while (tmp != 0){
            par_x  = par_x * 10 + tmp % 10;
            tmp /= 10;
        }
        return x == par_x;
    }
};