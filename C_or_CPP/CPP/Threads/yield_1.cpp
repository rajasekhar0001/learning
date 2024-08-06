/**
 * std::this_thread::yield() -> In multi threaded applications if we yield just before acquiring the mutex,
   the current thread allows the high priority threads to get CPU time rather than the low priority task continuously
   trying to acquire the mutex.
 */

#include <iostream>
#include <mutex>
#include <thread>
#include <unistd.h>

using namespace std;

mutex m;

void fun1() {
    this_thread::yield();
    unique_lock<mutex> lck(m);
    cout << "First thread\n";
    sleep(1); 
}

void fun2() {
    unique_lock<mutex> lck(m);
    cout << "Second thread\n";
}

int main() {
    thread t1(fun1);
    thread t2(fun2);

    t1.join();
    t2.join();
}