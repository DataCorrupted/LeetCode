# LeetCode/cpp

Here are all passed codes for LeetCode written in cpp.

## Status: 138/1425

Finished List:

	[1-14]
	17
	[19-29]
	[31-50]
	[53-94]
	[100-104]
	[118-123]
	[165-169]
	[171-172]
	[187-191]
	[198-208]
	297
	[299-301]
	[303-305]	
	307
	309
	409
	659
	664
	752
	809
	843
	946
	1007
	1145

## Coding

### Platform

**Windows**

You need [`MinGw`](http://www.mingw.org/) installed to code in Windows.

I never tried VS, maybe it works too.

**Ubuntu**

I used `clang` as my toolchain to use ASan, so get it installed.

### Format

By default all the file format should be using [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).
To achieve this, you can use 

`clang-format -i <file-name> -style=Google`

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

The test will ship itself automatically when the compilation is done.