#include <cstdio>

//��ʽ1
#include "hellolib/hello.h"

//��ʽ2
// #include "hello.h"
//CMake������# target_include_directories(a.out PUBLIC hellolib)

int main() {
    hello();
    return 0;
}
