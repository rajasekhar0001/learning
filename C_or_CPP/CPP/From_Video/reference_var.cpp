/**
 * reference variable declaration must happen with intialization
 * reference can't refere to some other value
 * reference varible references to the same location fo the variable
 * Don't use dereference to read/ write
 * refrence is like const, can't be used to reference with other
 */

/** const reference
 * const refernce: const is appiles to reference variable name not on value
 * Original variable value can be changed which will change reference value  BUT
 * * reference varible can't be used to change valiue
 */
#include <iostream>
using namespace std;

int main() {
    int var {5};
    #if 0
    // Reference declaration without initialization not allowed
    int& reference_to_var;
    #elif 0
    // refernce must be assigned with some variable  not with value (ERROR)
    int &reference_to_var {10};

    #elif 0
    
    int &referennce_to_val (var);
    cout << "var : " << var << "  and address: " << &var << endl;
    cout << "reference: " << referennce_to_val  << "   and address: " << &referennce_to_val << endl;

    // change reference value
    referennce_to_val = 100;
    cout << "var  after chnging refrence variabe: "<< referennce_to_val <<  endl;
    
    #elif 0
    // assigning dome other refrence
    int &ref = var;
    int val2 = 2;
    ref = val2;

    #elif 0
    int *const ptr = &var;    // pointer references to var
    int &ref = var;     // refrence references to var

    int var2 = 5;

    // ptr = &var2; // not allowed since ptr is constant pointer

    ref = var2;  // means changeing refrence vaule not changing the reference to point to some other reference

    // &ref = var2;  // refernce can't refer some other value but can be assigned with different values

    #elif 1
    // const value refrence
    int a= 10;

    const int & ref = a;

    a = 20;     // a can be used to change value, reference also updates

    // ref  = 30;  // ref can't be used to change value

    cout << "ref : " << ref << endl;


    #endif
}