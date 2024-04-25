/*
WHat is functor in C++? 
-> It works as a function and achieved by overloading "operator ()" in some class

Ex:
*/

#include <iostream>
using namespace std;

int count = 0;
class Funct {
    public:
    int _val;

    Funct() {}

    Funct(int v): _val(v) {
            count++;
    }
    int operator () (int x ) {		// overloaded opertor "()"
        return x * _val;
    }
};

int main() {
    Funct  obj(10);		//  instance created
    cout << obj._val << endl;	// 10
    cout << obj(2) << endl;	// 10*2 => 20

    cout << obj(3) << endl;     // 10 * 3 => 30

    cout << count << endl;	// 1  (one instance of object created, remaining times multiplication happened) 

}