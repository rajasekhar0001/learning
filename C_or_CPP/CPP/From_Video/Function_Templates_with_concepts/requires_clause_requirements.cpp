/**
 * requires clause requirements:
 * * Simple requirement
 * * Nested requirement
 * * Compound requirement
 * * Type requirements
 */

#include <iostream>
#include <concepts>

using namespace std;
/*
// Simple requirement 
// It will not enforec anything to fail
template <typename T>
concept Tinysize = requires (T a) {
    sizeof(a) < 4;  // enforces to check syntax
};
*/

/*
// Nested requirement
// Shows error for double since the maximum size of varaible is less than or equal to 4
template <typename T>
concept Tinysize = requires (T a) {
    sizeof(a) < 4;  // enforces to check syntax
    requires sizeof(a) <= 4; // Nested requirement, enforces size to be less than or equal to 4 if not error
};
*/

// Compound requirement
// Workd if it is possible to convert string to int
template <typename T>
concept Addable = requires (T a, T b) {
    // noexcept is optional
    {a + b} -> std::convertible_to<int>; // compound requirement
    // checks if  a+ b is valid syntax, doesn't throw exceptions (optional), and the result is convertible to int (optional)
};


// Tinysize auto add (Tinysize auto a, Tinysize auto b) {
//     return a + b;
// }

Addable auto add(Addable auto a, Addable auto b) {
    return a + b;
}

int main() {
    // char c1 {10};
    // char c2 {20};

    double c1 {10};
    double c2 {2.5};

    // string c1 = "raja";
    // string c2 = "sekhar";   // In this scenario compound requirement fails since string can't be convertible to int

    auto result = add(c1, c2);

    cout << "result : " << result << endl;
    cout << "sizeof(result) : " << sizeof(result) << endl;
}