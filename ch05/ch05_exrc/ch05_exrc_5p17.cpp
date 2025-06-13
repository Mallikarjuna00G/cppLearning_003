#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
    vector<int> v1, v2;
    
    cout << "Enter elements of two integer vectors separated by a |\n";

    int temp;
    while (cin >> temp) {
        v1.push_back(temp);
        cout << temp << endl;
    }

    while (cin >> temp) {
        cout << temp << endl;
        v2.push_back(temp);
    }

    decltype(v1.size()) smallerSize = v1.size() < v2.size() ? v1.size() : v2.size();

    bool prefix = true;
    for (decltype(smallerSize) i = 0; i < smallerSize && prefix; ++i) {
        if (v1[i] != v2[i]) {
            prefix = false;
        }
    }

    if (prefix) {
        cout << "One vector is a prefix of the other vector\n";
    } else {
        cout << "No vector is a prefix of the other vector\n";
    }

    cout << "Your vectors were: \n";
    for (auto a : v1) {
        cout << a << " ";
    }
    cout << endl;
    for (auto a : v2) {
        cout << a << " ";
    }

    return 0;
}