/**
Condition_varible in threads: 
----------------------------------------
Few important points to remember while using "condition variables" are as follows:
--> wait() causes the current thread to block until the condition variable is notified 
 or a spurious wakeup occurs.

-> Condition variables are synchronization primitives used for communication between multiple threads.
   They allow threads to wait for notification from another thread before proceeding.



1. Condition variables allow us to synchronise threads via notifications.
   a. notify_one();
   b. notify_all();
2. You need mutex to use condition variable
3. Condition variable is used to synchronise two or more threads.
4. Best use case of condition variable is Producer/Consumer problem.
5. Condition variables can be used for two purposes:
    a. Notify other threads
    b. Wait for some condition


Thread synchronization:
----------------------------------------
    Thread synchronization- It refers to the concept where only one thread is executed 
at a time while other threads are in the waiting state. This process is called thread 
synchronization. It is used because it avoids interference of thread and the problem 
of inconsistency.

Ex:   
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>


using namespace std;
mutex m;
condition_variable cv;

int balance = 0;
void addMoney(int bal) {
    lock_guard<mutex> lg(m);
    balance += bal;
    cout << "Amount after adding : " << balance << endl;
    cv.notify_one();    // condition varible notify the waiting thread
    // cv.notify_all()  -> notifies the waiting threads
}

bool checkBalance() {
    if (balance < 0)
        return false;
    return true;
}

void withdrawMoney(int money) {
    unique_lock<mutex> ul(m);
    cv.wait(ul, [] {return balance? true : false;});    // first argument in unique_lock object only
    // In the above function second argument can be a function name  ( without paranthesis) or function pointer ( functions with zero arguments)
    // wait (ul) -> can also be used in this way, 	
    // wait() release the mutex which is acquired by the thread 
    // Here current thread goes to sleep mode, it will wake up once notification from  condition_variable is received

    if(balance < money) {
        cout << balance << "  Insufficient funds in Account........\n";
    }
    else
    {
        balance -= money;
        cout << money << "  Rupees ->  withdrawn successfully\n";
        cout << "Remaining balance : " << balance << endl;
    }
}


int main() {
    thread t1(withdrawMoney, 500);
    // this_thread::sleep_for(chrono::seconds(3));
    thread t2 (addMoney, 5000);

    t1.join();
    t2.join();
}