class Solution {
public:
    vector<string> ans;
    void generate(int left, int right, string curr){
        if (left == 0 && right == 0){
            ans.push_back(curr);
        } else if ( left < 0 || right < 0){
            return;
        }
        if (left == right){
            generate(left-1, right, curr + '(');
        } else {
            if (left != 0) {
                generate(left-1, right, curr + '(');
            }
            generate(left, right-1, curr + ')');
        }
        
    }
    vector<string> generateParenthesis(int n) {
        generate(n, n, "") ;
        return ans;
    }
};