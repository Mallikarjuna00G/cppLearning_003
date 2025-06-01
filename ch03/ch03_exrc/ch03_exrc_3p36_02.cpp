#include <iostream>
#include <cstddef>
#include <vector>

using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::vector;

int main() {
    vector<int> arr1 = {1, 23, 56, 34, 57, 67, 89, 54, 23};
    vector<int> arr2 = {10, 23, 556, 34, 557, 67, 589, 54, 23};
    vector<int> arr3 = {10, 23, 556, 34, 557, 67, 589, 54, 23};
    vector<int> arr4 = {23, 556, 34, 557, 67, 589, 54, 23};

    cout << "arr1: ";
    for (auto x: arr1) {
        cout << x << " ";
    }
    cout << endl;

    cout << "arr2: ";
    for (auto x: arr2) {
        cout << x << " ";
    }
    cout << endl;

    cout << "arr3: ";
    for (auto x: arr3) {
        cout << x << " ";
    }
    cout << endl;

    cout << "arr4: ";
    for (auto x: arr4) {
        cout << x << " ";
    }
    cout << endl;

    bool equal = true;
    if (arr1.size() == arr2.size()) {
        for (decltype(arr1.size()) i = 0; i < arr1.size(); ++i) {
            if (arr1[i] != arr2[i]) {
                equal = false;
            }
        }
        if (equal == true) {
            cout << "arr1 and arr2 are equal" << endl;
        } else {
            cout << "arr1 and arr2 are not equal" << endl;
        }
    } else {
        cout << "arr1 and arr2 are not equal" << endl;
    }

    equal = true;
    if (arr2.size() == arr3.size()) {
        for (decltype(arr2.size()) i = 0; i < arr2.size(); ++i) {
            if (arr2[i] != arr3[i]) {
                equal = false;
            }
        }
        if (equal == true) {
            cout << "arr3 and arr2 are equal" << endl;
        } else {
            cout << "arr3 and arr2 are not equal" << endl;
        }
    } else {
        cout << "arr3 and arr2 are not equal" << endl;
    }

    equal = true;
    if (arr2.size() == arr3.size()) {
        for (decltype(arr2.size()) i = 0; i < arr2.size(); ++i) {
            if (arr2[i] != arr4[i]) {
                equal = false;
            }
        }
        if (equal == true) {
            cout << "arr4 and arr2 are equal" << endl;
        } else {
            cout << "arr4 and arr2 are not equal" << endl;
        }
    } else {
        cout << "arr4 and arr2 are not equal" << endl;
    }

    return 0;
}