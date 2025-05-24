#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::cerr;

struct Sales_data {
    string bookNo = "";
    unsigned int units_sold = 0;
    double revenue = 0.0;
};

int main() {
    Sales_data data1, data2;

    cin >> data1.bookNo >> data1.units_sold >> data1.revenue;
    cin >> data2.bookNo >> data2.units_sold >> data2.revenue;

    if (data1.bookNo == data2.bookNo) {
        unsigned totalCnt = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;

        // print: ISBN, total sold, total revenue
        cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
        
        return 0;  // indicate success
    } else {  // transactions were not for the same ISBN
        cerr << "Data must refer to the same ISBN" << endl;
        return -1;  // indicate failure
    }

    return 0;
}