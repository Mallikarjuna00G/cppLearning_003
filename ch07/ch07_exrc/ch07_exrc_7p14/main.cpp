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
        string hrLine = "--------------------------------------\n";
        // for default constructor
        cout << "With all parameter constructor:\n";
        Sales_data sd3("0-201-78345-X", 5, 25);
        print(cout, sd3) << "\n";
        cout << hrLine;

        cout << "With istream parameter constructor:\n";
        Sales_data sd4(cin);
        if(cin) {
            print(cout, sd4) << "\n";
            cout << hrLine;
        } else {
            throw runtime_error("You missed to enter valid/any data\nfor constructor with istream parameter.");
        }

        cout << "With default constructor:\n";
        Sales_data sd1;
        print(cout, sd1) << "\n";
        cout << hrLine;

        cout << "With one parameter (isbn) constructor:\n";
        Sales_data sd2("0-201-78345-X");
        print(cout, sd2) << "\n";
        cout << hrLine;

    } catch (const runtime_error &err) {
        cout << "ERROR: runtime error:\n\t" << err.what();
    }

    return 0;
}