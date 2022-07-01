#include <cstdio>

//方式1
#include "hellolib/hello.h"

//方式2
// #include "hello.h"
//CMake中增加# target_include_directories(a.out PUBLIC hellolib)

int main() {
    hello();
    return 0;
}
