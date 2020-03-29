#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#include "DebugUtil.h"
#include "PrintUtil.h"
#include "src/659.cpp"

int main() {
  for (unsigned i = 0; i < testCnt; i++) {
    cout << "test " << testNameVec[i] << " passed ... " << boolalpha
         << testFuncVec[i]() << endl;
  }
  return 0;
}
