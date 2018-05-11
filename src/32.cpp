class Solution {
public:
    int longestValidParentheses(string s) {        
        stack<char> par;
        stack<int> len;
        
        // Push a pesudo one inside that no one will match.
        par.push(')');
        len.push(0);
        
        for (int i=0; i<s.size(); i++){
            if (s[i] == ')' && par.top() == '('){
                int curr_len = len.top();
                len.pop();
                par.pop();
                
                len.top() += (2 + curr_len);
            } else {
                par.push(s[i]);
                len.push(0);
            }
        }
        int max = 0;
        while (len.size() != 0) {
            max = (len.top() > max) ? len.top(): max;
            len.pop();
        }
        return max;
    }
};