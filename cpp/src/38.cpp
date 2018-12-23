class Solution {
public:
	string countAndSay(int n) {
		string prev = "1";
		string curr = prev;
		for (int i=1; i<n; i++){
			curr = "";
			unsigned idx = 0;
			while (idx < prev.size()){
				int cnt = 0; 
				char c = prev[idx];
				while (prev[idx] == c && idx < prev.size()){
					cnt ++;
					idx ++;
				}
				curr += std::to_string(cnt) + c; 
			}
			prev = curr;
		}
		return curr;
	}
};

#ifdef DEBUG
#include "DebugUtil.h"

REGISTER_TEST(1){
	int n = 1;
	string groundTruth = "1";
	return Solution().countAndSay(n) == groundTruth;
}
REGISTER_TEST(2){
	int n = 2;
	string groundTruth = "11";
	return Solution().countAndSay(n) == groundTruth;
}
REGISTER_TEST(3){
	int n = 3;
	string groundTruth = "21";
	return Solution().countAndSay(n) == groundTruth;
}
REGISTER_TEST(4){
	int n = 4;
	string groundTruth = "1211";
	return Solution().countAndSay(n) == groundTruth;
}
REGISTER_TEST(5){
	int n = 5;
	string groundTruth = "111221";
	return Solution().countAndSay(n) == groundTruth;
}
REGISTER_TEST(6){
	int n = 6;
	string groundTruth = "312211";
	return Solution().countAndSay(n) == groundTruth;
}

#endif