#include <iostream>
#include "Sales_data.h"

int main() {
    Sales_data data1, data2;

    int count = 0;
    if (std::cin >> data1.bookNo >> data1.units_sold >> data1.revenue) {
        count++;
        while (std::cin >> data2.bookNo >> data2.units_sold >> data2.revenue) {

            if (data1.bookNo == data2.bookNo) {
                count++;
            } else {
                std::cout << data1.bookNo << " occured in " << count << " transactions" << std::endl;
                count = 1;
                data1 = data2;
            }
        }
        std::cout << data1.bookNo << " occured in " << count << " transactions" << std::endl;
        
    } else {
        std::cerr << "Terminating" << std::endl;
    }

    return 0;
}