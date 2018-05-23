#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>

using namespace std;

#include "printUtil.cpp"
#include "42.cpp"

int main(){
	vector<int> v({2, 0, 2});

	Solution solver;
	auto result = solver.trap(v);
	cout << result;
}

