/**
 * Dynamic binding -> virtual function are being used to resolve the problem in Static binding
 * LIkeage between function call and function defination happens at run time
 * virtual function has to be presnet in Base class as well as in child class, to access it with base class member but it will call
 *      child class member
 * 
 * 
 */

#include <iostream>

using namespace std;

class Shape {
    public:
    int x = 5;
    virtual void draw() {
        cout << "Shape drawn\n";
    }
    virtual void find() {
        cout <<"find in Shape\n";
    }
};

class Oval: public Shape {
    public:
    int y = 10;
    virtual void draw() {
        cout << "Oval drawn\n";
    }

     virtual void find() {
        cout << "find in Oval\n";
    }
};

int main() {

    #if 0
    Shape s;
    s.draw();
    // s.find();
    Oval o;
    Shape *ss {&o};
    ss->draw();
    ss->find();
    Shape *p ; // without allocating memory, no use of this
    p->draw();  // FUnction will not get called if memory is not allocated for p

    #else
    Shape s;
    Oval o;
    Shape shapes[] = {s, o};    // base class will be given preference
    for (Shape& ss: shapes) {
        ss.draw();
        // cout << ss.y << endl;
    }

    // What if we store in references: Compiler error
    // Shape &shapes[] = {s, o}; // error

    Shape *ptrs[] = {&s, &o};   // Derived class will be having priority
    for (Shape* sp: ptrs) {
        sp->draw();
        
    }

    // Even with smart pointers also same as pointers

    #endif

}