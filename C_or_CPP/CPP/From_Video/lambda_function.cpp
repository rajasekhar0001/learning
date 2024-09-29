/**
 * Lambda function signature
 * 
 *                  [capture list] (parameters) -> return type {
 *                      // function body;
 *                  };
 */

#include <iostream>

using namespace std;

int main() {
    #if 0
    // lambda funcrtion declaration / defination
    // Which actually won't print anything since not called
    []() {
        cout << "Hllo Raja\n";
    };
    #elif 0
    // lambda function defination with function call
    // Declare a lambda function and call it directly
    // Function gets executed
    []() {
        cout << "Hllo Raja\n";
    }();

    #elif 0
    // Declaring a lambda function with name and calling with name
    // Calling lambda function twice with name
    auto func = []() {
        cout << "Hllo Raja\n";
    };
    func();
    func();
    cout << "Done\n";

    #elif 0
    // lambda function declration with direct call
    // Lambda function with parameters
    [](int a, int b) {
        cout << "a+ b = " << a+ b << endl;
    }(5, 6);

    #elif 0
    // lambda function declration  with name
    // Lambda function with parameters and with name
    auto sum = [](int a, int b) {
        cout << "a+ b = " << a+ b << endl;
    };

    sum(1, 2);
    sum(3, 4);

    #elif 0
    // Lambda function with retun value
    // return value is stored in sum, can't be called function mjltiple times
    // since function with direct call with arguments
    auto sum = [](int a, int b) {
        return a + b;
    }(5, 6);

    cout << " sum : " << sum << endl;

    #elif 0
    // Lambda function with retun value
    // function with name and can be called multiple times
    auto sum = [](int a, int b) {
        return a + b;
    };

    cout << "sum : " << sum(1,2) << endl;
    cout << "sum : " << sum(3, 4) << endl;

    // dircectly using lambda function in cout
    cout << "sum : " << [](int a, int b) {
        return a + b;
    }(4, 5) << endl;

    #elif 1
    // function with name
    // explicitly specifying return type
    auto sum = [](int a, int b) -> int{
        return a + b;
    };
    // expilicitly speccifyng return type
    auto sum1 = [](int a, int b) -> double {
        return a + b;
    };
    cout << " sum : " << sum(1, 2) << endl;

    cout << "sum from int to double: " << sum1(2, 3) << endl;
    auto a = 11.0;
    cout << "suto var: " << a << endl;

    #endif
}