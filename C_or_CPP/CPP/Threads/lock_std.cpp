/*
std::lock(m1, m2, ...)
-> lock multiple threads at a time
-> If not able to lock atleast one thread it will release all the threads

mutex::lock(m)
-> lock the thread if not returns false (i.e. 0)

Ex: for dead lock and std::lock()
*/

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int count = 0;
mutex m1, m2, m3, m4;
// int count =0 ;

void run () {
    lock(m1, m2);
    this_thread::sleep_for(chrono::seconds(1));
    cout << "INside run\n";
    lock(m3, m4);
    cout << "Locked all Mutexes in Thread- " << count++  << " \n";
    m1.unlock();
    m2.unlock();
    m3.unlock();
    m4.unlock();
}

void run2 () {
    lock(m3, m4);
    cout << "INside run2\n";
    lock(m1, m2);
    cout << "Locked all mutexex in thread 2 \n";
    m1.unlock();
    m2.unlock();
    m3.unlock();
    m4.unlock();
}


int main() {

    thread t1 (run);
    thread t2 (run2);
 
    t2.join();
    t1.join();
    cout << "Count : "  << count << endl;

}