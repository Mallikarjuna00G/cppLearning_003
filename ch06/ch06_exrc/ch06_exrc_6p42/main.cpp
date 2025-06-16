#include <iostream>
#include "makePlural.h"

using std::cout;

int main() {
    cout << make_plural(1, "success", "es") << "\n";
    cout << make_plural(10, "success", "es") << "\n";
    cout << make_plural(1, "failure") << "\n";
    cout << make_plural(10, "failure") << "\n";

    return 0;
}