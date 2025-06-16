#include <iostream>
#include <exception>
#include <stdexcept>

#include "Sales_data.hpp"

using std::cout;
using std::cin;
using std::runtime_error;
using std::exception;

int main() {

    try {
        Sales_data total; // variable to hold data for the next transaction
        // read the first transaction and ensure that there are data to process
        if (cin >> total.bookNo >> total.units_sold >> total.revenue) {
            Sales_data trans; // variable to hold the running sum
            // read and process the remaining transactions
            while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
                // if we’re still processing the same book
                if (total.bookNo == trans.bookNo) {
                    total.units_sold += trans.units_sold; // update the running total
                    total.revenue += trans.revenue; // update the running total
                } else {
                    // print results for the previous book
                    cout << total.bookNo << " " << total.units_sold << " " << total.revenue << "\n";
                    total = trans; // total now refers to the next book
                }
            }
            cout << total.bookNo << " " << total.units_sold << " " << total.revenue << "\n";
        } else {
            // no input! terminate with error
            throw runtime_error("No sales data?!");
        }
    } catch (const runtime_error &err) {
        cout << "ERROR: runtime error:\n\t" << err.what();
    }

    return 0;
}