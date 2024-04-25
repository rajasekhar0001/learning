/*
Mutex -> Mutual Exclusion ( Accessing something mutualy, first you, then me like )
   	Mutual Exclusion is a property of Process Synchronization that states that
 "no two processes can exist in the critical section at any given point of time".
 means at the same time.

Where we use Mutex?
Race condition: Race condition is a situation where two or more threads/ processes happened
                to change a common/shared data at the same time.
              -> If there is no shared data or variable between thwo or more threads, then there
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

void incr() {
    m.lock();
    count++;    // Critical region
    m.unlock();

    // protected critical region using lock and unlock, there is mutual exclusion b/w these threads
}

int main() {
    cout << "Count : " << count << endl;

    thread t(incr);
    thread t2(incr);
    t.join();
    t2.join();

    cout << "Count : " << count << endl;
}




/*
===>> mutex::try_lock()
   -> it tries to lock the mutex, returns immediately. On successful lock aquisition returns true
      otherwise  returns false
   -> if try_lock() not able to lock mutex. then it does not get blocked that's why it is called 
      non-blocking
   -> If try_lock() is called again by the same thread which owns the mutex, the behaviour is undefined
      It is a dead lock situation with undefined behaviour.  ( look for recursive_mutex() in this case)

ex:
*/

  #include <iostream>
#include <mutex>
#include <thread>
using namespace std;
int c =0;
mutex m;

void incr() {
    for(int i=0;i< 100000;i++) {
        while (m.try_lock() == true) {
            c++;
            m.unlock();
        }
    }
}

int main() {
    thread t1(incr);
    thread t2(incr);
    

    t1.join();
    t2.join();

    cout << "coutn : " << c << endl;
}

/*
==>> std:: try_lock() -> global function (try to lock)
   -> Used to lock multiple mutexes at once

 Syntax:
    std::try_lock(mtx1, mtx2, ..., mtx_n);
  ->> returns -1 if all mutexes acquires lock
  -> returns 0 if any mutex fail to acquire lock, and all other mutexes also releases lock (unlock)
  --> Even if any exception occurs during locking, unlocks whatever acquired, throws exception

Note: 1. try_lock()  tries to lock, it won't wait there until lock acquires, it will do next processes not just like lock()
      2. lock() waits until lock acquires
*/