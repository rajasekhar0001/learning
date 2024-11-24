/**
 * Permutations of a number taking 'n' at a time not 'r'
 * 
 * Definition: Arrangements of items where the order is important.
    Key Idea: Changing the order of items results in a different permutation.
 * Formulat:  no. of permutations =  n! (if 'n' taken at a time)
 *                                nPr = n! / (n-r)!  (if 'r' taken at a time)
 * EX: A, B, C  r = 3;
 * ABC, ACB, BAC, BCA, CAB, CBA
 */

#include <bits/stdc++.h>

using namespace std;

// some way uses extra  space
// bool findPermutation(vector<char> &arr, vector<char> &ds, vector<int> &flag, string &s2) {
//     if (ds.size() == arr.size()) {
//         string str;
//         for (char c:ds) {
//             str += c;
//         }
//         if (s2.find(str) != string::npos)
//             return true;
//         else
//             return false;
//     }

//     for (int i=0;i<flag.size();i++) {
//         if (flag[i] != 1) {
//             ds.push_back(arr[i]);
//             flag[i] = 1;
//             if (findPermutation(arr, ds, flag, s2))
//                 return true;
//             ds.pop_back();
//             flag[i] = 0;
//         }
//     }
//     return false;
// }


// Optimised method using swapping in place in array (not using any extra space)
void findPermutation(vector<int> &arr, int index)
{
    if (index == arr.size())
    {
        for (int i=0;i<arr.size();i++) {
            cout << arr[i] << " ";
        } cout << endl;
        return;
    }
    for (int i = index; i < arr.size(); i++)
    {
        swap(arr[i], arr[index]);
        findPermutation(arr, 1+index);
        swap(arr[i], arr[index]);
    }
}

void generatePermutations(vector<int> &arr, int index)
{
    // vector<char> ds;
    // vector<int> flag (s1.size(), 0);
    // return findPermutation(arr, ds, flag, s2);
    findPermutation(arr, index);
}

int main() {
    vector<int> elements = {1, 2, 3}; // The set of elements
    // Not cnnsidering r, since traking all digits or chracters at a time

    cout << "Permutations of size " << elements.size() << " are:\n";
    vector<int> result;
    generatePermutations(elements, 0);
}