/**
 * Types of initializaton
 * * Braced initialization
 * * Functional initialization
 * * Initialization using assignment operator (also called copy initilization)
 */

#include <iostream>

using namespace std;

int main() {
    int braced {2}; // braced initialization
    int functional(3);  // functional initialization
    int assign = 5; // intilization using assignment (also called copy initilization)
    cout << braced << "  " << functional << "  " << assign << endl;

    int x (braced + functional);
    int y {braced + x};

    cout << x << "  " << y << endl;

    // int z {4.5}; //-> error because it prevents accidental narrowing conversions

    // int x (4.5); //-> works, does not prevent narrowing conversions

    // int x =4.5; // Does not prevent narrowing conversions, 
                   // Right hand side value is being assigned to left hand varaible

    cout << "z : " << sizeof(float) << endl;

}