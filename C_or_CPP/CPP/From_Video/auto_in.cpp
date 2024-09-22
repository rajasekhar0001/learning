/**
 * AUTO keyword in cpp
 * * Once first time initialization happens, compiler considers the type then other type data can't be assigned.
 * * If did so, implicit casting if possible like float to int, else error.
 */

#include <iostream>
using namespace std;

int main() {

    auto x = 2u;    // compiler deduces the type of auto as unsigned int

    cout << x << endl;
    x = -2;         // underflow happens since x is unsigned int
    cout << "x : " << x <<endl;

    x = 4.52f;  // truncated to 4

    // x= 'a';  // ascii of 'a'

    cout << "x as char: " << x << endl;
}