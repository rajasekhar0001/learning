#include <iostream>
#include <thread>

using namespace std;

void fun() {
    cout << "inside thread" << endl;
}

int main()
{
  thread t1;
  t1 = thread(fun);// Way to create thread and assigin its task

  t1.join(); // wait for t1, to complete its execution
  thread t2(fun); // other way to create along with initialization
  t2.join();
} 
