// Zombie process 
// Explanation
// Defination: If child process completes its execution earlier than parent process then that
              // that child process is called as Zombie Process
/**
 * To check the states of processs
 * CMD : ps -elf
 * zombie process is even completed execution still it will be there in the process table
 * Waiting for their parent process to retrieve their exit status
 * But Zombie processes don't consume any active resources like CPU, Memory, etc.
*/

// here we can see that state chenged for the terminated process

#include <iostream>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

int main() {
    cout << "Before\n";
    int ret = fork();   // creates child process
    if (ret ==0) {
        // child process
        printf("child proces is running\n");
        cout << "Child PID : " << getpid() << "   PPID : " << getppid()<< endl;
        sleep(2);
        printf("Child process terminated\n");
    }
    else if (ret > 0) {
        // parent process
        cout << "Parent process is running\n";
        cout << "Parent PID : " << getpid() << "   PPID : " << getppid() << endl;
        sleep(8);
        cout << "Parent process terminated\n";

    }
    else {
        perror("fork");
    }

    cout << "After\n";
    
}

