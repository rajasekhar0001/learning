#include <iostream>

using namespace std;

class Class {
    public:
    bool isFileOpen() {
        char* file = "check.cpp";
        FILE *fptr;
        fptr = fopen(file, "r");
        if (fptr == NULL)  {
            return false;
        }
        else {
            return true;
        }
    }
};

int main() {
    Class obj;
    cout  << obj.isFileOpen() << endl;
}