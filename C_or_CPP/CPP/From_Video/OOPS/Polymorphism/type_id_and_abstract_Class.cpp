/**
 * 
 */

#include <iostream>

using namespace std;

class A {
    public:
    int m_val;
    virtual void run() = 0; // typeid works  orrectly in polymorphism if base class having atleast one virtual function

};

class B : public A {
    public:
    int x;
    virtual void run() {
        cout << "Hello\n";
    }
};

class XXX  {

};

int main() {

    A *a = new B();
    A *a2 = new B();
    cout << typeid(a).name() << endl;
    cout << typeid(*a).name() << endl;

    cout << typeid(a2).name() << endl;
    cout << typeid(*a2).name() << endl;

    XXX b;
    cout << typeid(b).name() << endl;
    // cout << typeid(*a2).name() << endl;
    XXX *x = NULL;
    typeid(*x);

}