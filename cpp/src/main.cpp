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

#define DEBUG

using namespace std;

#include "DebugUtil.h"
#include "PrintUtil.h"
#include "solutions/809.cpp"

int main() {
  for (auto pair : TEST_NAME_FUNC_PAIR_VEC) {
    std::string& name = pair.first;
    bool test_result = pair.second();
    cout << "test " << name << " passed ... " << ((test_result) ? GREEN : RED)
         << boolalpha << test_result << WHITE << endl;
  }
  return 0;
}
