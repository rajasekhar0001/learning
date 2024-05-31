#include <iostream>

using namespace std;

class MainClass {
    public:

    int checkType(int num) {
        if (num > 0) {
            return 1;
        }
        else if (num ==0) {
            return 0;
        }
        return -1;
    }
};

int main() {

    MainClass obj;

    if (1) {
        obj.checkType(5);
    }

}