#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

template<class ...T>
auto sum(T ...t)
{
    return (0+...+t);//sum()也可以运行,return (+...+t)也行，但是sum()中必须有值才行
}

int main()
{
    std::cout<<sum(1,2,3)<<std::endl;
}