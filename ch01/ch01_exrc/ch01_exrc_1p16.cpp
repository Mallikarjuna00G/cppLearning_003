#include <iostream>

int main() {
    int sum = 0;
    // read until end-of-file, calculating a running total of all values read
    for (int value = 0; std::cin >> value;)
        sum += value;  // equivalent to sum = sum + value
    
    std::cout << "Sum is: " << sum << std::endl; 
    return 0;
}