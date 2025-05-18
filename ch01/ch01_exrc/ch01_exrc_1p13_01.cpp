#include <iostream>

int main()
{
    int sum = 0;
    // keep executing the while a long as val is less than or equal to 10
    for (int val = 50; val <= 100; ++val) {
        sum += val;  // assigns sum + val to sum
    }
    std::cout << "Sum of 50 to 100 inclusive is "
    << sum << std::endl;

    return 0;
}