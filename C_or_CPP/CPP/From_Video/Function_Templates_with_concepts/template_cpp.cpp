/**
 * FUNction template
 */

#include <iostream>
using namespace std;

// template <typename T1, typename T2>   -> Just to keep in mind for multiple arguments

template <typename T>
T maximum(T a, T b) {
    return a>b? a : b;
}

int main() {
    auto ret = maximum("raja", "sekhar");
    cout << "max : " << ret << endl;
    double ret1 = maximum<double> (6.5, 7.2);

    cout << "ret1 : " << ret1 << endl;

    int a = 10;
    int b = 20;

    auto ret3 = maximum(&a, &b);    // operation performed on address
    cout << "ret3 (template [assing by reference]) : " << ret3 << endl;
}
 
