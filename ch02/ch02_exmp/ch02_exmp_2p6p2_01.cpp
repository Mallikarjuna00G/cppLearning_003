#include <iostream>
#include <string>

struct Sales_data {
    std::string bookNo = "";
    unsigned int units_sold = 0;
    double revenue = 0.0;
};

int main() {
    Sales_data data1, data2;

    double price = 0;  // price per book, used to calculate the total revenue

    // read the first transactions: ISBN, number of books sold, price per book
    std::cin >> data1.bookNo >> data1.units_sold >> price;
    // calculate the revenue from price and units_sold
    data1.revenue = data1.units_sold * price;

    // read the second transactions: ISBN, number of books sold, price per book
    std::cin >> data2.bookNo >> data2.units_sold >> price;
    // calculate the revenue from price and units_sold
    data2.revenue = data2.units_sold * price;

    // code to check whether data1 and data2 have the same ISBN
    // and if so print the sum of data1 and data2
    if (data1.bookNo == data2.bookNo) {
        unsigned totalCnt = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;

        // print: ISBN, total sold, total revenue, average price per book
        std::cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
        if (totalCnt != 0) {
            std::cout << totalRevenue / totalCnt << std::endl;
        } else {
            std::cout << "(no sales)" << std::endl;
        }
        return 0;  // indicate success
    } else {  // transactions were not for the same ISBN
        std::cerr << "Data must refer to the same ISBN" << std::endl;
        return -1;  // indicate failure
    }

    return 0;
}