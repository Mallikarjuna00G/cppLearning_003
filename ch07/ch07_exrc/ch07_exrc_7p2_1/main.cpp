#include <iostream>
#include <exception>
#include <stdexcept>

#include "Sales_data.hpp"

using std::cout;
using std::cin;
using std::runtime_error;
using std::exception;

int main() {

    Sales_data item1;

    while (cin >> item1.bookNo >> item1.units_sold >> item1.revenue) {
        cout << "Sold book: " << item1.isbn() << " " << item1.units_sold << " " << item1.revenue << "\n";
    }

    return 0;
}