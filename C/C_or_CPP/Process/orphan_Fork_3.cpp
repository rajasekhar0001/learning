/**
 * Orphan Process
 * -> When a parent process completes exectution earlier tahn
*/


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

