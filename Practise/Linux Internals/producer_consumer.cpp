#include <iostream>
#include <thread>
#include <chrono>   
#include <mutex>
#include <condition_variable>
#include <queue>

using namespace std;

queue<int> q;
mutex mtx;
condition_variable cv;

constexpr int MAX_SIZE = 5;

void producer() {
    for (int i=1;i<=10;i++) {
        // jhsfv
        unique_lock<mutex> lock(mtx);

        cv.wait(lock, [] {
            return q.size() < MAX_SIZE;});
        
        q.push(i);
        cout << "Produced: " << i << endl;
        lock.unlock();
        cv.notify_all();

    }
}

void consumer() {
    for (int i=1;i<=10;i++) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []{
            return !q.empty(); });
        

        int item = q.front();
        cout << "Consumed: " << item << endl;
        q.pop();
        lock.unlock();
        cv.notify_all();
    }
}

int main() {
    thread prod(producer);
    // thread cons(consumer);

    prod.join();
    // cons.join();

    return 0;
}