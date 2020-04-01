# LeetCode/cpp

Here are all passed codes for LeetCode written in cpp.

## Status: 125/1397

Finished List:

	[1-14]
	17
	[19-29]
	[31-50]
	[53-89]
	[100-104]
	[118-123]
	[165-169]
	[171-172]
	[187-191]
	[198-207]
	[299-301]
	[303-304]
	[306-307]
	309
	409
	659

## Coding

### Windows

You need [`MinGw`](http://www.mingw.org/) installed to code in Windows.

I never tried VS, maybe it works too.

### Ubuntu

I used `clang` as my toolchain to use ASan, so get it installed.

## Testing

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