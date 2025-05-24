#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::cerr;

struct Sales_data {
    string bookNo = "";
    unsigned int units_sold = 0;
    double revenue = 0.0;
};

int main() {
    Sales_data data1, data2;

    int count = 0;
    if (cin >> data1.bookNo >> data1.units_sold >> data1.revenue) {
        count++;
        while (cin >> data2.bookNo >> data2.units_sold >> data2.revenue) {

            if (data1.bookNo == data2.bookNo) {
                count++;
            } else {
                cout << data1.bookNo << " occured in " << count << " transactions" << endl;
                count = 1;
                data1 = data2;
            }
        }
        cout << data1.bookNo << " occured in " << count << " transactions" << endl;
        
    } else {
        cerr << "Terminating" << endl;
    }

    return 0;
}