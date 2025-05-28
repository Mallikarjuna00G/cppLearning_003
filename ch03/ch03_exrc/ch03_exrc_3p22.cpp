#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::iterator;
using std::toupper;

int main() {
    vector<string> text;
    string temp;
    string hrLine = "\n--------------------------------------------\n";

    cout << "Enter your paragraph: " << endl;
    while (cin >> temp) {
        text.push_back(temp);
    }

    cout << hrLine;
    cout << "Text as obtained: " << endl;

    for (auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it)
        cout << *it << " ";
    cout << endl;

    // touppercase
    for (auto it = text.begin(); it != text.end() && !it->empty(); ++it)
        for (auto itc = it->begin(); itc != it->end() && !it->empty(); ++itc)
            *itc = toupper(*itc);    
    
    cout << hrLine;
    cout << "Text after uppercasing: " << endl;
    for (auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}