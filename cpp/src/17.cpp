class Solution {
public:
	map<char, string> dig_map;
	vector<string> ans;
	Solution(){
		dig_map['2'] = "abc";
		dig_map['3'] = "def";
		dig_map['4'] = "ghi";
		dig_map['5'] = "jkl";
		dig_map['6'] = "mno";
		dig_map['7'] = "pqrs";
		dig_map['8'] = "tuv";
		dig_map['9'] = "wxyz";
	}
	
	void generate(string digits, string context){
		if (digits.size() <= 0){
			ans.push_back(context);
			return;
		}
		string options = dig_map[digits[0]];
		for (unsigned i=0; i<options.size(); i++){
			generate(digits.substr(1), context+options[i]);
		}
	}
	vector<string> letterCombinations(string digits) {
		if (digits.size() == 0) { return ans; }
		generate(digits, "");
		return ans;
	}
};

#ifdef DEBUG
#include "debugUtil.h"

REGISTER_TEST(0){
	string digits = "23";
	vector<string> groundTruth = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
	return Solution().letterCombinations(digits) == groundTruth;
}

#endif
