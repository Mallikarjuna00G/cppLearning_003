#include <iostream>

using std::endl;
using std::cout;

int giveANumber() {
    static int a = 0;
    return a++;
}

int main() {
    cout << giveANumber() << endl;
    cout << giveANumber() << endl;
    cout << giveANumber() << endl;
    cout << giveANumber() << endl;
    cout << giveANumber() << endl;

    return 0;
}