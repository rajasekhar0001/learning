/*
Promise and Future:

-> These are like signals between threads, ex: if one thread expects something that 
   other thread has to do and waiting for response.

Ex:

*/

/**
 * we will learn about how std::promise and std::future and how they work together to synchronise threads.
 
 * Basically std::promise is sent to the called thread and once the value is ready we set that value in 
   promise object, now at calling thread side we get that value using std::future object which was created 
   using std::promise object before sending it to the called thread. And this is how we receive value 
   from one thread to another in synchronisation.
*/

/**
 * 🔹 Why future and promise exist
        Mutexes / locks / condition variables → help with shared state synchronization.
        But sometimes you don’t want to share state — you just want to pass a result from one thread to another safely.
        That’s where std::future and std::promise come in:

        std::promise → a thread sets a value (or exception).
        std::future → another thread retrieves that value, blocking until it’s ready.

        They are essentially safe communication channels between threads.

 *  ✅ Summary
        Condition variable version: Verbose, lower-level, flexible.
        Promise/Future version: Cleaner, less code, automatic synchronization.
        Async version: Easiest — just fire and forget, wait for result.
 */

#include <iostream>
#include <thread>
#include <future>

using namespace std;


void run(promise<unsigned long int> pro, unsigned long int s, unsigned long int e){ 
    int sum = 0;
    // this_thread::sleep_for(chrono::seconds(2));
    cout << "Thread id inside thread function: " <<  this_thread::get_id() << endl;
    for (unsigned long int i=0;i<e;i++) {
        sum += i;
    }
    pro.set_value(sum);     // until it sets the value feature can't expect the response
}

int main() {

    std::promise<unsigned long int> pro;    // promise
    std::future<unsigned long int> fut = pro.get_future();  // future to be implemented when promise sets something

    cout << "Thread created ssuccessfully\n";
    
    thread t1(run, move(pro), 0, 999999999);
    /**
     * there are 2 ways to pass promise object to thread
     * 1. move() -> Transferring the ownership of "pro" (promise) to thread which it is no longer belong to main thread
     * 2. shared_ptr<> -> If we want to keep alive promise object in parennt thread -> explore this if needed
    */

    cout << "waiting .............\n";
    cout << "main thread id : " << std::this_thread::get_id() << endl;
    //. wait for result
    cout << "Result :  " << fut.get() << endl;  // waits here until promise sets the value

    t1.join();  // wait for thread to complete its execution

    cout << "completed........\n";
}