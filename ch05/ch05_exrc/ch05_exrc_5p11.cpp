#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
    string str;
    int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, otherCnt = 0;
    int spaceCnt = 0, tabCnt = 0, newLineCnt = 0;

    cout << "Enter you text: \n";


    while (getline(cin, str)) {  // note: cin skips space character Exits at EOF character
        for (auto ch : str) {
            if ('a' == ch || 'A' == ch) {
                ++aCnt;
            } else if ('e' == ch || 'E' == ch) {
                ++eCnt;
            } else if ('i' == ch || 'I' == ch) {
                ++iCnt;
            } else if ('o' == ch || 'O' == ch) {
                ++oCnt;
            } else if ('u' == ch || 'U' == ch) {
                ++uCnt;
            } else if (' ' == ch) {
                ++spaceCnt;
            } else if ('\t' == ch) {
                ++tabCnt;
            } else {
                ++otherCnt;
            }
        }
        ++newLineCnt;
    }

    cout << "No. of 'a': " << aCnt
        << "\nNo. of 'e': " << eCnt
        << "\nNo. of 'i': " << iCnt
        << "\nNo. of 'o': " << oCnt
        << "\nNo. of 'u': " << uCnt
        << "\nNo. of white spaces: " << spaceCnt
        << "\nNo. of tab spaces: " << tabCnt
        << "\nNo. of new lines: " << newLineCnt
        << "\nNo. of other characters: " << otherCnt << "\n";

    return 0;
}