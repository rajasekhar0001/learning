/**
 * Static binding
 * Based on the object type compiler binds the function defination with function call
 * Base class function is being called which is not good
 * Even Array of objects can be stores in Shape type array with values as derived objects
 */

#include <iostream>

using namespace std;

class Shape {
    public:
    void draw() {
        cout << "Shape drawn\n";
    }
};

class Oval: public Shape {
    public:
    void draw() {
        cout << "Oval drawn\n";
    }
};

int main() {
    Shape s;
    s.draw();
    Oval o;
    Shape *ss {&o};
    ss->draw();

}