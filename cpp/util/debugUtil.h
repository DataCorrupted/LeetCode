#ifndef DEBUG_UTIL
#define DEBUG_UTIL

#include <map>
#include <string>

static std::map<std::string, bool(*)()> testMap = std::map<std::string, bool(*)()>();

#define REGISTER_TEST(x)  \
	static bool test##x(); \
	struct SolutionTest##x##Register{ \
		SolutionTest##x##Register() { testMap[#x] = &test##x;} \
	} solutionTest##x##Register; \
	static bool test##x()

#endif