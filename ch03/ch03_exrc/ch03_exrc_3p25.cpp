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
    // count the number of grades by clusters of ten: 0--9, 10--19, . .. 90--99, 100
    vector<unsigned> scores(11, 0); // 11 buckets, all initially 0
    unsigned grade;
    auto it = scores.begin();
    while (cin >> grade) { // read the grades
        if (grade <= 100) // handle only valid grades
            ++*(it + (grade / 10)); // increment the counter for the current cluster
    }

    for (auto &a: scores) {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}