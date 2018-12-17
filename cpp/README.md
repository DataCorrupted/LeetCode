# LeetCode/cpp

Here are all passed codes for LeetCode written in cpp.

## Status: 71/953

Finished List:

	[1-14]
	[19-29]
	[31-37]
	[39-49]
	54
	[58-70]
	78
	[82-84]
	[100-104]
	[118-120]
	409


## Test

Every file in _src/_ can be compiled against _main.cpp_.  
We have marco defined test cases.   
You can add your own test cases by attaching the following to the code:  

```cpp
#ifdef DEBUG
#include "debugUtil.h"

REGISTER_TEST(test-name){
    auto groundTruth;
    return Solution().<funcName>(argv) == groundTruth;
}
REGISTER_TEST(another-test){
    auto groundTruth;
    return Solution().<funcName>(argv) == groundTruth;
}
#endif
```

and simply run:

```sh
make
```

The test will ship when compilation is done.