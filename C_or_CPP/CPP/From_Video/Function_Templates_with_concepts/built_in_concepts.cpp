/**
 * FUnction templates using built in cconcepts
 * Compile with -std=c++20
 */

#include <iostream>
#include <concepts>

using namespace std;

// Sntax-1
/*
template <typename T>
requires std::integral<T>   // double will not work
T add (T a, T b) {
    return a + b;
}
*/

// Sntax-1 using type traits
/*]
template <typename T>
requires std::is_integral_v<T>   // double will not work
T add (T a, T b) {
    return a + b;
}
*/

// Syntax-2
/*
template <std::integral T>  // double will not work
T add (T a, T b) {
    return a + b;
}
*/

// Syntax - 3
/*
auto add (std::integral auto a, std::integral auto b) { // double will not work
    return a + b;
}
*/

// SYntax - 4
template <typename T>  // double will not work
T add (T a, T b) requires std::integral<T> {
    return a + b;
}

int main() {
    char c1{10};
    char c2 {20};
    auto result_1 = add(c1, c2);
    cout << "result_1 : " << static_cast<int>(result_1) << endl;

    int i1 {1};
    int i2 {2};
    int result_2 = add(i1, i2);
    cout << "result_2 : " << result_2 << endl;

    double d1 {11.2};
    double d2 {1.8};
    auto result_3 = add(d1, d2);
    cout << "result_3 : " << result_3 << endl;  
}