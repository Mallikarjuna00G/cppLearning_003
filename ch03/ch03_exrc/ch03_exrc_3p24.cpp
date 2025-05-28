#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::iterator;
using std::string;

int main() {
    vector<int> vInt;
    int temp;
    string hrLine = "\n------------------------------------\n";
    cout << "Enter some integers: " << endl;
    while (cin >> temp) {
        vInt.push_back(temp);
    }
    cout << hrLine;

    cout << "Sum of each pair of adjacent elements: " << endl;
    for (auto it = vInt.cbegin(); it != vInt.cend() - 1; it++) {
        int a = *it;
        int b = *(it + 1);
        temp = a + b;
        cout << a << " + " << b << " = " << temp << endl;
    }

    cout << hrLine;

    cout << "sum of the first and last elements, \nfollowed by the sum of the second and second-to-last, and so on: " << endl;
    // NOTE: writing `itb != ite` in the condition instead of 
    // `itb < ite` will lead to infinite loop and eventually 
    // ends with segmentation fault.
    // It happens especially when the size of the vector is even.
    // Because, the two iterators just cross each other but never get to 
    // point to same element.
    for (auto itb = vInt.cbegin(), ite = vInt.cend() - 1; !vInt.empty() && itb < ite; itb++, ite--) {
        int a = *itb;
        int b = *ite;
        temp = a + b;
        cout << a << " + " << b << " = " << temp << endl;
    }

    cout << hrLine;

    return 0;
}