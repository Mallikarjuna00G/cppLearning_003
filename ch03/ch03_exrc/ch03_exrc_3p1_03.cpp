#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int a = 0, b = 0;
    cout << "Enter two (positive) integers (<smaller number> <bigger number>):" << std::endl;
    cin >> a >> b;
    // keep executing the while a long as val is less than or equal to 10
    while (a <= b) {
        cout << a << endl;
        ++a;  // add 1 to val
    }

    return 0;
}