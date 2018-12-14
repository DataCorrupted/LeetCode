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

#include "PrintUtil.h"
#include "DebugUtil.h"

#include "19.cpp"

int main(){
	for (unsigned i=0; i<testCnt; i++){
		cout << "test " << testNameVec[i] << " passed ... " << boolalpha << testFuncVec[i]() << endl;
	}
	return 0;
}

