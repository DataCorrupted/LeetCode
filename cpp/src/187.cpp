class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		std::map<char, int> letterMap;
		letterMap['A'] = 0; letterMap['T'] = 1;
		letterMap['G'] = 2; letterMap['C'] = 3;

		std::map<int, int> occMap;
		std::map<int, string> strMap;
		for (unsigned i=0; i+9<s.size(); i++){
			int hash = 0;
			for (int j=0; j<10; j++){
				hash += letterMap[s[i+j]] << (j * 2);
			}
			if (occMap[hash] == 0){
				occMap[hash] = 1;
				strMap[hash] = s.substr(i, 10);
			} else {
				occMap[hash] ++;
			}
		}
		vector<string> result;
		for (auto pair: occMap){
			if (pair.second > 1){
				result.push_back(strMap[pair.first]);
			}
		}
		return result;
	}
};

#ifdef DEBUG
REGISTER_TEST(example1){
	string s("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
	vector<string> groundTruth({"CCCCCAAAAA", "AAAAACCCCC"});
	return Solution().findRepeatedDnaSequences(s) == groundTruth;
}
REGISTER_TEST(example2){
	string s("");
	vector<string> groundTruth;
	return Solution().findRepeatedDnaSequences(s) == groundTruth;
}
REGISTER_TEST(example3){
	string s("AAAAAAAAAAA");
	vector<string> groundTruth({"AAAAAAAAAA"});
	return Solution().findRepeatedDnaSequences(s) == groundTruth;
}
#endif