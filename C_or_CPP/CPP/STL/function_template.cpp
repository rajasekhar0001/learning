/**
 * Function Templates
 * To pass the datatype as parameter so we don't need write the same for different data types
 * 
 * ** But here passing the data type is optional in case of function templates
 * Templates are expanded at compile time with actual value just like macros
*/

#include <iostream>
#include <iomanip>

using namespace std;


template <typename T1, typename T2>   // must be used just before function or class in case of templates
T1 mul (T1 num, T2 num2) {
    return num * num2;
}

int main() {
    cout << mul<int, float> (4, 2) << endl;        // By specifying type when calling function

    // setprecision(6);

    cout <<  mul(8.3, 3) << endl;   /// Without specifying type while calling function
}