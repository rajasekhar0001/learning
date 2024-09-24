#include <iostream>

using namespace std;

int main() {
    #if 0
    // using junk address
    int *ptr;
    cout << "Before assigning to a junk address" << endl;
    *ptr = 20;  // causing segmentation fault
    cout << "*ptr : " << *ptr << endl;
    #endif

    #if 0
    // using a pointer pointing nowhere
    int *ptr {};
    cout << "Before assigning to a junk address" << endl;
    *ptr = 20;  // causing segmentation fault
    cout << "*ptr : " << *ptr << endl;
    #endif

    #if 0
    //  correct way to use
    int *ptr = NULL;
    ptr = new int;
    *ptr = 20;
    cout << "*ptr : "<< *ptr << endl;
    delete ptr;
    ptr = NULL; // good practise to make it NULL after delete
    // cout << "*ptr after delete: " << *ptr << endl;
    // delete ptr; //  not allowed
    #endif

    #if 1
    int *ptr = new int(20); // memory allocation and filling memory with value 20

    cout << "*ptr : "<< *ptr << endl;
    delete ptr;
    ptr = NULL;
    #endif

}