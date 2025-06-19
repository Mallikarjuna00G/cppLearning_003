#include "recVec.h"

using std::vector;
using std::cout;

void printVec(vector<int> &vec) {
    if (vec.empty()) {
        return;
    }

    recVec(vec, 0);
}

void recVec(vector<int> &vec, std::vector<int>::size_type index) {
    if (index == vec.size()) {
        cout << "\n";
        return;
    }

    cout << vec[index] << " ";
    recVec(vec, index + 1);
}