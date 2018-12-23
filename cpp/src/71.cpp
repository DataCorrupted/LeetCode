class Solution {
public:
	typedef std::pair<int, int> PosLenPair;
	string simplifyPath(string path) {
		std::stack<PosLenPair> locStack;

		// Extract folders
		unsigned idx = 0;
		while (idx < path.size()){
			while (path[idx] == '/' && idx < path.size()){ idx ++; }
			int pos=idx, len=0;
			while (path[idx] != '/' && idx < path.size()) { idx++; len++; }
			if (len == 0) { continue; }
			if (len == 1 && path[pos] == '.'){ continue; }
			if (len == 2 && path[pos] == '.' && path[pos+1] == '.') { 
				if (locStack.size() != 0) {
					locStack.pop(); 
				} 
				continue;
			}
			locStack.push(PosLenPair(pos, len));
		}

		// Assemble ans.
		string ans;
		while (locStack.size()){
			PosLenPair pair = locStack.top();
			locStack.pop();
			ans = "/" + path.substr(pair.first, pair.second) + ans; 
		}
		return (ans.size()) ? ans: "/";
	}
};

#ifdef DEBUG
#include "DebugUtil.h"

REGISTER_TEST(example1){
	string path("/home/");
	string groundTruth("/home");
	return Solution().simplifyPath(path) == groundTruth;
}
REGISTER_TEST(example2){
	string path("/a/./b/../../c/");
	string groundTruth("/c");
	return Solution().simplifyPath(path) == groundTruth;
}
REGISTER_TEST(example3){
	string path("/a/../../b/../c//.//");
	string groundTruth("/c");
	return Solution().simplifyPath(path) == groundTruth;
}
REGISTER_TEST(example4){
	string path("/a//b////c/d//././/..");
	string groundTruth("/a/b/c");
	return Solution().simplifyPath(path) == groundTruth;
}
#endif