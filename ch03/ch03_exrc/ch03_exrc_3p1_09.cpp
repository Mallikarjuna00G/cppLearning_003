#include <iostream>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

struct Sales_data {
    string bookNo = "";
    unsigned int units_sold = 0;
    double revenue = 0.0;
};

int main() {
    Sales_data total;  // variable to hold data for the next transaction
    // read the first transaction and ensure that there are data to process
    if (cin >> total.bookNo >> total.units_sold >> total.revenue) {
        Sales_data trans;  // variable to hold the running sum
        // read and process the remaining trransactions
        while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
            // if we're still processing the same book
            if (total.bookNo == trans.bookNo) {
                total.units_sold += trans.units_sold;  // update the running total
                total.revenue += trans.revenue;  // update the running total
            } else {
                // print results for the previous book
                cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
                total = trans;  // total now refers to the next book
            }
        }
        cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
    } else {
        // no input! warn the user
        cerr << "No data?!" << endl;
        return -1;  // indicate failure
    }
    return 0;
}