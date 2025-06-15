#include "recVec.h"

void printVec(vector<int> &vec) {
    if (vec.empty()) {
        return;
    }

    recVec(vec, 0);
}

void recVec(vector<int> &vec, size_t index) {
    if (index == vec.size()) {
        cout << "\n";
        return;
    }

    cout << vec[index] << " ";
    recVec(vec, index + 1);
}