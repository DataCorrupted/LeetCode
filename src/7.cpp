class Solution {
public:
    int reverse(int x) {
        int sign = (x > 0)? 1: -1;
        x = abs(x);
        long ans = 0;
        while (x!=0){
            ans  = ans * 10 + (x % 10);
            x = x / 10;
        }
        ans *= sign;
        if (ans > 2147483647 || ans < -2147483648){
            return 0;
        } else {
            return ans;
        }
    }
};