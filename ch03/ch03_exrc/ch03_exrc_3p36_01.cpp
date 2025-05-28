#include <iostream>
#include <cstddef>

using std::cout;
using std::endl;
using std::begin;
using std::end;

int main() {
    int arr1[] = {1, 23, 56, 34, 57, 67, 89, 54, 23};
    int arr2[] = {10, 23, 556, 34, 557, 67, 589, 54, 23};
    int arr3[] = {10, 23, 556, 34, 557, 67, 589, 54, 23};
    int arr4[] = {23, 556, 34, 557, 67, 589, 54, 23};

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
    auto len2 = end(arr2) - begin(arr2);
    if (len2 == end(arr2) - begin(arr2)) {
        for (decltype(len2) i = 0; i < len2; i++) {
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
    if (len2 == end(arr3) - begin(arr3)) {
        for (decltype(len2) i = 0; i < len2; i++) {
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
    if (len2 == end(arr4) - begin(arr4)) {
        for (decltype(len2) i = 0; i < len2; i++) {
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