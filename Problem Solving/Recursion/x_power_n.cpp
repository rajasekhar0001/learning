/**
 * Since pow() Standard Library function, which returns ong double 
 * Which will not work as expected for long long types (large ineger values)
 * 
 * 
 * The result of power might overflow, To avoid that, power is calculated under the modulo of some large value like 10^9+7, etc.
 * 
 * The method used to compute here is
 * * Modulo Arithmetic or Modulo Exponentiation  => like val % M
 * 
 * Solution Ex: 2^10 =>  (2*2)^5  => 4 * (4)^4 => 4 * (4*4)^2  => 4 * (16 * 16)^1  => 1024.
 */
#include <iostream>

using namespace std;

long long power(int x, int n) {
    static long long result = 1;    // or use it as an argument
    if (n < 1) {
        return result;
    }

    if (n & 1) {
        result *= x;
        n -= 1;
    }
    else {
        x *= x;
        n /= 2;
    }
    // cout << "x : " << x << endl;
    // cout << "result: " << result << endl << endl;;
    power(x, n);
    return result;
}

int main() {
    int x = 2;
    int n = 10;
    cout << power(x, n) << endl;
}