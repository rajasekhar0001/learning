// Base class destructor should be virtual, 
// The derived class (child) destructor does not need to be explicitly virtual — it becomes virtual automatically.

#include <iostream>
using namespace std;

class A {
    public:
    virtual ~A() { // Base class destructor should be virtual for proper cleanup in case of dynamic binding (Parent points to Child object)
        cout << "A Destructor\n";
    }
};

class B : public A {
    public:
    ~B() {
        cout << "B Destructor\n";
    }
};

int main() {
    // Write C++ code here
    // std::cout << "Try programiz.pro";
    {
        // Static binding
        A *a = new A();
        delete a; // ONly A's destructor called
    }
    cout << endl;
    {
        B *a = new B();
        delete a; // ONly B's destructor called
    }
    cout << endl;
    {
        A *a = new B();
        delete a; // If Base class destructor is virtual, both destructors will be called, first derived then base
        // If base class destructor is not virtual, Only base class destructor will be called, which will cause 
        // MEMORY LEAK
    }

    return 0;
}