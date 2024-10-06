/**
 * Virtual destructor
 * Order destructor called
 * * C -> B -> A
 */

#include <iostream>
using namespace std;

class A {
    public:
    virtual ~A() {
        cout << "A destructor\n";
    }
};

class B : public A {
    public:
    ~B() {
        cout << "B destructir called\n";

    }
};

class C: public B {
    public:
    ~C() {
        cout << "C destructor\n";
    }
};

int main() {
    A *obj = new C;
    delete obj;
}