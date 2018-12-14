class Solution {
private:
	std::map<unsigned, unsigned> idxMap;
	unsigned mod = 1'000'000'007;
	std::vector<unsigned> primeNum = {
			2731, 8161, 9679, 6229, 11519, 17293, 
			3517, 5273, 6449, 6481, 10079, 12547, 
			4007, 6679, 2351, 6763, 14629, 13147, 
			5591, 6373, 6977, 7001, 15329, 16649, 
			6053, 7211
	};

	unsigned hashString(string& s){
		std::map<char, unsigned> appearMap;
		unsigned hashVal = 0;
		for (char c: s){
			appearMap[c] = appearMap[c] + 1;
			hashVal = (hashVal + (primeNum[c-'a'] * appearMap[c] * primeNum[c-'a']) % mod) % mod;
		}
		return hashVal;
	}

public:

	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> result;

		for (string s: strs){
			unsigned hashVal = hashString(s);
			if (idxMap.find(hashVal) == idxMap.end()){
				idxMap[hashVal] = result.size();
				result.push_back(vector<string>());
			}
			result[idxMap[hashVal]].push_back(s);
		}
		return result;
	}
};

#ifdef DEBUG
#include "DebugUtil.h"
REGISTER_TEST(0){
	vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<vector<string>> groundTruth = {
			{"eat","tea","ate"},
			{"tan","nat"},
			{"bat"}
	};
	return Solution().groupAnagrams(strs) == groundTruth;
}
#endif 