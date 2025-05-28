#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::iterator;

int main() {
    vector<int> v1{73, 19, 95, 4, 61, 28, 80, 12, 55, 37};
    string hrLine = "\n------------------------------------------\n";

    cout << "Before twicing: " << endl;
    for (auto a = v1.begin(); a != v1.end(); a++) {
        cout << *a << " ";
    }
    cout << endl;
    
    // twicing
    for (auto a = v1.begin(); a != v1.end(); a++) {
        *a *= 2;
    }

    cout << hrLine;
    cout << "After twicing: " << endl;
    for (auto a = v1.begin(); a != v1.end(); a++) {
        cout << *a << " ";
    }
    cout << endl;

    return 0;
}