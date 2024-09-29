/**
 * TEMPLATE SPECIALIZATION since the default template won't work for c-style char*
 * If there is need to compare C-style string with template
 * There will be issue in using that, since C-strings can't be compared with operators
 * REquires function like strcmp
 */

#include <iostream>
#include <cstring> // for strcmp()

using namespace std;

template<typename T> 
T maximum(T a, T b) {
    return (a>b)? a : b;
}


// Below template to specifically handles the template if the type is char*
// Incase of const char * use the same 
// using below syntax
template<> 
char* maximum (char* a, char* b) {
    return strcmp(a, b) > 0? a :  b;
} 

int main() {
    char *s1 {"hello"};
    char *s2 {"abcd"};
    // The prolem here is the operation inside template considering the pointer address instead of characters
    // Based on address reurning the pointer to array of characters
    cout << maximum(s1, s2) << endl; // way to durecly use template
    cout << maximum<char*> (s2, s1) << endl; // explicitly specifying the type
}