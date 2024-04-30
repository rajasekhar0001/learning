/*
timed mutex:
-> Creating a thread in which after it is acquiring mutex, it waits until the time 
   mentioned in the try_mutex_lock(time in seconds) after that it unlocks the mutex
Ex:
*/

// std::timed_mutex
/**
 * lock()
 * try_lock()
 * try__lock_for()   ----
 * try_lock_until()  ---- These two functions makes timed_mutex different from mutex
 * unlock()
*/

/** try_lock_for()
 * waits until specified time_out_duration elapsed or lock acquired, which ever comes first.
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;
timed_mutex m;

int myCount = 0;
void run(int i ) {
    if (m.try_lock_for(std::chrono::seconds(3))) {
        myCount++;
        cout << "Thrad " << i << " called\n";
        std::this_thread::sleep_for(chrono::seconds(2));
        cout << "Before unlocking the mutex\n";
        m.unlock();
    }
    else {
        cout << "Fail to acquire the mutex for the thread " << i << "\n";
    }   
}

int main() {
    thread t1(run, 1);
    thread t2(run, 2);

    t1.join();
    t2.join();
   
    cout << "count  :  " << myCount << endl;
    

}