#include <iostream>
#include "Sales_data.h"

int main() {
    Sales_data item1;

    while (std::cin >> item1.bookNo >> item1.units_sold >> item1.revenue) {
        std::cout << "Sold book: " << item1.bookNo << " " << item1.units_sold << " " << item1.revenue << std::endl;
    }

    return 0;
}