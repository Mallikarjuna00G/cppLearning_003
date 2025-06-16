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
        if (total.read(cin, total)) {
            Sales_data trans; // variable to hold the running sum
            // read and process the remaining transactions
            while (trans.read(cin, trans)) {
                // if we’re still processing the same book
                if (total.isbn() == trans.isbn()) {
                    total.combine(trans);
                } else {
                    // print results for the previous book
                    total.print(cout, total) << "\n";
                    total = trans; // total now refers to the next book
                }
            }
            total.print(cout, total) << "\n";
        } else {
            // no input! terminate with error
            throw runtime_error("No sales data?!");
        }
    } catch (const runtime_error &err) {
        cout << "ERROR: runtime error:\n\t" << err.what();
    }

    return 0;
}