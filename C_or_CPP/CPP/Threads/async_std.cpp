/**
@ std::async

@General:
-> Asynchronous execution, on the other hand, involves running tasks concurrently without blocking 
   the main flow of execution.
---->>> Uses only future not promise


/**
 * It runs a function asynchronously (potentially in new thread) and returns std::future that will
   will hold the result.
 * Here we will learn std::async and its usage like how to create task. There are
   three different launch policy for creating task using std::async are as follows:
1. std::launch::async    -> Creates a thread instantly in the line where this launch is used 
2. std::launch::deffered   -> Uses main thread and calls the function when future requests a value
3. std::launch::async | std::launch::deffered

With the help of above policies std::async decides to create task as asynchronous or synchronous. 
*/


#include <iostream>
#include <thread>
#include <future>

using namespace std;


unsigned long int  run(unsigned long int s, unsigned long int e){ 
    cout << "Thread ID in run : " << this_thread::get_id() << endl;
    int sum = 0;
    for (unsigned long int i=0;i<e;i++) {
        sum += i;
    }
    return sum;
}

int main() {
    std::future<unsigned long int> fut = async(launch::deferred | launch::async, run, 0 , 9999999999);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               async(std::launch::deferred, run, 0, 99999999);  // future to be implemented when promise sets something
    /**
     * std::launch::deferred -> thread is not created, function gets called when fut.get()  executed -> synchronus
                     -> works like normal function call
     * std::launch::async -> thread is creatd instantly  -> asynchronous
     * check thread ID's for understanding
     * 
     * std::launch::async | std::launch::deferred  -> It is similar to async, when not specified clearly
    */
   
    cout << "Thread ID in main : " << this_thread::get_id() << endl;
    cout << "waiting .............\n";

    // wait for result
    // cout << "Result :  " << fut.get() << endl; // Here fut.get() calls run(), waits for return value in case of deferred launch

    cout << "completed........\n";

    
}


