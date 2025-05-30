#include <iostream>

using std::cout;
using std::endl;

int main() {
    typedef int integer;
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (integer &a: ia) {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}