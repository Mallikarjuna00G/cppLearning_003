#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    char ch;
    int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, otherCnt = 0;

    cout << "Enter you text: \n";

    while (cin >> ch) {  // note: cin skips space character
        if ('a' == ch) {
            ++aCnt;
        } else if ('e' == ch) {
            ++eCnt;
        } else if ('i' == ch) {
            ++iCnt;
        } else if ('o' == ch) {
            ++oCnt;
        } else if ('u' == ch) {
            ++uCnt;
        } else {
            ++otherCnt;
        }
    }

    cout << "No. of 'a': " << aCnt
        << "\nNo. of 'e': " << eCnt
        << "\nNo. of 'i': " << iCnt
        << "\nNo. of 'o': " << oCnt
        << "\nNo. of 'u': " << uCnt
        << "\nNo. of other characters: " << otherCnt << "\n";

    return 0;
}