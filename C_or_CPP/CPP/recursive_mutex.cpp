/*
Recursive_mutex:
// mutex can be locked multiple times with the same thread (extra feature in this)

Ex:
*/

/**
 * recursive_mutex
 * -->> IS is like mutex only, before unlocking the mutex, it is possible to lock mutex any number times
 *     at the end, it is nesessary too unlock the thread that many number of times
 * if not unlocked, other thread can't acquire mutex using that mutex
*/

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
int sum = 0;
recursive_mutex m;

void run(int n) {
    if (n < 1) {
        return ;    // recursive function cal ends when this condition is true
    }
    m.lock();       //Acquiring lock
    sum = sum  + n;
    
    run(n-1);       // recursive function call
    m.unlock();     // should happen same number of times as lock()
    
}


void run_with_loop(int n) {
    int sum =0;
    for (int i=0;i< n ;i++) {
        m.lock();		// locking multiple times
        sum += i;
    }
    cout << "Sum = : " << sum << endl;
    for (int i=0;i<n;i++)
        m.unlock();		// unlocking multiple times 
}


int main() {
    thread t1(run, 9);
    cout << "sum : " << sum  << endl;

    t1.join();

    cout << "sum : " << sum << endl;
}