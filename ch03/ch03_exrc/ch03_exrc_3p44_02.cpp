#include <iostream>
#include <cstddef>

using std::cout;
using std::endl;
using std::begin;
using std::end;

int main() {
    typedef size_t uint;
    const size_t arr_size = 10;
    int ia[arr_size] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};


    for (uint i = 0; i < arr_size; ++i) {
        cout << ia[i] << " ";
    }
    cout << endl;

    return 0;
}