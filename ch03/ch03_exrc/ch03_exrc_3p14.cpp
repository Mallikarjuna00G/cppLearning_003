#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
    vector<int> v1;

    int temp;
    while (cin >> temp) {
        v1.push_back(temp);
    }

    cout << "Following are your inputs: " << endl;

    for (auto a: v1) {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}