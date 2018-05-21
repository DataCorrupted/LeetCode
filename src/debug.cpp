#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>

using namespace std;

#include "58.cpp"
#include "printUtil.cpp"

int main(){
	vector<int> v({1, 2, 3});
	string s = "a ";

	Solution solver;
	auto result = solver.lengthOfLastWord(s);
	cout << result;
}

