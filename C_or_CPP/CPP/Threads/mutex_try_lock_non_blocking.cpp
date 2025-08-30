/*
===>> mutex::try_lock()
   -> it tries to lock the mutex, returns immediately. On successful lock aquisition returns true
      otherwise returns false
   -> if try_lock() not able to lock mutex. then it does not get blocked that's why it is called 
      non-blocking
   -> If try_lock() is called again by the same thread which owns the mutex, the behaviour is undefined
      It is a dead lock situation with undefined behaviour.  ( look for recursive_mutex() in this case)
*/

  #include <iostream>
#include <mutex>
#include <thread>
using namespace std;
int c =0;
mutex m;

void incr() {
    for(int i=0;i< 100000;i++) {
        if (m.try_lock() == true) {
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

    cout << "cout : " << c << endl;// Expected: 200000
}

/*
==>> std::try_lock() -> global function (try to lock)
   -> Used to lock multiple mutexes at once

 Syntax:
    std::try_lock(mtx1, mtx2, ..., mtx_n);
  ->> returns -1 if all mutexes acquires lock
  ->> returns 0 if any mutex fail to acquire lock, and all other mutexes also releases lock (unlock)
  --> Even if any exception occurs during locking, unlocks whatever acquired, throws exception
  --> If it fails to lock all, it unlocks any it did acquire, and returns the index of the mutex it couldn’t lock, else returns -1.

  std::try_lock(m1, m2, ...) // helps to avoid deadlock, in case of multiple threads require same set of multple mutex locks.

Note: 1. try_lock()  tries to lock, it won't wait there until lock acquires, it will do next processes not just like lock()
      2. lock() waits until lock acquires

*/