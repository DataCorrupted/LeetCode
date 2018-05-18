#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>

using namespace std;

#include "44.cpp"

int main(){
	string s = "aaaa";
	string p = "ab*ac*a";

	Solution solver;
	string result = solver.longestPalindrome(s);
	cout << result << endl;
}

