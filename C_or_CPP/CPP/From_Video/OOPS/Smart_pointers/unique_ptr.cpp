/**
 * unique_ptr
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
    unique_ptr<MyClass> ptr1 = std::make_unique<MyClass>();
    unique_ptr<MyClass> ptr2 = std::move(ptr1);
    if (!ptr1)
        cout << "ptr1 is null\n"; // since ownership is moved
}