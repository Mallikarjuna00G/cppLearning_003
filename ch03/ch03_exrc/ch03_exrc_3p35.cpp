#include <iostream>
#include <cstddef>

using std::cout;
using std::begin;
using std::end;
using std::endl;

int main() {
    constexpr size_t arr_size = 10;
    int a[arr_size] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "Before: " << endl;

    for (auto &x: a) {
        cout << x << " ";
    }
    cout << endl;

    auto *p = begin(a);  // int *p = a;
    auto const e = end(a);  // int *const e = &(a + arr_size)
    for (; p != e; ++p) {
        *p = 0;
    }

    cout << "After: " << endl;

    for (auto &x: a) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}