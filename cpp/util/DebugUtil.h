#ifndef DEBUG_UTIL
#define DEBUG_UTIL

#include <string>
#include <vector>

static std::vector<bool (*)()> testFuncVec = std::vector<bool (*)()>();
static std::vector<std::string> testNameVec = std::vector<std::string>();
static unsigned testCnt = 0;
#define REGISTER_TEST(x)               \
  static bool test##x();               \
  struct SolutionTest##x##Register {   \
    SolutionTest##x##Register() {      \
      testCnt++;                       \
      testFuncVec.push_back(&test##x); \
      testNameVec.push_back(#x);       \
    }                                  \
  } solutionTest##x##Register;         \
  static bool test##x()

#endif