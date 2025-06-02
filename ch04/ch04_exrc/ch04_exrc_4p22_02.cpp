#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    int grade;
    cin >> grade;
    string finalgrade = "";
    if (grade > 90) finalgrade = "high pass";
    else if (grade > 75) finalgrade = "pass";
    else if (grade > 59) finalgrade = "low pass"; 
    else finalgrade = "fail";

    cout << finalgrade;

    return 0;
}