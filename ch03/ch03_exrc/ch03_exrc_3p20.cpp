#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
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
    for (decltype(vInt.size()) i = 0; i < vInt.size() - 1; i++) {
        int a = vInt[i];
        int b = vInt[i + 1];
        temp = a + b;
        cout << a << " + " << b << " = " << temp << endl;
    }

    cout << hrLine;

    cout << "sum of the first and last elements, \nfollowed by the sum of the second and second-to-last, and so on: " << endl;
    for (decltype(vInt.size()) i = 0; i < vInt.size() / 2; i++) {
        int a = vInt[i];
        int b = vInt[vInt.size() - i - 1];
        temp = a + b;
        cout << a << " + " << b << " = " << temp << endl;
    }

    cout << hrLine;

    return 0;
}