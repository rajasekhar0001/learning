
/*
Thread synchronization:
----------------------------------------
    Thread synchronization- It refers to the concept where only one thread is executed 
at a time while other threads are in the waiting state. This process is called thread 
synchronization. It is used because it avoids interference of thread and the problem 
of inconsistency.

---------------------------------------
Few important points to remember for "Thread OR Process Synchronisation" is as follows:
1. Thread Or Process synchronize to access critical section.
2. Critical section is one or collection of program statements which should be executed
   by only one thread or process at a time.

Ex:
*/

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
mutex m;

int count = 0;

void run(int n) {	// whatever is like lock(), and unlock() is thread
                        // synchronization
    m.lock();
    while (n-->0)
        count++;
    m.unlock();
}


int main() {

    thread t1 (run, 50000);
    thread t2 (run, 50000);
 
    t2.join();
    t1.join();
    cout << "Count : "  << count << endl;	
	// count is not same always 
	// both threads trying to increment at the same time
}
