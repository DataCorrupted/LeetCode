#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>

using namespace std;

#include "printUtil.cpp"
#include "40.cpp"

int main(){
	vector<int> v({2,5,2,1,2});
	string s = "a ";

	Solution solver;
	auto result = solver.combinationSum2(v, 5);
	cout << result;
}

