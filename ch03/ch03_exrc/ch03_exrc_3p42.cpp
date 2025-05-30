#include <iostream>
#include <vector>
#include <cstddef>

using std::vector;
using std::cout;
using std::endl;
using std::end;

int main() {
    constexpr size_t len = 10;
    vector<int> varr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr[len];

    for (decltype(varr.size()) i = 0; i < varr.size(); i++) {
        arr[i] = varr[i];
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}