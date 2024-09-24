/**
 * REALLY HELPFUL
 *  To find last occurance of a character in a string
 * using std::strrchr() 
 * C-Style
 */
#include <iostream>
#include <cstring>
// #include 

using namespace std;


int main() {
    char *str = "/home/user/string/hellop.cpp";

    // char *result = strrchr(str, 'H');
    char *result;

    if((result = strrchr(str, '/'))) {
        cout << "Found at : " << result+1 << endl;
    }
    else {
        cout << "Not found\n";
    }
}
