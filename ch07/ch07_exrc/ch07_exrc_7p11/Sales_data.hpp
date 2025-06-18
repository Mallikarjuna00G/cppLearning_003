#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <cmath>  // for std::nan - not a number

struct Sales_data {
    // START: constructors
    Sales_data() = default;
    Sales_data(const std::string &s): bookNo(s) {}
    Sales_data(const std::string &s, unsigned int n, double p): bookNo(s), units_sold(n), revenue(n * p){}
    Sales_data(std::istream &is);
    // END: constructors

    std::string bookNo = "";
    unsigned int units_sold = 0;
    double revenue = 0.0;

    inline std::string isbn() const {return this->bookNo;};
    Sales_data& combine(const Sales_data &sd);

    
    inline double avg_price() const {
        if (units_sold == 0) {
            return std::nan("");  // Call std::nan as a function, provide an empty std::string tag
            //throw runtime_error("file: " + std::string(__FILE__) + " function: " + __func__ + "\n" + "Attempt to division by 0.");
        } 
        return revenue / units_sold;
    }
    
};

std::istream &read(std::istream &is, Sales_data &item);
std::ostream &print(std::ostream &os, const Sales_data &item);
Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

#endif