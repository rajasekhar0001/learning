#include <iostream>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

int main() {
    cout << "Before\n";
    int count =10;
    int ret = fork();   // creates child process
    if (ret ==0) {
        // child process
        printf("child proces is running\n");
        cout <<" Child count : " << count << endl;
        sleep(4);
        printf("Child process terminated\n");
    }
    else if (ret > 0) {
        
        // parent process
        count++;
        cout << "Parent process is running\n";
        cout << "Parent count : " <<  count << endl;
        sleep(4);
        cout << "Parent process terminated\n";

    }
    else {
        perror("fork");
    }

    cout << "After\n";
    
}

