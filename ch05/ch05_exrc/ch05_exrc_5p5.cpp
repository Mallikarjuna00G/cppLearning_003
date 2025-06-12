#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main() {
    const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
    // if grade is less than 60 it's an F, otherwise compute a subscript
    string lettergrade;
    int grade;
    cin >> grade;

    if (grade < 60) {
        lettergrade = scores[0];
    } else {
        lettergrade = scores[(grade - 50)/10];
        if (grade != 100) {
            if (grade % 10 > 7) {
                lettergrade += '+'; // grades ending in 8 or 9 get a +
            } else if (grade % 10 < 3) {
                lettergrade += '-'; // grades ending in 0, 1, or 2 get a -
            }
        }
    }

    cout << "Your grade is " << lettergrade << "\n";

    return 0;
}