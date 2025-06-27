/**
 * @file main.cpp
 * @brief Demonstrates sequential container comparisons using `seqContainerCompare`.
 *
 * This file serves as the main entry point for the program. It initializes
 * several `std::vector<int>` and `std::list<int>` objects with various integer sequences.
 * It then utilizes the `displaySeqContainer` function (from `displaySeqContainer.hpp`)
 * to print the contents of each created container to standard output.
 *
 * The core purpose of this program is to showcase the functionality of the
 * `seqContainerCompare` function (from `seqContainerCompare.hpp`), which performs
 * a three-way lexicographical comparison between a `std::vector<int>` and a `std::list<int>`.
 * The program explicitly prints the results of these comparisons, clarifying the
 * meaning of the return values (-1, 0, 1).
 *
 * @author Mallikarjuna00G
 * @date 2025-06-27
 */

#include <iostream>
#include <vector>
#include <list>

#include "displaySeqContainer.hpp" // Assumes this header provides overloads for std::vector<int> and std::list<int>
#include "seqContainerCompare.hpp"   // Declares the seqContainerCompare function

using std::cout;
using std::vector;
using std::list;

int main() {

    vector<int> v1 = { 1, 3, 5, 7, 9, 12 };
    vector<int> v2 = { 1, 3, 9 };
    vector<int> v3 = { 1, 3, 5, 7 };
    vector<int> v4 = { 1, 3, 5, 7, 9, 12 };

    list<int> l1 = { 1, 3, 5, 7, 9, 12 };
    list<int> l2 = { 1, 3, 9 };
    list<int> l3 = { 1, 3, 5, 7 };
    list<int> l4 = { 1, 3, 5, 7, 9, 12 };

    cout << "v1 ==> ";
    displaySeqContainer(v1);
    cout << "v2 ==> ";
    displaySeqContainer(v2);
    cout << "v3 ==> ";
    displaySeqContainer(v3);
    cout << "v4 ==> ";
    displaySeqContainer(v4);

    cout << "l1 ==> ";
    displaySeqContainer(l1);
    cout << "l2 ==> ";
    displaySeqContainer(l2);
    cout << "l3 ==> ";
    displaySeqContainer(l3);
    cout << "l4 ==> ";
    displaySeqContainer(l4);

    cout << "\nNOTE: 0 is equal, -1 is lesser, and 1 is greater\n";
    cout << "Compare v1, l1: " << seqContainerCompare(v1, l1) << "\n";
    cout << "Compare v1, l2: " << seqContainerCompare(v1, l2) << "\n";
    cout << "Compare v2, l1: " << seqContainerCompare(v2, l1) << "\n";
    cout << "Compare v3, l4: " << seqContainerCompare(v3, l4) << "\n";
    cout << "Compare v4, l2: " << seqContainerCompare(v4, l2) << "\n";

    return 0;
}
