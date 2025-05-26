#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main() {
    vector<string> v1;

    string temp;
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