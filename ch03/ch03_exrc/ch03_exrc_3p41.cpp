#include <iostream>
#include <vector>
#include <cstddef>

using std::vector;
using std::cout;
using std::endl;
using std::end;

int main() {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> varr(arr, end(arr));

    for (auto a: varr) {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}