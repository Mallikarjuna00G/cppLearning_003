#include <iostream>

#include "exercise.hpp"
#include "displaySeqContainer.hpp"

using std::vector;
using std::cout;
using std::endl;

int exercise() {
    cout << "Demonstrating `Capacity`" << endl;
    vector<int> ivec;
    // size should be zero; capacity is implementation defined
    dispVectorSizeAndCapacity(ivec);
    
    // give ivec 24 elements
    for (vector<int>::size_type i = 0; i != 24; ++i) {
        ivec.push_back(i);
        dispVectorSizeAndCapacity(ivec);
    }
    
    cout << "Demonstrating `reserve`" << endl;
    vector<int> ivec2;
    dispVectorSizeAndCapacity(ivec2);
    ivec2.reserve(10);
    dispVectorSizeAndCapacity(ivec2);
    // give ivec 13 elements
    for (vector<int>::size_type i = 0; i != 13; ++i) {
        ivec2.push_back(i);
        dispVectorSizeAndCapacity(ivec2);
    }

    cout << "Calling shrink to fit on ivec2" << endl;
    ivec2.shrink_to_fit();
    dispVectorSizeAndCapacity(ivec2);

    return EXIT_SUCCESS;
}