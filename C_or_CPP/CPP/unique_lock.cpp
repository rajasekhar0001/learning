/*
unique_lock: 

1. The class unique_lock is a mutex ownership wrapper.
2. It Allows:
    a. Can Have Different Locking Strategies
    b. time-constrained attempts at locking (try_lock_for, try_lock_until)
    c. recursive locking
    d. transfer of lock ownership (move not copy)
    e. condition variables. )

Locking Strategies
   TYPE           EFFECTS(S)
1. defer_lock  does not acquire ownership of the mutex and assumes that the calling thread is going to call lock to acquire the mutex.
2. try_to_lock  try to acquire ownership of the mutex without blocking.
3. adopt_lock  assume the calling thread already has ownership of the mutex.

Ex:
*/

/**
 * Features
 * 1. defer_lock
 * 2. try_to_lock
 * 3. adopt_lock
*/

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
mutex m;

void run(string s) {
    unique_lock<mutex> lock(m, defer_lock);  // does not call lock, just like informing
    // Whenever it needs to be locked it can lock()
    lock.lock();    // Other classes like lock_guard is not having this feature
    
    // lock is just a object name here  
    for (int i=0;i < 5; i++)
        cout << s << endl;
}

int main() {

    thread t1(run, "thread 1");
    thread t2 (run, "thread 2");
    t1.join();
    t2.join();

}

