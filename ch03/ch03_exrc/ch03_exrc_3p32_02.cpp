#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> arr2;

    for (decltype(arr.size()) t = 0; t < arr.size(); t++) {
        arr2.push_back(arr[t]);
    }

    
    for (decltype(arr.size()) t = 0; t < arr.size(); t++) {
        cout << "at t = " << t << " arr[t]:arr2[t] are " << arr2[t] << ":" << arr[t] << endl;
    }

    return 0;
}