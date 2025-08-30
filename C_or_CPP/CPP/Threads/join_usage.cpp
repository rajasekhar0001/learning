/*
join() 

-> Once a thread is created we wait for that thread to finish its job 
-> (double join)  calling join() on same thread twice may result termination of program
-> In the above situation, its better to check whether the thread already joined or not by usig
   "joinable()" method.

Ex:
*/

#include <iostream>
#include <thread>

using namespace std;

void run(int x) {
    while (x-- > 0)
        cout << x << endl;

    this_thread::sleep_for(chrono::seconds(1));  // this is to keep thread in sleep mode
}

int main() {
    thread t(run, 5); // THread creation with task assignment with arguments
    cout << "AFter creating thread\n";
    t.join();
    // If you have written 100's of lines here
    // you forgot like whether thread is joined or not you better to do like follwoing
    if(t.joinable()) {
        t.join();
        cout << "Thread is joinable\n";
    }
    else {
        cout << "Thread is not joinable, because already joined\n";
    }
    cout << "Main() after join\n";
}