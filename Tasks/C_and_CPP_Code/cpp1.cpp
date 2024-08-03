#include <iostream>
#include "c1.h"

using namespace std;

void printCPP() {
    cout << "Inside CPP code\n";
}

#if 1
int main() {
    cout << "CPP code" << endl;
    printC();
}
#endif

