#include <iostream>
#include <exception>
#include <stdexcept>
#include <fstream>
#include <string>

#include "Sales_data.hpp"

using std::cout;
using std::cin;
using std::runtime_error;
using std::exception;
using std::ifstream;
using std::ofstream;
using std::string;

int main(int argc, char *argv[]) {

    try {
        ifstream fin(argv[1]);

        if(!fin) {
            throw runtime_error("Couldn't open file: " + string(argv[1]));
        }

        ofstream fout(argv[2], ofstream::app);
        if (!fout) {
            throw runtime_error("Couldn't open file: " + string(argv[2]));
        }
        Sales_data total(fin); // variable to hold data for the next transaction
        // read the first transaction and ensure that there are data to process
        if (fin) {
            Sales_data trans; // variable to hold the running sum
            // read and process the remaining transactions
            while (read(fin, trans)) {
                // if we’re still processing the same book
                if (total.isbn() == trans.isbn()) {
                    total.combine(trans);
                } else {
                    // print results for the previous book
                    print(fout, total) << "\n";
                    total = trans; // total now refers to the next book
                }
            }
            print(fout, total) << "\n";
        } else {
            // no input! terminate with error
            throw runtime_error("No sales data?!");
        }
    } catch (const runtime_error &err) {
        cout << "ERROR: runtime error:\n\t" << err.what();
    }

    return 0;
}