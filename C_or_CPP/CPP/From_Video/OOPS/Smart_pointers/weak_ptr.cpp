/**
 * weak_ptr
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
    shared_ptr<MyClass> sharedPtr = std::make_shared<MyClass>();
    weak_ptr<MyClass> weakPtr = sharedPtr; // creates weak_ptr, but reference count will not increase

    cout << "sharedPtr count: " << sharedPtr.use_count() << endl; // 1

    if (sharedPtr == weakPtr.lock()) 
        cout << "Object is still alive\n";
    else    
        cout << "Object has been sedtroyed\n";

}