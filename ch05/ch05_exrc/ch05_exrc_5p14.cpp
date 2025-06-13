#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
    string str1, str2;
    string highestRepeatedWord = "";
    int count1 = 0, count2 = 0;

    while (cin >> str1) {
        if (str2 == str1) {
            ++count1;
        } else {
            str2 = str1;
            count1 = 1;
        }
        if (count1 != 1 && count2 < count1) {
            count2 = count1;
            highestRepeatedWord = str1;
        }
    }



    if (count2 > 1) {
        cout << "Highest duplicated word: " << highestRepeatedWord
            << "\nRepeat count: " << count2 << "\n";
    } else {
        cout << "No word was repeated\n";
    }

    return 0;
}