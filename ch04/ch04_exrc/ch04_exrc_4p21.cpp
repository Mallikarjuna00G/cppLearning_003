#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {
    vector<int> vint = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    vector<int>::iterator it;

    for (it = vint.begin(); it != vint.end(); ++it) {
        cout << *it << " -> " << ((*it % 2 == 0 ? *it : 2 * *it)) << endl;
    }

    return 0;
}