#include <iostream>
#include <vector>
#include <string>

#include "exercise.hpp"
#include "displaySeqContainer.hpp"

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int exercise() {
    vector<string> svec;
    cout << "On fresh declaration: \n";
    dispVectorSizeAndCapacity(svec);
    svec.reserve(1024);
    cout << "On reserve(1024): \n";
    dispVectorSizeAndCapacity(svec);
    
    string word;
    cout << "While feeding: \n";
    while (cin >> word) {
        svec.push_back(word);
        dispVectorSizeAndCapacity(svec);
    }
    
    svec.resize(svec.size()+svec.size()/2);
    cout << "After resize \n";
    dispVectorSizeAndCapacity(svec);

    return EXIT_SUCCESS;
}