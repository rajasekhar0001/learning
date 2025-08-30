/**
 * lock_guard:
 * 
 * It is very light weight wrapper for owning mutex on scoped basis
 * It acquires mutex lock whenever you create the object for lock_guard
 * explicitly no need to release (unlock) the mutex, destructor of the lock_guard class releases the 
   mutex when object goes out of scope

 * we can not explicitly unlock the lock_guard
*/


#include <iostream>
#include <thread>
#include <mutex>


using namespace std;
mutex m;

void run(string s) {
    lock_guard<mutex> lock(m);  // way to create locked mutex
    // lock is just a object name here
    for (int i=0;i< 5;i++)
        cout << s << endl;
}


int main() {

    thread t1(run, "thread 1");
    thread t2 (run, "thread 2");
    t1.join();
    t2.join();

}
