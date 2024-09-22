// -> use cmath header file like below
//     #include <cmath>

// -> log in base e
//     std::log(number);
// -> log with base 10
//     std::log10(number);

// -> std::floor(num) -> rounded to backward
// -> std::ceil(num) -> rounded to forward
// -> std::round(num) -> less than .5 => works like floor
//                        greater than or equal to .5 -> works like ceil

#include <iostream>
#include <cmath>

using namespace std;
int main() {

    cout << "floor of 3.5: "<< floor(3.5) << endl;

    cout << "ceil or 3.5 : "<< ceil(3.5) << endl;

    cout << "round of 3.4: " << round(3.4) << endl;

    cout << "round or 3.5 or more: " << round(3.5) << endl;
}