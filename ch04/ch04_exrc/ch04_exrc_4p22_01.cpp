#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    int grade;
    cin >> grade;
    string finalgrade = (grade > 90) ? "high pass" : 
        (grade > 75) ? "pass" : 
        (grade < 60) ? "fail" : 
        "low pass";

    cout << finalgrade;

    return 0;
}