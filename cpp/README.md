# LeetCode/cpp

Last Update: Dec 13

Here are all passed codes for LeetCode written in cpp.

## Status: 50/949

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