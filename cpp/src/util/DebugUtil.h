#ifndef DEBUG_UTIL
#define DEBUG_UTIL

#include <string>
#include <vector>

static std::string RED = "\033[1;31m";
static std::string GREEN = "\033[1;32m";
static std::string WHITE = "\033[0m";

typedef std::pair<std::string, bool (*)()> TestNameFuncPair;
typedef std::vector<TestNameFuncPair> TestNameFuncPairVec;
static TestNameFuncPairVec TEST_NAME_FUNC_PAIR_VEC = TestNameFuncPairVec();
#define REGISTER_TEST(x)                                                 \
  static bool test##x();                                                 \
  struct SolutionTest##x##Register {                                     \
    SolutionTest##x##Register() {                                        \
      TEST_NAME_FUNC_PAIR_VEC.push_back(TestNameFuncPair(#x, &test##x)); \
    }                                                                    \
  } solutionTest##x##Register;                                           \
  static bool test##x()

#endif