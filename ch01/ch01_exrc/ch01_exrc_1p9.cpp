#include <iostream>

int main()
{
    int sum = 0, val = 50;
    // keep executing the while a long as val is less than or equal to 10
    while (val <= 100) {
        sum += val;  // assigns sum + val to sum
        ++val;  // add 1 to val
    }
    std::cout << "Sum of 50 to 100 inclusive is "
    << sum << std::endl;

    return 0;
}