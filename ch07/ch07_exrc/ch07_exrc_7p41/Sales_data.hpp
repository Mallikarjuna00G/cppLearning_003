#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <cmath>  // for std::nan - not a number

struct Sales_data;  // forward declaration
std::istream &read(std::istream &is, Sales_data &item);

class Sales_data {
    // START: friends
    friend std::istream &read(std::istream &is, Sales_data &item);
    friend std::ostream &print(std::ostream &os, const Sales_data &item);
    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
    // END: friends

    public:
    // START: constructors
    Sales_data(const std::string&s, unsigned int n, double p): bookNo(s), units_sold(n), revenue(n * p){
        std::cout << "I am a delected-to constructor with 3 parameters\n";
    }
    Sales_data(): Sales_data("", 0, 0) {
        std::cout << "I am a delecting constructor with 0 parameters (default constrcutor)\n";
    }
    Sales_data(const std::string& s): Sales_data(s, 0, 0) {
        std::cout << "I am a delecting constructor with 1 parameter (isbn).\nWill delegate the only available delegating-to constructor.\n";
    }
    Sales_data(std::istream &is): Sales_data() {
        std::cout << "I am a delecting constructor with 1 parameter (reference to std::istream).\nWill delegate the only available delegating-to constructor.\n";
        read(is, *this);
    }
    // END: constructors

    inline std::string isbn() const {return this->bookNo;};
    Sales_data& combine(const Sales_data &sd);

    
    inline double avg_price() const {
        return units_sold ? revenue / units_sold : 0;
    }

    private:
    std::string bookNo = "";
    unsigned int units_sold = 0;
    double revenue = 0.0;
};

std::ostream &print(std::ostream &os, const Sales_data &item);
Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

#endif