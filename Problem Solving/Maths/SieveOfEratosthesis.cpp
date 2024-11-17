/**
 * Siee if Eratosthesis
 * * alogorithm used to identify prime number from 1 to N 
 * * We use an atrray of size n with vaues as 1 // which means prime
 * * we keep checking element from 1 to N, if arr[i] == 1, then will make all array indeices multiple of i and greater than i as zero (0)
 */
#include <bits/stdc++.h>
using namespace std;

int countPrimes(int n) {
    vector<int> primes(n, 1);
    // for (int i=2;i<n;i++) {
    //     if (primes[i] == 1) {
    //         for (int j=i*2;j < n;j = j+i) {
    //             primes[j] = 0;
    //         }
    //     }
    // }

    for (int i=2;i*i<=n;i++) {
        if (primes[i] == 1) {
            for (int j=i*i;j < n;j = j+i) {
                primes[j] = 0;
            }
        }
    }

    int count = 0;
    for (int i=2;i<n;i++) {
        if (primes[i] == 1) 
            count++;
    }
    return count;
}

int main() {
    cout << countPrimes(10) << endl;
}