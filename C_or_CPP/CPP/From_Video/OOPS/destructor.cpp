/**
 * ** WHen destructors are called ?
 * Destructors are called in weird places that may not be obvious
 * * WHen an object is passed by value to a function
 * * When a local object returned from a function
 * Obvious cases are
 * * WHen a local stack object goes out of scope (dies)
 * * WHen a heap object released with delete
 */

#include <iostream>
using namespace std;


class Cylinder {
    public:
    // int *p = new int;
    int p;
    public:

    Cylinder(int a) {
        p = a;
        cout << "construcor called "  << p <<  "\n";
    }
    ~Cylinder() {
        cout << "Destructor called:  " << p << "\n";
        // delete p;
    }
};

void func(Cylinder obj) {

}

int main() {
    Cylinder c(1);

    func(c);
    cout << "c: " << (c.p) << endl;;
    {
        Cylinder c2(2); // WHen local stack object goes out of scope
    }

    Cylinder *c3 = new Cylinder(3);

    delete c3;
    // Since c1 is not destroyed, object scope is still in

}