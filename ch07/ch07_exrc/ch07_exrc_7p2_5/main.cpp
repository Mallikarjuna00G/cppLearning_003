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

        int count = 0;
        if (cin >> data1.bookNo >> data1.units_sold >> data1.revenue) {
            count++;
            while (cin >> data2.bookNo >> data2.units_sold >> data2.revenue) {

                if (data1.isbn() == data2.isbn()) {
                    count++;
                } else {
                    cout << data1.isbn() << " occured in " << count << " transactions" << "\n";
                    count = 1;
                    data1 = data2;
                }
            }
            cout << data1.bookNo << " occured in " << count << " transactions" << "\n";
            
        } else {
            // no input! terminate with error
            throw runtime_error("You have not entered valid/any data.");
        }
    } catch (const runtime_error &err) {
        cout << "ERROR: runtime error:\n\t" << err.what();
    }

    return 0;
}