#include <iostream>

struct Sales_data {
    std::string bookNo = "";
    unsigned int units_sold = 0;
    double revenue = 0.0;
};

int main() {
    Sales_data item1;

    while (std::cin >> item1.bookNo >> item1.units_sold >> item1.revenue) {
        std::cout << "Sold book: " << item1.bookNo << " " << item1.units_sold << " " << item1.revenue << std::endl;
    }

    return 0;
}