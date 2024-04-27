#include <iostream>
#include <thread>

using namespace std;

void fun() {
    cout << "inside thread" << endl;
}

int main()
{
  thread t1;
  t1 = thread(fun);  

  t1.join();
  t1 = thread(fun);
  t1.join();
} 
