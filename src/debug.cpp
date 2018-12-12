#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>

using namespace std;

#include "printUtil.cpp"
#include "68.cpp"

int main(){
	Solution solver;
	std::vector<string> v = {"This", "is", "an", "example", "of", "text", "justification."};
	std::vector<string> groundTruth = {
			"What   must   be",
			"acknowledgment  ",
			"shall be        "
	};
	int maxWidth = 16;
	auto result = solver.fullJustify(v, maxWidth);
	cout << result;
}

