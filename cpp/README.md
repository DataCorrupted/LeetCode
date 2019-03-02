# LeetCode/cpp

Here are all passed codes for LeetCode written in cpp.

## Status: 100/995

Finished List:

	[1-14]
	[19-29]
	[31-50]
	[53-75]
	[78-84]
	[88-89]
	[100-104]
	[118-120]
	[165-169]
	[171-172]
	[200-207]
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

The test will ship itself automatically when compilation is done.