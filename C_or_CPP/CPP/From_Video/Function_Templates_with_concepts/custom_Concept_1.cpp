/**
 * Creating custom concept on built in concept (using type trait)
 */

#include <iostream>
#include <concepts>

using namespace std;

// crating custom concept
template <typename T>
concept MyIntegrable = std::is_integral_v<T>;

// Creating the function template using custom concpt
template <typename T>
requires MyIntegrable<T>
T add (T a, T b) {
    return  a+ b;
}

int main() {
    // double a {10.0};
    // double b {11.2};

    int a {10};
    int b {11};
    auto result = add(a, b);
    cout << "result :: "  << result << endl;
}