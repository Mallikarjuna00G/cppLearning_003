#include "recVec.h"

using std::vector;
using std::cout;
using std::size_t;

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

    #ifndef NDEBUG
    cout << "\n --> Size of the vector is " << vec.size() << " on call count " << index + 1 << "\n";
    #endif

    cout << vec[index] << " ";
    recVec(vec, index + 1);
}