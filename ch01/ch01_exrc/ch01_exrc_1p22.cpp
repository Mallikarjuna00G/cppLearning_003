#include <iostream>
#include "Sales_item.h"

int main() {
    Sales_item item, sum;

    std::cin >> item;
    sum = item;
    while (std::cin >> item) {
        sum += item;
    }
    std::cout << "Sum: " << sum << std::endl;

    return 0;
}