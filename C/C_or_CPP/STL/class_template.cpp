/**
 * Class Templates
 * -> To pass the data types that we use in class as parameters so we don't need write the same code
 *    for multiple data types
 * -> Mostly it is being used in STLs (application in libraries)
*/

// @ ISO  -> International Organization for Standardization

#include <iostream>
#include <iomanip>

using namespace std;

template <typename T1, typename T2, typename T3>    // must be used just before function or class in case of templates
class Student {
    T1 marks;
    T2 grade;
    T3 *name;
    public:
    Student(T1 m, T2 g, T3 *n) : marks(m), grade(g), name(n) {}

    void display () {
        cout << marks << endl;
        cout << grade << endl;
        cout << name << endl;
    }

};

int main() {

    //
    Student<int, char, char> s(25, 'B', "Raja");
    s.display();

}