/**
 * wait -> it is blocked waiting for one of the child to chenge its state
 * waitpid -> It can be used in blocking way and non blocking way with the option
 *            WNOHANG
 * wait -> int wait(int &status);  // on success, returns the process ID of the child, else -1
 * waitpid -> int waitpid(pid_t pid, int &status, int flag);
 *         -> on success returns the process ID of process whose PID is given as input, else -1
 *         -> Behaviour of this system call can be adjusted using flags (blocking or non blocking)
*/

#include <stdio.h>
#include <sys/wait.h>


int main() {
    
}