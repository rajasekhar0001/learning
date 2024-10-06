/**
 * Default arguments with virtual functions
 */

#include <iostream>
using namespace std;

class Base {
    public:
    virtual double add (double a= 5, double b = 5) {
        cout << "Add in Base\n";
        return a+b +1;
    }
};

class Derived: public Base {
    public:
    virtual double add (double a= 10, double b = 10) override {
        cout << "Add in Derived\n";
        return a + b + 2;
    }
};

int main() {
    
    Derived d;
    Base b = d; // Raw objects: slicing uses static binding
    cout << b.add() << endl;
    Base &bb = d;
    cout << bb.add() << endl;

    Base *bp = &d;
    cout << bp->add() << endl;
    
}