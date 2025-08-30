/*
Mutex -> Mutual Exclusion (Accessing something mutualy, first you, then me like )
   	Mutual Exclusion is a property of Process Synchronization that states that
 "no two processes can exist in the critical section at any given point of time".
 means at the same time.

Where we use Mutex?
Race condition: Race condition is a situation where two or more threads/processes happened
                to change a common/shared data at the same time.
              -> If there is no shared data or variable between two or more threads, then there
                 is no RACE condition
              -> If there is a race condition, then we have to protect it and the protected section
                 is called critical section/region.


-> Mutex is used to avoid race condition
-> we will use lock(), unlock() on mutex to avoid race condition

Ex:
*/

#include <iostream>
#include <mutex>
#include <thread>

using namespace std;
int count = 0;
mutex m;

// Run by commenting mutex which causes Race condition
// apply mutex, it works as expected
void incr(int times) {
    m.lock();
    for (int i=0;i<times;i++) {
      count++;    // Critical region
    }
    m.unlock();
    // protected critical region using lock and unlock, there is mutual exclusion b/w these threads
}

int main() {
    cout << "Count : " << count << endl;

    thread t(incr, 100000); // Big number required, else diffcult to show Race condition
    thread t2(incr, 300000);
    t.join();
    t2.join();

    cout << "Count : " << count << endl; // Expected count : 400000
}
