class SolutionTLE {
public:
	string t;
	bool eq(const char a, const char b){
		return (a == b || b == '?');
	}
	bool isMatch(string s, string p) {
		cout << s << "\n" << p << "\n\n";
		cin >> t;
		if (s.size() ==0){
			if (p.size() == 0) { 
				return true; 
			} else if (p[0] =='*') {
				return isMatch("", p.substr(1));
			} else {
				return false;
			}
		} 
		if (p.size() == 0) { return false; }
		
		if (eq(s[0], p[0])){
			return isMatch(s.substr(1), p.substr(1));
		} else if (p[0] == '*'){
			int k = 0;
			while (k < p.size() && p[k] == '*') { k++; }
			for (int i=0; i<=s.size(); i++){
				if (isMatch(s.substr(i), p.substr(k))){
					return true;
				}
			}
		}
		return false;
	}
};