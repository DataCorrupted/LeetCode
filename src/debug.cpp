#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>

using namespace std;

#include "10.cpp"

int main(){
	string s = "aaa";
	string p = "ab*ac*a";

	Solution solver;
	bool result = solver.isMatch(s, p);
	cout << result << endl;
}

