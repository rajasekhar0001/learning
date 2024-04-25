/**
 * fork() -> system call to create Child process
 * returns
 * -1 -> on failure
 * 0 -> child process returns
 * > 0 (child process ID) -> Parent process rerurns
*/

#include <iostream>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

int main() {
    cout << "Before\n";
    int check =90;
    int ret = fork();   // creates child process

    if (ret ==0) {
        // child process
        printf("child proces is running\n");
        check++;
        sleep(4);
        printf("Child process terminated\n");
        
        cout << "child check : " << check << endl;
    }
    else if (ret > 0) {
        // parent process
        cout << "Parent process is running\n";
        sleep(4);
        cout << "Parent process terminated\n";
        cout << "parent check : "<< check << endl;

    }
    else {
        perror("fork");
    }

    cout << "After\n";
    
}

