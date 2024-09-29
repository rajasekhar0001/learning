/**
 * Creating custom concept without using buikt int concept
 */

#include <iostream>
#include <concepts>

using namespace std;

// crating custom concept
template <typename T>
concept Incrementable = requires (T a) {
    a++; // Just make sure that argument incrementable
    // Actually will not increment the actual variable, just it will check
};

// Creating the function template using custom concept
template <typename T>
requires Incrementable<T>    // the arguments should suppose to be multipliable
T add (T a, T b) {
    return  a+ b;
}

int main() {
    double a {10.0};
    double b {11.2};    // works for double

    // int a {10};
    // int b {11}; // works for int

    // string a {"H"};
    // string b {"h"};  // Compiler Error since the arguments (Strings) are not Incrementable
                        // concept not satishfied

    auto result = add(a, b);
    cout << "result :: "  << result << endl;
}