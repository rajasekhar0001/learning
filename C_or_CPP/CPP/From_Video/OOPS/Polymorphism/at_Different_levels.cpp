/**
 * Inheritance and Polymorphism at different levels
 */

#include <iostream>
using namespace std;

class Parent {
    public:
    virtual void print() {
        cout << "print in Parent\n";
    }

    virtual void show () {
        cout << "show in Parent\n";
    }
};

class Child : public Parent {
    public:

    virtual void print() override {
        cout << "print in Child\n";
    }
    virtual void show () {
        cout << "show in Parent\n";
    }
    // virtual void 
};

int main() {

    Parent p;
    Child c;

    Child *cc = &p;

    cc.print();
    


}