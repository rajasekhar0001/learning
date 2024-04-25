#include <iostream>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

int main() {
    cout << "Before\n";
    fork();
    cout << "After\n";
    
}

