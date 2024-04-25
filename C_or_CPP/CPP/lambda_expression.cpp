/*
Lambda expression: are anonymus function which means function without a name, not reusable
 -> Small piece of code easy to under stand
 -> faster
==>> TO create lambda expression
  we need [cc] (p) {fd}
-> capture closure  -> parameters  -> function defination

Syntax:
    [] ()-> return_type {}
    -> return_type is optional

*/

#include <iostream>
#include <vector>

using namespace std;

 int main() {
    string name="raja";  // locla variable to function
    vector<int> v{1,2 ,3 ,4,5 };
    for_each(v.begin(), v.end(), [](int x, string name){   // [name]  -> not	 modifiable in lambda (or) [&name] -> Modifiable

        cout << "Name: " << name << endl;
        name ="sekhar";
        cout << "Inside lambda"<< endl;
    });
}  // lambda block is executed for all the values in vector
// We need to include "algorithm" header file which has functions like "for_Each()"

/*
Note:  1-> [=] -> all local variables can be accessed but not possible to modify
       2-> [&] -> All local variables can be accessed and also possible to modify


===>   auto   keyword
    -> Based on the value assigned to auto variable, compiler decides the type
      Ex: auto a =10;// must be initialized during declaration

*/

