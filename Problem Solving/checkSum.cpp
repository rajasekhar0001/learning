#include <iostream>

using namespace std;


int checkSum(int val, int *arr) {

    static int ret = 0;
    if (val == arr[0])
        ret++;
    else {
        for (int i=0;i<)
    }

    return ret;

}

int main() {

    int val = 7;
    int arr[4] = {5, 4, 3, 7};

    int result = checkSum(val, arr);

    cout << "Result : " << result << endl;

}