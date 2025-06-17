#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <cmath>  // for std::nan - not a number

using std::string;
using std::cout;
using std::istream;
using std::ostream;
using std::exception;
using std::runtime_error;

struct Sales_data;  // forward declaration
istream &read(istream &is, Sales_data &item);

class Sales_data {
    // START: friends
    friend istream &read(istream &is, Sales_data &item);
    friend ostream &print(ostream &os, const Sales_data &item);
    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
    // END: friends

    public:
    // START: constructors
    Sales_data(const string&s, unsigned int n, double p): bookNo(s), units_sold(n), revenue(n * p){
        cout << "I am a delected-to constructor with 3 parameters\n";
    }
    Sales_data(): Sales_data("", 0, 0) {
        cout << "I am a delecting constructor with 0 parameters (default constrcutor)\n";
    }
    Sales_data(const string& s): Sales_data(s, 0, 0) {
        cout << "I am a delecting constructor with 1 parameter (isbn).\nWill delegate the only available delegating-to constructor.\n";
    }
    Sales_data(istream &is): Sales_data() {
        cout << "I am a delecting constructor with 1 parameter (reference to istream).\nWill delegate the only available delegating-to constructor.\n";
        read(is, *this);
    }
    // END: constructors

    inline string isbn() const {return this->bookNo;};
    Sales_data& combine(const Sales_data &sd);

    
    inline double avg_price() const {
        return units_sold ? revenue / units_sold : 0;
    }

    private:
    string bookNo = "";
    unsigned int units_sold = 0;
    double revenue = 0.0;
};

ostream &print(ostream &os, const Sales_data &item);
Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

#endif