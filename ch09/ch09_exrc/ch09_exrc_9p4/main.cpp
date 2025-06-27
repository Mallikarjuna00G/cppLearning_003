#include <iostream>
#include <vector>

#include "itemFound.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {

    cout << "Enter the integer value you want to find: \n";
    int seek = 0;
    if(cin >> seek) {
        cout << "Enter the elements of your sequence: \n";
        int temp;
        vector<int> vec1;
        while(cin >> temp) {
            vec1.push_back(temp);
        }
        cout << seek << " is found in the given sequence: " << (itemFound(vec1.cbegin(), vec1.cend(), seek) ? "TRUE" : "FALSE") << endl;
    }
    
    return 0;
}