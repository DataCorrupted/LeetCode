#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>

using namespace std;

#include "78.cpp"

int main(){
	vector<int> v;

	Solution solver;
	auto result = solver.subsets(v);
	cout << result.size();
}

