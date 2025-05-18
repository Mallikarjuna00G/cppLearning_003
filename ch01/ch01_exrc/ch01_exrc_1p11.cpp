#include <iostream>

int main()
{
    int a = 0, b = 0;
    std::cout << "Enter two (positive) integers (<smaller number> <bigger number>):" << std::endl;
    std::cin >> a >> b;
    // keep executing the while a long as val is less than or equal to 10
    while (a <= b) {
        std::cout << a << std::endl;
        ++a;  // add 1 to val
    }

    return 0;
}