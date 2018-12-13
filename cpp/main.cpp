#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <functional>

using namespace std;

#include "printUtil.h"
#include "debugUtil.h"

#include "49.cpp"

int main(){
	for (auto pair: testMap){
		cout << "test " << pair.first << " passed ... " << boolalpha << pair.second() << endl;
	}
	return 0;
}

