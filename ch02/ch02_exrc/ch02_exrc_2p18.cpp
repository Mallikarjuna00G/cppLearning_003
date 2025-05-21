#include <iostream>

int main() {
    int i = 42, j = 65;
    int *p = &i;
    std::cout << "Before: " << std::endl;
    std::cout << "p = " << p << std::endl;
    std::cout << "*p = " << *p << std::endl;
    std::cout << "i = " << i << std::endl;
    std::cout << "j = " << j << std::endl;
    p = &j;
    *p = 67;
    std::cout << "After: " << std::endl;
    std::cout << "p = " << p << std::endl;
    std::cout << "*p = " << *p << std::endl;
    std::cout << "i = " << i << std::endl;
    std::cout << "j = " << j << std::endl;
    
    return 0;
}