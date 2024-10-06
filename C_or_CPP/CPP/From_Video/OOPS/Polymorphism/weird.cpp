/**
 * Weird
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
    
    Base *d = new Derived;
    cout << d->add() << endl ;
    
}