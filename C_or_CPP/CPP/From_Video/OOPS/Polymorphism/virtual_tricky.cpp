/**
 * Calling virtual functions inside constructor or destructor
 * WHich is not preferred
 * 
 * because which gives static biding behaviour
 */

#include <iostream>
using namespace std;

class A {
    public:
    int m_val;  // To understand constructor way
    A() {
        // m_al = 10;
        print();
    }

    virtual void print() {
        m_val = 10;
    }
};

class B : public A {
    public:
    B() {
    }
    virtual void print() {
        m_val = 100;
    }
};


int main() {
    A *obj = new B;
    cout << obj->m_val << endl;
}

