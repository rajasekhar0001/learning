/**
 * Object slicing
 */

#include <iostream>

using namespace std;

class Shape {
    public:
    double x = 5;
    virtual void draw() {
        cout << "Shape drawn\n";
    }
};

class Oval: public Shape {
    public:
    int y = 10.6;
    virtual void draw() {
        cout << "Oval drawn\n";
    }
};

class Circle : public Oval {
    public:
    int x;
    int y;
    //
};

int main() {

    Oval o;
    Shape s;    // object slicing happened since object by value assigned
    Shape ss = o;
    Circle c;
    s.draw(); // calls Shape::draw()
    // cout << s.y << endl; // not possible to access data any way
    cout << "sizeof o: " << sizeof(o) << endl;
    cout << "sizeof s: " << sizeof(s) << endl;
    cout << "sizeof ss: " << sizeof(ss) << endl;

    cout << "sizeof of c: " << sizeof(c) << endl;
    // 

    

    

}