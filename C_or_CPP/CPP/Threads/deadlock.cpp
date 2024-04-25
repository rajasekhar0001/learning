/**
Deadlock:

     A deadlock is a situation where a set of processes are blocked because
 each process is holding a resource and waiting for another resource acquired
 by some other process. 

Ex:  Two resources R1 and R2
     Two threads T1 and T2
     ===> T1 acquired R1, waiting for R2
     ===> T2 acquired R2, waiting for R1
  -> At the same time, It hapened, none of the threads completes its execution

Ex:
*/

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex m1;
mutex m2;

void thread1() {
    m1.lock();
    this_thread::sleep_for(chrono::seconds(1));
    m2.lock();
    cout << "Inside thread 1\n";
    m1.unlock();
    m2.unlock();
}

void thread2() {
    m2.lock();
    this_thread::sleep_for(chrono::seconds(1));
    m1.lock();
    cout << "Inside thread 2\n";
    m2.unlock();
    m1.unlock();
}

int main() {
    thread t1(thread1);
    thread t2(thread2);

    t1.join();
    t2.join();
}

/*
==>> A process in operating system uses resources in the following way. 
1. Requests a resource 
2. Use the resource 
3. Releases the resource 
*/