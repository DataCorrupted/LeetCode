class Solution {
public:
    int matchDigits(string s){
        int i = 0;
        if (s.size() == i) { return 0; }
        if (s[i] == '-') {
        	i++;
            if (s.size() == i){ return 0; }
        }
        for (int i=0; i<s.size(); i++){
            if (s[i] < '0' || s[i] > '9'){
                return i;
            }
        }
        return -1;
    }
    int matchFloat(string s){
        int i = 0;
        if (s.size() == 0){ return 0; }
        i = matchDigits(s);
        cout << s << " " << i << endl;
        if (i == -1){
            return -1;
        } else if(s[i] == '.'){
            return matchDigits(s);
        } else {
            return i;
        } 
    }
    int matchNumber(string s){
        int i = matchFloat(s);
        cout << i << endl;
        if (i == -1){
            return true;
        } else if (s[i] == 'e'){
            return matchFloat(s.substr(i+1)) == -1;
        } else {
            return false;
        }
    }
    bool isNumber(string s) {
        int i=0; 
        while (i < s.size() && s[i] == ' ' ) { i ++; }
        s = s.substr(i);
        if (s.size() == 0){
            return false;
        }
        return matchNumber(s);
    }
};