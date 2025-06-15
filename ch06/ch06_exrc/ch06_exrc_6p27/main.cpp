#include <iostream>
#include "sumIniList.h"

using std::cout;

int main() {
    int sum = 0;

    sum = sumIniList({1, 2, 3, 4, 5});
    cout << sum << "\n";

    sum = sumIniList({1, 2, 13, 4, 5, 15, 56});
    cout << sum << "\n";

    return 0;
}