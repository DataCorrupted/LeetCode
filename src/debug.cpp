#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>

using namespace std;

#include "78.cpp"
#include "printUtil.cpp"

int main(){
	vector<int> v({1, 2, 3});

	Solution solver;
	auto result = solver.subsets(v);
	cout << result;
}

