#include <iostream>
#include "Sales_item.h"

int main() {
    Sales_item item1, item2;

    int count = 0;
    if (std::cin >> item1) {
        count++;
        while (std::cin >> item2) {

            if (item1.isbn() == item2.isbn()) {
                item1 += item2;
                count++;
            } else {
                std::cout << item1 << " occured in " << count << " transactions" << std::endl;
                count = 1;
                item1 = item2;
            }
        }
        std::cout << item1 << " occured in " << count << " transactions" << std::endl;
        
    } else {
        std::cerr << "Terminating" << std::endl;
    }

    return 0;
}