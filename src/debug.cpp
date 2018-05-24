#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>

using namespace std;

#include "printUtil.cpp"
#include "67.cpp"

int main(){
	string a = "1010";
	string b = "1011";

	Solution solver;
	auto result = solver.addBinary(a, b);
	cout << result;
}

