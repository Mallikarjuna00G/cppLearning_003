#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Sales_data {
    string bookNo = "";
    unsigned int units_sold = 0;
    double revenue = 0.0;
};

int main() {
    Sales_data item1;

    while (cin >> item1.bookNo >> item1.units_sold >> item1.revenue) {
        cout << "Sold book: " << item1.bookNo << " " << item1.units_sold << " " << item1.revenue << endl;
    }

    return 0;
}