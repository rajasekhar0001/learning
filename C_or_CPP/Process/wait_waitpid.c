/**
 * wait and waitpid system calls are looking for the state change in child processes
 * wait -> it is blocked waiting for one of the child to chenge its state
 * waitpid -> It can be used in blocking way and non blocking way with the option
 *            WNOHANG
 * wait -> int wait(int &status);  // on success, returns the process ID of the child, else -1
 * waitpid -> int waitpid(pid_t pid, int &status, int flag);
 *         -> on success returns the process ID of process whose PID is given as input, else -1
 *         -> Behaviour of this system call can be adjusted using flags (blocking or non blocking)
 * 
 * 
 * Usaually wait() and waitpid() are blocking calls
 * 
 * waitpid() can be used as non-blocking call with the options, Option to use is 
 * 
 * WNOHANG
 * 
 * Syntax:
       pid_t waitpid(pid_t pid, int *wstatus, int options);
       pid_t wait(int *wstatus); // wastatus is a int variable with no value, status of child process
       is stored in this variable

* 
*/

#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>


int main() {

    int ret = fork();
    

    if (ret == 0) {
        printf("Child process\n");
        sleep(3);
        printf("Child is terminated\n");
    }

    else if (ret > 0) {
        printf("Parent process\n");
        int status;

        #if 0

        wait(&status); // we can use wait(NULL) as well, butu we miss the process exit status
        // The above wait is blocking call
        printf("With exit status : %d\n", WEXITSTATUS(status));


        #elif 0

        waitpid(ret, &status, 0); // Now its eqivalent to wait()
        // if 0 is given as an option
        printf("With exit status : %d\n", WEXITSTATUS(status));

        #elif 1

        int r = waitpid(ret, &status, WNOHANG);
        // WNOHANG is used for Non Blocking purpose in calling process, it's just like siganl registering
        while (1) {
            if (WIFEXITED(status)) {
                printf("Child is terminated With exit status :  %d   %d\n", WEXITSTATUS(status));
            }
        }

        #endif

        

        printf("WNOHANG : %d\n", WNOHANG);

        printf("Parent is terminated\n");
    }

    
}