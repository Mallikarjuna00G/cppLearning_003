#include <iostream>
#include <cstddef>

using std::cin;
using std::cout;
using std::endl;

int main() {
    constexpr size_t array_size = 10;
    int arr[array_size] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr2[array_size];

    for (size_t t = 0; t < array_size; t++) {
        arr2[t] = arr[t];
    }

    
    for (size_t t = 0; t < array_size; t++) {
        cout << "at t = " << t << " arr[t]:arr2[t] are " << arr2[t] << ":" << arr[t] << endl;
    }

    return 0;
}