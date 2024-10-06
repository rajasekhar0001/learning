/**
 * override
 * * Practise
 */

#include <iostream>
using namespace std;

class Parent {
    public:
    virtual void print() {
        cout << "print in Parent\n";
    }
};

class Child : public Parent {
    public:
    // virtual void prinT() override {
    //     cout << "print in Child\n";
    // }

     virtual void print() override {
        cout << "print in Child\n";
    }


};

int main() {

    Parent p;
    Child c;
    Parent &pp = c;
    c.print();
    p.print();
    pp.print();


}