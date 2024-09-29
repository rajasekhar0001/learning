/**
 * capture by value -> can't be changed inside lambda function, it's like constant
 * * having acopy of variable
 * Capture by reference -> can be changed inside lambda function
 * * having the reference of the vsame variable
 */

#include <iostream>

using namespace std;

int main() {
    
    #if 0
    // capture by value  -> can't be changed insied lambda function
    int a {10};

    auto func = [a](){
        cout << "Inside : " << a  << "  address: " << &a << endl;
    };
    a++;
    cout << "Outside : " << a  << "  address: " << &a << endl;

    func();

    #elif 0
    // captyre by reference -> can be changed inside lambda function
    int a {10};

        auto func = [&a](){
            a++;
            cout << "Inside : " << a  << "  address: " << &a << endl;
        };
        
        cout << "outside : " << a << "  address: " << &a << endl;
        func();
        cout << "outside : " << a << "  address: " << &a << endl;

    #elif 0
    // capture all by value
    // mention '=' in capture list
    int a{10};
    int b{20};
    
    auto func = [=]() {
        cout << "Inside sum : " << a + b << endl;
    };
    cout << "ouside sum : " << a+ b << endl;
    func();

    #elif 1
    int a{10};
    int b{20};
    
    auto func = [&]() {
        a++; b++;
        cout << "Inside sum : " << a + b << endl;
    };
    a++; b++;
    cout << "ouside sum : " << a+ b << endl;
    func();
    cout << "Inside sum: " << a+ b << endl;
    #endif
}