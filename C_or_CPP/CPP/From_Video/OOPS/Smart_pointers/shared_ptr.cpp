/**
 * shared_ptr
 */

#include <iostream>
#include <memory>

using namespace std;

class MyClass {
    public:
    MyClass() {
        cout << "COnstructor\n";
    }
    ~MyClass() {
        cout << "Destructor\n";
    }
};

int main() {
    shared_ptr<MyClass> ptr1 = make_shared<MyClass>();
    cout << "reference count : " << ptr1.use_count() << endl;
    {
        shared_ptr<MyClass> ptr2 = ptr1;
        cout << "reference count : " << ptr1.use_count() << endl; // use ptr1 or ptr2
    }
    cout << "reference count : " << ptr1.use_count() << endl;
}