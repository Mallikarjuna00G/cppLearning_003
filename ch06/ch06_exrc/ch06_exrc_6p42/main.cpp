#include <iostream>
#include "makePlural.h"

using std::cout;

int main() {
    cout << make_plural(std::string::size_type(1), "success", "es") << "\n";
    cout << make_plural(std::string::size_type(10), "success", "es") << "\n";
    cout << make_plural(std::string::size_type(1), "failure") << "\n";
    cout << make_plural(std::string::size_type(10), "failure") << "\n";

    return 0;
}