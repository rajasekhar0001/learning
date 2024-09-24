/**
 * Possibility to avoid crash if new fails
 * * using try and catch
 * * using std::nothrow
 */
#include <iostream>

using namespace std;

int main() {
    #if 0
    int *p = new int [100000000000];
    cout << "new allocated memory\n";

    #elif 0

    for (int i=0;i<10000000;i++) {
        try {
            int *p = new int[1000000000];
            cout << "success\n";
        }
        catch(std::exception& e) {
            cout << "Exception thrown : " << e.what() << endl;
            break;
        }
    }
    #elif 0
    // using std::nothrow to protect from crash if new fails
    int *p = new(std::nothrow) int[10000000000000000000];

    if(p != nullptr) {
        cout << "Memory allocated successfully\n";
    }
    else {
        cout << "Failed to allocate memory" << endl;
    }

    #else
    
    int *p = nullptr;

    delete p;
    delete p;


    #endif
}