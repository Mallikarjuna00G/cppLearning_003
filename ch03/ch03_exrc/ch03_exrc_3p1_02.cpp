#include <iostream>
using std::cout;
using std::endl;

int main()
{
    int val = 10;
    // keep executing the while a long as val is less than or equal to 10
    while (val >= 0) {
        cout << val << endl;
        --val;  // add 1 to val
    }

    return 0;
}