#include <iostream>
#include "Sales_data.h"

int main() {
    Sales_data data1, data2;

    std::cin >> data1.bookNo >> data1.units_sold >> data1.revenue;
    std::cin >> data2.bookNo >> data2.units_sold >> data2.revenue;

    if (data1.bookNo == data2.bookNo) {
        unsigned totalCnt = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;

        // print: ISBN, total sold, total revenue
        std::cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
        
        return 0;  // indicate success
    } else {  // transactions were not for the same ISBN
        std::cerr << "Data must refer to the same ISBN" << std::endl;
        return -1;  // indicate failure
    }

    return 0;
}