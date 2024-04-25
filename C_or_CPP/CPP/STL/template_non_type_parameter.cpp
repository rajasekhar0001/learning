// non null paramter must be constant experssion, because it is being evaluated at compile time

#include <iostream>
#include <cstring>

using namespace std;

template <typename T, int size>   // here size is received as template argument
class Arr {
    T name;
    static int arr[size];     // size is non type parameter
    public:
    Arr(T n) {
        name = n;
    }
    void display() {
        cout << "name : " << name << endl;
        cout << sizeof(arr)/ sizeof(T) << endl;
    }
};

int main() { 
    Arr<string, 10> obj("Raja");
    obj.display();
   
}