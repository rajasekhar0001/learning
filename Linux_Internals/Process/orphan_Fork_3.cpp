/**
 * Orphan Process
 * -> When a parent process completes exectution earlier than child process, there child process is called Orphan process.
 * -> Because Usually Parent process clears resources occupied by Child, when child completes execution.
 * -> but here Parent process terminated earlier, Here there is no parent for child process
 * -> In this case init process will become as parent to child (PPID of child = 1)
*/

/**
 * Note
 * in normal parent and child processes, it has to be specified that parent has to clean child resources
 * Here resources is like stack frames, etc.
*/

// Here we can see that child PPID is changed after parent terminated


#include <iostream>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

int main() {
    cout << "Before\n";
    int ret = fork();   // creates child process
    switch(ret) {
        case -1: 
            perror("fork");
            break;
        case 0: 
            cout << "Child process running\n";
            cout << "Child PID : " << getpid() << "  PPID : " <<  getppid() << endl;
            sleep(8);
            cout << "Child process is terminated\n";
            break;
        default: 
            cout << "Parent process running\n";
            cout << "Parent PID : " << getpid() << "   PPID : " << getppid() << endl;
            sleep(4);
            cout << "Parent process terminated\n";
            
    }

    
    // cout << "After\n";
    
}

