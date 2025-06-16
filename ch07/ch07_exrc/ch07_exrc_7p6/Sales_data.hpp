#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

using std::string;
using std::istream;
using std::ostream;

struct Sales_data {
    std::string bookNo = "";
    unsigned int units_sold = 0;
    double revenue = 0.0;

    inline string isbn() const {return this->bookNo;};
    Sales_data& combine(const Sales_data &sd);

    inline double avg_price() const {return revenue / units_sold;}
};

istream &read(istream &is, Sales_data &item);
ostream &print(ostream &os, const Sales_data &item);
Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

#endif