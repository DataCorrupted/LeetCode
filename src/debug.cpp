#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>

using namespace std;

#include "printUtil.cpp"
#include "65.cpp"

int main(){
	string s;
	cin >> s;
	Solution solver;
	auto result = solver.isNumber(s);
	cout << ((result == true)? "true": "false");
}

