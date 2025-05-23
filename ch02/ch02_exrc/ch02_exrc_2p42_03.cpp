#include <iostream>
#include "Sales_data.h"

int main() {
    Sales_data data1, data2;

    if (std::cin >> data1.bookNo >> data1.units_sold >> data1.revenue) {
        while (std::cin >> data2.bookNo >> data2.units_sold >> data2.revenue) {
            if (data1.bookNo == data2.bookNo) {
                data1.units_sold += data2.units_sold;
                data1.revenue += data2.revenue;
            }
        }
        std::cout << "Summary: " << data1.bookNo << " " << data1.units_sold << " " << data1.revenue << std::endl;
    } else {
        return -1;
    }

    return 0;
}