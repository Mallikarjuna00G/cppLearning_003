#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>

#include "Sales_data.hpp"

using std::string;
using std::cout;
using std::cin;
using std::runtime_error;
using std::exception;

int main() {

    try {
        Sales_data data1, data2;

        if (cin >> data1.bookNo >> data1.units_sold >> data1.revenue) {
            while (cin >> data2.bookNo >> data2.units_sold >> data2.revenue) {
                if (data1.isbn() == data2.isbn()) {
                    data1.combine(data2);
                }
            }
            cout << "Summary: " << data1.isbn() << " " << data1.units_sold << " " << data1.revenue << "\n";
        } else {
            // no input! terminate with error
            throw runtime_error("Enter atleast one record");
        }
    } catch (const runtime_error &err) {
        cout << "ERROR: runtime error:\n\t" << err.what();
    }

    return 0;
}