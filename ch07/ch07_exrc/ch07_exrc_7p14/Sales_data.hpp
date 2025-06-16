#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <cmath>  // for std::nan - not a number

using std::string;
using std::istream;
using std::ostream;
using std::exception;
using std::runtime_error;


struct Sales_data;  // forward declaration of the structure
istream &read(istream &is, Sales_data &item);

struct Sales_data {
    // START: constructors
    Sales_data(): bookNo(""), units_sold(0), revenue(0) {}
    Sales_data(const string& s): bookNo(s) {}
    Sales_data(const string&s, unsigned int n, double p): bookNo(s), units_sold(n), revenue(n * p){}
    Sales_data(istream &is) {
        read(is, *this);
    }
    // END: constructors

    string bookNo = "";
    unsigned int units_sold = 0;
    double revenue = 0.0;

    inline string isbn() const {return this->bookNo;};
    Sales_data& combine(const Sales_data &sd);

    
    inline double avg_price() const {
        if (units_sold == 0) {
            return std::nan("");  // Call std::nan as a function, provide an empty string tag
            //throw runtime_error("file: " + string(__FILE__) + " function: " + __func__ + "\n" + "Attempt to division by 0.");
        } 
        return revenue / units_sold;
    }
    
};

ostream &print(ostream &os, const Sales_data &item);
Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

#endif