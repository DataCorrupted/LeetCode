#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>

using namespace std;

#include "11.cpp"
#include "printUtil.cpp"

int main(){
	vector<int> v({4, 6, 2, 6, 7, 11, 2});
	string s = "a ";

	Solution solver;
	auto result = solver.maxArea(v);
	cout << result;
}

