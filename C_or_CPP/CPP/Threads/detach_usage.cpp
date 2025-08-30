/*
detach()
-> This is used to detach newly created thread from the parent thread (main thread)
-> If we have detached thread and main function is returning then the detached thread
   executon is suspended
-> Always check thread is joinable or not, if you use detach twice it results termination of program
-> Useful for “fire-and-forget” tasks (logging, background monitoring, etc.).
-> But ⚠️ be careful: if the main thread exits before the detached thread finishes, the program may terminate unexpectedly.


Note: OS takes some time to start thread created, it can't start instantly

JOIN vs DETACH:
{
    When you call detach() on a thread, you separate the thread of execution from the thread object (or from parent thread)s

    The detached thread continues running independently, and the thread object is no longer associated with it.

    You cannot join a detached thread; it runs in the background.

    Use detach() when you want the thread to run independently without blocking the main thread.
}


Note: Either join() or detach() should be called on thread object, otherwise during thread object's 
      destructor, it will terminate the program. Because inside destructor it checks if thread is still
      joinable? if yes then it terminates the program.

EX:
*/

#include <iostream>
#include <thread>

using namespace std;

void run(int x) {
    while (x-- > 0)
        cout << x << endl;
    this_thread::sleep_for(chrono::seconds(2));
    // this_thread::sleep_for(chrono::seconds(5));
    cout << "after sleep\n";
}

int main() {

    thread t(run, 5);
    cout << "AFter creating thread\n" <<  endl;
    // t.detach();
    // If you have written 100's of lines here
    // you forgot like whether thread is detached or not you better to do like follwoing
    if(t.joinable())
        t.detach();
    cout << "Main() after join\n";

    // this_thread::sleep_for(chrono::seconds(3));  // use to under stand if it is not here it may suspend thread craeted

    // cout << t.joinable() << endl;
}
