class Solution {
public:
    bool isValid(string s) {
        stack<char> str_stack;
        str_stack.push('$');
        char c;
        for (int i=0; i<s.size(); i++){
            c = s[i];
            if (str_stack.top() == '(' && c == ')'
              || str_stack.top() == '[' && c == ']'
              || str_stack.top() == '{' && c == '}'){
                str_stack.pop();
            } else {
                str_stack.push(c);
            }
        }
        return (str_stack.size() == 1);
    }
};