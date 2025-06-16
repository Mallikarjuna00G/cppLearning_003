#include "Sales_data.hpp"

Sales_data& Sales_data::combine(const Sales_data &sd) {
    this->units_sold += sd.units_sold;
    this->revenue += sd.revenue;

    return *this;  // we are dereferencing here.
}