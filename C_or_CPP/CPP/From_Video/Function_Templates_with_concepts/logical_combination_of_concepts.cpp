/**
 * using && and ||
 */

#include <iostream>
#include <concepts>

using namespace std;

template <typename T>
concept TinyType = requires (T a) {
    sizeof(T) <= 4; // simple requirement
    requires sizeof(T) <= 4;    // nested requirement
};

/*
template <typename T>
// // requires std::integral<T> || std::floating_point<T> 
requires std::integral<T>  && TinyType<T>
T add (T a, T b) {
    return a + b;
}
*/

/*  OR (we can use this as well)

T add (T a, T b) requires std::integral<T>  &&  TinyType<T> {
    return a + b;
}

*/


// The below way is hard to understand, not recommended
// Better to use the above ways in logical combination of concepts
template <typename T>
T add(T a, T b) requires std::integral<T> && requires (T t) {
    sizeof(T) <= 4;
    requires sizeof(T) <= 4;
} {
    cout << "sum inside : " << a + b << endl;
    return a + b;
}



int main() {

    int a {10};
    int b {20};

    // char a {1};
    // char b {2}; // for result casting required

    // double a {10};
    // double b {20.5};

    // string a {"raja"};
    // string b {"sekhar"};

    auto result = add(a, b);
    cout << "result : " << result << endl;
}