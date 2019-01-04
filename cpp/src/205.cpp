class Solution {
public:
	bool isInjection(string s, string t){
		if (s.size() != t.size()) { return false; }
		map<char, char> funcMap;
		for (unsigned i=0; i<s.size(); i++){
			if (funcMap.find(s[i]) != funcMap.end() && funcMap[s[i]] != t[i]) {
				return false;
			} else {
				funcMap[s[i]] = t[i];
			}
		}
		return true;		
	}
	bool isIsomorphic(string s, string t) {
		return isInjection(s, t) && isInjection(t, s);
	}
};

#ifdef DEBUG
#include "DebugUtil.h"

REGISTER_TEST(example0){
	string s("title"), t("paper");
	bool groundTruth(true);
	return Solution().isIsomorphic(s, t) == groundTruth;
}
REGISTER_TEST(example1){
	string s("aa"), t("ab");
	bool groundTruth(false);
	return Solution().isIsomorphic(s, t) == groundTruth;
}
#endif