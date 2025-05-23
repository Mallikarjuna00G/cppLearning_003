#include <iostream>

int main() {
    const int i = 42;
    auto j = i;
    const auto &k = i;
    auto *p = &i;
    auto q = &i;
    const auto j2 = i, &k2 = i;

    std::cout << i << std::endl;
    std::cout << j << std::endl;
    std::cout << k << std::endl;
    std::cout << p << std::endl;
    std::cout << *p << std::endl;
    std::cout << q << std::endl;
    std::cout << *q << std::endl;
    std::cout << j2 << std::endl;
    std::cout << k2 << std::endl;

    return 0;
}