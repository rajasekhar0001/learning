/**
 * Creating custom concept without using buikt int concept
 */

#include <iostream>
#include <concepts>

using namespace std;

// crating custom concept
template <typename T>
concept Multipliable = requires (T a, T b) {
    a * b; // Just make sure taht arguments are multipliable
};

/*
// Creating the function template using custom concept
template <typename T>
requires Multipliable<T>    // the arguments should suppose to be multipliable
T add (T a) {
    return  2*a;
}
// It will work, considers single argument, since there is no possibility to fail
// only one argument
//  But not works for strings
*/

// Creating the function template using custom concept
template <typename T>
requires Multipliable<T>    // the arguments should suppose to be multipliable
T add (T a, T b) {
    return  a+ b;
}

int main() {
    double a {10.0};
    double b {11.2};    // works for double

    // int a {10};
    // int b {11}; // works for int

    // string a {"H"};
    // string b {"h"};  // Compiler Error since the arguments (Strings) are not multipliables
                        // concept not satishfied

    auto result = add(a, b);
    cout << "result :: "  << result << endl;
}