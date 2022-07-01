#include <vector>
#include <iostream>
#include <numeric>

int main() {
    std::vector v = {4, 3, 2, 1};

    auto sum = std::reduce(v.begin(), v.end());
    auto sum = std::reduce(v.begin(), v.end(), std::plus{});
    int sum = std::reduce(v.begin(), v.end(), 0, [] (int x, int y) {
        return x + y;
    });

    std::cout << sum << std::endl;
    return 0;
}
