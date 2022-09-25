#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

template <class ...T>
constexpr auto sum(T ...t) {
    return (sizeof(T) + ...);
}

template <class T0, class ...T>
void print(T0 const &t0, T const &...t) {
    std::cout << t0;
    ((std::cout << ' ' << t), ...);
    std::cout << std::endl;
}


template<typename... Ts>
void printAll(Ts&&... mXs)
{
    (std::cout << ... << mXs) << std::endl;
}

void func2(int const &t) {
    printf("int const &\n");
}

void func2(int &&t) {
    printf("int &&\n");
}

//std::forward作用：
//当T为左值引用类型时，t将被转换为T类型的左值
//当T不是左值引用类型时，t将被转换为T类型的右值
template <class ...T>
void func1(T &&...t) {
    func2(std::forward<decltype(t)>(t)...);//等价于： func2(std::forward<(T)>(t)...);
}

int main() {
    printAll(1,2,3);
    float arr[1<<20]; int i = 0;
    std::generate_n(std::begin(arr), std::size(arr), [&] () { return std::sin(i++); });
    float sum = std::accumulate(std::begin(arr), std::end(arr), 0.f, std::minus{});
    print(sum);

    //std::reduce可以reduce一个vector的数组
    std::vector<float> arr;
    float sum = std::reduce(arr.begin().arr.end());
    //为了支持vector和C数组，可以使用std::begin().std::end(), std::reduce();来自C++17
    float arr[32] = {1,2,3};
    //等价于float sum = std::reduce(std::begin(arr), std::end(arr),0.f, std::plus<float>{});//std::plus{};是针对所有类型的加法
    float sum = std::reduce(std::begin(arr), std::end(arr),0.f, [](float a, float b){return a+b;});
    // std::reduce 比std::accumulate更准确而已

    float arr2[1<<20];
    std::generate(std::begin(arr),std::end(arr),std::rand);

    return 0;
}
