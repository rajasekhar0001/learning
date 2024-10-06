/**
 * dynamic_cast
 * if cast fails, it returns nullptr
 */

#include <iostream>
using namespace std;

class A {
    public:
    virtual void show() {
        cout << "A show\n";
    }
};

class B : public A {
    public:
    virtual void show() {
        cout << "B show\n";
    }
};

class C: public B {
    public:
    virtual void show() {
        cout << "C show\n";
    }
};

int main() {
    A *a = new B();
    // a->show();
    B *b = dynamic_cast<B*> (a);
    if (b) {
        b->show();
    }
    else
    {
        cout << "Failed to cast\n";
    }
    C *c = dynamic_cast<C*>(a);
    if (c) {
        c->show();
    }
    else {
        cout << "Couldn't do transfomation from A* pointer to C* pointer \n";
    }

    // References
    B bb;
    A &a_ref = bb;
    // reference in ptr
    B *b_ptr = dynamic_cast<B*> (&a_ref);
    if (b_ptr) {
        b_ptr->show();
    }
    // ref in ref
    B &b_ref2 = dynamic_cast<B&> (a_ref);
    b_ref2.show();

}