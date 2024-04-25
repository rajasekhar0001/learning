/*
1) Creational Design pattern:   ( Focusses on object creation)

	Creational design patterns are a subset of design patterns in software development. 
They deal with the process of object creation, trying to make it more flexible and efficient. 
It makes the system independent and how its objects are created, composed, and represented.

   a) Singleton design pattern 
   b) Factory method design pattern, etc


Ex: for a)
*/

#include <iostream>
using namespace std;

class Singleton {

    protected:
    Singleton(int d) {
        cout << "Constructor called" << endl;
        a = d;
    }
    public:
    int a;

    static Singleton& get_instance(int d) {     // creates the single instance
        // return the same instance, when ever we try to create object
        static Singleton obj(d);            
        return obj;
    }
    Singleton(const Singleton& obj) = delete;   // disables the copy constructor
    ~Singleton()
    {
        cout << "Destructor called" << endl;
    }
};

int main() {
    Singleton &obj = Singleton::get_instance(2);
    Singleton &obj2= Singleton::get_instance(2);
    cout << obj.a << endl;
    obj.a = 20;
      cout << obj.a << endl;
    cout << obj2.a << endl;

    //  Singleton obj3 = obj;
    // system("pause");
}
