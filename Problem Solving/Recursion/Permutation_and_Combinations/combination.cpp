/**
 * Definition: Selections of items where the order does not matter.
 * Key Idea: Changing the order of items does not result in a different combination.
 *  Formula: nCr = n! / ((n-r)! (r)!)
 * Ex: A,B,C
 * * Arranging 2 at a time
 * * AB, AC, BC
 * 
 * EX: A, B, C, D         r = 3
 * * ABC, ABD, ACD, BCD
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to generate combinations
void generateCombinations(vector<int>& elements, int r, int index, vector<int> &result) {
    if (result.size() ==  r) {
        for (int i=0;i<r;i++) {
            cout << result[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i=index;i<elements.size();i++) {
        result.push_back(elements[index]);
        generateCombinations(elements, r, ++index, result);
        result.pop_back();
    }
}

int main() {
    vector<int> elements = {1, 2, 3, 4, 5}; // The set of elements
    int r = 3; // Size of each combination

    cout << "Combinations of size " << r << " are:\n";
    vector<int> result;
    generateCombinations(elements, r, 0, result);

    return 0;
}
